#include <SFML/Graphics.hpp>
#include <iostream>
#include "event_handler.h"
#include "game_state.h"
#include "renderer.h"
#include "sound_handler.h"
#include "move_handler.h"

int main()
{

    // Size of the game window and the game area
    int size_x = WINDOWSIZE_X;
    int size_y = WINDOWSIZE_Y;

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(size_x, size_y), "Emotional Revolver");

    // Update rate
    sf::Time updateRate = sf::seconds(1.0f / 60.0f);

    // Clock used in restricting Update loop to a fixed rate
    sf::Clock clock;

    // Time since last update
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // Game state
    GameState gameState(size_x, size_y);

    // Event handler
    EventHandler eventHandler(&app,&gameState);

	//Sound Handler
	SoundHandler* soundHandler = SoundHandler::getSoundHandler();
    
    //Move Handler
    MoveHandler moveHandler(&gameState);
    
    // Renderer
    Renderer renderer(&app,&gameState);
    
    //Start sound
    soundHandler->playBg();

	// Start the game loop
    while (app.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
		//std::cout<<"time: " << timeSinceLastUpdate << "\n";
        while (timeSinceLastUpdate > updateRate)
        {
        	//std::cout<<"time \n";
            timeSinceLastUpdate -= updateRate;
          	// std::cout<<"event \n";
            eventHandler.handleEvents();
            //std::cout<<"gamestate \n";
            gameState.updateGameState(); // updated entitys
            //std::cout<<"move \n";
            moveHandler.handleEvents();
            
            renderer.drawGame();
        }

       // renderer.drawGame();
    }

    return EXIT_SUCCESS;
}
