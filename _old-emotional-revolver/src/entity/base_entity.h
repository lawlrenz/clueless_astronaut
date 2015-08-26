#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include <SFML/Graphics.hpp>
#include "defines.h"

class BaseEntity: public sf::Transformable
{
public:
	//void draw(sf::RenderWindow* window);
	//void setTextureParameters(TextureParameters *texture_parameters);
	//sf::Vector2f getLocation();
	//void setLocation(sf::Vector2f location);
	sf::Vector2f getSize();
	void setSize(sf::Vector2f size);
	sf::FloatRect getBoundingBox();
	sf::Vector2f getCenter();
	void setCenter(sf::Vector2f location);
	float getTop();
	float getBottom();
	float getLeft();
	float getRight();
	void setTop(float value);
	void setBottom(float value);
	void setLeft(float value);
	void setRight(float value);
	sf::Vector2u getGridLocation();
	int getType();
	int getSubtype();
protected:
	BaseEntity(int type, int subtype, sf::Vector2f size);
	const int m_type;
	const int m_subtype;
	//TextureManager &m_texture_manager;
	//TextureParameters* m_texture_parameters;
	//sf::Vector2f m_location;
	sf::Vector2f m_size;
	//sf::VertexArray m_vertex_array;
};

#endif