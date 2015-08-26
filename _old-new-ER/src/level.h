#ifndef LEVEL_H
#define LEVEL_H

#include "defines.h"
#include <iostream>
#include <string>
#include <list>
#include "wall.h"
#include "entity.h"
#include "bullet.h"
#include "spider.h"
#include <SFML/Graphics.hpp>
#include <fstream>

class Level
{
public:
	//constructors
	Level();
	Level(std::string levelPath);
	
	//
	sf::Vector2f getBounds();
	
	//Walls
	std::list <Wall>* getWalls();
	
	//Bullets
	std::vector <Bullet>* getBullets();
	
	//Coins
	std::vector<sf::Vector2f>* getCoins();
	
	//Spiders
	std::vector<Spider>* getSpiders();
	
	// initial player position
	sf::Vector2f getPlayerStart();
	
	// move/erase entitys in Entity list & spawn coins
	void updateEntitys();
private:
	//
	sf::Vector2f levelBounds;
	
	//entitys
	std::vector<Bullet> bullets;
	
	//spiders
	std::vector<Spider> spiders;
	float m_new_spider_threshold;
	float spiderSpawnRate;
	
	//coins
	std::vector<sf::Vector2f> coins;
	float m_new_coin_threshold;
	float coinSpawnRate;
	
	//walls
	std::list<Wall> walls;
	
	// first char of levelpath
	char* beginLevelPath;
	
	// init level
	void initLevel();
	
	//position where player starts
	sf::Vector2f playerStart;
	
};

#endif
