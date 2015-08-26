#include "sound_handler.h"
//Singleton Class


//constructor
SoundHandler::SoundHandler()
{
	bgVolume = 30;
	muted = 0;
	soundVolume = 100;
	loadBuffers();
	
}



sf::SoundBuffer gun;
sf::SoundBuffer gun_dry;
sf::SoundBuffer chambering;
								
SoundHandler* SoundHandler::s = NULL;

SoundHandler* SoundHandler::getSoundHandler()
{
	// if there is no SoundHandler build new one
	if(s == NULL)
	{
		s = new SoundHandler;
		
	}
	return s;
}



void SoundHandler::playSound(int soundNumber)
{
	if(!muted)
	{
		int pitch = 1;
		switch(soundNumber) {
			case (SHOOT):
				sound.setBuffer(gun);
				break;
			case (DRY_SHOOT):
				sound.setBuffer(gun_dry);
				break;
			case(CHAMBERING):
				sound.setBuffer(chambering);
				break;
		}

		sound.setVolume(soundVolume);
		sound.play();
	}
}


void SoundHandler::playBg()
{
	bgMusic.setBuffer(bgMusicBuff);
	bgMusic.play();
	bgMusic.setLoop(true);
	bgMusic.setVolume(bgVolume);
}



void SoundHandler::toggleMute()
{
	
	bgMusic.setVolume(muted * bgVolume); 
	muted ^= 1; //invertieren
}


void SoundHandler::setBgVolume(float volume)
{
	bgVolume = volume;
	bgMusic.setVolume(volume);
}


void SoundHandler::setSoundVolume(float volume)
{
	soundVolume = volume;
}

void SoundHandler::loadBuffers()
{
	bgMusicBuff.loadFromFile("sfx/bg/sound2.aif");
	gun.loadFromFile("sfx/sounds/GunFire.wav");
	gun_dry.loadFromFile("sfx/sounds/DryFire.wav");
	chambering.loadFromFile("sfx/sounds/Chambering.wav");
}
