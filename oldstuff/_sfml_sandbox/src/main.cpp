#include <SFML/Graphics.hpp>
#include <iostream>

sf::Vector2f playerPosition;
sf::Texture playerTexture;
sf::Sprite playerSprite;
sf::Event event;


int main()
{

    int size_x = 1280;
    int size_y = 800;

    sf::RenderWindow app(sf::VideoMode(size_x, size_y), "SFML Game");
    sf::Time updateRate = sf::seconds(1.0f / 60.0f);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;


    if (!playerTexture.loadFromFile("assets/pacman_right.png"))
    {
      app.close();
    }
    playerSprite.setTexture(playerTexture);
    playerPosition = sf::Vector2f(200,200);
    while (app.isOpen())
    {
        app.clear();
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;

        while (timeSinceLastUpdate > updateRate)
        {
            timeSinceLastUpdate -= updateRate;
            playerSprite.setPosition(playerPosition);
            app.draw(playerSprite);
        }

        while (app.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
          {
              app.close();
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          {
            if (!playerTexture.loadFromFile("assets/pacman_left.png"))
            {
              app.close();
            }
            playerPosition += sf::Vector2f(-3,0);
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
            if (!playerTexture.loadFromFile("assets/pacman_right.png"))
            {
              app.close();
            }
            playerPosition += sf::Vector2f(3,0);
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
              {
                if (!playerTexture.loadFromFile("assets/pacman_up.png"))
                {
                  app.close();
                }
                 playerPosition += sf::Vector2f(0,-3);
              }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          {
            if (!playerTexture.loadFromFile("assets/pacman_down.png"))
            {
              app.close();
            }
                 playerPosition += sf::Vector2f(0,3);
              }
          playerSprite.setTexture(playerTexture);


        }


        app.display();

    }

    return EXIT_SUCCESS;
}
