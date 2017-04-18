#include "Bullet.h"

#include "Physics.h"
#include "SDL2\SDL_opengl.h"

namespace Asteroids 
{
	namespace Entity 
	{
		Bullet::Bullet(Engine::Math::Vector2D pos, Engine::Math::Vector2D v, float angle)
		{
			m_mass = 0.3f;
			m_radius = 7.f;
			m_angle = angle;
			m_angleInRads = (m_angle + Asteroids::angle_offset) * (Engine::Math::PI / 180);
			m_position = pos;
			//m_currentColor = Engine::Math::Vector3D(0.f, 1.f, 0.f);
			m_lifeTime = 0;
		};
		
		void Bullet::Render() 
		{
			m_lifeTime++;

			//
			glLoadIdentity();

			//warpping
			wrapAround();

			//Translate
			glTranslatef(m_position.m_x, m_position.m_y, 0.f);

			//Change color
			//glColor3f(m_currentColor.m_x, m_currentColor.m_y, m_currentColor.m_z);

			//Draw Bullet
			glLoadIdentity();
			glBegin(GL_TRIANGLE_FAN);
				int num_segments = 100;
				for (int idx = 0; idx < num_segments; idx++) 
				{
					float theta = 2.0f * Engine::Math::PI * float(idx) / float(num_segments);
					float x = m_radius * cosf(theta);
					float y = m_radius * sinf(theta);
					Engine::Math::Vector2D vertex(
						x + m_position.m_x, 
						y + m_position.m_y);
					glVertex2f(vertex.m_x, vertex.m_y);
				}
			glEnd();
		};

		void Bullet::Update(float fps) 
		{
			// Calculating new position
			Engine::Math::Vector2D current;
			if (m_mass > 0)
			{
				float impulse = (Physics::THRUST / m_mass);
				float x = impulse * std::cosf(m_angleInRads);
				float y = impulse * std::sinf(m_angleInRads);

				current += Engine::Math::Vector2D(x, y);
			}
			// Translation to new position
			current += m_position;
			translate(current);
			return;
		};

		void Bullet::wrapAround() 
		{
			if (m_position.m_x > 650)
			{
				Engine::Math::Vector2D invertedPos(m_position.m_x * -1, m_position.m_y * -1);
				translate(invertedPos);
			}
			else if (m_position.m_x < -650)
			{
				Engine::Math::Vector2D invertedPos(m_position.m_x * -1, m_position.m_y * -1);
				translate(invertedPos);
			}

			if (m_position.m_y > 400)
			{
				Engine::Math::Vector2D invertedPos(m_position.m_x * -1, m_position.m_y * -1);
				translate(invertedPos);
			}
			else if (m_position.m_y < -400)
			{
				Engine::Math::Vector2D invertedPos(m_position.m_x * -1, m_position.m_y * -1);
				translate(invertedPos);
			}
		};
	}
}