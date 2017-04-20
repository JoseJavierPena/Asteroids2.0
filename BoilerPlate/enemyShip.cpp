#include "EnemyShip.hpp"

// SDL
#include <SDL2/SDL_opengl.h>

//
#include "Draw.hpp"

//
#include <cmath>
#include <algorithm>

const float Max_Speed = 10.0f;
const float Fuerza = 1.25f;

EnemyShip::EnemyShip()
	: PositionEnemy(Vector2(400, 0))
	, IncreX(-565.0f)
	, Radio(15.0f)
	, Time(0)
	, Time2(0)
	, Angulo(0)
	, PermitirDisparar(true)
{
	initShip.push_back(Vector2(-2.0, 14.0));
	initShip.push_back(Vector2(-2.0, 11.0));
	initShip.push_back(Vector2(-14.0, 2.0));
	initShip.push_back(Vector2(0.0, -14.0));
	initShip.push_back(Vector2(14.0, 2.0));
	initShip.push_back(Vector2(2.0, 11.0));
	initShip.push_back(Vector2(2.0, 14.0));
	
	setPoint();
	setRadioAl(Radio);
}

EnemyShip::~EnemyShip()
{
	for (int x = 0; x < Balas.size(); x++)
	{
		EliminarBala(Balas[x]);
	}
	PermitirDisparar = false;
}

void EnemyShip::Draw()
{
	//Reset matrix
	glLoadIdentity();

	//Wrap around of the enemy ship
	limite();

	//Translation to the position
	glTranslatef(PositionEnemy.GetX(), PositionEnemy.GetY(), 0.0f);

	//Enemy ship rotation
	glRotatef(Angulo, 0.0f, 0.0f, 1.0f);
	
	//Drawing the enemy ship
	DrawT(GL_LINE_LOOP, initShip);
	
	//Drawing the bullets of the enemy ship
	for (int i = 0; i < Balas.size(); i++)
		Balas[i]->Render();
}

void EnemyShip::Update(float deltatime, Vector2 Position)
{
	double y = IncreX * (PI / 180);

	if (Time == 350)
	{
		if(Time2 == 0 && PermitirDisparar == true)
			Disparar(Position);

		if (Time2 == 50)
		{
			Time = 0;
			Time2 = 0;
		}
		else
			Time2++;
	}
	else
	{
		Time++;
		PositionEnemy = Vector2(IncreX, 300 * sinf(y));
		IncreX += 0.500f;
		if (300 * sinf(y) >= 0)
		{
			Angulo -= 0.11f;
		}
		else if (300 * sinf(y) < 0)
		{
			Angulo += 0.11f;
		}
		setPosAl(PositionEnemy);
	}

	for (int i = 0; i < Balas.size(); i++)
	{
		Balas[i]->Update(deltatime);
		if (Balas[i]->m_lifeTime >= 150)
		{
			EliminarBala(Balas[i]);
			break;
		}
	}
}

void EnemyShip::limite()
{
	if (PositionEnemy.GetX() > 570)
	{
		Vector2 newPos = Vector2(PositionEnemy.GetX() * -1, PositionEnemy.GetY() * -1);
		Trasladar(newPos);
	}
	else if (PositionEnemy.GetX() < -570)
	{
		Vector2 newPos = Vector2(PositionEnemy.GetX() * -1, PositionEnemy.GetY() * -1);
		Trasladar(newPos);
	}
	else if (PositionEnemy.GetY() > 320)
	{
		Vector2 newPos = Vector2(PositionEnemy.GetX() * -1, PositionEnemy.GetY() * -1);
		Trasladar(newPos);
	}
	else if (PositionEnemy.GetY() < -320)
	{
		Vector2 newPos = Vector2(PositionEnemy.GetX() * -1, PositionEnemy.GetY() * -1);
		Trasladar(newPos);
	}
}

void EnemyShip::Trasladar(Vector2 newPos)
{
	PositionEnemy = static_cast<Vector2> (newPos);
	IncreX = -570;
	setPosAl(PositionEnemy);
}

void EnemyShip::Disparar(Vector2 Position)
{
	double valor = (PositionEnemy.GetY() - Position.GetY()) / (PositionEnemy.GetX() - Position.GetX());
	double anguloA = atan(valor) * (180 / PI);
	
	if (PositionEnemy.GetX() < 0 || PositionEnemy.GetX() < 0 && Position.GetX() >= 0 || PositionEnemy.GetX() >= 0 && Position.GetX() >= 0)
		anguloA = anguloA + 270.0f;
	else if (PositionEnemy.GetX() >= 0 || PositionEnemy.GetX() >= 0 && Position.GetX() < 0 || PositionEnemy.GetX() < 0 && Position.GetX() < 0)
		anguloA = anguloA + 90.0f;

	Bala* nBullet = new Bala(PositionEnemy, Vector2(30,30), anguloA);
	Balas.push_back(nBullet);
}

void EnemyShip::EliminarBala(Bala* bala)
{
	Balas.erase(remove(Balas.begin(), Balas.end(), bala), Balas.end());
	delete bala;
}

void EnemyShip::setPoint()
{
	for (int point = 0; point < 16; ++point)
	{
		float valor = static_cast<float> (2.0f * PI * (point / 16.0f));
		float x = Radio * cosf(valor);
		float y = Radio * sinf(valor);
		Circulo.push_back(Vector2(x, y));
	}
}