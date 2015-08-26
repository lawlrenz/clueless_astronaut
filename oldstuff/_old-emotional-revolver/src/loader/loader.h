#ifndef LOADER_H
#define LOADER_H

#include <SFML/Graphics.hpp>
#include "registry/game_registry.h"
#include "handler/event_handler.h"
#include "handler/emotion_handler.h"
#include "handler/sound_handler.h"
#include "handler/texture_handler.h"
#include "handler/view_handler.h"
#include "handler/draw_handler.h"

class Loader
{
public:
	Loader();
	void loadTestLevel();
private:
	
};

#endif