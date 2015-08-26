#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "level.h"
#include "player.h"

#define STATE_MENU 0
#define STATE_CONTROLS 1
#define STATE_PLAYING 2
#define STATE_PAUSE 3
#define STATE_LOST 4

#define SCREW_SPAWN_THRESHOLD 30

class GameState
{
public:
	GameState();
	GameState(int x, int y);
	int getGameState();
	void restartGame();
	void updateGameState();
	
	//movement direction
//	void setPlayerMovementDirection(int direction);
//	int getPlayerMovementDirection();
	
	//playerLocation
	sf::Vector2f getPlayerLocation();
//	void setPlayerLocation(sf::Vector2f location);
	
	//screws
	void addScrew(sf::Vector2f location);
	std::vector<sf::Vector2f>* getScrewLocations();
	int getVisibleScrewsCount();
	int getCollectedScrewsCount();
	void collectedScrew();
	
	//change gameState
	void setGameState(int state);
	
	//level
	Level* getLevel();
	
	//player
	Player* getHero();

private:
	int m_game_state;
	int m_size_x;
	int m_size_y;

	std::vector<sf::Vector2f> m_screw_locations;
	float m_new_screw_threshold;
	int m_screws_collected;
	Level* level;
	Player* hero;
};

#endif
