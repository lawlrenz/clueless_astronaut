#include "game_state.h"

GameState::GameState(int x, int y)
{
	// Initial game state
	m_game_state = STATE_MENU;

	// Size of the game area
	m_size_x = x;
	m_size_y = y;

	// Set initial player movement and location
	setPlayerMovementDirection(DIRECTION_NONE);
	setPlayerLocation(sf::Vector2f(x/2-ROBOT_WIDTH/2,y/2-ROBOT_HEIGHT/2));

	// Initialize random seed
	srand (static_cast <unsigned> (time(0)));
}

int GameState::getGameState()
{
	return m_game_state;
}

void GameState::startPlaying()
{
	m_game_state = STATE_PLAYING;

	// Reset all values
	m_screws_collected = 0;
	setPlayerMovementDirection(DIRECTION_NONE);
	setPlayerLocation(sf::Vector2f(m_size_x/2-ROBOT_WIDTH/2,m_size_y/2-ROBOT_HEIGHT/2));
	m_screw_locations.clear();

}

void GameState::updateGameState()
{
	// Do nothing if the game is not in playing state
	if(m_game_state != STATE_PLAYING)
	{
		return;
	}

	// Return to menu state when losing the game
	if(getVisibleScrewsCount() >= 10)
	{
		m_game_state = STATE_MENU;
		return;
	}

	// Update the player location
	sf::Vector2f delta;

	switch(m_player_direction)
	{
		case DIRECTION_LEFT:
		delta = sf::Vector2f(-5,0);
		break;

		case DIRECTION_RIGHT:
		delta = sf::Vector2f(5,0);
		break;

		case DIRECTION_UP:
		delta = sf::Vector2f(0,-5);
		break;

		case DIRECTION_DOWN:
		delta = sf::Vector2f(0,5);
		break;

		default:
		delta = sf::Vector2f(0,0);
		break;
	}

	// Apply delta to the player position
	sf::Vector2f new_location(getPlayerLocation() + delta);

	// Check if new position is inside the game area
	if(new_location.x >= 0
		&& new_location.x + ROBOT_WIDTH <= m_size_x
		&& new_location.y >= 0
		&& new_location.y + ROBOT_HEIGHT <= m_size_y)
	{
		setPlayerLocation(new_location); // Update location
	}
	
	// Bounding box of the player
	sf::FloatRect player_box(getPlayerLocation(),sf::Vector2f(ROBOT_WIDTH,ROBOT_HEIGHT));

	std::vector<sf::Vector2f>::iterator s_it;
	s_it = m_screw_locations.begin();

	// Check for each screw location ...
	while(s_it != m_screw_locations.end())
	{
		// ... if the robot is "eating" the screw
		sf::FloatRect screw_box(*s_it,sf::Vector2f(SCREW_WIDTH,SCREW_HEIGHT));
		if(screw_box.intersects(player_box))
		{
			// Remove screw
			m_screw_locations.erase(s_it);
			m_screws_collected++;
		}
		else
		{
			// Advance iterator to next screw
			s_it++;
		}
	}

	// Add a new screw when threshold value is reached
	m_new_screw_threshold += static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	if(m_new_screw_threshold > SCREW_SPAWN_THRESHOLD)
	{
		m_new_screw_threshold = 0;

		// New random position for screw inside the game area
		float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(m_size_x-SCREW_WIDTH)));
		float y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(m_size_y-SCREW_HEIGHT)));
		m_screw_locations.push_back(sf::Vector2f(x,y));
	}
}

void GameState::setPlayerMovementDirection(int direction)
{
	m_player_direction = direction;
}

void GameState::setPlayerLocation(sf::Vector2f location)
{
	m_player_location = location;
}

sf::Vector2f GameState::getPlayerLocation()
{
	return m_player_location;
}

void GameState::addScrew(sf::Vector2f location)
{
	m_screw_locations.push_back(location);
}

std::vector<sf::Vector2f> GameState::getScrewLocations()
{
	return m_screw_locations;
}

int GameState::getVisibleScrewsCount()
{
	return m_screw_locations.size();
}

int GameState::getCollectedScrewsCount()
{
	return m_screws_collected;
}