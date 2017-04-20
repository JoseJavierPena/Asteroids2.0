#pragma once
#ifndef _Game_Asteroids_H_
#define _Game_Asteroids_H_

// STD
#include <vector>

//Vector includes
#include "Vector2D.h"

//Asteroids Game includes
#include "Ship.h"
#include "Asteroid.h"
#include "Utils.h"
#include "enemyShip.h"

namespace Game 
{
	const Engine::Math::Vector2D null(0.f, 0.f);

	class Game
	{
	public:

		/*======================================*/
		/*			PUBLIC FUNCTIONS			*/
		/*======================================*/
		Game(int WIDTH, int HEIGHT);
		~Game();
		void Init();
		void Update(float fps);
		void Render();

		/*======================================*/
		/*			PUBLIC MEMBERS				*/
		/*======================================*/
		std::vector<Asteroids::Entity::Ship*>				m_player;
		int													m_playerIndex;
		std::vector<Asteroids::Entity::Asteroid*>			m_enemies;

	private:
		/*======================================*/
		/*			PRIVATE MEMBERS				*/
		/*======================================*/
		int								m_WIDTH;
		int								m_HEIGHT;
		
		//Seconds to respawn
		double secondsTo = 0;

		//Lifes
		int lifes;

		//Enemy
		std::vector<Asteroids::Entity::EnemyShip*> m_enemy;

		/*======================================*/
		/*			PRIVATE FUNCTIONS			*/
		/*======================================*/
		void checkCollitions(int life);
		void deleteEnemy(Asteroids::Entity::Asteroid*);
		void createDebris(Asteroids::Entity::Asteroid::AsteroidSize size, Engine::Math::Vector2D pos);
		void createEnemy(int, Asteroids::Entity::Asteroid::AsteroidSize, Engine::Math::Vector2D);
	};
}

#endif // !_Game_Asteroids_H_