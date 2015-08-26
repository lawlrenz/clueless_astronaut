#include "level_handler.h"

LevelHandler::LevelHandler(std::string level_file)
{
    parseMapFile(level_file);

    m_test_unit = new UnitEntity(0, "unit");
    m_test_unit->setPosition(sf::Vector2f(100,80));

}

void LevelHandler::update()
{
    m_test_unit->update();
    m_test_unit->handleCollision(m_tiles);
    m_test_unit->handleCollision(m_projectiles);

    NPCUnitContainer::iterator it = m_npcs.begin();

    while(it != m_npcs.end())
    {
        (*it)->update();
        (*it)->handleCollision(m_tiles);
        (*it)->handleCollision(m_projectiles);

        //ProjectileEntity* prj = (*it)->doShoot();
        //if(prj != NULL)
        //{
        //    m_projectiles.push_back(prj);
        //}

        if(!(*it)->isAlive())
        {
            delete *it;
            m_npcs.erase(it);
        }
        else
        {
            it++;
        }
    }


    ProjectileContainer::iterator it2 = m_projectiles.begin();

    while(it2 != m_projectiles.end()){
        (*it2)->fly();
        (*it2)->handleCollision(m_tiles);
        if((*it2)->hasCollided())
        {
            delete *it2;
            m_projectiles.erase(it2);
        }
        else
        {
            it2++;
        }
    }


}

// Parse a map file
void LevelHandler::parseMapFile(std::string file)
{
    std::ifstream input(file.c_str());
    std::string line;

    int size_x;
    int size_y;

    // Get map dimensions
    getline(input, line);
    std::istringstream iss(line);
    if (!(iss >> size_x >> size_y)) { return; } // Malformed file?

    // Create tile map for these dimensions
    m_tiles = new TileMap(size_x, size_y, "tileset");

    int pos_x = 0;

    while(getline(input, line))
    {
        parseLine(line, pos_x, 0);
        pos_x++;
    }
}

// Parse one line of a level file
void LevelHandler::parseLine(std::string line, int pos_x, int pos_y)
{
    std::vector<std::string> elements;
    std::vector<std::string>::iterator elem_it;
    splitLine(line, COORDINATE_DELIMITER, elements);

    for(elem_it = elements.begin(); elem_it != elements.end(); elem_it++)
    {
        parseCoordinate(*elem_it, pos_x, pos_y);
        pos_y++;
    }

}

// Parse one coordinate of a level file
void LevelHandler::parseCoordinate(std::string str, int pos_x, int pos_y)
{
    std::vector<std::string> elements;
    std::vector<std::string>::iterator elem_it;
    splitLine(str, ELEMENT_DELIMITER, elements);

    for(elem_it = elements.begin(); elem_it != elements.end(); elem_it++)
    {
        parseElement(*elem_it, pos_x, pos_y);
    }

}

// Parse a single element of a level file
void LevelHandler::parseElement(std::string element, int pos_x, int pos_y)
{
    std::istringstream iss(element);
    int id, subid;
    if (!(iss >> id >> subid)) { return; } // Malformed file?

    // Debug output
    //std::cout << "ID: " << id << " SUBID: " << subid << std::endl;

    if(id == ENTITY_TYPE_BASE && subid == ENTITY_SUBTYPE_BASE_AIR)
    {
        // This is air. We do not create entities for air :-)
        return;
    }

    if(id == ENTITY_TYPE_TILE || id == ENTITY_TYPE_DECORATIVE_TILE)
    {
        m_tiles->setTileAt(pos_x, pos_y, id, subid);
    }
    else if (id == ENTITY_TYPE_UNIT && subid == ENTITY_SUBTYPE_NPC)
    {
        // Create a new NPC
        NPCUnitEntity* npc = new NPCUnitEntity(subid,"unit");
        npc->setPosition(sf::Vector2f(TILE_SIZE*pos_x, TILE_SIZE*pos_y));
        m_npcs.push_back(npc);
    }
    else
    {
        // Uh, unknown ID. Whut?
    }

}

// Helper function for splitting a string
std::vector<std::string> &LevelHandler::splitLine(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

UnitEntity *LevelHandler::getPlayerEntity()
{
    return m_test_unit;
}

ProjectileContainer *LevelHandler::getProjectileContainer()
{
  return &m_projectiles;
}

NPCUnitContainer *LevelHandler::getNPCUnitContainer()
{
  return &m_npcs;
}

TileMap *LevelHandler::getTileMap()
{
    return m_tiles;
}

void LevelHandler::addProjectile(ProjectileEntity* projectile)
{
    m_projectiles.push_back(projectile);
}
