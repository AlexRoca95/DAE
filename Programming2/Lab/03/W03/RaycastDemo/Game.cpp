#include "pch.h"
#include "Game.h"
#include "utils.h"
#include <iostream>

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
	
}

void Game::Cleanup( )
{
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
}

void Game::Draw( ) const
{
	ClearBackground( );

	// The surface
	Point2f surfPt1{ 350, 50 }, surfPt2{150, 250};
	utils::SetColor(Color4f{ 1.f, 0.5f, 0.2f, 1.0f });
	utils::DrawLine(surfPt1, surfPt2);

	// The ray
	Point2f p1{ 100, 40 }, p2{ 380, 180 };
	p2.x = m_MousePos.x;
	p2.y = m_MousePos.y;
	utils::SetColor(Color4f{ 1.f, 1.f, 0.f, 1.0f });
	utils::DrawLine(p1, p2);


	// Raycast (intersection)
	utils::HitInfo hitInfo{};
	std::vector<Point2f> surface{surfPt1, surfPt2};
	if (utils::Raycast(surface, p1, p2, hitInfo)) // hitInfo will hold the output of the function
	{
		// Draw the HitPoint (yellow) as circle
		utils::SetColor(Color4f(1, 1, 0, 1));
		utils::FillEllipse(hitInfo.intersectPoint, 4, 4);
		//std::cout << hitInfo.lambda << '\n';	 // Info about the intersection point


		// Normal
		utils::SetColor(Color4f(0, 1, 0, 1));
		DrawVector(hitInfo.intersectPoint, hitInfo.normal * 50);	 // Scale the normal so we can see it	

		// Reflect 
		utils::SetColor(Color4f{ 1, 1, 1, 1 });
		Vector2f ray{ p1, p2 };
		Vector2f reflectedRay{ ray.Reflect(hitInfo.normal) };
		DrawVector(hitInfo.intersectPoint, reflectedRay * (1 - hitInfo.lambda));

		// We can use it to calculate the new position after hitting the surface
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
	m_MousePos.x = float(e.x);
	m_MousePos.y = float(e.y);
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
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::DrawVector(const Point2f& pos, const Vector2f& v) const
{

	utils::DrawLine(pos.x, pos.y, pos.x + v.x, pos.y + v.y);

}
