#ifndef MOVE_HANDLER_H
#define MOVE_HANDLER_H

#include <SFML/Graphics.hpp>
#include "defines.h"
#include "game_state.h"

class MoveHandler
{
public:
	MoveHandler(GameState *state);
	void handleEvents();
private:
	GameState* m_gst;
	bool collisionWall(sf::Vector2f position,sf::FloatRect* box,Wall wall_it);
};

#endif
