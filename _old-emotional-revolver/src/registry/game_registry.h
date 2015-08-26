#ifndef GAME_REGISTRY_H
#define GAME_REGISTRY_H

// Forward declaration
class DrawHandler;
class EmotionHandler;
class EventHandler;
class LevelHandler;
class SoundHandler;
class TextureHandler;
class ViewHandler;
namespace sf
{
	class RenderWindow;
}

class GameRegistry
{
public:
	static GameRegistry* getInstance();
	void setHandler(DrawHandler* handler);
	void setHandler(EmotionHandler* handler);
	void setHandler(EventHandler* handler);
	void setHandler(LevelHandler* handler);
	void setHandler(SoundHandler* handler);
	void setHandler(TextureHandler* handler);
	void setHandler(ViewHandler* handler);
	void setWindow(sf::RenderWindow* window);
	DrawHandler* getDrawHandler();
	EmotionHandler* getEmotionHandler();
	EventHandler* getEventHandler();
	LevelHandler* getLevelHandler();
	SoundHandler* getSoundHandler();
	TextureHandler* getTextureHandler();
	ViewHandler* getViewHandler();
	sf::RenderWindow* getRenderWindow();
private:
	GameRegistry();
	DrawHandler* m_draw_handler;
	EmotionHandler* m_emotion_handler;
	EventHandler* m_event_handler;
	LevelHandler* m_level_handler;
	SoundHandler* m_sound_handler;
	TextureHandler* m_texture_handler;
	ViewHandler* m_view_handler;
	sf::RenderWindow* m_render_window;
};

#endif