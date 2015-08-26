#include "gui.h"

GUI::GUI()
{
	lifebar = sf::RectangleShape(sf::Vector2f(100, 16));
	lifebar.setPosition(sf::Vector2f(32, 32));
	lifebar.setFillColor(sf::Color::Red);

	lifebar_outline = sf::RectangleShape(sf::Vector2f(100, 16));
	lifebar_outline.setPosition(sf::Vector2f(32, 32));
	lifebar_outline.setFillColor(sf::Color::Transparent);
	lifebar_outline.setOutlineColor(sf::Color::White);
	lifebar_outline.setOutlineThickness(1);

	// FONTS
	if (!font.loadFromFile("./assets/Sisperdotze-Regular.ttf"))
	{
   	    
	}
}

void GUI::draw()
{
	LevelHandler* level_handler = GameRegistry::getInstance()->getLevelHandler();
	sf::RenderWindow* window = GameRegistry::getInstance()->getRenderWindow();

	// Reset view before drawing GUI
	window->setView(window->getDefaultView());

	
	if(level_handler->getPlayerEntity()->isAlive())
	{
		// Draw lifebar
		lifebar.setSize(sf::Vector2f(level_handler->getPlayerEntity()->getHealth(), 16));
		window->draw(lifebar);
		window->draw(lifebar_outline);
	}
	else
	{
		// Game over
    	sf::Text text;
    	text.setFont(font);
    	text.setColor(sf::Color::Red);
    	text.setString("Game Over");
    	text.setCharacterSize(40);
    	text.setPosition(200, 200);
    	text.setStyle(sf::Text::Bold);
    	window->draw(text);
	}


}