#include "renderer.h"

Renderer::Renderer(sf::RenderWindow *window, GameState *state)
{
	m_wnd = window;
	m_gst = state;

	// Load all the textures
	if (!m_texture_background.loadFromFile("assets/bg1.jpg"))
	{
    	m_wnd->close();
    }
    m_texture_background.setRepeated(true);

    if (!m_texture_player.loadFromFile("assets/hero-64x64/hero.png"))
	{
    	m_wnd->close();
    }

    if (!m_texture_coin.loadFromFile("assets/Qoin_klein.png"))
	{
    	m_wnd->close();
    }
    if (!m_texture_bullet.loadFromFile("assets/Muni/Muni-Normal.png"))
	{
    	m_wnd->close();
    }
	if (!m_texture_wall.loadFromFile("assets/wall.png"))
	{
    	m_wnd->close();
    }
    m_texture_wall.setRepeated(true);
    if (!m_texture_spider.loadFromFile("assets/entitys-64x64/Spinne1.png"))
	{
    	m_wnd->close();
    } 
    // Load all the fonts
    if (!m_normal_font.loadFromFile("assets/Roboto-Regular.ttf"))
    {
    	m_wnd->close();
    }

	//Load life texture
	if (!m_texture_life_EMPTY.loadFromFile("assets/Herz_leer.png")) {m_wnd->close();}
//    if (!m_texture_life_HALF.loadFromFile("assets/Herz_halb.png")) {m_wnd->close();}
    if (!m_texture_life_FULL.loadFromFile("assets/Herz_voll.png")) {m_wnd->close();}
	
    if (!m_bold_font.loadFromFile("assets/Roboto-Bold.ttf"))
    {
    	m_wnd->close();
    }
	
}

