#ifndef PLAYER_H
#define PLAYER_H

#include "defines.h"
#include "entity.h"
#include "level.h"
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "sound_handler.h"

class Player:Entity
{
public:
	Player();
	Player(Level* lev);
	void move();
//	void addMoveVector(sf::Vector2f move);
	sf::Vector2f getPosition();
	void setMovementDirection(int direction);
	int getCollectedCoins();
	int getOrientation();
	void setOrientation(int newOrientation);
	void shoot();
	//start/stop shooting // setzt shooting
	void startShooting();
	void stopShooting();
	
	//prüft ob player lebt und gibt lebenspunkte zurück
	float checkLife();
	void reset(Level* level);
	
private:
	sf::Vector2f position;
	void initPlayer();
	sf::Vector2f moveVector;
	Level* level;
	int collectedCoins;
	
	int orientation;
	void onDeath();
	
	//soundhandler
	SoundHandler* s;
	
	//space gedrückt?
	bool shooting;
	//bestimmt wie lange hero noch bis zum nächsten schuss warten muss
	float shoot_threshold;
	//bestimmt wie lange die pause zwischen schüssen ist
	float reload_time;

};

#endif
