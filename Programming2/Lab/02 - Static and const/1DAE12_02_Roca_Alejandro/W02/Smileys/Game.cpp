#include "pch.h"
#include "Game.h"
#include "Smiley.h"
#include "utils.h"
#include <iostream>

Game::Game( const Window& window ) 
	:m_Window{ window },
	g_HighestSmiley{ -1}
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	
	CreateSmileys();

	// Initialize the safe area
	m_SafeArea.left = 30.f;
	m_SafeArea.bottom = 30.f;
	m_SafeArea.width = m_Window.width - m_SafeArea.left * 2;
	m_SafeArea.height = m_Window.height - m_SafeArea.bottom*2;

}

void Game::Cleanup( )
{
	DeleteSmileys();
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

	UpdateSmileys(elapsedSec);
	CheckHighest();

}

void Game::Draw( ) const
{
	ClearBackground( );

	DrawSmileys();

	
	utils::SetColor(Color4f{ 0.f, 0.f, 0.f, 1.f });
	utils::DrawRect(m_SafeArea);
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	switch ( e.keysym.sym )
	{
	
	case SDLK_UP:
		IncreaseSmileySpeed();
		break;
	case SDLK_DOWN:
		DecreaseSmileySpeed();
		break;

	case SDLK_DELETE:
		DeleteSleepers();
		break;
	}
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
		HitSmileys(Point2f{ float(e.x), float(e.y) });
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

void Game::CreateSmileys()
{
	const float separation = 30.f;

	Point2f position{ separation, (m_Window.height / 2) - 25.f };
	
	for (int i{ 0 }; i < m_NrSmileys; i++)
	{
		m_pSmileys[i] = new Smiley(position);

		position.x += 50.f + separation;
	}

}

void Game::DeleteSmileys()
{
	for (int i{ 0 }; i < m_NrSmileys; i++)
	{
		// Check if has not been already deleted
		if (m_pSmileys[i] != nullptr)
		{
			delete m_pSmileys[i];
			m_pSmileys[i] = nullptr;
		}
	}
	
}

void Game::DrawSmileys() const
{

	for (int i{ 0 }; i < m_NrSmileys; i++)
	{
		if (m_pSmileys[i] != nullptr)
		{
			m_pSmileys[i]->Draw();
		}
	}

}

void Game::UpdateSmileys(float elapsedSec)
{
	Rectf boundingArea{ 0.f, 0.f, m_Window.width, m_Window.height };

	for (int i{ 0 }; i < m_NrSmileys; i++)
	{
		if (m_pSmileys[i] != nullptr)
		{
			m_pSmileys[i]->Update(elapsedSec, boundingArea, m_SafeArea);
		}
	}

}

void Game::CheckHighest()
{
	
	for (int i{ 0 }; i < m_NrSmileys; i++)
	{
		
		if (m_pSmileys[i] != nullptr && m_pSmileys[i]->IsSleeping() == false)
		{
			// Not sleeping

			if (g_HighestSmiley == -1)
			{
				// Store the index of the highest smiley
				m_pSmileys[i]->SetHighest(true);
				g_HighestSmiley = i;
			}
			else
			{
				// Check if we didn't delete the highest value
				if (m_pSmileys[g_HighestSmiley] == nullptr)
				{
					g_HighestSmiley = -1;
				}
				else
				{
					if (m_pSmileys[i]->GetPosition().y > m_pSmileys[g_HighestSmiley]->GetPosition().y)
					{
						// Set the new highest smiley
						m_pSmileys[g_HighestSmiley]->SetHighest(false);
						m_pSmileys[i]->SetHighest(true);
						g_HighestSmiley = i;

					}
				}
				
			}
		}

	}

}

void Game::HitSmileys(const Point2f& pos)
{
	for (int i{ 0 }; i < m_NrSmileys; i++)
	{
		if (m_pSmileys[i] != nullptr)
		{
			m_pSmileys[i]->HitTest(pos);
		}
	}

}

void Game::IncreaseSmileySpeed()
{
	for (int i{ 0 }; i < m_NrSmileys; i++)
	{
		if (m_pSmileys[i] != nullptr)
		{
			m_pSmileys[i]->IncreaseSpeed();
		}

	}

}

void Game::DecreaseSmileySpeed()
{
	for (int i{ 0 }; i < m_NrSmileys; i++)
	{
		if (m_pSmileys[i] != nullptr)
		{
			m_pSmileys[i]->DecreaseSpeed();
		}

	}

}

void Game::DeleteSleepers()
{

	for (int i{ 0 }; i < m_NrSmileys; i++)
	{
		
		if (m_pSmileys[i]!= nullptr && m_pSmileys[i]->IsSleeping() == true)
		{
			delete m_pSmileys[i];
			m_pSmileys[i] = nullptr;
		}
	}

}

void Game::ClearBackground( ) const
{
	glClearColor( 0.30f, 0.30f, 0.30f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
