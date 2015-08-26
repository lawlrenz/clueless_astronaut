#include "drawable_entity.h"

DrawableEntity::DrawableEntity(int type, int subtype, sf::Vector2f size, std::string texture_identifier):
	BaseEntity(type,subtype,size)
{
	// initialize vertex array
	m_vertex_array = sf::VertexArray(sf::Quads, 4);

	m_texture_wrapper = TextureRegistry::getInstance()->getTexture(texture_identifier);

	sf::Vector2u tex_size = m_texture_wrapper->texture->getSize();
	m_vertex_array[0].texCoords = sf::Vector2f(0,0);
	m_vertex_array[1].texCoords = sf::Vector2f(tex_size.x,0);
	m_vertex_array[2].texCoords = sf::Vector2f(tex_size.x,tex_size.y);
	m_vertex_array[3].texCoords = sf::Vector2f(0,tex_size.y);
}


void DrawableEntity::draw(sf::RenderTarget* target)
{

	m_vertex_array[0].position = getPosition();
	m_vertex_array[1].position = getPosition() + sf::Vector2f(m_size.x, 0);
	m_vertex_array[2].position = getPosition() + sf::Vector2f(m_size.x, m_size.y);
	m_vertex_array[3].position = getPosition() + sf::Vector2f(0, m_size.y);

	target->draw(m_vertex_array,m_texture_wrapper->texture);
}
/*
void BaseEntity::setTextureParameters(TextureParameters *texture_parameters)
{

	if(texture_parameters == NULL)
	{
		// No parameters found. This is bad.
		return;
	}

	m_texture_parameters = texture_parameters;

	m_vertex_array[0].texCoords = sf::Vector2f(m_texture_parameters->left, m_texture_parameters->top);
	m_vertex_array[1].texCoords = sf::Vector2f(m_texture_parameters->left + m_texture_parameters->width, m_texture_parameters->top);
	m_vertex_array[2].texCoords = sf::Vector2f(m_texture_parameters->left + m_texture_parameters->width, m_texture_parameters->top + m_texture_parameters->height);
	m_vertex_array[3].texCoords = sf::Vector2f(m_texture_parameters->left, m_texture_parameters->top + m_texture_parameters->height);

}
*/
