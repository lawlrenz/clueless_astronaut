#include "bullet.h"

Bullet::Bullet(sf::Vector2f pos,int orientation)
{
	position = pos;
	movementSpeed = 16;
	switch (orientation)
	{
		case DIRECTION_LEFT:
			moveVector = sf::Vector2f(-movementSpeed,0);
			break;
		case DIRECTION_RIGHT:
			moveVector = sf::Vector2f(movementSpeed,0);
			break;
		case DIRECTION_UP:
			moveVector = sf::Vector2f(0,-movementSpeed);
			break;
		case DIRECTION_DOWN:
			moveVector = sf::Vector2f(0,movementSpeed);
			break;
	}
	
}


void Bullet::move()
{
	position += moveVector;
}
sf::Vector2f Bullet::getPosition()
{
	return position;
}
