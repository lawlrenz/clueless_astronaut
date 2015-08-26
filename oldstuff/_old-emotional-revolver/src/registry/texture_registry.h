#ifndef TEXTURE_REGISTRY_H
#define TEXTURE_REGISTRY_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

typedef std::unordered_map<int,sf::IntRect> ParameterContainer;

struct TextureWrapper
{
	sf::Texture* texture;
	ParameterContainer parameters;
};

typedef std::unordered_map<std::string,TextureWrapper*> TextureContainer;

class TextureRegistry
{
public:
	static TextureRegistry* getInstance();
	void setTexture(std::string identifier, TextureWrapper* texture);
	TextureWrapper* getTexture(std::string identifier);
	
private:
	TextureRegistry();
	TextureContainer m_texture_container;
};

#endif