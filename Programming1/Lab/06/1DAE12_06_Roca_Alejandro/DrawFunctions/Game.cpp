#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	
	g_YPosGrad = (g_WindowHeight/2) + 30;

}

void Draw()
{
	ClearBackground();

	// Concentric squares
	float outermostSize = 80.f;  // Size of the outer square
	float size = outermostSize;  // Reference size for calculating the Y pos for all rectangles
	int amount{ 10 };			 // Amount of rectangles to draw
	Point2f pos{ pos.x = g_Border, pos.y = g_WindowHeight - g_Border - size};

	for (int i = 0; i < 3; i++)
	{
		DrawSquares(pos, outermostSize, amount);

		pos.x += outermostSize + g_Border; 
		amount = int(amount / 1.5f);
		outermostSize /= 1.5f;
	}


	// Equilateral triangles
	float length{ 60.f };
	bool filled = true;
	Point2f posVert{ posVert.x = g_WindowWidth / 2, posVert.y = g_WindowHeight - g_Border - size };

	for (int i = 0; i < 3; i++)
	{
		//DrawEquilateralTriangle(posVert, length, filled);

		//posVert.x += 5;
		//posVert.y += 5;
		//length -= 5;

	}

	//Linear Gradient
	Point2f leftPos{ leftPos.x = g_Border, leftPos.y = g_YPosGrad };
	float width = 40;
	float height = 15;
	Color4f colorL{ colorL.r = 1.0f, colorL.g = 0.f, colorL.b = 1.0f, colorL.a = 1.0f };
	Color4f colorR{ colorL.r = 1.0f, colorL.g = 0.f, colorL.b = 1.0f, colorL.a = 1.0f };
	DrawLinearGradient(leftPos, width, height, colorL, colorR);

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
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

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here


void DrawSquares(Point2f pos, float outermostSize, int squares)
{
	utils::SetColor(0.f, 0.f, 0.f);

	// We draw the outermost square 
	utils::DrawLine(pos.x, pos.y, pos.x + outermostSize, pos.y);
	utils::DrawLine(pos.x, pos.y, pos.x, pos.y + outermostSize);
	utils::DrawLine(pos.x + outermostSize, pos.y, pos.x + outermostSize, pos.y + outermostSize);
	utils::DrawLine(pos.x, pos.y + outermostSize, pos.x + outermostSize, pos.y + outermostSize);

	int space{ };

	space += (int(outermostSize) / squares) / 2;

	// Draw the number squares indicated by argument (-1 because the outer is already been drawn)
	for (int i = 0; i < squares - 1; i++) 
	{
		
		utils::DrawLine(pos.x + space, pos.y + space, pos.x + outermostSize - space, pos.y + space);
		utils::DrawLine(pos.x + space, pos.y + space, pos.x + space, pos.y + outermostSize - space);
		utils::DrawLine(pos.x + outermostSize - space, pos.y + space, pos.x + outermostSize - space, pos.y + outermostSize - space);
		utils::DrawLine(pos.x + space, pos.y + outermostSize - space, pos.x + outermostSize - space, pos.y + outermostSize - space);

		space += (int(outermostSize) / squares) / 2;  // Space between squares
	}



}


void DrawEquilateralTriangle(Point2f posVert, float length, bool filled)
{
	utils::SetColor(1.f, 0.f, 0.f);

	//Point2f p2{ p2.x = posVert.x + length, p2.y = posVert.y };
	//Point2f p3{ p3.x = posVert.x + length/2, p3.y = posVert.y + length };

	



	//utils::FillTriangle(posVert, p2, p3);

}

// Draw a linear gradient rectangle from one color to other color passed by parameter
void DrawLinearGradient(Point2f pos, float width, float height, Color4f leftC, Color4f rightC)
{
	utils::SetColor(leftC);

	utils::FillRect(pos.x, pos.y, width, height);
	



}

#pragma endregion ownDefinitions