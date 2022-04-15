#include "pch.h"
#include "Game.h"
#include "Avatar.h"
#include "Helicopter.h"
#include "BulletManager.h"
#include "EnemiesManager.h"
#include <iostream>



Game::Game( const Window& window ) 
	:m_Window{ window }
	, m_Camera{ new Camera(m_Window.width, m_Window.height) }
	, m_Level{ new Level }
	, m_Avatar{ new Avatar }
	, m_pEnemiesManager { new EnemiesManager }
	, m_NrHelicopters{ 1 }
	, m_GameState { GameState::start }
{
	Initialize( );

}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	InitAvatar();
	InitCamera();
	InitEnemiesManager();

}

void Game::InitAvatar()
{
	
	m_pGameObjects.push_back(m_Avatar);
	m_Avatar->SetVerticesLevel(m_Level->GetVertices());

}

void Game::InitCamera()
{
	m_Camera->SetLevelBoundaries(m_Level->GetBoundaries());

}

void  Game::InitEnemiesManager()
{
	
	m_pEnemiesManager->AddEnemy(Point2f{ g_Stage2Pos * g_Scale, 700.f }, GameObject::Type::enemyHelicopter);
	m_pEnemiesManager->AddEnemy(Point2f{ g_Stage3Pos * g_Scale, 700.f }, GameObject::Type::enemyHelicopter);

	m_pEnemiesManager->SetVerticesLevel(m_Level->GetVertices());
}



void Game::Cleanup( )
{
	for (GameObject* ptr : m_pGameObjects)
	{
		delete ptr;
	}

	m_pGameObjects.clear();  // Remove all elements from the vector

	delete m_Level;
	delete m_Camera;
	delete m_pEnemiesManager;
}

void Game::Update( float elapsedSec )
{
	/*
	for (GameObject* ptr : m_pGameObjects)
	{
		ptr->Update(elapsedSec, m_Level);
	}
	*/

	m_Avatar->Update(elapsedSec, m_Level, m_Camera->GetCameraPos());


	m_pEnemiesManager->Update(elapsedSec, m_Avatar);

	m_Avatar->GetBullets()->CheckHitEnemies(m_pEnemiesManager->GetEnemies());

	m_Level->Update(elapsedSec, m_Avatar->GetBotShape());

	m_Camera->SetLevelBoundaries(m_Level->GetBoundaries());


}


void Game::Draw( ) const
{
	ClearBackground( );

	glPushMatrix();
	
		m_Camera->Transform(m_Avatar->GetBotShape(), m_Avatar->GetGameStage() );
	
		m_Level->DrawBackground();
		
		m_pEnemiesManager->Draw();

		// Draw all game objects
		for (GameObject* ptr : m_pGameObjects)
		{
			ptr->Draw();
		}
		
		m_Level->DrawForeground();

	glPopMatrix();


}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{

	if (e.keysym.sym == SDLK_x)
	{
		m_Avatar->Shoot();
	}
	
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}

	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
