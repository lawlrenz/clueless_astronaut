#ifndef UNIT_ENTITY_H
#define UNIT_ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "entity/drawable_entity.h"
#include "entity/tile_entity.h"
#include "entity/projectile_entity.h"
#include "map/tile_map.h"

class UnitEntity: public DrawableEntity
{
public:
	UnitEntity(int subtype, std::string texture_identifier);
	void update();
	void handleCollision(TileMap* tiles);
	void handleCollision(ProjectileContainer &projectiles);
	sf::Vector2f getMovementSpeed();
	void setMovementSpeed(sf::Vector2f speed);
	void setJumpEnabled();
	void doJump();
	void changeMode(int new_mode);
	void setMovementDirection(Direction dir);
	Direction getMovementDirection();
	ProjectileEntity* doShoot();
	void killUnit();
	bool isAlive();
	bool isAbleToJump();
	bool isMovingRight();
	bool isMovingLeft();
	int getHealth();
	sf::Vector2f getProjectileSpawnLocation();
protected:
	sf::Vector2f m_movement_speed;
	Direction m_movement_direction;
	Direction m_orientation;
	bool m_can_jump;
	bool m_is_alive;
	int m_cooldown;
	int m_fire_mode;
	int m_health;
};

#endif
