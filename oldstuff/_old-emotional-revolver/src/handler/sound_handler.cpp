#include "sound_handler.h"
#include <stdio.h>

SoundHandler::SoundHandler(std::string file)
{

	// Planned: Load sound definitions from file

    m_window = GameRegistry::getInstance()->getRenderWindow();

	// Load jump sound
	if (!m_jump.loadFromFile("assets/sounds/jump.ogg"))
	{
		m_window->close();
	}
	m_jump_sound.setBuffer(m_jump);

	// Load landing sound
	if (!m_land.loadFromFile("assets/sounds/land.ogg"))
	{
		m_window->close();
	}
	m_land_sound.setBuffer(m_land);

	// Load gunshot sound
	if (!m_gunshot.loadFromFile("assets/sounds/gunshot.ogg"))
	{
		m_window->close();
	}
	m_gunshot_sound.setBuffer(m_gunshot);

	// Load music
	if (!m_background.openFromFile("assets/music/level2.ogg"))
	{
		m_window->close();
	}
}

/*
void SoundHandler::LoadLevelByID(int LevelID)
{
	m_LevelID = LevelID;
	bufferstream << m_LevelID;

	// LADE GUNSHOT, LEERE SS
	ss << "./assets/music/gunshot_level_" << bufferstream.str() << ".ogg";
	if (!gunshot.loadFromFile(ss.str()))
		m_window->close();
	gunshot_sound.setBuffer(gunshot);
	ss.str("");

	// LADE BACKGROUND
	ss << "./assets/music/level" << bufferstream.str() <<"_alt.ogg";
	if (!background.openFromFile(ss.str()))
		m_window->close();
}
*/

void SoundHandler::StartBackgroundMusic()
{
	m_background.setVolume(50);
	m_background.setLoop(true);
	m_background.play();
}

void SoundHandler::Gunshot()
{
	m_gunshot_sound.play();
}

void SoundHandler::Jump()
{
	m_jump_sound.play();
}

void SoundHandler::Land()
{
	m_land_sound.play();
}
