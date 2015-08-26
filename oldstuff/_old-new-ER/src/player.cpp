#include "player.h"

Player::Player()
{
	moveVector = sf::Vector2f(0,0);
}


Player::Player(Level* lev)
{
	position = lev->getPlayerStart();
	std::cout << "pos: " << position.x << "," << position.y << "\n";
//	initPlayer();
	movementSpeed = 8;
	level = lev;
	collectedCoins = 0;
	orientation = DIRECTION_LEFT;
	s = SoundHandler::getSoundHandler();
	shooting = false;
	reload_time = 40;
	shoot_threshold = 0;
	leben = 100.0f;
}


void Player::move()
{
	
	// Update the player location
	sf::Vector2f new_location(position + moveVector*movementSpeed);
	//std::cout << "pos: " << position.x << "," << position.y << "\n";
	

	// Bounding box of the player(after the move)
	sf::FloatRect player_box(new_location,sf::Vector2f(ROBOT_WIDTH,ROBOT_HEIGHT));

	std::list<Wall>::iterator wall_it;
	bool collision = false;
	
	// Check for each wall ...
	for(wall_it = level->getWalls()->begin();wall_it != level->getWalls()->end();wall_it++)
	{
		if(wall_it->isCollision(new_location,&player_box))//collisionWall(new_location,&player_box,*wall_it))
		{
			collision = true;
			break;
		}
	}
	
	std::vector<Spider>::iterator spider_it;
	// Check for each wall ...
	for(spider_it = level->getSpiders()->begin();spider_it != level->getSpiders()->end();spider_it++)
	{
		leben -= spider_it->isCollision(new_location,&player_box);
	}
	
	// Check if new position is inside the game area
	if(new_location.x >= 0
		&& new_location.x + ROBOT_WIDTH <= level->getBounds().x*ROBOT_WIDTH
		&& new_location.y >= 0
		&& new_location.y + ROBOT_HEIGHT <= level->getBounds().y*ROBOT_HEIGHT
		&& collision == false)
	{
	//	std::cout<< collision << "\n";
		position = new_location; // Update location
	}
	
	//collect coins
	std::vector<sf::Vector2f>*  coins = level->getCoins();
	std::vector<sf::Vector2f>::iterator coin_it;
	// Check for each coin ...
	for(coin_it = level->getCoins()->begin();coin_it != level->getCoins()->end();)
	{
		sf::FloatRect coinRect(*coin_it,sf::Vector2f(COIN_WIDTH,COIN_HEIGHT));
		if(coinRect.intersects(player_box))
		{
			collectedCoins++;
			
			level->getCoins()->erase(coin_it);
		//	std::cout<<"coins: " << collectedCoins<<"\n";
		}
		else
			coin_it++;
	}
	
}

void Player::setMovementDirection(int direction)
{
	switch(direction)
	{
		case DIRECTION_LEFT:
		moveVector = sf::Vector2f(-1,0);
		break;

		case DIRECTION_LEFT_UP:
		moveVector = sf::Vector2f(-1,-1);
		break;
		
		case DIRECTION_LEFT_DOWN:
		moveVector = sf::Vector2f(-1,1);
		break;

		case DIRECTION_RIGHT:
		moveVector = sf::Vector2f(1,0);
		break;
		
		case DIRECTION_RIGHT_UP:
		moveVector = sf::Vector2f(1,-1);
		break;
		
		case DIRECTION_RIGHT_DOWN:
		moveVector = sf::Vector2f(1,1);
		break;

		case DIRECTION_UP:
		moveVector = sf::Vector2f(0,-1);
		break;

		case DIRECTION_DOWN:
		moveVector = sf::Vector2f(0,1);
		break;

		default:
		moveVector = sf::Vector2f(0,0);
		break;
	}
}
//wird in gameloop aufgerufen
void Player::shoot()
{
	shoot_threshold += 1;
	if(shoot_threshold >= reload_time)
		if(shooting)
		{
			//TODO bulletposition anpassen
			Bullet newBullet(position,orientation);
			level->getBullets()->push_back(newBullet);
		//	std::cout << "pos: " << newBullet.getPosition().x << "," << newBullet.getPosition().y << "\n";
		//	std::cout<< "bullet: " << level->getBullets()->begin()->getPosition().x << "," << level->getBullets()->begin()->getPosition().y << "\n";
			s->playSound(SHOOT);
			shoot_threshold = 0;
		}
}

sf::Vector2f Player::getPosition()
{
	return position;
}

int Player::getCollectedCoins()
{
	return collectedCoins;
}
int Player::getOrientation()
{
	return orientation;
}
void Player::setOrientation(int newOrientation)
{
	orientation = newOrientation;
}	
void Player::startShooting()
{
	shooting = true;
}

void Player::stopShooting()
{
	shooting = false;
}
float Player::checkLife()
{
	if(leben < 0)
		onDeath();
	return leben;
}
void Player::onDeath()
{

}
void Player::reset(Level* level)
{
	this->level = level;
	position = level->getPlayerStart();
	collectedCoins = 0;
	shooting = false;
	orientation = DIRECTION_LEFT;
	shoot_threshold = 0;
	leben = 100.0f;
}
