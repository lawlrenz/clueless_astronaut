#include "wall.h"


Wall::Wall(sf::Vector2f pos)
{
	//set walls position
	position = pos;
	
	//init rect
	rect = sf::FloatRect(pos,sf::Vector2f(ROBOT_HEIGHT,ROBOT_WIDTH));
}


// get rect
sf::FloatRect Wall::getRect()
{
	return rect;
}

sf::Vector2f Wall::getPosition()
{
	return position;
}
bool Wall::isCollision(sf::Vector2f entPosition,sf::FloatRect* box)
{
	sf::Vector2f distance = position - entPosition;
	//	std::cout<< "distance: (" << distance.x << "," << distance.y <<")\n";
	//std::cout << (distance.x*distance.x + distance.y*distance.y) /(80*80)<< "\n";
	 
	// 					  x^2 + y^2 				   < wurzel(2) * 80^2
	if((distance.x*distance.x + distance.y*distance.y) < 9051)
		if(rect.intersects(*box))
		{
			return true;
		//	std::cout << "collision: " << collision;
		}
}


