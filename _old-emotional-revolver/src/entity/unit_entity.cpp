#include "unit_entity.h"

UnitEntity::UnitEntity(int subtype, std::string texture_identifier):
	DrawableEntity(ENTITY_TYPE_UNIT, subtype, sf::Vector2f(UNIT_WIDTH,UNIT_HEIGHT), texture_identifier)
{
	m_movement_speed = sf::Vector2f(0,0);
	m_movement_direction = DIRECTION_NONE;
	m_cooldown = 0;
	m_is_alive = true;
	m_health = 100;
	m_fire_mode = 0;
	m_orientation = DIRECTION_RIGHT;

}

void UnitEntity::update()
{
	if(m_movement_direction == DIRECTION_LEFT){
		// Moving left, accelerate
		m_movement_speed.x -= 0.5;
	}
	else if(m_movement_direction == DIRECTION_RIGHT){
		// Moving right, accelerate
		m_movement_speed.x += 0.5;
	}
	else if(m_movement_speed.x > 0.5)
	{
		// Not moving, slow down
		m_movement_speed.x -= 0.5;
	}
	else if(m_movement_speed.x < -0.5)
	{
		// Not moving, slow down
		m_movement_speed.x += 0.5;
	}
	else {
		// Not moving and slow, stop
		m_movement_speed.x = 0;
	}

	// Gravity influence
	m_movement_speed.y += 0.3;

	// Maximum x speed
	if(m_movement_speed.x > 4)
	{
		m_movement_speed.x = 4;
	}
	if(m_movement_speed.x < -4)
	{
		m_movement_speed.x = -4;
	}

	// Maximum y speed
	if(m_movement_speed.y > 9)
	{
		m_movement_speed.y = 9;
	}
	if(m_movement_speed.y < -9)
	{
		m_movement_speed.y = -9;
	}

	// Update location
	setPosition(getPosition()+m_movement_speed);

	// Decrement shooting cooldown
	if(m_cooldown > 0)
	{
		m_cooldown--;
	}

}

void UnitEntity::handleCollision(TileMap* tiles)
{
    TileContainer colliding_tiles;
    TileContainer::iterator it;
    //TileMap::iterator mit;
/*
    std::cout << "Collision detection loop at " << getGridLocation().x << " " << getGridLocation().y << std::endl;


    // Find colliding tiles
    for(mit = tiles.begin(); mit != tiles.end(); mit++)
    {
        if(mit->second->getBoundingBox().intersects(getBoundingBox()))
        {
           //colliding_tiles.push_back(mit->second);
           std::cout << mit->first.x << " " << mit->first.y << std::endl;
           //std::cout << mit->second->getGridLocation().x << " " << mit->second->getGridLocation().y << std::endl;
        }
    }
*/
	//std::cout << "Collision detection precise at " << getGridLocation().x << " " << getGridLocation().y << std::endl;
    
    std::vector<sf::Vector2u> locations;
    std::vector<sf::Vector2u>::iterator loc_it;

    sf::Vector2u grid_location = getGridLocation();

    locations.push_back(grid_location + sf::Vector2u(0,0));
    locations.push_back(grid_location + sf::Vector2u(0,1));
    locations.push_back(grid_location + sf::Vector2u(0,2));
    locations.push_back(grid_location + sf::Vector2u(1,0));
    locations.push_back(grid_location + sf::Vector2u(1,1));
    locations.push_back(grid_location + sf::Vector2u(1,2));
    locations.push_back(grid_location + sf::Vector2u(2,0));
    locations.push_back(grid_location + sf::Vector2u(2,1));
    locations.push_back(grid_location + sf::Vector2u(2,2)); 

    for(loc_it = locations.begin();loc_it != locations.end(); loc_it++)
    {
    	TileEntity* tile = tiles->getTileAt(loc_it->x, loc_it->y);
    	if(tile
    		&& tile->getType() == ENTITY_TYPE_TILE
    		&& tile->getBoundingBox().intersects(getBoundingBox()))
	    {
	    	colliding_tiles.push_back(tile);
	    	//std::cout << loc_it->x << " " << loc_it->y << std::endl;
	    }
    }
    
    // Resolve collisions
    for(it = colliding_tiles.begin(); it != colliding_tiles.end(); it++)
    {
        // Check if still colliding
        if(!(*it)->getBoundingBox().intersects(getBoundingBox()))
        {
            continue;
        }

        float min_amount = 9999;
        sf::Vector2f delta(0,0);
        sf::Vector2f speed = getMovementSpeed();
        sf::Vector2f newspeed;

        // Unit colliding on left side
        if(getLeft() < (*it)->getRight())
        {
            float amount = (*it)->getRight() - getLeft();
            if(amount<min_amount)
            {
                min_amount = amount;
                delta = sf::Vector2f(amount,0);
                newspeed = sf::Vector2f(0,speed.y);
            }
        }

        // Unit colliding on right side
        if(getRight() > (*it)->getLeft())
        {
            float amount = getRight() - (*it)->getLeft();
            if(amount<min_amount)
            {
                min_amount = amount;
                delta = sf::Vector2f(-amount,0);
                newspeed = sf::Vector2f(0,speed.y);
            }
        }

        // Unit colliding on top side
        if(getTop() < (*it)->getBottom())
        {
            float amount = (*it)->getBottom() - getTop();
            if(amount<min_amount)
            {
                min_amount = amount;
                delta = sf::Vector2f(0,amount);
                newspeed = sf::Vector2f(speed.x,0);
            }
        }

        // Unit colliding on bottom side
        if(getBottom() > (*it)->getTop())
        {
            float amount = getBottom() - (*it)->getTop();
            if(amount<min_amount)
            {
                min_amount = amount;
                delta = sf::Vector2f(0,-amount);
                newspeed = sf::Vector2f(speed.x,0);
                setJumpEnabled();
            }
        }

        setPosition(getPosition()+delta);
        setMovementSpeed(newspeed);

    }
}

