#include "tile_entity.h"

TileEntity::TileEntity(int type, int subtype):
	BaseEntity(type, subtype, sf::Vector2f(TILE_SIZE,TILE_SIZE))
{
	//sf::IntRect parameters = m_texture_wrapper->parameters[subtype];
	//m_vertex_array[0].texCoords = sf::Vector2f(parameters.left, parameters.top);
	//m_vertex_array[1].texCoords = sf::Vector2f(parameters.left + parameters.width, parameters.top);
	//m_vertex_array[2].texCoords = sf::Vector2f(parameters.left + parameters.width, parameters.top + parameters.height);
	//m_vertex_array[3].texCoords = sf::Vector2f(parameters.left, parameters.top + parameters.height);
}