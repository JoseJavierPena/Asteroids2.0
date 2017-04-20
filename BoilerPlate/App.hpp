#pragma once
#ifndef APP_HPP
#define APP_HPP

// C++ STL
#include <string>
#include <list>
#include <vector>

//
#include <random>
#include <algorithm>

// Asteroids
#include "SDLEvent.hpp"
#include "TimeManager.hpp"
#include "ship.hpp"
#include "Load.hpp"
#include "Asteroide.hpp"
#include "Draw.hpp"
#include "Bala.hpp"
#include "EnemyShip.hpp"
#include "MathUtils.hpp"

namespace Engine
{
	class App : public SDLEvent
	{
	public:
		/* =============================================================
		* ENUMERATORS
		* ============================================================= */
		struct GameState
		{
			enum State
			{
				UNINITIALIZED = 0,
				INIT_FAILED = 1,
				INIT_SUCCESSFUL = 2,
				RUNNING = 4,
				PAUSED = 8,
				QUIT = 16
			};
		};

		/* =============================================================
		 * PUBLIC FUNCTIONS
		 * ============================================================= */
		App( const std::string& title, const int width, const int height );
		~App( );
		void Execute						( );
		bool Init							( );
		void Update							( );
		void Render							( );
		int Index;
		std::vector<ship> Ship;
		std::vector<Asteroide*> Ast;
	private:
		/* =============================================================
		 * PRIVATE FUNCTIONS
		 * ============================================================= */
		bool SDLInit						( );
		bool GlewInit						( );
		void SetupViewport					( );
		void CleanupSDL						( );
		void OnResize						( int width, int height ) override;
		void OnExit							( ) override;
		void OnKeyDown						( SDL_KeyboardEvent keyBoardEvent ) override;
		void OnKeyUp						( SDL_KeyboardEvent keyBoardEvent ) override;
		void CheckColliding					( );
		void CheckLive						( );
		void CheckAst						( );


		/* =============================================================
		 * MEMBERS
		 * ============================================================= */
		int									m_width;
		int									m_height;
		int									m_nUpdates;
		double								m_lastFrameTime;
		std::string							m_title;
		SDL_Window*							m_mainWindow;
		SDL_GLContext						m_context;
		GameState::State					m_state;
		Engine::TimeManager*				m_timer;
		std::vector<ship>				    ShipVidas;
		int									CantVidas;
		EnemyShip							enemy;
		int									Score;
		bool								Entro;
		int									Time;
		int									RespawnTime;
		bool								EnterColliding;
		int									CantAsteroides;
	};
}
#endif /* APP_HPP */