void UnitEntity::handleCollision(ProjectileContainer &projectiles)
{
	ProjectileContainer::iterator it;
    // Find colliding projectiles
    for(it = projectiles.begin(); it != projectiles.end(); it++)
    {
        if((*it)->getBoundingBox().intersects(getBoundingBox()))
        {
        	// Set projectile to collided state
        	(*it)->setCollided();

        	// Decrease health
        	m_health -= 20;

        	// Kill unit if HP is 0
        	if(m_health <= 0)
        	{
        		m_is_alive = false;
        	}
        	return;
        }
    }
}


void UnitEntity::setJumpEnabled()
{
	m_can_jump = true;
}

void UnitEntity::doJump()
{
	if(!m_can_jump)
	{
		// Cannot jump right now
		return;
	}

	m_movement_speed.y = -9;
	m_can_jump = false;
}

Direction UnitEntity::getMovementDirection(){
	return  m_movement_direction;
}


void UnitEntity::changeMode(int new_mode){
	m_fire_mode = new_mode;
}

ProjectileEntity* UnitEntity::doShoot()
{
	sf::Vector2f speed;
	
	if(m_orientation == DIRECTION_LEFT) 
	{
		speed = sf::Vector2f(-7,0);
	}
	else
	{
		speed = sf::Vector2f(7,0);
	}

	if(m_cooldown > 0)
	{

		// cant shoot. weapon not ready.
		return NULL;
	}
	if(m_fire_mode == 0){
		ProjectileEntity* projectile = new ProjectileEntity(0, speed, "projectile");
		projectile->setCenter(getProjectileSpawnLocation());
		m_cooldown = 40;

		return projectile;
	}

	else if(m_fire_mode == 1){
		//shotgun
		m_fire_mode = 0;
	}
	else if(m_fire_mode == 2){
		// Machinegun
		ProjectileEntity* projectile = new ProjectileEntity(0, speed, "projectile");
		projectile->setCenter(getProjectileSpawnLocation());
		m_cooldown = 10;
		return projectile;
	}

	else if(m_fire_mode == 3){
		// Charged
		m_fire_mode = 0;
	}

	else if(m_fire_mode == 4){
		// Sniper
		m_fire_mode = 0;
	}

	else if(m_fire_mode == 5){
		// Slowmotion
		m_fire_mode = 0;
	}
	else if(m_fire_mode == 6){
		// Halfautomatic
		ProjectileEntity* projectile = new ProjectileEntity(0, speed, "projectile");
		projectile->setCenter(getProjectileSpawnLocation());
		m_cooldown = 20;
		return projectile;
	}
	else if(m_fire_mode == 7){
		// uncontrolled
		m_fire_mode = 0;
	}
	else if(m_fire_mode == 8){
		m_fire_mode = 0;
	}

	return NULL;
}

void UnitEntity::setMovementDirection(Direction dir)
{
	m_movement_direction = dir;

	if(dir == DIRECTION_LEFT && m_orientation != DIRECTION_LEFT)
	{
		m_orientation = DIRECTION_LEFT;
	}
	else if(dir == DIRECTION_RIGHT && m_orientation != DIRECTION_RIGHT)
	{
		m_orientation = DIRECTION_RIGHT;
	}
}

sf::Vector2f UnitEntity::getMovementSpeed()
{
	return m_movement_speed;
}

void UnitEntity::setMovementSpeed(sf::Vector2f speed)
{
	m_movement_speed = speed;
}

void UnitEntity::killUnit()
{
	m_is_alive = false;
}

bool UnitEntity::isAlive()
{
	return m_is_alive;
}

bool UnitEntity::isAbleToJump()
{
	return m_can_jump;
}

int UnitEntity::getHealth()
{
	return m_health;
}

sf::Vector2f UnitEntity::getProjectileSpawnLocation()
{
	sf::Vector2f loc = getCenter();
	sf::Vector2f delta(30,0);

	if(m_orientation == DIRECTION_LEFT)
	{
		return loc - delta;
	}
	else
	{
		return loc + delta;
	}
	
}

bool UnitEntity::isMovingRight()
{
	if(m_movement_speed.x > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UnitEntity::isMovingLeft()
{
	if(m_movement_speed.x < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}