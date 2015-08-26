#include "tile_map.h"

TileMap::TileMap(int size_x, int size_y, std::string texture_identifier):
	m_size_x(size_x),
	m_size_y(size_y)
{
	// Get the tileset texture parameters
	m_texture_wrapper = TextureRegistry::getInstance()->getTexture(texture_identifier);

	// Create vertex array
	m_vertex_array = sf::VertexArray(sf::Quads, 4 * m_size_x * m_size_y);

	// Reserve space in tile vector
	m_tiles.resize(m_size_x * m_size_y, NULL);
}

// Get the tile at coordinate x,y
TileEntity* TileMap::getTileAt(int x, int y)
{
	return m_tiles[x + m_size_x * y];
}

// Set the tile at coordinate x,y
void TileMap::setTileAt(int x, int y, int type, int subtype)
{
	// Calculate vector index from x and y
	int index = x + m_size_x * y;

	// First we create a new tile instance
	if(type == ENTITY_TYPE_TILE)
	{
		m_tiles[index] = new SolidTileEntity(subtype);
	}
	else if(type == ENTITY_TYPE_DECORATIVE_TILE)
	{
		m_tiles[index] = new DecorativeTileEntity(subtype);
	}
	else
	{
		// This is not a tile?
		return;
	}

	// Set tile position
	m_tiles[index]->setPosition(sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));

	// Update vertex map coordinates
	sf::Vertex* quad = &m_vertex_array[index * 4];
	quad[0].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);
	quad[1].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE) + sf::Vector2f(TILE_SIZE,0);
	quad[2].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE) + sf::Vector2f(TILE_SIZE,TILE_SIZE);
	quad[3].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE) + sf::Vector2f(0,TILE_SIZE);


	// Update vertex map texture
	sf::IntRect parameters = m_texture_wrapper->parameters[subtype];
	quad[0].texCoords = sf::Vector2f(parameters.left, parameters.top);
	quad[1].texCoords = sf::Vector2f(parameters.left + parameters.width, parameters.top);
	quad[2].texCoords = sf::Vector2f(parameters.left + parameters.width, parameters.top + parameters.height);
	quad[3].texCoords = sf::Vector2f(parameters.left, parameters.top + parameters.height);
}

void TileMap::draw(sf::RenderTarget* target)
{
	// Translate the currently visible area to world coordinates
	sf::Vector2f topleft = target->mapPixelToCoords(sf::Vector2i(0,0));
	sf::Vector2f bottomright = target->mapPixelToCoords((sf::Vector2i) target->getSize());

	// Which tiles are visible?
	int min_x = topleft.x/TILE_SIZE;
	int min_y = topleft.y/TILE_SIZE;
	int max_x = bottomright.x/TILE_SIZE;
	int max_y = bottomright.y/TILE_SIZE;

	// Do not run out of bounds ;-)
	if(min_x < 0)
	{
		min_x = 0;
	}

	if(min_y < 0)
	{
		min_y = 0;
	}

	if(max_x >= m_size_x)
	{
		max_x = m_size_x-1;
	}

	if(max_y >= m_size_y)
	{
		max_y = m_size_y-1;
	}

	// Put all visible vertices into the array
	sf::VertexArray v = sf::VertexArray(sf::Quads);
	for(int i=min_x;i<=max_x;i++)
	{
		for(int j=min_y;j<=max_y;j++)
		{
			sf::Vertex* quad = &m_vertex_array[(i + m_size_x * j) * 4];
			v.append(quad[0]);
			v.append(quad[1]);
			v.append(quad[2]);
			v.append(quad[3]);
		}
	}

	// Draw this array
	target->draw(v, m_texture_wrapper->texture);
}