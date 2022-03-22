#include "pch.h"
#include "Game.h"
#include "utils.h"
#include <vector>
#include "Matrix2x3.h"
#include <iostream>

Game::Game( const Window& window ) 
	:m_Window{ window },
	m_Width{48.f},
	m_Height{48.f},
	m_Angle{0},
	m_Scale{1},
	m_Translation{Point2f{m_Width/2, m_Height / 2}},
	m_Clicked{false}
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_Vertices.push_back(Point2f{ m_Width / 2, 0.f });
	m_Vertices.push_back(Point2f{ 0.f, m_Height/2 });
	m_Vertices.push_back(Point2f{ m_Width / 2, m_Height });
	m_Vertices.push_back(Point2f{ m_Width, m_Height / 2 });

}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	// Check keyboard state
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_A] )
	{
		m_Angle += 60 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_D])
	{
		m_Angle -= 60 * elapsedSec;
	}

	if ( pStates[SDL_SCANCODE_W])
	{
		m_Scale *= 1 + 3 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_S])
	{
		m_Scale /= 1 + 3 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_LEFT])
	{
		m_Translation.x -= 120 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_RIGHT])
	{
		m_Translation.x += 120 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_UP])
	{
		m_Translation.y += 120 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_DOWN])
	{
		m_Translation.y -= 120 * elapsedSec;
	}


	//m_Clicked = utils::IsPointInPolygon(m_Mouse, m_Vertices);

}

void Game::Draw( ) const
{
	ClearBackground( );

	if (m_Clicked)
	{
		utils::SetColor(Color4f{ 1.0f, 0.0f, 0.f, 1.0f });
	}
	else
	{
		utils::SetColor(Color4f{ 0.0f, 0.0f, 1.f, 1.0f });
	}
	

	// Using OpenGl to transform the polygon
	//DrawPolyOpenGl();
	DrawPolyMatrix2x3();
}

void Game::DrawPolyOpenGl() const
{
	glPushMatrix();
	{
		glTranslatef(m_Translation.x, m_Translation.y, 0.f);
		glRotatef(m_Angle, 0.f, 0.f, 1.f);
		glScalef(m_Scale, m_Scale, 1.f);
		glTranslatef(-m_Width / 2, -m_Height / 2, 0.f);  // Rotates around its center
		utils::DrawPolygon(m_Vertices);
	}
	glPopMatrix();
}

void Game::DrawPolyMatrix2x3() const
{
	//utils::DrawPolygon(m_Vertices);

	Matrix2x3 matTranslate, matRotate, matScale, matCenter;  // Transformation matrices
	Matrix2x3 matWorld;  // Resulting matrix with all the transformations

	matTranslate.SetAsTranslate(m_Translation.x, m_Translation.y); // Translation matrix
	matRotate = Matrix2x3::CreateRotationMatrix(m_Angle);
	matScale.SetAsScale(m_Scale);
	matCenter = Matrix2x3::CreateTranslationMatrix(-m_Width / 2, -m_Height / 2); // Center of the polygon

	// TRS Transformation
	matWorld = matTranslate * matRotate * matScale * matCenter;

	std::vector<Point2f> transformedVerts;
	transformedVerts = matWorld.Transform(m_Vertices);

	utils::DrawPolygon(transformedVerts);


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
		m_Mouse.x = float(e.x);
		m_Mouse.y = float(e.y);
		
		if (utils::IsPointInPolygon(m_Mouse, m_Vertices))
		{

			if (m_Clicked)
			{
				m_Clicked = false;
			}
			else
			{
				m_Clicked = true;
			}
			
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
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
