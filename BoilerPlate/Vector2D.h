#pragma once

#ifndef Vector2D_H_
#define Vector2D_H_

namespace Engine 
{
	namespace Math 
	{
		class Vector2D 
		{
		public:
			
			/*======================================*/
			/*			CONSTRUCTORS				*/
			/*======================================*/
			Vector2D();
			Vector2D(float uniform);
			Vector2D(float x, float y);

			/*======================================*/
			/*				OPERATORS				*/
			/*======================================*/
			Vector2D& operator=(const Vector2D& rhs);
			Vector2D& operator+=(const Vector2D& rhs);
			Vector2D& operator-=(const Vector2D& rhs);
			Vector2D& operator*=(const Vector2D& rhs);
			Vector2D& operator/=(const Vector2D& rhs);
			Vector2D operator+(const Vector2D& rhs);
			Vector2D operator-(const Vector2D& rhs);
			Vector2D operator-();
			Vector2D operator*(const Vector2D& rhs);
			Vector2D operator/(const Vector2D& rhs);
			bool operator==(const Vector2D& rhs);
			bool operator!=(const Vector2D& rhs);
			friend Vector2D operator*(float scaleUnit, const Vector2D& rhs);
			friend Vector2D operator*(const Vector2D& lhs, float scaleUnit);
			
			/*======================================*/
			/*			PUBLIC MEMBERS				*/
			/*======================================*/
			float m_x;
			float m_y;
			float m_length;


			/*======================================*/
			/*			PUBLIC FUNCTIONS			*/
			/*======================================*/
			float Length();
		};
	}
}

#endif // !Vector2D_H_