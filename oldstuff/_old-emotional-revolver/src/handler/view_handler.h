#ifndef VIEW_HANDLER_H
#define VIEW_HANDLER_H

#include <SFML/Graphics.hpp>
#include "handler/level_handler.h"
#include "entity/unit_entity.h"
#include "registry/game_registry.h"

class ViewHandler
{
public:
	ViewHandler();
	void handleView();
private:
	LevelHandler *m_level_handler;
	sf::RenderWindow *m_window;
	sf::View m_view;
};

#endif