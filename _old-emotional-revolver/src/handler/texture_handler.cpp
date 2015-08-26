#include "texture_handler.h"

TextureHandler::TextureHandler()
{
	// Load test texture for unit
	sf::Texture* unit_texture = new sf::Texture();
	TextureWrapper* unit_texture_wrapper = new TextureWrapper();
	unit_texture->loadFromFile("assets/guy_sprite_single.png");
	unit_texture_wrapper->texture = unit_texture;
	unit_texture_wrapper->parameters[0] = sf::IntRect(0,0,UNIT_WIDTH,UNIT_HEIGHT);

	TextureRegistry::getInstance()->setTexture("unit",unit_texture_wrapper);

	// Load test texture for projectile
	sf::Texture* projectile_texture = new sf::Texture();
	TextureWrapper* projectile_texture_wrapper = new TextureWrapper();
	projectile_texture->loadFromFile("assets/test_shot.png");
	projectile_texture_wrapper->texture = projectile_texture;
	projectile_texture_wrapper->parameters[0] = sf::IntRect(0,0,PROJECTILE_SIZE,PROJECTILE_SIZE);

	TextureRegistry::getInstance()->setTexture("projectile",projectile_texture_wrapper);

	//m_tileset_texture.loadFromFile("assets/tiles_level1.png");
	//m_tileset_texture.setSmooth(true);
	//parseTilesFile("assets/tiles_level1.txt");

	//m_projectile_texture.loadFromFile("assets/test_shot.png");
	//m_projectile_parameters = new TextureParameters(0,0,PROJECTILE_SIZE,PROJECTILE_SIZE,m_projectile_texture);
}

// Parse a tile definition file
void TextureHandler::loadTextureAndDefinitions(std::string identifier, std::string texture_file, std::string defines_file)
{
	// Load the texture
	sf::Texture* texture = new sf::Texture();
	TextureWrapper* texture_wrapper = new TextureWrapper();
	texture->loadFromFile(texture_file);
	texture_wrapper->texture = texture;
	
    std::ifstream input(defines_file.c_str());

    for(std::string line; getline(input, line);)
    {
        parseLine(line, texture_wrapper);
    }

    TextureRegistry::getInstance()->setTexture(identifier,texture_wrapper);
}

// Parse one line of a tile definition file
void TextureHandler::parseLine(std::string line, TextureWrapper* texture_wrapper)
{
    std::istringstream iss(line);
    int subid, left, top, width, height;
    if (!(iss >> subid >> left >> top >> width >> height)) { return; } // Malformed file?

    texture_wrapper->parameters[subid] = sf::IntRect(left, top, width, height);
}
