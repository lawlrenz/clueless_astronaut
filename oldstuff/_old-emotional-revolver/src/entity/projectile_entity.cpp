#include "projectile_entity.h"

ProjectileEntity::ProjectileEntity(int subtype, sf::Vector2f speed, std::string texture_identifier):
	DrawableEntity(ENTITY_TYPE_PROJECTILE, subtype, sf::Vector2f(PROJECTILE_SIZE,PROJECTILE_SIZE), texture_identifier)
{
	m_fly_speed = speed;
	m_has_collided = false;
}

void ProjectileEntity::fly()
{
  setPosition(getPosition()+m_fly_speed);
}

void ProjectileEntity::handleCollision(TileMap* tiles)
{

	std::vector<sf::Vector2u> locations;
    std::vector<sf::Vector2u>::iterator loc_it;

    sf::Vector2u grid_location = getGridLocation();

    locations.push_back(grid_location + sf::Vector2u(0,0));
    locations.push_back(grid_location + sf::Vector2u(0,1));
    locations.push_back(grid_location + sf::Vector2u(1,0));
    locations.push_back(grid_location + sf::Vector2u(1,1));

    for(loc_it = locations.begin();loc_it != locations.end(); loc_it++)
    {
    	TileEntity* tile = tiles->getTileAt(loc_it->x, loc_it->y);
    	if(tile
    		&& tile->getType() == ENTITY_TYPE_TILE
    		&& tile->getBoundingBox().intersects(getBoundingBox()))
	    {
	    	m_has_collided = true;
        	return;
	    }
    }
/*
	TileMap::iterator it;
    // Find colliding tiles
    for(it = tiles.begin(); it != tiles.end(); it++)
    {
        if(it->second->getBoundingBox().intersects(getBoundingBox()))
        {
        	m_has_collided = true;
        	return;
        }
    }
*/
}

void ProjectileEntity::setCollided()
{
	m_has_collided = true;
}

bool ProjectileEntity::hasCollided()
{
	return m_has_collided;
}
