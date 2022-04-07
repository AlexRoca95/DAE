#include "pch.h"
#include "Game.h"
#include "Avatar.h"


Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_Camera{m_Window.width, m_Window.height}
	, m_Scale{2.7f}
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
}

void Game::InitAvatar()
{
	m_Avatar = new Avatar();
	m_pGameObjects.push_back(m_Avatar);

}

void Game::InitCamera()
{
	m_Camera.SetLevelBoundaries(m_Level.GetBoundaries());

}

void Game::Cleanup( )
{

	for (GameObject* ptr : m_pGameObjects)
	{
		delete ptr;
	}

	m_pGameObjects.clear();  // Remove all elements from the vector

}

void Game::Update( float elapsedSec )
{
	
	for (GameObject* ptr : m_pGameObjects)
	{
		ptr->Update(elapsedSec, m_Level);
	}
	
	m_Level.Update(elapsedSec, m_Avatar->GetShape());
	m_Camera.SetLevelBoundaries(m_Level.GetBoundaries());
}

void Game::Draw( ) const
{
	ClearBackground( );

	glPushMatrix();
	
	m_Camera.Transform(m_Avatar->GetShape());
	
	m_Level.DrawBackground();
	
	// Draw all game objects
	for (GameObject* ptr : m_pGameObjects)
	{
		ptr->Draw();
	}
	m_Level.DrawForeground();

	glPopMatrix();


}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
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