void Renderer::drawGame()
{
	//
	m_wnd->clear();
	
	//view follows the player //TODO view an playergroesse anpassen
	sf::View view(m_gst->getPlayerLocation(), sf::Vector2f(WINDOWSIZE_X,WINDOWSIZE_Y));
    m_wnd->setView(view);
	
	//draw background
	sf::Sprite sprite_background_wall;
	sprite_background_wall.setTexture(m_texture_wall);
	sprite_background_wall.setTextureRect(sf::IntRect(0,0,m_gst->getLevel()->getBounds().x*2*ROBOT_WIDTH,-m_gst->getLevel()->getBounds().y*2*ROBOT_HEIGHT));
	sprite_background_wall.setPosition(-WINDOWSIZE_X/2-1,-WINDOWSIZE_Y/2);
	m_wnd->draw(sprite_background_wall);
	
	
	//draw arena background
    sf::Sprite sprite_background;
	sprite_background.setTexture(m_texture_background);
	sprite_background.setTextureRect(sf::IntRect(0,0,m_gst->getLevel()->getBounds().x*ROBOT_WIDTH,m_gst->getLevel()->getBounds().y*ROBOT_HEIGHT));
	m_wnd->draw(sprite_background);

	
	//draw walls
	sf::Sprite sprite_wall;
	sprite_wall.setTexture(m_texture_wall);
	
	for (std::list<Wall>::iterator it = m_gst->getLevel()->getWalls()->begin(); it != m_gst->getLevel()->getWalls()->end(); it++)
   	{
   		
		sprite_wall.setTextureRect(sf::IntRect(0,0,ROBOT_WIDTH,ROBOT_HEIGHT));
		sprite_wall.setPosition(it->getPosition().x,it->getPosition().y);
		m_wnd->draw(sprite_wall);
   	}  //*/
	
	//draw spiders
	sf::Sprite sprite_spider;
	sprite_spider.setTexture(m_texture_spider);
	
	for (std::vector<Spider>::iterator spider_it = m_gst->getLevel()->getSpiders()->begin(); spider_it != m_gst->getLevel()->getSpiders()->end(); spider_it++)
   	{
   		
		sprite_spider.setTextureRect(sf::IntRect(0,0,SPIDER_WIDTH,SPIDER_HEIGHT));
		sprite_spider.setPosition(spider_it->getPosition().x,spider_it->getPosition().y);
		m_wnd->draw(sprite_spider);
   	}
	
	//draw player
    sf::Sprite sprite_player;
	sprite_player.setTexture(m_texture_player);
	sprite_player.setPosition(m_gst->getPlayerLocation());
	//draw orientation
	switch(m_gst->getHero()->getOrientation())
	{
		case DIRECTION_LEFT:
			sprite_player.setTextureRect(sf::IntRect(64,64,64,64));
			break;
		case DIRECTION_RIGHT:
			sprite_player.setTextureRect(sf::IntRect(0,64,64,64));
			break;
		case DIRECTION_UP:
			sprite_player.setTextureRect(sf::IntRect(64,0,64,64));
			break;
		case DIRECTION_DOWN:
			sprite_player.setTextureRect(sf::IntRect(0,0,64,64));
			break;
	}
	m_wnd->draw(sprite_player);
	
	//Draw Life!
    float life = m_gst->getHero()->checkLife();

    sf::Sprite sprite_heart_empty;
    m_texture_life_EMPTY.setRepeated(true);
    sprite_heart_empty.setTexture(m_texture_life_EMPTY);

    sf::Sprite sprite_heart_full;
    m_texture_life_FULL.setRepeated(true);
    sprite_heart_full.setTexture(m_texture_life_FULL);

    sf::Vector2f heartsPos(m_gst->getPlayerLocation().x+3,m_gst->getPlayerLocation().y+ROBOT_HEIGHT+3);
    ///std::cout <<"life: " << life << "\n";
	
    sprite_heart_empty.setPosition(heartsPos);
    sprite_heart_empty.setTextureRect(sf::IntRect(0,0,16*4,16));
    m_wnd->draw(sprite_heart_empty);
    sprite_heart_full.setPosition(heartsPos);
    sprite_heart_full.setTextureRect(sf::IntRect(0,0,(life*16*4/100),16));
    m_wnd->draw(sprite_heart_full);

	//draw Coins
    sf::Sprite sprite_coin;
	sprite_coin.setTexture(m_texture_coin);

	std::vector<sf::Vector2f> *coins = m_gst->getLevel()->getCoins();
	std::vector<sf::Vector2f>::iterator coin_it;

	for(coin_it = coins->begin();coin_it != coins->end();coin_it++)
	{
		sprite_coin.setPosition(*coin_it);
		m_wnd->draw(sprite_coin);
	}
	
	//draw Bullets
	sf::Sprite sprite_bullet;
	sprite_bullet.setTexture(m_texture_bullet);

	std::vector<Bullet> *bullets = m_gst->getLevel()->getBullets();
	std::vector<Bullet>::iterator bullet_it;
	sf::Vector2f position;
	for(bullet_it = bullets->begin();bullet_it != bullets->end();bullet_it++)
	{
		sprite_bullet.setPosition(bullet_it->getPosition());
		//std::cout<< "bullet(renderer): " << m_gst->getLevel()->getBullets()->begin()->getPosition().x << "," << m_gst->getLevel()->getBullets()->begin()->getPosition().y << "\n";
		m_wnd->draw(sprite_bullet);
	}
	
	// draw game( depends on gameState) 
	if(m_gst->getGameState() == STATE_MENU)
	{
		// Menu texts
		sf::Text text_title;
		text_title.setFont(m_bold_font);
		text_title.setString("Emotional Revolver");
		text_title.setCharacterSize(80);
		text_title.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x  -160 ,m_gst->getPlayerLocation().y -160));
		m_wnd->draw(text_title);

		sf::Text text_help;
		text_help.setFont(m_normal_font);
		text_help.setString("Larry the robot likes to eat screws->\n    Start with the <SPACE> key.\n       For Controls press <C>");
		text_help.setCharacterSize(20);
		text_help.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x  -120 ,m_gst->getPlayerLocation().y +100));
		m_wnd->draw(text_help);
	}
	else if(m_gst->getGameState() == STATE_CONTROLS)
	{
		// Controls texts
		sf::Text text_title;
		text_title.setFont(m_bold_font);
		text_title.setString("Controls");
		text_title.setCharacterSize(80);
		text_title.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x  -120 ,m_gst->getPlayerLocation().y -160));
		m_wnd->draw(text_title);

		sf::Text text_controls;
		text_controls.setFont(m_normal_font);
		text_controls.setString(" Pause \t\t\t\t\t\t\t\t\t\t <P>\n Mute \t\t\t\t\t\t\t\t\t\t  <M>\n Beenden\t\t\t\t\t\t\t\t\t <Escape>\n Spiel starten/fortsetzen \t\t <Space>\n Spiel neustarten\t\t\t\t\t\t<R>\n");
		text_controls.setCharacterSize(20);
		text_controls.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x  -120 ,m_gst->getPlayerLocation().y +100));
		m_wnd->draw(text_controls);
	}
	else if(m_gst->getGameState() == STATE_PAUSE)
	{
		// Pause texts
		sf::Text text_title;
		text_title.setFont(m_bold_font);
		text_title.setString("PAUSE");
		text_title.setCharacterSize(80);
		text_title.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x  -120 ,m_gst->getPlayerLocation().y -160));
		m_wnd->draw(text_title);

		sf::Text text_controls;
		text_controls.setFont(m_normal_font);
		text_controls.setString("Zum Weiterspielen <SPACE> druecken");
		text_controls.setCharacterSize(20);
		text_controls.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x  -120 ,m_gst->getPlayerLocation().y +100));
		m_wnd->draw(text_controls);
	}
	else if(m_gst->getGameState() == STATE_LOST)
	{
		// Lost texts
		sf::Text text_title;
		text_title.setFont(m_bold_font);
		text_title.setString("VERLOREN");
		text_title.setCharacterSize(80);
		text_title.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x  -160 ,m_gst->getPlayerLocation().y -160));
		//text_title.setPosition(sf::Vector2f(m_wnd->getSize().x/2 - text_title.getLocalBounds().width/2,200));
		m_wnd->draw(text_title);

		sf::Text text_lost;
		text_lost.setFont(m_normal_font);
		text_lost.setString("Zum Neustarten <SPACE> druecken");
		text_lost.setCharacterSize(20);
		text_lost.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x  -120 ,m_gst->getPlayerLocation().y +100));
	//	text_controls.setPosition(sf::Vector2f(m_wnd->getSize().x/2 - text_controls.getLocalBounds().width/2,500));
		m_wnd->draw(text_lost);
	}
	
	// ScoreBoard:
	std::stringstream str;
	str << m_gst->getHero()-> getCollectedCoins() << " Coins\n";

	sf::Text text_screws;
	text_screws.setFont(m_bold_font);
	text_screws.setString(str.str());
	text_screws.setCharacterSize(30);
	//show scroeboard relative to playerLocation
	text_screws.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x - WINDOWSIZE_X/2 +60 ,m_gst->getPlayerLocation().y - WINDOWSIZE_Y/2 +60));
	m_wnd->draw(text_screws);
	
	//anzeigen
	m_wnd->display();

}
