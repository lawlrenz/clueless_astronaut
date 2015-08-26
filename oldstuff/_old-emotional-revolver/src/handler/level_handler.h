#ifndef LEVEL_HANDLER_H
#define LEVEL_HANDLER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "entity/tile_entity.h"
#include "entity/decorative_tile_entity.h"
#include "entity/solid_tile_entity.h"
#include "entity/unit_entity.h"
#include "entity/npc_unit_entity.h"
#include "entity/projectile_entity.h"
#include "map/tile_map.h"

class LevelHandler
{
public:
	LevelHandler(std::string level_file);
	void update();
	UnitEntity *getPlayerEntity();
	ProjectileContainer *getProjectileContainer();
	NPCUnitContainer *getNPCUnitContainer();
	TileMap *getTileMap();
	void addProjectile(ProjectileEntity* projectile);
private:
	TileMap* m_tiles;
	ProjectileContainer m_projectiles;
	NPCUnitContainer m_npcs;
	UnitEntity *m_test_unit;

	void parseMapFile(std::string file);
	void parseLine(std::string line, int pos_x, int pos_y);
	void parseCoordinate(std::string str, int pos_x, int pos_y);
	void parseElement(std::string element, int pos_x, int pos_y);
	std::vector<std::string> &splitLine(const std::string &s, char delim, std::vector<std::string> &elems);

};

#endif
