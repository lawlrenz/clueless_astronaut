#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SFML/Graphics.hpp>
#include "handler/level_handler.h"
#include "handler/sound_handler.h"
#include "handler/emotion_handler.h"
#include "entity/unit_entity.h"
#include "entity/projectile_entity.h"
#include "registry/game_registry.h"

class EventHandler
{
public:
	EventHandler();
	void handleEvents();
private:
	LevelHandler *m_level_handler;
	sf::RenderWindow *m_window;
	SoundHandler *m_sound_handler;
	EmotionHandler *m_emotion_handler;
};

#endif
