#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SFML/Graphics.hpp>
#include "game_state.h"

class EventHandler
{
public:
	EventHandler(sf::RenderWindow *window, GameState *state);
	void handleEvents();
private:
	sf::RenderWindow *m_wnd;
	GameState *m_gst;
};

#endif