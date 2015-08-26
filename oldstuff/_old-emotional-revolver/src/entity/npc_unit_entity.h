#ifndef NPC_UNIT_ENTITY_H
#define NPC_UNIT_ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "entity/unit_entity.h"

class NPCUnitEntity: public UnitEntity
{
public:
	NPCUnitEntity(int subtype, std::string texture_identifier);
	void setPosition(sf::Vector2f location);
	void update();
private:
	int m_movement_interval;
	sf::Vector2f m_origin_location;
	Direction m_target_direction;
};

typedef std::vector<NPCUnitEntity*> NPCUnitContainer;

#endif
