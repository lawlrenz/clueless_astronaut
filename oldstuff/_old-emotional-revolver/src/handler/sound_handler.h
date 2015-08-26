#ifndef SOUND_HANDLER_H
#define SOUND_HANDLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "registry/game_registry.h"

class SoundHandler
{
public:
	SoundHandler(std::string file);
	//void LoadLevelByID(int LevelID);
	void Gunshot();
	void StartBackgroundMusic();
	void Jump();
	void Land();
private:
	sf::RenderWindow *m_window;
	sf::SoundBuffer m_gunshot;
	sf::Sound m_gunshot_sound;
	sf::SoundBuffer m_jump;
	sf::Sound m_jump_sound;
	sf::SoundBuffer m_land;
	sf::Sound m_land_sound;
	sf::Music m_background;
};

#endif
