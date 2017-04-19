#pragma once
#ifndef _Game_Asteroids_H_
#define _Game_Asteroids_H_

// STD
#include <vector>

//
#include "Vector2D.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Utils.h"

namespace Game 
{
	const Engine::Math::Vector2D null(0.f, 0.f);

	class AsteroidsGame
	{
	public:

		/*======================================*/
		/*			PUBLIC FUNCTIONS			*/
		/*======================================*/
		AsteroidsGame(int WIDTH, int HEIGHT);
		~AsteroidsGame();
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
		int lifes;

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