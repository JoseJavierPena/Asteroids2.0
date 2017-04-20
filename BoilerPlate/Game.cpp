#include "Game.h"

#include <algorithm>

namespace Game 
{
	Game::Game(int WIDTH, int HEIGHT)
		: m_WIDTH(WIDTH)
		, m_HEIGHT(HEIGHT)
		, m_playerIndex(0)
	{}

	Game::~Game() 
	{
		for (int i = 0; i < m_player.size() - 1; i++)
			delete m_player.at(i);

		for (int i = 0; i < m_enemies.size() - 1; i++)
			delete m_enemies.at(i);
	}

	void Game::Init()
	{
		//Loading Ships or PLayer Models
		Asteroids::Utilities::Load config;
		m_player = config.LoadModels();

		//Creating the asteroids
		createEnemy(7, Asteroids::Entity::Asteroid::AsteroidSize::BIG, null);

		//Creating enemy ship
		//m_enemy = config.LoadModels();

		return;
	}

	void Game::Update(float fps)
	{
		//Update player
		m_player[m_playerIndex]->Update(fps);

		//Update enemies
		for (int i = 0; i < m_enemies.size(); i++)
			m_enemies.at(i)->Update(fps);

		//Check collitions
		checkCollitions(lifes);

		//Check enemy Ship
		//m_enemy.Update(fps);

		return;
	}

	void Game::Render()
	{
		// Render player
		m_player[m_playerIndex]->Render();

		// Render enemies
		for (int i = 0; i < m_enemies.size(); i++)
			m_enemies[i]->Render();

		//Rendering enemy ship
		/*if (secondsTo > 5)
		{
			for(int i=0;i<m_enemy)
		}*/
		
		return;
	}

	void Game::checkCollitions(int life)
	{
		if (!m_player[m_playerIndex]->canCollide()) return;

		bool colliding = false;
		bool bulletHit = false;
		for (auto temp : m_enemies)
		{
			Asteroids::Entity::Asteroid* pAsteroid = dynamic_cast<Asteroids::Entity::Asteroid*>(temp);
			if (pAsteroid)
			{
				if (m_player[m_playerIndex]->isColliding(pAsteroid))
				{
					//Lifes
					colliding = true;
					life = lifes;
					lifes--;
					

					//Getting size for debris
					Asteroids::Entity::Asteroid::AsteroidSize currentSize = pAsteroid->getSize();

					//Deleting asteroid
					deleteEnemy(temp);

					//Creating debris
					createDebris(currentSize, m_player[m_playerIndex]->getPosition());

					//Respawn
					m_player[m_playerIndex]->Respawn();
					break;
				}
				
				for (int i = 0; i < m_player[m_playerIndex]->m_magazine.size(); i++)
				{
					if (m_player[m_playerIndex]->m_magazine[i]->isColliding(pAsteroid))
					{
						//Getting size for debris
						Asteroids::Entity::Asteroid::AsteroidSize currentSize = pAsteroid->getSize();
						Engine::Math::Vector2D currentPos = pAsteroid->getPosition();

						//Deleting asteroid
						deleteEnemy(temp);

						//Deleting bullet
						m_player[m_playerIndex]->deleteBullet(m_player[m_playerIndex]->m_magazine[i]);
						//Creating debris
						createDebris(currentSize, currentPos);
						bulletHit = true;
					}
				}
				if (bulletHit == true)
					break;
				/*if (bulletHit == m_player[m_playerIndex])
					return false;*/
			}
		}
		return;
	}

	void Game::createEnemy(int cant, Asteroids::Entity::Asteroid::AsteroidSize size, Engine::Math::Vector2D pos)
	{
		if (pos == null)
		{
			for (int i = 0; i < cant; i++)
			{
				Asteroids::Entity::Asteroid* nEnemy = new Asteroids::Entity::Asteroid();
				m_enemies.push_back(nEnemy);
			}
			return;
		}

		else
		{
			for (int i = 0; i < cant; i++)
			{
				Asteroids::Entity::Asteroid* nEnemy = new Asteroids::Entity::Asteroid(size, pos);
				m_enemies.push_back(nEnemy);
			}
		}

	}

	void Game::deleteEnemy(Asteroids::Entity::Asteroid* dEnemy) 
	{
		m_enemies.erase(
			remove(m_enemies.begin(), m_enemies.end(), dEnemy), m_enemies.end()
		);
		delete dEnemy;
	}

	void Game::createDebris(Asteroids::Entity::Asteroid::AsteroidSize size, Engine::Math::Vector2D pos)
	{
		if (size == Asteroids::Entity::Asteroid::AsteroidSize::BIG)
		{
			createEnemy(2, Asteroids::Entity::Asteroid::AsteroidSize::MEDIUM, pos);
		}

		if (size == Asteroids::Entity::Asteroid::AsteroidSize::MEDIUM)
		{
			createEnemy(2, Asteroids::Entity::Asteroid::AsteroidSize::SMALL, pos);
		}
	}
}