#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SFML/Graphics.hpp>
#include <vector>

#define STATE_MENU 0
#define STATE_PLAYING 1

#define DIRECTION_NONE 0
#define DIRECTION_LEFT 1
#define DIRECTION_RIGHT 2
#define DIRECTION_UP 3
#define DIRECTION_DOWN 4

#define ROBOT_WIDTH 80
#define ROBOT_HEIGHT 80
#define SCREW_WIDTH 96
#define SCREW_HEIGHT 56

#define SCREW_SPAWN_THRESHOLD 30

class GameState
{
public:
	GameState(int x, int y);
	int getGameState();
	void startPlaying();
	void updateGameState();
	void setPlayerMovementDirection(int direction);
	void setPlayerLocation(sf::Vector2f location);
	sf::Vector2f getPlayerLocation();
	void addScrew(sf::Vector2f location);
	std::vector<sf::Vector2f> getScrewLocations();
	int getVisibleScrewsCount();
	int getCollectedScrewsCount();
private:
	int m_game_state;
	int m_size_x;
	int m_size_y;
	int m_player_direction;
	sf::Vector2f m_player_location;
	std::vector<sf::Vector2f> m_screw_locations;
	float m_new_screw_threshold;
	int m_screws_collected;
};

#endif