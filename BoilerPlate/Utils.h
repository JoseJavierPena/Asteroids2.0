#pragma once

#ifndef Utils_H_
#define Utils_H_

//STD includes
#include <vector>

//Game includes
#include "Ship.h"
#include "Game.h"
#include "enemyShip.h"
#include "Bullet.h"
#include "Asteroid.h"


namespace Asteroids 
{
	namespace Utilities 
	{
		class Load
		{
			public:

				/*======================================*/
				/*			PUBLIC FUNCTIONS			*/
				/*======================================*/
				std::vector<Entity::Ship*> LoadModels();
				std::vector<Asteroids::Entity::EnemyShip*> LoadEnemy();

		};
	}
}
#endif // !Utils_H_