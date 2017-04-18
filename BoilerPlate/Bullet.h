#pragma once
#ifndef _BULLET_H_
#define _BULLET_H_

//
#include "MathUtils.h"
#include "Entities.h"

namespace Asteroids 
{
	namespace Entity 
	{
		class Bullet : public Entities
		{
		public:

			/*======================================*/
			/*			PUBLIC FUNCTIONS			*/
			/*======================================*/
			Bullet(Engine::Math::Vector2D, Engine::Math::Vector2D, float);
			void Render();
			void Update(float);
			void wrapAround();
			void rotate(float num) override { m_angle = num; };
			void translate(Engine::Math::Vector2D pos) override { m_position = pos; };

			/*======================================*/
			/*				MEMBERS					*/
			/*======================================*/
			int						m_lifeTime;
		};
	}
}

#endif // !_BULLET_H_
