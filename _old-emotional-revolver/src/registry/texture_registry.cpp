#include "texture_registry.h"

TextureRegistry::TextureRegistry()
{
}

TextureRegistry* TextureRegistry::getInstance()
{
	static TextureRegistry instance;
	return &instance;
}

void TextureRegistry::setTexture(std::string identifier, TextureWrapper* texture)
{
	m_texture_container[identifier] = texture;
}

TextureWrapper* TextureRegistry::getTexture(std::string identifier)
{
	if(m_texture_container.find(identifier) != m_texture_container.end())
	{
		return m_texture_container[identifier];
	}
	else
	{
		return NULL;
	}
	
}