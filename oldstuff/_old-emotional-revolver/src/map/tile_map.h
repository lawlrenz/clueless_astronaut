#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "defines.h"
#include "entity/tile_entity.h"
#include "entity/decorative_tile_entity.h"
#include "entity/solid_tile_entity.h"
#include "registry/texture_registry.h"

class TileMap
{
public:
	TileMap(int size_x, int size_y, std::string texture_identifier);
	TileEntity* getTileAt(int x, int y);
	void setTileAt(int x, int y, int type, int subtype);
	void draw(sf::RenderTarget* target);
private:
	const int m_size_x;
	const int m_size_y;
	TextureWrapper* m_texture_wrapper;
	sf::VertexArray m_vertex_array;
	TileContainer m_tiles;
};

#endif