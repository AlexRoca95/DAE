#include "pch.h"
#include "Game.h"
#include "Enemy.h"
#include "Avatar.h"
#include "utils.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	
	CreateEnemies();
	CreateAvatar();

}

void Game::Cleanup( )
{
	DeleteEnemies();
	delete m_pAvatar;
	m_pAvatar = nullptr;
}

void Game::Update( float elapsedSec )
{
	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}

	m_pAvatar->Update(elapsedSec, *m_pEnemies, m_NrEnemies);

}

void Game::Draw( ) const
{
	ClearBackground( );

	DrawEnemies();
	DrawAvatar();
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
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
	
		break;
	}
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


void Game::CreateEnemies()
{
	float width{ 35.f };
	float height{ 35.f };
	int idx{ 0 };
	float separation{ 10.f };
	float initialX{ separation + width };
	float initialY{ separation };

	Point2f centerEnemy{ initialX , m_Window.height - initialY };

	for (int i{ 0 }; i < m_NrEnemies / 10; i++)
	{
		for (int j{ 0 }; j < m_NrEnemies / 4; j++)
		{
			idx = GetIndex(i, j, m_NrEnemies / 4);
			m_pEnemies[idx] = new Enemy(centerEnemy, width, height);
			centerEnemy.x += initialX;
		}

		centerEnemy.x = initialX;
		centerEnemy.y -= initialY + height;

	}

}

void Game::CreateAvatar()
{
	float width{ 40.f };
	float height{ 40.f };
	Point2f center{ (m_Window.width / 2) - (width / 2), height };

	Rectf boundaries{ 0.f, 0.f, m_Window.width, m_Window.height };
	m_pAvatar = new Avatar(center, width, height);
	m_pAvatar->SetBoundaries(boundaries);
}

// Get the index of the 2D array
int Game::GetIndex(int rowIdx, int colIdx, int nrCols)
{
	int idx{};

	idx = rowIdx * nrCols + colIdx;

	return idx;
}

void Game::DeleteEnemies()
{

	for (int i{ 0 }; i < m_NrEnemies; i++)
	{
		delete m_pEnemies[i];
		m_pEnemies[i] = nullptr;
	}

}
void Game::DrawEnemies() const
{

	for (int i{ 0 }; i < m_NrEnemies; i++)
	{
		m_pEnemies[i]->Draw();
	}

}

void Game::DrawAvatar() const
{
	m_pAvatar->Draw();
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
