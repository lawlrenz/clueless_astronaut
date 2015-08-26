#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "game_state.h"

class Renderer
{
public:
	Renderer(sf::RenderWindow *window, GameState *state);
	void drawGame();
private:
	sf::RenderWindow *m_wnd;
	GameState *m_gst;
	sf::Texture m_texture_background;
	sf::Texture m_texture_player;
	sf::Texture m_texture_screws;
	sf::Font m_normal_font;
	sf::Font m_bold_font;
};

#endif