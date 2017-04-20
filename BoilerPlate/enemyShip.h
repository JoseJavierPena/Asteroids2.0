#pragma once
#ifndef ENEMYSHIP_H_
#define ENEMYSHIP_H_

#include <iostream>
#include <vector>
#include "Vector2D.h"
#include "Bullet.h"
#include "Ship.h"
#include "Physics.h"

namespace Asteroids
{
	namespace Entity
	{
		class EnemyShip : public Entities
		{
		public:
			/*=============================
			======PUBLIC FUNCTIONS=========
			==============================*/
			EnemyShip();
			EnemyShip(const std::vector<Engine::Math::Vector2D> points);
			~EnemyShip();
			void Render();
			void drawEnemyShip(unsigned int mode, std::vector<Engine::Math::Vector2D> point);
			void Update(float deltaTime);
			void RandomTranslation(Engine::Math::Vector2D pos);
			void limit();
			void shoot(Engine::Math::Vector2D position);
			void deleteBullet(Bullet* bullet);
			void setPoint();

			/*=============================
			========PUBLIC MEMBERS=========
			==============================*/
			std::vector<Bullet*> bull;

		private:
			/*=============================
			========PUBLIC MEMBERS=========
			==============================*/
			std::vector<Engine::Math::Vector2D> m_points;
			Engine::Math::Vector2D enemyPos;
			std::vector<Engine::Math::Vector2D> points_circle;
			Engine::Math::Vector2D m_velocity;
			float increaseX;
			float EnemyAngle;
			float EnemyRadius;
			bool canShoot;
		};
	}
}

#endif // !ENEMYSHIP_H_