#include "AsteroidsGame.h"

#include <algorithm>

namespace Game 
{
	AsteroidsGame::AsteroidsGame(int WIDTH, int HEIGHT)
		: m_WIDTH(WIDTH)
		, m_HEIGHT(HEIGHT)
		, m_playerIndex(0)
	{}

	AsteroidsGame::~AsteroidsGame() 
	{
		for (int i = 0; i < m_player.size() - 1; i++)
			delete m_player.at(i);

		for (int i = 0; i < m_enemies.size() - 1; i++)
			delete m_enemies.at(i);
	}

	void AsteroidsGame::Init()
	{
		//Loading Ships or PLayer Models
		Asteroids::Utilities::Load config;
		m_player = config.LoadModels();

		//Creating the asteroids
		createEnemy(3, Asteroids::Entity::Asteroid::AsteroidSize::BIG, null);

		return;
	}

	void AsteroidsGame::Update(float fps)
	{
		//Update player
		m_player[m_playerIndex]->Update(fps);

		//Update enemies
		for (int i = 0; i < m_enemies.size(); i++)
			m_enemies.at(i)->Update(fps);

		//Check collitions
		checkCollitions();

		return;
	}

	void AsteroidsGame::Render()
	{
		// Render player
		m_player[m_playerIndex]->Render();

		// Render enemies
		for (int i = 0; i < m_enemies.size(); i++)
			m_enemies[i]->Render();
		
		return;
	}

	void AsteroidsGame::checkCollitions()
	{
		if (!m_player[m_playerIndex]->canCollide()) return;

		int i = 0;
		bool bulletHit = false;
		for (auto temp : m_enemies)
		{
			Asteroids::Entity::Asteroid* pAsteroid = dynamic_cast<Asteroids::Entity::Asteroid*>(temp);
			if (pAsteroid)
			{
				if (m_player[m_playerIndex]->isColliding(pAsteroid))
				{
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
			}
		}
		return;
	}

	void AsteroidsGame::createEnemy(int cant, Asteroids::Entity::Asteroid::AsteroidSize size, Engine::Math::Vector2D pos)
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

	void AsteroidsGame::deleteEnemy(Asteroids::Entity::Asteroid* dEnemy) 
	{
		m_enemies.erase(
			remove(m_enemies.begin(), m_enemies.end(), dEnemy), m_enemies.end()
		);
		delete dEnemy;
	}

	void AsteroidsGame::createDebris(Asteroids::Entity::Asteroid::AsteroidSize size, Engine::Math::Vector2D pos)
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