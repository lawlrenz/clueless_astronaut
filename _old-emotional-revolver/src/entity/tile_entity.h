#ifndef TILE_ENTITY_H
#define TILE_ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include "entity/base_entity.h"

class TileEntity: public BaseEntity
{
protected:
	TileEntity(int type, int subtype);
};

// This is needed for the hashmap below. TODO: Check hash function
/*
struct VectorHasher
{
  std::size_t operator()(const sf::Vector2u& v) const
  {
    using std::size_t;
    using std::hash;

    return hash<unsigned int>()(v.x*1024) ^ hash<unsigned int>()(v.y);
  }
};
*/

typedef std::vector<TileEntity*> TileContainer;
//typedef std::unordered_map<sf::Vector2u,TileEntity*,VectorHasher> TileMap;

#endif