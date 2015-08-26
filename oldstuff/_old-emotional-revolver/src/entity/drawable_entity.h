#ifndef DRAWABLE_ENTITY_H
#define DRAWABLE_ENTITY_H

#include <SFML/Graphics.hpp>
#include "registry/texture_registry.h"
#include "base_entity.h"

class DrawableEntity: public BaseEntity
{
public:
	void draw(sf::RenderTarget* target);
protected:
	DrawableEntity(int type, int subtype, sf::Vector2f size, std::string texture_identifier);
	sf::VertexArray m_vertex_array;
	TextureWrapper* m_texture_wrapper;
};

#endif