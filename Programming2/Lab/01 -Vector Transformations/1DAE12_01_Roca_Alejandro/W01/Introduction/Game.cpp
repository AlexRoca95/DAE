#include "pch.h"
#include "Game.h"
#include "Ball.h"
#include "Texture.h"
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
	
	Point2f center{ 20.f, 100.f };
	Vector2f vel{ 50.f, 80.f };
	Color4f color{ 0.84f, 0.68f, 0.32f, 1.f };
	float radius{ 20.f };

	Ball* ball1 = new Ball(center, vel, color, radius);

	center.x = 50.f;
	vel.y = 100.f;
	vel.x = 120.f;
	color.r = 1.f;
	color.g = 0.5f;
	radius = 40.f;
	Ball* ball2 = new Ball(center, vel, color, radius);

	m_pBallArray[0] = ball1;
	m_pBallArray[1] = ball2;

	LoadResources();

}

void Game::LoadResources()
{
	// Load resource into the texture
	m_pDAEImage = new Texture("Resources/DAE.png");

	m_pText = new Texture("Hello World!", "Resources/DIN-Light.otf", 48, Color4f{ 1,1,1,1 });

	m_Knight.texture = new Texture("Resources/RunningKnight.png");


	m_Knight.cols = 8;
	m_Knight.frames = 8;				// Number of frames for the animation
	m_Knight.currentFrame = 0;
	m_Knight.frameTime = 1 / 10.f;		// Framerate for the animation	
	m_Knight.pos.x = 40.f;
	m_Knight.pos.y = 40.f;
	m_Knight.accumulatedTime = 0.f;

}

void Game::Cleanup( )
{
	
	for (int i{ 0 }; i < m_NrBalls; i++)
	{
		delete m_pBallArray[i];
		m_pBallArray[i] = nullptr;
	}
	
	delete m_pDAEImage;
	delete m_pText;
	delete m_Knight.texture;
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

	Rectf wind{ 0.f, 0.f, m_Window.width, m_Window.height };
	for (int i{ 0 }; i < m_NrBalls; i++)
	{
		m_pBallArray[i]->Update(elapsedSec, wind);
	}

	// Hold info about the elapsed time
	m_Knight.accumulatedTime += elapsedSec;

	// Check if the elapsed time is larger than the framerate (
	if (m_Knight.accumulatedTime > m_Knight.frameTime)
	{
		// Elapsed time more than framerate --> Next frame 
		++m_Knight.currentFrame %= m_Knight.frames;		// Check if we reach the limit of frames  (if so reset to 0)

		m_Knight.accumulatedTime -= m_Knight.frameTime; // Reset accumulatedTime so it counts again
	}

	MoveKnight(elapsedSec);

	
}

void Game::Draw( ) const
{
	ClearBackground( );

	for (int i{ 0 }; i < m_NrBalls; i++)
	{
		m_pBallArray[i]->Draw();
	}

	float separation{ 50.f };

	// Position of the texture
	Rectf dstRectangle{ separation, m_Window.height / 2, m_pDAEImage->GetWidth(), m_pDAEImage->GetHeight() };
	// Part of the texture drawing
	Rectf srcRectangle{ 0, 0, m_pDAEImage->GetWidth(), m_pDAEImage->GetHeight() };
	m_pDAEImage->Draw(dstRectangle, srcRectangle);

	
	for (int i{ 0 }; i < 3; i++)
	{

		m_pDAEImage->Draw(dstRectangle, srcRectangle);

		// Change pos adn width every iteration of the loop
		dstRectangle.left += separation + dstRectangle.width; 
		dstRectangle.width = dstRectangle.width / 3;
		

	}


	dstRectangle.bottom = m_Window.height - m_pDAEImage->GetHeight();
	dstRectangle.left = separation;
	dstRectangle.width = m_pText->GetWidth();
	dstRectangle.height = m_pText->GetHeight();
	m_pText->Draw(dstRectangle);

	DrawKnight();
	
}

void Game::DrawKnight() const
{
	// Part of the texture that corresponds with the current frame number
	Rectf srcRect{};

	srcRect.height = m_Knight.texture->GetHeight();
	srcRect.width = m_Knight.texture->GetWidth() / m_Knight.cols;
	srcRect.left = m_Knight.currentFrame * srcRect.width;
	srcRect.bottom = srcRect.height;

	float scale{ 5.0f };
	Rectf destRect{};

	destRect.left = m_Knight.pos.x;
	destRect.bottom = m_Knight.pos.y;
	destRect.width = srcRect.width * scale;
	destRect.height = srcRect.height * scale;
	m_Knight.texture->Draw(destRect, srcRect);
}

void Game::MoveKnight(float elapsedSec)
{

	m_Knight.pos.x += 100.f * elapsedSec;

	if (m_Knight.pos.x >= m_Window.width)
	{
		m_Knight.pos.x = 5.f;
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
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
