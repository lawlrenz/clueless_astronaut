#include "base_entity.h"

BaseEntity::BaseEntity(int type, int subtype, sf::Vector2f size):
	m_type(type),
	m_subtype(subtype)
{
	// initialize vertex array
	//m_vertex_array = sf::VertexArray(sf::Quads, 4);

	// Fetch the texture for this entity
	//setTextureParameters(m_texture_manager.getTextureParameters(m_type,m_subtype));

	// Set width and height
	setSize(size);
}

/*
void BaseEntity::draw(sf::RenderWindow* window)
{

	m_vertex_array[0].position = sf::Vector2f(m_location.x, m_location.y);
	m_vertex_array[1].position = sf::Vector2f(m_location.x + m_size.x, m_location.y);
	m_vertex_array[2].position = sf::Vector2f(m_location.x + m_size.x, m_location.y + m_size.y);
	m_vertex_array[3].position = sf::Vector2f(m_location.x, m_location.y + m_size.y);

	window->draw(m_vertex_array, &m_texture_parameters->texture);
}

void BaseEntity::setTextureParameters(TextureParameters *texture_parameters)
{

	if(texture_parameters == NULL)
	{
		// No parameters found. This is bad.
		return;
	}

	m_texture_parameters = texture_parameters;

	m_vertex_array[0].texCoords = sf::Vector2f(m_texture_parameters->left, m_texture_parameters->top);
	m_vertex_array[1].texCoords = sf::Vector2f(m_texture_parameters->left + m_texture_parameters->width, m_texture_parameters->top);
	m_vertex_array[2].texCoords = sf::Vector2f(m_texture_parameters->left + m_texture_parameters->width, m_texture_parameters->top + m_texture_parameters->height);
	m_vertex_array[3].texCoords = sf::Vector2f(m_texture_parameters->left, m_texture_parameters->top + m_texture_parameters->height);

}

sf::Vector2f BaseEntity::getLocation()
{
	return m_location;
}

void BaseEntity::setLocation(sf::Vector2f location)
{
	m_location = location;
}
*/

// Get the size of the entity
sf::Vector2f BaseEntity::getSize()
{
	return m_size;
}

// Set the size of the entity
void BaseEntity::setSize(sf::Vector2f size)
{
	m_size = size;
}

// Get bounding box of the entity
sf::FloatRect BaseEntity::getBoundingBox()
{
	return sf::FloatRect(getPosition().x, getPosition().y, m_size.x, m_size.y);
}

// Get the center coordinate of the entity
sf::Vector2f BaseEntity::getCenter()
{
	return sf::Vector2f(getPosition().x + m_size.x/2.0f, getPosition().y + m_size.y/2.0f);
}

// Set the center coordinate of the entity
void BaseEntity::setCenter(sf::Vector2f location)
{
	setPosition(sf::Vector2f(location.x - m_size.x/2.0f, location.y - m_size.y/2.0f));
}

// Get the y value of the top edge of the entity
float BaseEntity::getTop()
{
	return getPosition().y;
}

// Get the y value of the bottom edge of the entity
float BaseEntity::getBottom()
{
	return getPosition().y + m_size.y;
}

// Get the x value of the left edge of the entity
float BaseEntity::getLeft()
{
	return getPosition().x;
}

// Get the x value of the right edge of the entity
float BaseEntity::getRight()
{
	return getPosition().x + m_size.x;
}

// Set the y value of the top edge of the entity
void BaseEntity::setTop(float value)
{
	setPosition(getPosition().x,value);
}

// Set the y value of the bottom edge of the entity
void BaseEntity::setBottom(float value)
{
	setPosition(getPosition().x,value - m_size.y);
}

// Set the x value of the left edge of the entity
void BaseEntity::setLeft(float value)
{
	setPosition(value, getPosition().y);
}

// Set the x value of the right edge of the entity
void BaseEntity::setRight(float value)
{
	setPosition(value - m_size.x, getPosition().y);
}

// Get the grid coordinates of the left-top edge of the entity
sf::Vector2u BaseEntity::getGridLocation()
{
	return sf::Vector2u(getPosition().x/TILE_SIZE, getPosition().y/TILE_SIZE);
}

// Get the main type of the entity
int BaseEntity::getType()
{
	return m_type;
}

// Get the subtype of the entity
int BaseEntity::getSubtype()
{
	return m_subtype;
}