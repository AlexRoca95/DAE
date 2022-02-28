#include "pch.h"
#include "Game.h"
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

	// Polygon with 6 vertices
	std::vector <Point2f> surface;

	surface.push_back(Point2f{ m_Window.width / 2, 50.f });
	surface.push_back(Point2f{ m_Window.width - 150.f , 150.f });
	surface.push_back(Point2f{ m_Window.width - 150.f , 350.f });
	surface.push_back(Point2f{ m_Window.width / 2, 450.f });
	surface.push_back(Point2f{ 150.f, 350.f });
	surface.push_back(Point2f{ 150.f, 150.f });

	utils::SetColor(Color4f{0.f, 0.f, 0.f, 1.0f});
	utils::FillPolygon(surface);

	// Draw lines around surface
	utils::SetColor(Color4f{ 0.84f, 0.61f, 0.47f, 1.0f });
	utils::DrawLine(surface[0], surface[1], 5.f);
	utils::DrawLine(surface[1], surface[2], 5.f);
	utils::DrawLine(surface[2], surface[3], 5.f);
	utils::DrawLine(surface[3], surface[4], 5.f);
	utils::DrawLine(surface[4], surface[5], 5.f);
	utils::DrawLine(surface[5], surface[0], 5.f);


	// The ray
	Point2f p1{ m_Window.width / 2, m_Window.height / 2 };
	utils::SetColor(Color4f{ 1.f, 1.f, 0.f, 1.0f });
	utils::DrawLine(p1, m_MousePos);


	// The raycast
	utils::HitInfo hitInfo{}; // Will hold info about the intersection point
	if (utils::Raycast(surface, p1, m_MousePos, hitInfo)) 
	{
		// Hitpoint
		utils::SetColor(Color4f{ 1.f, 1.f, 1.f, 1.0f });
		utils::FillEllipse(hitInfo.intersectPoint, 5.f, 5.f);

		//Normal
		utils::SetColor(Color4f{ 0.f, 1.f, 1.f, 1.0f });
		DrawVector(hitInfo.intersectPoint, hitInfo.normal * 30.f);

		// Reflect
		utils::SetColor(Color4f{ 1, 1, 1, 1 });
		Vector2f ray{ p1, m_MousePos };
		Vector2f reflectedRay{ ray.Reflect(hitInfo.normal) };
		DrawVector(hitInfo.intersectPoint, reflectedRay * (1 - hitInfo.lambda));
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
	glClearColor( 0.70f, 0.70f, 0.7f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}


void Game::DrawVector(const Point2f& pos, const Vector2f& v) const
{

	utils::DrawLine(pos.x, pos.y, pos.x + v.x, pos.y + v.y);

}
