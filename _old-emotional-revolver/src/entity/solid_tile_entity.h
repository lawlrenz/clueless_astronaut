#ifndef SOLID_TILE_ENTITY_H
#define SOLID_TILE_ENTITY_H

#include <SFML/Graphics.hpp>
#include "entity/tile_entity.h"

class SolidTileEntity: public TileEntity
{
public:
	SolidTileEntity(int subtype);
private:
};

#endif