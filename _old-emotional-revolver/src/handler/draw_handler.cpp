#include "draw_handler.h"

DrawHandler::DrawHandler()
{
    GameRegistry* registry = GameRegistry::getInstance();
    m_window = registry->getRenderWindow();
    m_level_handler = registry->getLevelHandler();
}

void DrawHandler::draw()
{

    // Draw tiles
    TileMap* tiles = m_level_handler->getTileMap();
    tiles->draw(m_window);
    //TileMap::iterator tit;
    //for(tit = tiles->begin(); tit != tiles->end(); tit++)
    //{
    //    tit->second->draw(m_window);
    //}

    // Draw projectiles
    ProjectileContainer* projectiles = m_level_handler->getProjectileContainer();
    ProjectileContainer::iterator pit;
    for(pit = projectiles->begin(); pit != projectiles->end(); pit++){
        (*pit)->draw(m_window);
    }

    // Draw NPCs
    NPCUnitContainer* npcs = m_level_handler->getNPCUnitContainer();
    NPCUnitContainer::iterator nit;
    for(nit = npcs->begin(); nit != npcs->end(); nit++)
    {
        (*nit)->draw(m_window);
    }

    // Draw player
    m_level_handler->getPlayerEntity()->draw(m_window);

}