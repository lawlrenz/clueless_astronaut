#include "game_registry.h"

GameRegistry::GameRegistry()
{
}

GameRegistry* GameRegistry::getInstance()
{
	static GameRegistry instance;
	return &instance;
}

void GameRegistry::setHandler(DrawHandler* handler)
{
	m_draw_handler = handler;
}

void GameRegistry::setHandler(EmotionHandler* handler)
{
	m_emotion_handler = handler;
}

void GameRegistry::setHandler(EventHandler* handler)
{
	m_event_handler = handler;
}

void GameRegistry::setHandler(LevelHandler* handler)
{
	m_level_handler = handler;
}

void GameRegistry::setHandler(SoundHandler* handler)
{
	m_sound_handler = handler;
}

void GameRegistry::setHandler(TextureHandler* handler)
{
	m_texture_handler = handler;
}

void GameRegistry::setHandler(ViewHandler* handler)
{
	m_view_handler = handler;
}

void GameRegistry::setWindow(sf::RenderWindow* window)
{
	m_render_window = window;
}

DrawHandler* GameRegistry::getDrawHandler()
{
	return m_draw_handler;
}

EmotionHandler* GameRegistry::getEmotionHandler()
{
	return m_emotion_handler;
}

EventHandler* GameRegistry::getEventHandler()
{
	return m_event_handler;
}

LevelHandler* GameRegistry::getLevelHandler()
{
	return m_level_handler;
}

SoundHandler* GameRegistry::getSoundHandler()
{
	return m_sound_handler;
}

TextureHandler* GameRegistry::getTextureHandler()
{
	return m_texture_handler;
}

ViewHandler* GameRegistry::getViewHandler()
{
	return m_view_handler;
}

sf::RenderWindow* GameRegistry::getRenderWindow()
{
	return m_render_window;
}