#include "level.h"

std::list<Wall> walls;

char *beginLevelPath = NULL;

Level::Level()
{

}


Level::Level(std::string levelPath)
{
	beginLevelPath = &levelPath.at(0);
	
	//coins
	m_new_coin_threshold = 0;
	coinSpawnRate = 30;
	
	//spiders
	m_new_spider_threshold = 0;
	spiderSpawnRate = 30;
	
	//
	initLevel();
}

void Level::initLevel()
{
	std::string line = "42";
	//ifstream brauch const char* bzw const string aka "blablub"
	const char* myPath = beginLevelPath;
    std::ifstream infile(myPath);
    
    // init before for loop, because need after it for levelbounds
    int row = 0;
    int col = 0;
    //load walls etc
    for(; !std::getline(infile,line).eof();++row)
    {
    	col = 0;
    	for(; col+2 < line.length();++col)
    	{
    		switch(line[col+1])
    		{
    			//Player
    			case 'p':
    			case 'P':
    				playerStart = (sf::Vector2f(col*ROBOT_WIDTH,row*ROBOT_HEIGHT));
    				break;
    				
    			//Wall
    			case 'x':
    			case 'X':
					//std::cout<<"push wall \n";
					Wall newWall(sf::Vector2f(col*ROBOT_WIDTH,row*ROBOT_HEIGHT));
					//std::cout<<"(" << newWall.getRect().left <<","<< newWall.getRect().top <<")   "  << "push wall \n";
					walls.push_back(newWall);
					//std::cout<< walls.size() << "\n";
					break;
    		}
    		
    	}
    }
    // bestimme levelbounds
    levelBounds = sf::Vector2f(col,row); 
}

void Level::updateEntitys()
{
	// Add a new coin when threshold value is reached
	m_new_coin_threshold += static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	if(m_new_coin_threshold > coinSpawnRate)
	{
		m_new_coin_threshold = 0;
		bool collision = true;
	
		std::list<Wall>::iterator wall_it;
		
		// Coins nicht in Walls spawnen
		while(collision)
		{
			// New random position for screw inside the game area
			float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(levelBounds.x*ROBOT_WIDTH-COIN_WIDTH)));
			float y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(levelBounds.y*ROBOT_HEIGHT-COIN_HEIGHT)));
			sf::Vector2f new_location(x,y);
			sf::FloatRect box(new_location,sf::Vector2f(COIN_WIDTH,COIN_HEIGHT));
		
			for(wall_it = walls.begin();wall_it != walls.end();wall_it++)
			{
				if(wall_it->isCollision(new_location,&box))
				{
					break;
				}
			}
			if(wall_it == walls.end())
			{
				collision = false;
				coins.push_back(sf::Vector2f(x,y));
			}
		}
	}
	
	// Add a new spider when threshold value is reached
	m_new_spider_threshold += static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	if(m_new_spider_threshold > spiderSpawnRate)
	{
		m_new_spider_threshold = 0;
		bool collision = true;
	
		std::list<Wall>::iterator wall_it;
		
		// spiders nicht in Walls spawnen
		while(collision)
		{
			// New random position for screw inside the game area
			float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(levelBounds.x*ROBOT_WIDTH-SPIDER_WIDTH)));
			float y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(levelBounds.y*ROBOT_HEIGHT-SPIDER_HEIGHT)));
			sf::Vector2f new_location(x,y);
			sf::FloatRect box(new_location,sf::Vector2f(SPIDER_WIDTH,SPIDER_HEIGHT));
		
			for(wall_it = walls.begin();wall_it != walls.end();wall_it++)
			{
				if(wall_it->isCollision(new_location,&box))
				{
					break;
				}
			}
			if(wall_it == walls.end())
			{
				collision = false;
				spiders.push_back(Spider(sf::Vector2f(x,y),levelBounds,&walls));
			}
		}
	}
	
	//move spiders
	std::vector<Spider>::iterator spider_it;
	for(spider_it = spiders.begin();spider_it != spiders.end();spider_it++)
	{
		spider_it->move();
	}
	
	
	
	//move bullets
	std::vector<Bullet>::iterator bullet_it;
	std::list<Wall>::iterator wall_it;
	sf::Vector2f position;
	
	for(bullet_it = bullets.begin();bullet_it != bullets.end();)
	{
		// bewege bullet
		bullet_it->move();
		position = bullet_it->getPosition();
		
		// wenn bullet außerhalb des levels ist: lösche bullet
		if(position.x >= levelBounds.x*ROBOT_WIDTH || position.x < 0 || position.y >= levelBounds.y*ROBOT_HEIGHT || position.y < 0)
		{
			bullets.erase(bullet_it);
			continue;
		}
		else
		{	
			//wenn bullet mit wand collidiert: lösche bullet
			bool collision = false;
			sf::FloatRect box(position,sf::Vector2f(BULLET_WIDTH,BULLET_HEIGHT));
			//for all walls
			for(wall_it = walls.begin();wall_it != walls.end();wall_it++)
			{
				if(wall_it->isCollision(position,&box))
				{
					bullets.erase(bullet_it);
					
					collision = true;
					break;
				}
			}
			//wenn bullet mit entity collidiert: lösche bullet und töte entity
			//for all spiders
			for(spider_it = spiders.begin();spider_it != spiders.end();)
			{
				if(spider_it->isCollision(position,&box) != 0)
				{
					bullets.erase(bullet_it);
					spiders.erase(spider_it);
					collision = true;
					break;
				}
				else
					spider_it++;
			}
			if(!collision)
			{
				bullet_it++;
			}
			
		}
		
	}
}


std::vector<sf::Vector2f>* Level::getCoins()
{
	return &coins;
}
std::list<Wall>* Level::getWalls()
{
	return &walls;
}

std::vector<Bullet>* Level::getBullets()
{
	return &bullets;
}

std::vector<Spider>* Level::getSpiders()
{
	return &spiders;
}

sf::Vector2f Level::getBounds()
{
	return levelBounds;
}
sf::Vector2f Level::getPlayerStart()
{
	return playerStart;
}
