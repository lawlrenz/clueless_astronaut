#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include "defines.h"

class Wall
{
public:
	Wall(sf::Vector2f pos);
	void setColor(int color);
	int getColor();
	sf::Vector2f getPosition();
	sf::FloatRect getRect();
	bool isCollision(sf::Vector2f entPosition,sf::FloatRect* box);

private:
	int color;
	sf::Vector2f position;
//	void draw(sf::RenderTarget& target, sf::RenderStates states);
	sf::FloatRect rect;
};

#endif
