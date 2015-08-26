#ifndef PROJECTILE_ENTITY_H
#define PROJECTILE_ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "entity/drawable_entity.h"
#include "entity/tile_entity.h"
#include "map/tile_map.h"

class ProjectileEntity: public DrawableEntity
{
public:
	ProjectileEntity(int subtype, sf::Vector2f speed, std::string texture_identifier);
	void fly();
	void handleCollision(TileMap* tiles);
	void setCollided();
	bool hasCollided();
private:
	sf::Vector2f m_fly_speed;
	bool m_has_collided;
	//gravitation, flugbahn?
};
typedef std::vector<ProjectileEntity*> ProjectileContainer;
#endif
