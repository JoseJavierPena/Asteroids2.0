#pragma once
#ifndef _SHIP_
#define _SHIP_

#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>

//
#include "Vector2.hpp"
#include "Draw.hpp"
#include "Bala.hpp"
#include "MathUtils.hpp"

class ship : public draw
{
public:
		ship();
		ship(const std::vector<Vector2> points);
		void Draw();
		void MoveUp();
		void MoveDown();
		void MoveRight();
		void MoveLeft();
		void Trasladar(Vector2 position);
		void limite();
		void setMasa();
		void setPoint();
		Vector2 getPosition();
		void Reiniciar();
		void Update(float deltatime);
		void Disparar();
		void EliminarBala(Bala* bala);
		void Vidas(int vidas, int index);
		std::vector<Bala*> Balas;
		Vector2 Position;

private: 
		std::vector<Vector2> Point;
		std::vector<Vector2> Circulo;
		Vector2 Velocity;
		float Angulo;
		float AnguloRadianes;
		float Masa;
		float RadioShip;
		float Speed;
		Vector2 Min;
		Vector2 Max;
		bool Inmune;
		int Time;
		int UsoBala;
};

#endif // !_SHIP_