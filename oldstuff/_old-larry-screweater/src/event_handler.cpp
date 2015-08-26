#include "event_handler.h"

EventHandler::EventHandler(sf::RenderWindow *window, GameState *state)
{
	m_wnd = window;
	m_gst = state;
}

void EventHandler::handleEvents()
{
	sf::Event event;
    while (m_wnd->pollEvent(event))
    {
        // Close window : exit
        if (event.type == sf::Event::Closed)
        {
            m_wnd->close();
        }

        // Start playing when SPACE is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_gst->getGameState() == STATE_MENU)
        {
        	m_gst->startPlaying();
        }

        // Get robot direction
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_LEFT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_RIGHT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_UP);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_DOWN);
        }
        else
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_NONE);
        }
    }
}