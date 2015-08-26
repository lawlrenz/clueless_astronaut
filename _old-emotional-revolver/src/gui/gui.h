#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "registry/game_registry.h"
#include "handler/level_handler.h"

class GUI
{
public:
	GUI();
	void draw();
private:
	sf::RectangleShape lifebar;
	sf::RectangleShape lifebar_outline;
	sf::Font font;
};

#endif
