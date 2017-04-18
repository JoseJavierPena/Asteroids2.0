#pragma once
#ifndef MathUtils_H_
#define MathUtils_H_

#include <time.h>

namespace Engine 
{
	namespace Math 
	{
		/*======================================*/
		/*			DECLARED CONSTS				*/
		/*======================================*/
		const float PI = 3.1415926535897323846f;

		/*======================================*/
		/*			RANDOM FLOAT GENERATOR		*/
		/*======================================*/
		template<typename T>
		T RandomInRange(T min, T max)
		{
			return min + (max - min) * (rand() / static_cast<T>(RAND_MAX));
		}
	}
}

#endif // !MathUtils_H_