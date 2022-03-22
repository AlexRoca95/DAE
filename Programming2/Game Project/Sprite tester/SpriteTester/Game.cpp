#include "pch.h"
#include "Game.h"
#include <iostream>

Game::Game( const Window& window )
	:m_Window{ window }
	, m_AccuSec{}
	, m_CurFrame{}
	, m_SrcRect{}
	, m_DestRect{}
	, m_BgColor{ 0.89f, 0.89f, 0.89f, 1.0f }
	, m_ShowInfo{ true }

	// TODO: Adapt following initialization to your sprite properties
	, m_Texture{ "Resources/MarcoLegs.png" }
	, m_SpriteSheetLeft{0.0f}
	, m_SpriteSheetTop{ 25.f }
	, m_SpriteSheetWidth{360.f }
	, m_SpriteSheetHeight{ 19.f }
	, m_Cols{ 12 }
	, m_Rows{ 1 }
	, m_FramesPerSec{ 10 }
	, m_Scale{ 1.f }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_FrameTime = 1.0f / m_FramesPerSec;

	InitSourceRect( );
	InitDestinationRect( );

	ShowInfo( );
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	UpdateSprite( elapsedSec );
}


void Game::Draw( ) const
{
	ClearBackground( );
	DrawSprite( );
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	// Handle keys for framerate and help
	switch ( e.keysym.sym )
	{
	case SDLK_UP:
		ChangeFrameRate( false );
		break;
	case SDLK_DOWN:
		if ( m_FramesPerSec > 1 )
		{
			ChangeFrameRate( true );
		}
		break;
	case SDLK_h:
		m_ShowInfo = !m_ShowInfo;
		ShowInfo( );
		break;
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ClearBackground( ) const
{
	glClearColor( m_BgColor.r, m_BgColor.g, m_BgColor.b, m_BgColor.a );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::UpdateSprite( float elapsedSec )
{
	// Update current frame number
	m_AccuSec += elapsedSec;
	if ( m_AccuSec > m_FrameTime )
	{
		++m_CurFrame %= ( m_Cols * m_Rows );
		m_AccuSec -= m_FrameTime;
		UpdateSourceRect( );
	}

	// Handle keys for scaling
	const Uint8 * pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_PAGEUP] )
	{
		ChangeScale( true, elapsedSec );
	}
	if ( pStates[SDL_SCANCODE_PAGEDOWN] )
	{
		ChangeScale( false, elapsedSec );
	}
}

void Game::DrawSprite( ) const
{
	m_Texture.Draw( m_DestRect, m_SrcRect );
}


void Game::ChangeFrameRate( bool lower )
{
	if ( lower )
	{
		--m_FramesPerSec;
	}
	else
	{
		++m_FramesPerSec;
	}
	m_FrameTime = 1.0f / m_FramesPerSec;
	ShowInfo( );
}

void Game::ChangeScale( bool zoomIn, float elapsedSec )
{
	const float scaleSpeed{ 2 };
	if ( zoomIn )
	{
		m_Scale *= 1 + scaleSpeed * elapsedSec;
	}
	else
	{
		m_Scale /= 1 + scaleSpeed * elapsedSec;
	}
	ShowInfo( );

	InitDestinationRect( );
}


void Game::InitDestinationRect( )
{
	m_DestRect.width = m_SpriteSheetWidth / m_Cols * m_Scale;
	m_DestRect.height = m_SpriteSheetHeight / m_Rows * m_Scale;
	m_DestRect.left = ( m_Window.width - m_DestRect.width ) / 2;
	m_DestRect.bottom = ( m_Window.height - m_DestRect.height ) / 2;
}

void Game::InitSourceRect( )
{
	m_SrcRect.width = m_SpriteSheetWidth / m_Cols;
	m_SrcRect.height = m_SpriteSheetHeight / m_Rows;
	UpdateSourceRect( );
}

void Game::UpdateSourceRect( )
{
	m_SrcRect.left = m_SpriteSheetLeft + m_CurFrame % m_Cols * m_SrcRect.width;
	m_SrcRect.bottom = m_SpriteSheetTop + ( m_CurFrame / m_Cols + 1 )* m_SrcRect.height;
}

void Game::ShowInfo( ) const
{
	if ( m_ShowInfo )
	{
		std::cout << "h: Show/hide info\n";
		std::cout << "Up/Down : Change frame rate (" << m_FramesPerSec << ")\n";
		std::cout << "Page up/down: Change scale (" << m_Scale << ")\n\n";
	}
}

