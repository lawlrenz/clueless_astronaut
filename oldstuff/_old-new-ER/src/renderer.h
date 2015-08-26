#ifndef RENDERER_H
#define RENDERER_H

#define WINDOWSIZE_X 1200
#define WINDOWSIZE_Y 720

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "game_state.h"
//#include "bullet.h"

class Renderer
{
public:
	Renderer(sf::RenderWindow *window, GameState *state);
	void drawGame();
private:
	sf::RenderWindow *m_wnd;
	GameState *m_gst;
	sf::Texture m_texture_background;
	sf::Texture m_texture_wall;
	sf::Texture m_texture_player;
	sf::Texture m_texture_coin;
	sf::Texture m_texture_bullet;
	sf::Texture m_texture_spider;
	sf::Texture m_texture_life_EMPTY;
	sf::Texture m_texture_life_FULL;
	sf::Font m_normal_font;
	sf::Font m_bold_font;
};

#endif
