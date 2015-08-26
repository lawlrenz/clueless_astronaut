#include "event_handler.h"

EventHandler::EventHandler(sf::RenderWindow *window, GameState *state)
{
	m_wnd = window;
	m_gst = state;
	s = SoundHandler::getSoundHandler();
	hero = state->getHero();
}


void EventHandler::handleEvents()
{
	sf::Event event;
	
    while (m_wnd->pollEvent(event))
    {
        // Close window : exit
        if (event.type == sf::Event::Closed ||event.key.code == sf::Keyboard::Escape)
        {
            m_wnd->close();
        }


        if (m_gst->getGameState() == STATE_MENU || m_gst->getGameState() == STATE_PAUSE || m_gst->getGameState() == STATE_CONTROLS)
        {
        	// Start/continue playing when SPACE is pressed
        	if(event.key.code == sf::Keyboard::Space)
        	{
        		m_gst->setGameState(STATE_PLAYING);
        	}
        	//show control when C is pressed
        	else if(event.key.code == sf::Keyboard::C)
        	{
        		m_gst->setGameState(STATE_CONTROLS);
        	}
        }
        // restart Game when R is pressed or when game is lost and SPACE is pressed
        else if(event.key.code == sf::Keyboard::R || (m_gst->getGameState() == STATE_LOST && event.key.code == sf::Keyboard::Space))
        {
			m_gst->restartGame();
        }
        // pause game when P is pressed
        else if(m_gst->getGameState() == STATE_PLAYING)
        {
        	if(event.key.code == sf::Keyboard::P)
        	{
        		m_gst->setGameState(STATE_PAUSE);
        	}	
        }
		
        // Get robot direction
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
        	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        		hero->setMovementDirection(DIRECTION_LEFT_UP);
        	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        		hero->setMovementDirection(DIRECTION_LEFT_DOWN);
        	else
        		hero->setMovementDirection(DIRECTION_LEFT);
        //	hero->setOrientation(DIRECTION_LEFT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
        	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        		hero->setMovementDirection(DIRECTION_RIGHT_UP);
        	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        		hero->setMovementDirection(DIRECTION_RIGHT_DOWN);
        	else
        		hero->setMovementDirection(DIRECTION_RIGHT);
        //	hero->setOrientation(DIRECTION_RIGHT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
        	hero->setMovementDirection(DIRECTION_UP);
        //	hero->setOrientation(DIRECTION_UP);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
        	hero->setMovementDirection(DIRECTION_DOWN);
        //	hero->setOrientation(DIRECTION_DOWN);
        }
        else
        {
        	hero->setMovementDirection(DIRECTION_NONE);
        } //*/
        
        if(event.type == sf::Event::KeyPressed)
		{
			switch(event.key.code)
			{
				case sf::Keyboard::M:
					s->toggleMute();
					break;
				case sf::Keyboard::Space:
					
					hero->startShooting();
					break;
				case sf::Keyboard::A:
					hero->setOrientation(DIRECTION_LEFT);
					break;
				case sf::Keyboard::D:
					hero->setOrientation(DIRECTION_RIGHT);
					break;
				case sf::Keyboard::W:
					hero->setOrientation(DIRECTION_UP);
					break;
				case sf::Keyboard::S:
					hero->setOrientation(DIRECTION_DOWN);
					break;
			}
		}
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			hero->stopShooting();
			
    }
}
