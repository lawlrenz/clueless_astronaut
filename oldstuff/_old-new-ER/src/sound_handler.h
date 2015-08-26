#ifndef SOUND_HANDLER_H
#define SOUND_HANDLER_H

#include <SFML/Audio.hpp>
#include "defines.h"
#include <iostream>
#include <string>
#include <list>


class SoundHandler
{
public:
	//getter Methode der Singleton Class
	static SoundHandler* getSoundHandler();
	
	//Sound abspielen
	void playSound(int soundNumber);
	
	//spielt die Hintergrundmusik
	void playBg();
	
	//schaltet mute an/aus
	void toggleMute();
	
	//Lautstaerke der Hintergrundmusik setzen
	void setBgVolume(float volume);
	
	//Standart-autstaerke aller Sounds setzen
	void setSoundVolume(float volume);
protected:
	//constructor only for class
	SoundHandler();	

	
private:
	//pointer to SoundHandler object
	static SoundHandler* s;

	//init Sound Buffers
	void loadBuffers();
	
	//object for playing background music
	sf::Sound bgMusic;
	
	//object for playing sounds
	sf::Sound sound;
	
	//Volume
	float bgVolume;
	float soundVolume;
	
	int muted;
	
	//Buffers
	sf::SoundBuffer bgMusicBuff;
	sf::SoundBuffer gun;
	sf::SoundBuffer gun_dry;
	sf::SoundBuffer chambering;
	
	
	
};

#endif
