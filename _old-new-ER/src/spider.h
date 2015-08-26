#ifndef SPIDER_H
#define SPIDER_H

#include "defines.h"
#include "entity.h"
#include "wall.h"
#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>

class Spider:Entity
{
public:
	Spider();
	Spider(sf::Vector2f pos,sf::Vector2f levelBounds,std::list<Wall>* walls);
	void move();
	sf::Vector2f getPosition();
	
	//0: keine collision sonst:Schaden
	int isCollision(sf::Vector2f pos,sf::FloatRect* box);
private:
	std::list<Wall>* walls;
	sf::Vector2f levelBounds;
	sf::FloatRect rect;
	float schaden;

};

#endif
