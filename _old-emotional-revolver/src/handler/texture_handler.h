#ifndef TEXTURE_HANDLER_H
#define TEXTURE_HANDLER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <fstream>
#include "defines.h"
#include "registry/texture_registry.h"

class TextureHandler
{
public:
	TextureHandler();
	void loadTextureAndDefinitions(std::string identifier, std::string texture_file, std::string defines_file);
private:
	void parseLine(std::string line, TextureWrapper* texture_wrapper);
};

#endif
