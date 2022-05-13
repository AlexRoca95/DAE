#include "pch.h"
#include "Game.h"
#include "Avatar.h"
#include "Helicopter.h"
#include "BulletManager.h"
#include "GameObjectManager.h"
#include "SoundManager.h"
#include "Soldier.h"
#include "Boss.h"
#include "HUD.h"
#include "Menu.h"
#include <iostream>


Game::Game( const Window& window ) 
	:m_Window{ window }
	, m_pCamera{ }
	, m_pLevel{ }
	, m_pAvatar{ }
	, m_pGameObjectManager{ }
	, m_pSoundManager{ new SoundManager() }
	, m_pMenu { }
	, m_GameState { GameState::menu }
{
	InitMenu();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_pLevel = new Level;

	InitAvatar();
	InitCamera();
	InitHUD();
	AddGameObjects();

	InitLevelSounds();

	
}

void Game::InitAvatar()
{
	m_pAvatar = new Avatar(m_pSoundManager);
	m_pAvatar->SetVerticesLevel(m_pLevel->GetVertices());
}

void Game::InitCamera()
{
	m_pCamera = new Camera(m_Window.width, m_Window.height);
	m_pCamera->SetLevelBoundaries(m_pLevel->GetBoundaries());

}

void Game::InitHUD()
{
	// Bottom left and size of the window
	m_pHUD = new HUD(Point2f{ }, Point2f{ m_Window.width, m_Window.height } ); 
}

void Game::InitMenu()
{
	m_pMenu = new Menu( Point2f{m_Window.width, m_Window.height} );

	m_pMenuSong = m_pSoundManager->GetSound("Resources/Sounds/MenuSoundtrack.mp3");

	m_pMenuSong->Play(true);
}

void Game::InitLevelSounds()
{
	
	m_pLevelSong = m_pSoundManager->GetSound("Resources/Sounds/Soundtrack.mp3");
	m_pPistolFire = m_pSoundManager->GetEffect("Resources/Sounds/PistolFire.wav");
	m_pMissionStartSound = m_pSoundManager->GetEffect("Resources/Sounds/MissionStart.mp3");
	 
	// Stop the menu song and start the level song
	m_pMenuSong->Stop();
	m_pLevelSong->Play(true); 

	m_pMissionStartSound->Play(0);  

	
	if (!m_pSoundManager->GetSoundActivated())
	{
		// If the sound was disabled dont play it yet
		m_pLevelSong->Pause();
	}
	
}

void  Game::AddGameObjects()
{
	m_pGameObjectManager = new GameObjectManager(m_pSoundManager);

	// Helicoperts
	m_pGameObjectManager->AddGameObject(Point2f{ g_Stage2Pos * g_Scale, 700.f }, GameObject::Type::helicopter, false);
	m_pGameObjectManager->AddGameObject(Point2f{ g_Stage3Pos * g_Scale, 700.f }, GameObject::Type::helicopter, false);

	// Normal Soldiers
	m_pGameObjectManager->AddGameObject(Point2f{ 800.f * g_Scale, 160.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 980.f * g_Scale, 280.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 1400 * g_Scale, 160.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 1450 * g_Scale, 280.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 2110 * g_Scale, 300.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 2150 * g_Scale, 160.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 2600 * g_Scale, 160.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 2620 * g_Scale, 160.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 3550 * g_Scale, 300.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 3480 * g_Scale, 280.f }, GameObject::Type::soldier, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 3650 * g_Scale, 455.f }, GameObject::Type::soldier, true);


	// Shield soldiers
	m_pGameObjectManager->AddGameObject(Point2f{ 1480 * g_Scale, 160.f }, GameObject::Type::soldierShield, false);
	m_pGameObjectManager->AddGameObject(Point2f{ 1700 * g_Scale, 160.f }, GameObject::Type::soldierShield, false);
	m_pGameObjectManager->AddGameObject(Point2f{ 2500 * g_Scale, 160.f }, GameObject::Type::soldierShield, false);

	// Prisoners
	m_pGameObjectManager->AddGameObject(Point2f{ 450.f * g_Scale, 156.f }, GameObject::Type::prisoner, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 1430.f * g_Scale, 280.f}, GameObject::Type::prisoner, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 1125.f * g_Scale, 170.f }, GameObject::Type::prisoner, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 2450.f * g_Scale, 390.f }, GameObject::Type::prisoner, true);
	m_pGameObjectManager->AddGameObject(Point2f{ 3970.f * g_Scale, 690.f }, GameObject::Type::prisoner, true);
	
	// Boss 
	m_pGameObjectManager->AddGameObject(Point2f{ 4022.f * g_Scale, 390.f }, GameObject::Type::boss, true);
}



void Game::Cleanup( )
{
	// Delete according in the state the player is
	switch (m_GameState)
	{
		case Game::GameState::menu:
			delete m_pMenu;
			break;
		case Game::GameState::playing:
			delete m_pAvatar;
			delete m_pLevel;
			delete m_pCamera;
			delete m_pGameObjectManager;
			delete m_pHUD;
			break;
		case Game::GameState::gameOver:
			delete m_pAvatar;
			delete m_pLevel;
			delete m_pCamera;
			delete m_pGameObjectManager;
			delete m_pHUD;
			break;
	}

	delete m_pSoundManager;
}

void Game::Update( float elapsedSec )
{
	switch (m_GameState)
	{
	case Game::GameState::menu:
		m_pMenu->Update(elapsedSec, m_GameState);

		if ( m_pMenu->GetStartPlaying() )
		{
			// Start playing --> Init all data needed
			Initialize();
			delete m_pMenu;
		}
		break;
	case Game::GameState::playing:
		UpdatePlaying(elapsedSec);
		break;
	case Game::GameState::gameOver:
		break;
	}
}

void Game::UpdatePlaying(float elapsedSec)
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

	switch (m_GameState)
	{
	case Game::GameState::menu:
		m_pMenu->Draw();
		break;
	case Game::GameState::playing:
		DrawPlaying();
		break;
	case Game::GameState::gameOver:
		break;
	}
}

// Draw the Playing GAME STATE
void  Game::DrawPlaying() const
{
	glPushMatrix();

		m_pCamera->Transform(m_pAvatar->GetBotShape(), m_pAvatar->GetGameStage());

		m_pLevel->DrawBackground();

		m_pGameObjectManager->Draw();

		m_pAvatar->Draw();

		m_pLevel->DrawForeground();

		m_pGameObjectManager->DrawBoss();

	glPopMatrix();

	// HUD will always stay at a fixed position
	m_pHUD->Draw();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{

	switch (m_GameState)
	{
	case Game::GameState::menu:
		// Enter key --> Start Playing
		if (e.keysym.sym == SDLK_RETURN)
		{
			m_pMenu->SetPlaying(true);
		}
		break;
	case Game::GameState::playing:

		// X Key --> Shoot
		if (e.keysym.sym == SDLK_x)
		{
			m_pAvatar->Shoot();
			m_pSoundManager->PlaySoundEffect(m_pPistolFire, 0);
		}

		// I key --> Show controls game info at the console
		if (e.keysym.sym == SDLK_i)
		{
			DisplayControlsInfo();
		}

		break;
	case Game::GameState::gameOver:
		break;
	}


	if (e.keysym.sym == SDLK_p)
	{
		// Turn on / off the sound 
		m_pSoundManager->turnOnOffSound();
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
	std::cout << " - ENTER key --> Start the Game (Only for the Start Screen Menu)" << std::endl;

}

void Game::ClearBackground( ) const
{
	glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
