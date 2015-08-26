#include "game_state.h"

//Level GameState::level("levels/level0.dat");

GameState::GameState()
{
}

GameState::GameState(int x, int y)
{
	
	// Initial game state
	m_game_state = STATE_MENU;
	
	//
	level = new Level("levels/level0.dat");

	// Size of the game area
	m_size_x = level->getBounds().x*ROBOT_WIDTH;
	m_size_y = level->getBounds().y*ROBOT_HEIGHT;
	
	//std::cout <<"m_size_x: " << m_size_x << "\n";
	
	// Set initial player movement and location
	hero = new Player(level);
	//setPlayerMovementDirection(DIRECTION_NONE);
	//setPlayerLocation(sf::Vector2f(x/2-ROBOT_WIDTH/2,y/2-ROBOT_HEIGHT/2));
	
	//number of collected screws
	m_screws_collected = 0;
	
	// Initialize random seed
	srand (static_cast <unsigned> (time(0)));
	
}

int GameState::getGameState()
{
	return m_game_state;
}

void GameState::restartGame()
{
	// Reset all values
	m_game_state = STATE_PLAYING;
	level = new Level("levels/level0.dat");
	hero ->reset(level);
//	m_screws_collected = 0;
	//setPlayerMovementDirection(DIRECTION_NONE);
	//setPlayerLocation(sf::Vector2f(m_size_x/2-ROBOT_WIDTH/2,m_size_y/2-ROBOT_HEIGHT/2));
//	m_screw_locations.clear();

}

void GameState::updateGameState()
{
	// Do nothing if the game is not in playing state
	if(m_game_state == STATE_PLAYING)
	{
		level->updateEntitys();
		//player prüft ob er schießen darf
		hero->shoot();
		if(hero->checkLife() < 0)
			m_game_state = STATE_LOST;
	}
}

void GameState::setGameState(int state)
{
	m_game_state = state;
}

sf::Vector2f GameState::getPlayerLocation()
{
	return hero->getPosition();
}

void GameState::addScrew(sf::Vector2f location)
{
	m_screw_locations.push_back(location);
}

std::vector<sf::Vector2f>* GameState::getScrewLocations()
{
	return &m_screw_locations;
}

int GameState::getVisibleScrewsCount()
{
	return m_screw_locations.size();
}

int GameState::getCollectedScrewsCount()
{
	return m_screws_collected;
}
Level* GameState::getLevel()
{
	return level;
}

void GameState::collectedScrew()
{
	m_screws_collected++;
}

Player* GameState::getHero()
{
	return hero;
}
