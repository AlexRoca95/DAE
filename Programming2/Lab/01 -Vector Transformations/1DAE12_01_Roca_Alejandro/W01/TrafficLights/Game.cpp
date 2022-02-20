#include "pch.h"
#include "Game.h"
#include "TrafficLight.h"
#include "utils.h"
#include <iostream>

Game::Game( const Window& window ) 
	:m_Window{ window },
	m_Click{ false },
	m_MousePos{Point2f{}}

{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	const float separation{ 10.f };
	const float initPosX{ separation };
	Point2f trafficLightPos{ initPosX, m_Window.height - 220.f };
	
	
	for (int i{ 0 }; i < m_NrTrafficLights; i++)
	{
		if (i == m_NrTrafficLights / 2)
		{
			trafficLightPos.y -= m_pTrafficLights[i-1]->getHeight() + separation;
			trafficLightPos.x = initPosX;
 		}
		m_pTrafficLights.push_back(new TrafficLight(trafficLightPos));

		trafficLightPos.x += m_pTrafficLights[i]->getWidth() + separation;

	}

}

void Game::Cleanup()
{
	for (int i{ 0 }; i < m_pTrafficLights.size(); i++)
	{
		delete m_pTrafficLights[i];
		m_pTrafficLights[i] = nullptr;
	}

}

void Game::Update( float elapsedSec )
{

	for (int i{ 0 }; i < m_pTrafficLights.size(); i++)
	{
		m_pTrafficLights[i]->Update(elapsedSec);
	}

}

void Game::Draw( ) const
{
	ClearBackground( );

	for (int i{ 0 }; i < m_pTrafficLights.size(); i++)
	{
		m_pTrafficLights[i]->Draw();
	}
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
	
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		m_Click = true;
		m_MousePos.x = float(e.x);
		m_MousePos.y = float(e.y);
		for (int i{ 0 }; i < m_pTrafficLights.size(); i++)
		{
			m_pTrafficLights[i]->DoHitTest(m_MousePos);
		}
		
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

void Game::ClearBackground( ) const
{
	glClearColor( 0.6f, 0.6f, 0.6f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
