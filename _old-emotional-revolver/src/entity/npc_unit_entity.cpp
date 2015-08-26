#include "npc_unit_entity.h"

NPCUnitEntity::NPCUnitEntity(int subtype, std::string texture_identifier):
	UnitEntity(subtype, texture_identifier)
{
	m_movement_interval = 0;
	m_health = 40;
	setMovementDirection(DIRECTION_LEFT);
}

void NPCUnitEntity::setPosition(sf::Vector2f location)
{
	UnitEntity::setPosition(location);
	m_origin_location = location;
	m_target_direction = DIRECTION_LEFT;
}

void NPCUnitEntity::update()
{
	if(m_movement_interval > 0)
	{
		m_movement_interval--;
		setMovementDirection(DIRECTION_NONE);
	}
	else
	{
		setMovementDirection(m_target_direction);
	}

	if(getMovementDirection() == DIRECTION_LEFT && getPosition().x < m_origin_location.x - 10)
	{
		m_target_direction = DIRECTION_RIGHT;
		m_movement_interval = rand() / (RAND_MAX/240);
	}
	else if(getMovementDirection() == DIRECTION_RIGHT && getPosition().x > m_origin_location.x + 10)
	{
		m_target_direction = DIRECTION_LEFT;
		m_movement_interval = rand() / (RAND_MAX/240);
	}

	UnitEntity::update();

}
