#include "event_handler.h"

EventHandler::EventHandler()
{
    GameRegistry* registry = GameRegistry::getInstance();
    m_window = registry->getRenderWindow();
	m_level_handler = registry->getLevelHandler();
	m_sound_handler = registry->getSoundHandler();
	m_emotion_handler = registry->getEmotionHandler();

    // No repeated key events
    m_window->setKeyRepeatEnabled(false);
}

void EventHandler::handleEvents()
{
    UnitEntity *player = m_level_handler->getPlayerEntity();

	sf::Event event;
    while (m_window->pollEvent(event))
    {
        // Close window : exit
        if(event.type == sf::Event::Closed)
        {
            m_window->close();
        }
        else if(event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Left)
            {
                player->setMovementDirection(DIRECTION_LEFT);
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                player->setMovementDirection(DIRECTION_RIGHT);
            }
            else if (event.key.code == sf::Keyboard::Space && player->isAbleToJump())
            {
                player->doJump();
                m_sound_handler->Jump();
            }
            else if (event.key.code == sf::Keyboard::LShift)
            {
                Direction dir = player->getMovementDirection();
                ProjectileEntity *prj = player->doShoot();
                if(prj != NULL)
                {
                    m_level_handler->addProjectile(prj);
                    m_sound_handler->Gunshot();
                    m_emotion_handler->alterEmotion(0.0,-5.0);
                }
            }

        }
        else if(event.type == sf::Event::KeyReleased)
        {
            if ((event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
                && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                player->setMovementDirection(DIRECTION_NONE);
            }
        }
    }

    /*

    Complete 8 direction movement

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player->setMovementDirection(DIRECTION_UPLEFT);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player->setMovementDirection(DIRECTION_UPRIGHT);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        player->setMovementDirection(DIRECTION_DOWNLEFT);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        player->setMovementDirection(DIRECTION_DOWNRIGHT);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player->setMovementDirection(DIRECTION_LEFT);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->setMovementDirection(DIRECTION_RIGHT);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player->setMovementDirection(DIRECTION_UP);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        player->setMovementDirection(DIRECTION_DOWN);
    }
    else
    {
        player->setMovementDirection(DIRECTION_NONE);
    }
    */


}
