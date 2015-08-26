#include "spider.h"

Spider::Spider()
{

}
Spider::Spider(sf::Vector2f pos,sf::Vector2f levelBounds,std::list<Wall>* walls)
{
	position = pos;
	movementSpeed = 5;
	orientation = DIRECTION_DOWN;
	this->walls = walls;
	this->levelBounds = levelBounds;
	rect = sf::FloatRect(pos,sf::Vector2f(SPIDER_WIDTH,SPIDER_HEIGHT));
	schaden = 5.0f;
}


void Spider::move()
{
	int orientation =((orientation + (std::rand()))%4)+1;
//	std::cout << "orientation: " << orientation << "\n";
	sf::Vector2f newPos;
	switch(orientation){
		case DIRECTION_UP:   
			newPos = position + sf::Vector2f(0, -(movementSpeed));
			break;
		case DIRECTION_LEFT:  
			newPos = position + sf::Vector2f(-(movementSpeed), 0);
			break;
		case DIRECTION_DOWN: 
			newPos = position + sf::Vector2f(0, (movementSpeed));
			break;
		case DIRECTION_RIGHT: 
			newPos = position + sf::Vector2f((movementSpeed), 0);
			break;
	}
	// Bounding box of the player(after the move)
	sf::FloatRect box(newPos,sf::Vector2f(SPIDER_WIDTH,SPIDER_HEIGHT));

	std::list<Wall>::iterator wall_it;
	bool collision = false;
	
	// Check for each wall ...
	for(wall_it = walls->begin();wall_it != walls->end();wall_it++)
	{
		if(wall_it->isCollision(newPos,&box))
		{
			collision = true;
			break;
		}
	}
	if(!collision 
		&& newPos.x >= 0
		&& newPos.x + SPIDER_WIDTH <= levelBounds.x*ROBOT_WIDTH
		&& newPos.y >= 0
		&& newPos.y + SPIDER_HEIGHT <= levelBounds.y*ROBOT_HEIGHT)
	{
		position = newPos;
		rect = box;
	}
}

int Spider::isCollision(sf::Vector2f pos,sf::FloatRect* box)
{
	sf::Vector2f distance = position - pos;
	//	std::cout<< "distance: (" << distance.x << "," << distance.y <<")\n";
	//std::cout << (distance.x*distance.x + distance.y*distance.y) /(80*80)<< "\n";
	 
	// 					  x^2 + y^2 				   < wurzel(2) * 80^2
	if((distance.x*distance.x + distance.y*distance.y) < 9051)
		if(rect.intersects(*box))
		{
			return schaden;
		//	std::cout << "collision: " << collision;
		}
	return 0;	
}

sf::Vector2f Spider::getPosition()
{
	return position;
}


