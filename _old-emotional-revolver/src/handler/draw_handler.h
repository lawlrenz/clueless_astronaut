#ifndef DRAW_HANDLER_H
#define DRAW_HANDLER_H

#include <SFML/Graphics.hpp>
#include "registry/game_registry.h"
#include "handler/level_handler.h"

class DrawHandler
{
public:
	DrawHandler();
	void draw();
private:
	LevelHandler *m_level_handler;
	sf::RenderWindow *m_window;
};

#endif
