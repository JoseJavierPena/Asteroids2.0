#include "enemyShip.h"

//SDL includes
#include <SDL2\SDL_opengl.h>

//Math includes
#include <cmath>
#include <algorithm>
#include "MathUtils.h"

const float MAX_SPEED = 10.0f;
const float force = 1.25f;

namespace Asteroids
{
	namespace Entity
	{
		EnemyShip::EnemyShip()
			: enemyPos(Engine::Math::Vector2D(400, 0))
			, increaseX(-565.0f)
			, EnemyRadius(15.0f)
			, EnemyAngle(0)
			, canShoot(true)
		{};

		EnemyShip::EnemyShip(const std::vector<Engine::Math::Vector2D> points)
			: m_points(points)
		{
			m_angle = 0.0f;
		}

		EnemyShip::~EnemyShip()
		{
			for (int i = 0; i < bull.size(); i++)
			{
				deleteBullet(bull[i]);
			}
			canShoot = false;
		};

		void EnemyShip::Render()
		{
			//Reset matrix
			glLoadIdentity();

			//Limit where the enemy ship appears
			limit();

			// Translation to ship position
			glTranslatef(m_position.m_x, m_position.m_y, 0.0f);

			// Ship rotation to current angle
			glRotatef(EnemyAngle, 0.0f, 0.0f, 1.0f);

			//Color of the enemy ship
			glColor3f(0.0f, 1.0f, 0.0f);

			//Drawing the enemy ship	
			drawEnemyShip(GL_LINE_LOOP, m_points);

			for (int i = 0; i < bull.size(); i++)
			{
				bull[i]->Render();
			}
		};

		void EnemyShip::Update(float deltaTime)
		{
			//Speed limit
			float speed = std::fabs(m_velocity.Length());

			if (speed > MAX_SPEED)
			{
				m_velocity = Engine::Math::Vector2D((m_velocity.m_x / speed) * MAX_SPEED, (m_velocity.m_y / speed) * MAX_SPEED);

				speed = std::fabs(m_velocity.Length());
			}

			// Applying drag
			m_velocity = Engine::Math::Vector2D(
				m_velocity.m_x * Physics::DRAG,
				m_velocity.m_y * Physics::DRAG);

			// Calculating new position
			Engine::Math::Vector2D pos = m_position + m_velocity;

			// Translation to new position
			translate(pos);

			return;
		};

		void EnemyShip::drawEnemyShip(unsigned int mode, std::vector<Engine::Math::Vector2D> point)
		{
			//Drawing the enemy ship
			glBegin(mode);
			for (auto temp : point)
			{
				glVertex2f(temp.m_x, temp.m_y);
			}
			glEnd();
		};

		void EnemyShip::limit()
		{
			if (m_position.m_x > 570)
			{
				Engine::Math::Vector2D newPos = Engine::Math::Vector2D(m_position.m_x * -1, m_position.m_y * -1);
				RandomTranslation(newPos);
			}
			else if (m_position.m_x < -570)
			{
				Engine::Math::Vector2D newPos = Engine::Math::Vector2D(m_position.m_x * -1, m_position.m_y * -1);
				RandomTranslation(newPos);
			}
			if (m_position.m_y > 320)
			{
				Engine::Math::Vector2D newPos = Engine::Math::Vector2D(m_position.m_x * -1, m_position.m_y * -1);
				RandomTranslation(newPos);
			}
			else if (m_position.m_y < -320)
			{
				Engine::Math::Vector2D newPos = Engine::Math::Vector2D(m_position.m_x * -1, m_position.m_y * -1);
				RandomTranslation(newPos);
			}
		};

		void EnemyShip::RandomTranslation(Engine::Math::Vector2D pos)
		{
			Engine::Math::Vector2D newPos;
			m_position = static_cast<Engine::Math::Vector2D>(newPos);
			increaseX = -570;
			m_position = newPos;
		};

		void EnemyShip::shoot(Engine::Math::Vector2D Position)
		{
			float val = (m_position.m_y - Position.m_y) / (m_position.m_x - Position.m_x);
			float angle1 = atan(val) * (180 / Engine::Math::PI);

			if (m_position.m_x < 0 || m_position.m_x < 0 && Position.m_x >= 0 || m_position.m_x >= 0 && Position.m_x >= 0)
			{
				angle1 = angle1 + 270.0f;
			}
			else if (m_position.m_x >= 0 || m_position.m_x >=0 && Position.m_x || m_position.m_x < 0 && Position.m_x < 0)
			{
				angle1 = angle1 + 90.0f;
			}

			Bullet* newBullet = new Bullet(m_position, Engine::Math::Vector2D(30, 30), angle1);
			bull.push_back(newBullet);
		};

		void EnemyShip::deleteBullet(Bullet* bullet)
		{
			bull.erase(remove(bull.begin(), bull.end(), bullet), bull.end());
			delete bullet;
		};

		void EnemyShip::setPoint()
		{
			for (int x = 0; x < 16; x++)
			{
				float val = static_cast<float>(2.0f*Engine::Math::PI * (x / 16.0f));
				float k = EnemyRadius * cosf(val);
				float j = EnemyRadius * sinf(val);
				points_circle.push_back(Engine::Math::Vector2D(k, j));
			}
		};

	}
}