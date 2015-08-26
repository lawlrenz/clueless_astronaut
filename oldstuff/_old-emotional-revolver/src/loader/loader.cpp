#include "loader.h"

Loader::Loader()
{

}

void Loader::loadTestLevel()
{
	GameRegistry* registry = GameRegistry::getInstance();

	// Create and register all handlers
	TextureHandler* texture_handler = new TextureHandler();
	texture_handler->loadTextureAndDefinitions("tileset","assets/tiles_level1.png","assets/tiles_level1.txt");
	registry->setHandler(texture_handler);

	LevelHandler* level_handler = new LevelHandler("assets/level1_map.txt");
	registry->setHandler(level_handler);

	SoundHandler* sound_handler = new SoundHandler("dummy.replaceme");
	registry->setHandler(sound_handler);

	EmotionHandler* emotion_handler = new EmotionHandler();
	registry->setHandler(emotion_handler);

	EventHandler* event_handler = new EventHandler();
	registry->setHandler(event_handler);

	ViewHandler* view_handler = new ViewHandler();
	registry->setHandler(view_handler);

	DrawHandler* draw_handler = new DrawHandler();
	registry->setHandler(draw_handler);
}