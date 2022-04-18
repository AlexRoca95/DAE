#include "pch.h"
#include "Game.h"
#include "Avatar.h"
#include "Helicopter.h"
#include "BulletManager.h"
#include "GameObjectManager.h"
#include "Soldier.h"
#include <iostream>


Game::Game( const Window& window ) 
	:m_Window{ window }
	, m_pCamera{ new Camera( m_Window.width, m_Window.height ) }
	, m_pLevel{ new Level }
	, m_pAvatar{ new Avatar }
	, m_pGameObjectManager{ new GameObjectManager }
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
	AddGameObjects();

}

void Game::InitAvatar()
{
	m_pAvatar->SetVerticesLevel(m_pLevel->GetVertices());
}

void Game::InitCamera()
{

	m_pCamera->SetLevelBoundaries(m_pLevel->GetBoundaries());

}

void  Game::AddGameObjects()
{
	// Helicoperts
	m_pGameObjectManager->AddGameObject(Point2f{ g_Stage2Pos * g_Scale, 700.f }, GameObject::Type::helicopter, false);
	m_pGameObjectManager->AddGameObject(Point2f{ g_Stage3Pos * g_Scale, 700.f }, GameObject::Type::helicopter, false);

	// Soldiers
	m_pGameObjectManager->AddGameObject(Point2f{ 800.f * g_Scale, 160.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 980.f * g_Scale, 280.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 1400 * g_Scale, 160.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 1450 * g_Scale, 280.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 1480 * g_Scale, 160.f }, GameObject::Type::soldier, false);
	m_pGameObjectManager->AddGameObject(Point2f{ 1700 * g_Scale, 160.f }, GameObject::Type::soldier, false);
	m_pGameObjectManager->AddGameObject(Point2f{ 2110 * g_Scale, 300.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 2150 * g_Scale, 160.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 2500 * g_Scale, 160.f }, GameObject::Type::soldier, false);
	m_pGameObjectManager->AddGameObject(Point2f{ 2600 * g_Scale, 160.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 2620 * g_Scale, 160.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 3550 * g_Scale, 300.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 3480 * g_Scale, 280.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 3650 * g_Scale, 455.f }, GameObject::Type::soldier, true);

	// Prisoners
	m_pGameObjectManager->AddGameObject(Point2f{ 450.f * g_Scale, 156.f }, GameObject::Type::prisoner, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 1430.f * g_Scale, 280.f}, GameObject::Type::prisoner, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 1125.f * g_Scale, 170.f }, GameObject::Type::prisoner, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 2450.f * g_Scale, 390.f }, GameObject::Type::prisoner, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 3970.f * g_Scale, 690.f }, GameObject::Type::prisoner, true);

}



void Game::Cleanup( )
{
	
	delete m_pAvatar;
	delete m_pLevel;
	delete m_pCamera;
	delete m_pGameObjectManager;

}

void Game::Update( float elapsedSec )
{
	
	m_pAvatar->Update(elapsedSec, m_pLevel, m_pCamera->GetCameraPos());

	m_pGameObjectManager->Update(elapsedSec, m_pAvatar, m_pLevel, m_pCamera->GetCameraPos());

	m_pAvatar->GetBullets()->CheckHitGameObjects(m_pGameObjectManager->GetGameObjects());

	m_pLevel->Update(elapsedSec, m_pAvatar->GetBotShape());

	m_pCamera->SetLevelBoundaries(m_pLevel->GetBoundaries());

}


void Game::Draw( ) const
{
	ClearBackground( );

	glPushMatrix();
	
		m_pCamera->Transform(m_pAvatar->GetBotShape(), m_pAvatar->GetGameStage() );
	
		m_pLevel->DrawBackground();
		
		m_pGameObjectManager->Draw();

		m_pAvatar->Draw();
		
		m_pLevel->DrawForeground();

	glPopMatrix();

}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	// X Key --> Shoot
	if (e.keysym.sym == SDLK_x)
	{
		m_pAvatar->Shoot();
	}

	// I key --> Show controls game info at the console
	if (e.keysym.sym == SDLK_i)
	{
		DisplayControlsInfo();
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

// Show in the console all the information about the game control keys
void Game::DisplayControlsInfo()
{
	std::cout << std::endl;
	std::cout << "-- METAL SLUG GAME CONTROLS INFO -- " << std::endl;
	std::cout << std::endl;
	std::cout << " - Use the left, Right and Up Arrow Keys to move the avatar throw the level." << std::endl;
	std::cout << " - Down Arrow key --> Avatar starts crawling. " << std::endl;
	std::cout << " - C key --> Jump." << std::endl;
	std::cout << " - X key --> Shoot." << std::endl;

}

void Game::ClearBackground( ) const
{
	glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
