#include "Utils.h"

// stdlib
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// Engine
#include "Utilities.h"
#include "Vector2D.h"

namespace Asteroids
{
	namespace Utilities
	{

		std::string const folder_name = "models";

		//Load player models (ships)
		std::vector<Entity::Ship*> Load::LoadModels()
		{
			Engine::FileSystem::Utilities util;
			auto modelsList = util.ListFile(folder_name);

			std::vector<Entity::Ship*> ships;

			std::cout << " *Loaded models* " << std::endl;
			for (int i = 2; i < modelsList.size(); i++)
			{
				std::string model = modelsList[i];
				std::ifstream inFile(util.buildPath(folder_name, model));
				std::string current("");
				std::vector<Engine::Math::Vector2D> points;

				if (inFile.good())
				{
					std::string getFloat;
					while (inFile >> current)
					{
						std::vector<float> pointsRead;
						getFloat = current.substr(0, current.find_last_of(","));
						pointsRead.push_back(std::stof(getFloat));
						getFloat = current.substr(current.find_last_of(",") + 1, current.length());
						pointsRead.push_back(std::stof(getFloat));
						
						//Adding to points vector
						points.push_back(Engine::Math::Vector2D(pointsRead[0], pointsRead[1]));
					}
				}

				std::cout << model << " has " << points.size() << " points" << std::endl;
				
				//Adding points to temp
				Entity::Ship* temp = new Entity::Ship(points);

				//Adding temp to ships vector, who storages the ships in a vector
				ships.push_back(temp);
			}
			std::cout << std::endl;
			return ships;
		}

		//Enemy model
		std::string const enemyShip_dir = "enemyShip";

		//Load enemy ship model
		std::vector<Asteroids::Entity::EnemyShip*> Load::LoadEnemy()
		{
			Engine::FileSystem::Utilities util;

			//Retrieve the files from the directory
			auto models = util.ListFile(enemyShip_dir);

			std::vector<Asteroids::Entity::EnemyShip*> FlyingSaucer;

			for (auto temp : models)
			{
				//Load file
				std::ifstream ifstream(util.buildPath(enemyShip_dir, temp));

				//
				std::string content;

				std::vector<Engine::Math::Vector2D> points;
				while (ifstream >> content)
				{
					//Read components
					std::stringstream lineStream(content);
					std::string cell;
					std::vector<float> components;

					while (std::getline(lineStream, cell, ','))
					{
						components.push_back(std::stof(cell));
					}
					//Adding points to vector
					points.push_back(Engine::Math::Vector2D(components[0], components[1]));
				}
				//Adding enemy ship to array
				FlyingSaucer.push_back(new Asteroids::Entity::EnemyShip(points));
				//FlyingSaucer[FlyingSaucer.size() - 1]->RandomTranslation();
			}
			std::cout << std::endl;
			return FlyingSaucer;
		}
	}
}