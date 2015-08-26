#include "move_handler.h"

MoveHandler::MoveHandler(GameState *state)
{
	m_gst = state;
	//s = SoundHandler::getSoundHandler();
}


void MoveHandler::handleEvents()
{	
	//only move when playing
	if(m_gst->getGameState() == STATE_PLAYING)
	{	
		//move entitys (before moving hero!!)
		//moveEntitys();
	
		//move hero
		m_gst->getHero()->move();
	}
}
bool MoveHandler::collisionWall(sf::Vector2f position,sf::FloatRect* box,Wall wall_it)
{
	sf::Vector2f distance = wall_it.getPosition() - position;
	//	std::cout<< "distance: (" << distance.x << "," << distance.y <<")\n";
	//std::cout << (distance.x*distance.x + distance.y*distance.y) /(80*80)<< "\n";
	 
	// 					  x^2 + y^2 				   < wurzel(2) * 80^2
	if((distance.x*distance.x + distance.y*distance.y) < 9051)
		if(wall_it.getRect().intersects(*box))
		{
			return true;
		//	std::cout << "collision: " << collision;
		}
}
		
