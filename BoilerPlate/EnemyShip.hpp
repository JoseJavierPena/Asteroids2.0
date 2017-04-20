#pragma once
#ifndef _ENEMYSHIP_
#define _ENEMYSHIP_

#include <iostream>
#include <vector>

//
#include "Vector2.hpp"
#include "Draw.hpp"
#include "Bala.hpp"
#include "ship.hpp"
#include "MathUtils.hpp"

class EnemyShip : public draw
{
public: 
		EnemyShip();
		~EnemyShip();
		void Draw();
		void Update(float deltatime, Vector2 Position);
		void Trasladar(Vector2 newPos);
		void limite();
		void Disparar(Vector2 Position);
		void EliminarBala(Bala* bala);
		void setPoint();
		std::vector<Bala*> Balas;

private: 
		 std::vector<Vector2> initShip;
		 Vector2 PositionEnemy;
		 std::vector<Vector2> Circulo;
		 float Radio;
		 float IncreX;
		 int Time;
		 int Time2;
		 float Angulo;
		 bool PermitirDisparar;
};

#endif // !_ENEMYSHIP_