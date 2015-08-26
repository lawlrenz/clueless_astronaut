#ifndef BULLET_H
#define BULLET_H

#include "entity.h"
#include "defines.h"

class Bullet:Entity
{
public:
	Bullet();
	Bullet(sf::Vector2f pos,int orientation);
	void move();
	sf::Vector2f getPosition();

private:
	float movementSpeed;
	sf::Vector2f moveVector;
	sf::Vector2f position;
};

#endif
