#pragma once

#ifndef PlayerModel_H_
#define PlayerModel_H_

//Std
#include <vector>

//Math includes
#include "MathUtils.h"
#include "Physics.h"

//Game includes
#include "Entities.h"
#include "Bullet.h"

namespace Asteroids 
{
	namespace Entity
	{
		class Ship : public Entities
		{
		public:

			/*======================================*/
			/*			PUBLIC FUNCTIONS			*/
			/*======================================*/
			Ship();
			Ship(std::vector<Engine::Math::Vector2D> model_points);
			void Render() override;
			void MoveForward();
			void MoveRight();
			void MoveLeft();
			void Shoot();
			void Update(float deltaTime) override;
			void Respawn();
			bool canCollide() const { return m_inmune; };
			void setCollision(bool status) { m_inmune = status; };
			void setVelocity(Engine::Math::Vector2D v) { m_velocity = v; };
			Engine::Math::Vector2D getPosition() const { return m_position; };
			void deleteBullet(Bullet*);

			//Lifes function
			void Lifes(int, int);

			/*======================================*/
			/*			PUBLIC MEMBERS				*/
			/*======================================*/
			std::vector<Bullet*> m_magazine;

		protected:

			/*======================================*/
			/*			PRIVATE FUNCTIONS			*/
			/*======================================*/
			void wrapAround() override;
			void rotate(float num) override;
			void translate(Engine::Math::Vector2D pos) override;

		private:
			/*======================================*/
			/*			PRIVATE FUNCTIONS			*/
			/*======================================*/
			void Mass();
			void ResetOrientation();

			/*======================================*/
			/*			PRIVATE MEMBERS				*/
			/*======================================*/
			Engine::Math::Vector2D m_velocity;
			bool m_inmune;
			Engine::Math::Vector3D m_currentColor;
			int m_respawnTime;
			int m_usedBullets;
			float m_currentSpeed;
		};
	}
}

#endif // !PlayerModel_H_