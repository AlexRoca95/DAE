#include "pch.h"
#include "Game.h"
#include "SoundStream.h"
#include <iostream>

Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_StreamMenuText{ "Resources/Images/StreamsMenu.png" }
	,m_EffectMenuText { "Resources/Images/EffectsMenu.png" }
	,m_StreamTest {true}
	// TODO: 1. Create the DonkeyKong and Mario SoundStream objects
	,m_DonkeySong{"Resources/sounds/DonkeyKong.mp3"}
	,m_MarioSong{ "Resources/sounds/Mario.mp3" }
	// TODO: 4. Create the Laser and Jingles SoundEffect objects
	,m_LaserEffect{ "Resources/sounds/laser.ogg" }
	,m_JinglesEffect{ "Resources/sounds/jingles.ogg" }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
}

void Game::Draw( ) const
{
	ClearBackground( );
	DrawMenu( );
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	switch ( e.keysym.sym )
	{
	case SDLK_RIGHT:
	case SDLK_LEFT:
		SwitchTest( );
		break;
	default:
		// Handle user request
		if ( m_StreamTest )
		{
			TestStreams( e );
		}
		else
		{
			TestEffects( e );
		}
	}
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
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
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::DrawMenu( ) const
{
	if ( m_StreamTest )
	{
		m_StreamMenuText.Draw( );
	}
	else
	{
		m_EffectMenuText.Draw( );
	}
}

void Game::SwitchTest( )
{
	if ( m_StreamTest )
	{
		// TODO: 3. User switches to the "Effect test", stop the music
		if (m_DonkeySong.IsPlaying())
		{
			m_DonkeySong.Stop();
		}

		if (m_MarioSong.IsPlaying())
		{
			m_MarioSong.Stop();
		}
	}
	else
	{
		// TODO: 6. User switches to the "Stream test", stop the effects
		m_LaserEffect.StopAll();
	}
	m_StreamTest = !m_StreamTest;
}

void Game::TestStreams( const SDL_KeyboardEvent& e )
{
	// TODO: 2. Handle the user requests in the "Stream test" menu 
	switch ( e.keysym.sym )
	{
	case SDLK_1:
	case SDLK_KP_1:
		// Play Donkey Kong (repeated)
		m_DonkeySong.Play(true);		// Play and repeat
		break;
	case SDLK_2:
	case SDLK_KP_2:
		// Play Mario (not repeated)
		m_MarioSong.Play(false);		// Play and not repeat
		break;
	case SDLK_p:
		// Pause the SoundStream
		if (m_MarioSong.IsPlaying())
		{
			m_MarioSong.Pause();
		}

		if (m_DonkeySong.IsPlaying())
		{
			m_DonkeySong.Pause();
		}
		break;
	case SDLK_r:
		// Resume the SoundStream
		if (m_MarioSong.IsPlaying())
		{
			m_MarioSong.Resume();
		}

		if (m_DonkeySong.IsPlaying())
		{
			m_DonkeySong.Resume();
		}
		break;
	case SDLK_s:
		// Stop the SoundStream
		if (m_MarioSong.IsPlaying())
		{
			m_MarioSong.Stop();
		}

		if (m_DonkeySong.IsPlaying())
		{
			m_DonkeySong.Stop();
		}
		break;
	case SDLK_UP:
		// Increase volume of SoundStream
		m_DonkeySong.SetVolume(m_DonkeySong.GetVolume() + 10);
		m_MarioSong.SetVolume(m_MarioSong.GetVolume() + 10);
		break;
	case SDLK_DOWN:
		// Decrease volume of SoundStream
		m_DonkeySong.SetVolume(m_DonkeySong.GetVolume() - 10);
		m_MarioSong.SetVolume(m_MarioSong.GetVolume() - 10);
		break;
	}
}

void Game::TestEffects( const SDL_KeyboardEvent& e )
{
	// TODO: 5. Handle the user requests in the "Effect test" menu 
	switch ( e.keysym.sym )
	{
	case SDLK_1:
	case SDLK_KP_1:
		// Play laser (repeated)
		m_LaserEffect.Play(2);
		break;
	case SDLK_2:
	case SDLK_KP_2:
		// Play jingles (a number of times)
		m_JinglesEffect.Play(4);
		break;
	case SDLK_p:
		// Pause all soundEffects
		m_JinglesEffect.PauseAll();
		break;
	case SDLK_r:
		// Resume all soundEffects
		m_LaserEffect.ResumeAll();
		break;
	case SDLK_s:
		// Stop  all soundEffects
		m_LaserEffect.StopAll();
		break;
	case SDLK_UP:
		// Increase volume of all SoundEffects
		
		m_LaserEffect.SetVolume(m_LaserEffect.GetVolume() + 10);
		m_JinglesEffect.SetVolume(m_JinglesEffect.GetVolume() + 10);
		break;
	case SDLK_DOWN:
		// Decrease volume of all SoundEffects
		m_LaserEffect.SetVolume(m_LaserEffect.GetVolume() - 10);
		m_JinglesEffect.SetVolume(m_JinglesEffect.GetVolume() - 10);
		break;
	}
}

