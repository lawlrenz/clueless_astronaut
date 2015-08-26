#include <SFML/Graphics.hpp>
#include <iostream>
#include "event_handler.h"
#include "game_state.h"
#include "renderer.h"

int main()
{

    // Size of the game window and the game area
    int size_x = 1280;
    int size_y = 800;

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(size_x, size_y), "SFML Game");

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

    // Renderer
    Renderer renderer(&app,&gameState);

	// Start the game loop
    while (app.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;

        while (timeSinceLastUpdate > updateRate)
        {
            timeSinceLastUpdate -= updateRate;
            eventHandler.handleEvents();
            gameState.updateGameState();
        }

        renderer.drawGame();
    }

    return EXIT_SUCCESS;
}
