#ifndef DECORATIVE_TILE_ENTITY_H
#define DECORATIVE_TILE_ENTITY_H

#include <SFML/Graphics.hpp>
#include "entity/tile_entity.h"

class DecorativeTileEntity: public TileEntity
{
public:
	DecorativeTileEntity(int subtype);
private:
};

#endif