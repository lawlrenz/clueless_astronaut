#include <SFML/Graphics.hpp>
#include <iostream>

#include "entity/base_entity.h"
#include "entity/tile_entity.h"

#include "registry/game_registry.h"

#include "handler/level_handler.h"
#include "handler/event_handler.h"
#include "handler/view_handler.h"
#include "handler/emotion_handler.h"
#include "handler/sound_handler.h"

#include "loader/loader.h"

#include "gui/gui.h"

#include <SFML/Audio.hpp>

int main()
{

    // Initialize random seed
    srand (static_cast <unsigned> (time(0)));

    // Get game registry instance
    GameRegistry* registry = GameRegistry::getInstance();

    // Size of the game window and the game area
    int size_x = 720;
    int size_y = 400;

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(size_x, size_y), "SFML Game");
    registry->setWindow(&app);

/*

    // TITLE SCREEEEEEEEN
        // TEXTURES
    sf::Vector2f wolke1_pos = sf::Vector2f(100,200);
    sf::Vector2f wolke2_pos = sf::Vector2f(300,100);
    sf::Vector2f wolke3_pos = sf::Vector2f(600,300);
    sf::Vector2f wolke4_pos = sf::Vector2f(700,310);
    sf::Vector2f wolke5_pos = sf::Vector2f(500,250);
    sf::Texture background_texture;
    	if (!background_texture.loadFromFile("./assets/title/title_screen.png"))
    	{
    		app.close();
    	}

    sf::Texture wolke1_texture;
    	if (!wolke1_texture.loadFromFile("./assets/title/cloud1.png"))
    	{
    		app.close();
    	}

    sf::Texture wolke2_texture;
    	if (!wolke2_texture.loadFromFile("./assets/title/cloud2.png"))
    	{
    		app.close();
    	}

    sf::Texture wolke3_texture;
    	if (!wolke3_texture.loadFromFile("./assets/title/cloud3.png"))
    	{
    		app.close();
    	}

    sf::Texture wolke4_texture;
    	if (!wolke4_texture.loadFromFile("./assets/title/cloud3.png"))
    	{
    		app.close();
    	}

    sf::Texture wolke5_texture;
    	if (!wolke5_texture.loadFromFile("./assets/title/cloud1.png"))
    	{
    		app.close();
    	}

    sf::Texture guy_texture;
    	if (!guy_texture.loadFromFile("./assets/title/title_lying.png"))
    	{
    		app.close();
    	}

    // SPRITES
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    background_sprite.setTextureRect(sf::IntRect(0, 0, size_x, size_y));

    sf::Sprite guy_sprite;
    guy_sprite.setTexture(guy_texture);
    guy_sprite.setPosition(150, 200);

    sf::Sprite wolke1_sprite;
    wolke1_sprite.setTexture(wolke1_texture);
    wolke1_sprite.setColor(sf::Color(255,255,255,160));
    sf::Sprite wolke2_sprite;
    wolke2_sprite.setTexture(wolke2_texture);
    wolke2_sprite.setColor(sf::Color(255,255,255,160));
    sf::Sprite wolke3_sprite;
    wolke3_sprite.setTexture(wolke3_texture);
    wolke3_sprite.setColor(sf::Color(255,255,255,160));
    sf::Sprite wolke4_sprite;
    wolke4_sprite.setTexture(wolke4_texture);
    wolke4_sprite.setColor(sf::Color(255,255,255,160));
    sf::Sprite wolke5_sprite;
    wolke5_sprite.setTexture(wolke5_texture);
    wolke5_sprite.setColor(sf::Color(255,255,255,160));

    // FONTS
    sf::Font title_screen_text_font;
	if (!title_screen_text_font.loadFromFile("./assets/Sisperdotze-Regular.ttf"))
	{
   	    app.close();
	}

    // TEXT
    sf::Text title_screen_text;
    title_screen_text.setFont(title_screen_text_font);
    title_screen_text.setColor(sf::Color::Red);
    title_screen_text.setString("Emotional \nRevolver");
    title_screen_text.setCharacterSize(20);
    title_screen_text.setPosition(230, 90);
    title_screen_text.setStyle(sf::Text::Bold);

    sf::Text title_screen_PLAY;
    title_screen_PLAY.setFont(title_screen_text_font);
    title_screen_PLAY.setColor(sf::Color::Red);
    title_screen_PLAY.setCharacterSize(36);
    title_screen_PLAY.setString("Press SPACE");
    title_screen_PLAY.setPosition(300, 230);
    title_screen_PLAY.setStyle(sf::Text::Bold);

    sf::Text title_screen_tut;
    title_screen_tut.setFont(title_screen_text_font);
    title_screen_tut.setColor(sf::Color::Red);
    title_screen_tut.setCharacterSize(18);
    title_screen_tut.setString("A fucking text \n that explains \n  the game");
    title_screen_tut.setPosition(370, 300);
    title_screen_tut.setStyle(sf::Text::Bold);


    // TITLE SCREEEEEN ENDE

    app.clear();
    app.draw(background_sprite);
	app.draw(guy_sprite);
	app.draw(title_screen_text);
	app.draw(title_screen_PLAY);
	app.draw(title_screen_tut);
	app.draw(wolke1_sprite);
 	app.draw(wolke2_sprite);
	app.draw(wolke3_sprite);
 	app.draw(wolke4_sprite);
	app.draw(wolke5_sprite);
	app.display();

    bool leertastePressed = false;
    // WHILE NOT LEER TASTE
    while(!leertastePressed){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		leertastePressed=true;
    }

*/

    // Load test level
    Loader loader;
    loader.loadTestLevel();

    // GUI
    GUI gui;

    // Start music
    //GameRegistry::getInstance()->getSoundHandler()->StartBackgroundMusic();


    // Update rate
    sf::Time updateRate = sf::seconds(1.0f / 60.0f);

    // Clock used in restricting Update loop to a fixed rate
    sf::Clock clock;

    // Time since last update
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // Clock to monitor how long the update loop takes
    sf::Clock update_loop_time;

    // FPS calculation
    sf::Clock fps_clock;
    float fps_avg = 0;

    // Start the game loop
    while (app.isOpen())
    {

        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;

        // Update the game state
        while (timeSinceLastUpdate > updateRate)
        {
            //update_loop_time.restart();

            // Process input
            registry->getEventHandler()->handleEvents();
            if(registry->getLevelHandler()->getPlayerEntity()->isAlive())
            {
                // Movement, collisions, ...
                registry->getLevelHandler()->update();
                // Gun emotion
                registry->getEmotionHandler()->emotionUpdate();

                //sf::Vector2u loc = registry->getLevelHandler()->getPlayerEntity()->getGridLocation();
                //std::cout << loc.x << " " << loc.y << std::endl;
            }

            timeSinceLastUpdate -= updateRate;
            //std::cout << "Update loop took " << update_loop_time.getElapsedTime().asSeconds() << std::endl;
            //std::cout << "Running at " << fps_avg << " FPS" << std::endl;
        }
        // Adjust the view location
        registry->getViewHandler()->handleView();

        app.clear();

        registry->getDrawHandler()->draw();

        gui.draw();

        app.display();

        //float currentTime = fps_clock.restart().asSeconds();
        //float fps = 1.f / currentTime;
        //fps_avg = 0.99 * fps_avg + 0.01 * fps;
    }

    return EXIT_SUCCESS;
}
