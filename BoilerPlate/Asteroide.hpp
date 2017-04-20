#pragma once
#ifndef _ASTEROIDE_
#define _ASTEROIDE_

#include <iostream>
#include <random>
#include <vector>
#include <time.h>

//
#include "Vector2.hpp"
#include "Draw.hpp"
#include "MathUtils.hpp"

class Asteroide : public draw
{
public: 
		Asteroide(Vector2 pos, int size);
		Asteroide();
		~Asteroide();
		void DrawAst();
		void Mover(float deltaTime);
		void Trasladar(Vector2 newPos);
		void limite();
		void GenerarCirculo();
		void Dividir(int Cantidad, int size, Vector2 position);
		void setMasa();
		int getSize();
		void setPoint();

private: 
		float Angulo;
		std::vector<Vector2> Point;
		std::vector<Vector2> Circulo;
		float RadioAst;
		float Masa;
		float AnguloRadian;
		int Size;
		Vector2 PositionAst;
		Vector2 Mn;
		Vector2 Mx;
};

#endif // !_ASTEROIDE_