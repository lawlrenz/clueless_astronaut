#ifndef ENTITY_H
#define ENTITY_H

#include "defines.h"
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	virtual void move() = 0;
//	sf::Vector2f getPosition();

protected:
	float movementSpeed;
	sf::Vector2f position;
	float leben;
	int orientation;
};

#endif
