#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	g_SquareSize = 80;
	g_BombX = int(g_WindowWidth / 2) - (g_SquareSize / 2 );
	g_BombY = int(g_WindowHeight / 2) - (g_SquareSize / 2);

	g_Bomb = false;

	// LEFT TOP SQUARE
	g_RedSquareX1 = g_BombX - g_SquareSize / 2;
	g_RedSquareY1= g_BombY + g_SquareSize / 2;
	// TOP RIGHT SQUARE
	g_RedSquareX2 = g_BombX + g_SquareSize / 2;
	g_RedSquareY2 = g_BombY + g_SquareSize / 2;
	// BOTTOM LEFT SQUARE
	g_RedSquareX3 = g_BombX - g_SquareSize / 2 ;
	g_RedSquareY3 = g_BombY - g_SquareSize / 2;
	// BOTTOM RIGHT SQUARE
	g_RedSquareX4 =  g_BombX + g_SquareSize / 2;
	g_RedSquareY4 =  g_BombY - g_SquareSize / 2;

}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here

	DrawExplosion();

}

void Update(float elapsedSec)
{
	
	if (g_Bomb == true)
	{
		// bomb clicked
		UpdateExplosion();
	}
	
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
	//Point2f g_MousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		g_MousePos.x = float(e.x);
		g_MousePos.y = float(g_WindowHeight - e.y);
		ProcessMouseClick();
		break;
	}
	case SDL_BUTTON_RIGHT:
		//std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		//std::cout << "Middle mouse button released\n";
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

// Draw the bomb and the 4 red rectangles when we click the bomb
void DrawExplosion()
{
	float transp{1.f};
	if (g_Bomb == true)
	{
		// If the explosion occurs, then it will become transparent
		transp = 0.5f; 
		DrawRedSquares();
	}
	utils::SetColor(0.f, 0.f, 0.f, transp);
	utils::FillRect(float(g_BombX), float(g_BombY), float(g_SquareSize), float(g_SquareSize));

}

void DrawRedSquares()
{
	
	utils::SetColor(1.f,0.f,0.f);
	// TOP LEFT SQUARE
	utils::FillRect(float(g_RedSquareX1), float(g_RedSquareY1), float(g_SquareSize), float(g_SquareSize));
	// TOP RIGHT SQUARE
	utils::FillRect(float(g_RedSquareX2), float(g_RedSquareY2), float(g_SquareSize), float(g_SquareSize));
	// BOTTOM LEFT SQUARE
	utils::FillRect(float(g_RedSquareX3), float(g_RedSquareY3), float(g_SquareSize), float(g_SquareSize));
	// BOTTOM RIGHT SQUARE
	utils::FillRect(float(g_RedSquareX4), float(g_RedSquareY4), float(g_SquareSize), float(g_SquareSize));


}
// Chech if we have clicked inside the bomb
void ProcessMouseClick()
{

	if (g_MousePos.x >= g_BombX && g_MousePos.x <= g_BombX + g_SquareSize)
	{
		if (g_MousePos.y >= g_BombY && g_MousePos.y <= g_BombY + g_SquareSize)
		{
			// Bomb clicked
			g_Bomb = true;
		}
	}


}

void UpdateExplosion()
{
	// TOP LEFT SQUARE
	g_RedSquareX1--;
	g_RedSquareY1++;
	// TOP RIGHT SQUARE
	g_RedSquareX2++;
	g_RedSquareY2++;
	// BOTTOM LEFT SQUARE
	g_RedSquareX3--;
	g_RedSquareY3--;
	// BOTTOM RIGHT SQUARE
	g_RedSquareX4++;
	g_RedSquareY4--;


	if ((g_RedSquareX2 + g_SquareSize / 2) >= g_WindowWidth && (g_RedSquareY1 + g_SquareSize / 2) >= g_WindowHeight)
	{
		// RED SQUARES LEFT THE WINDOW. EXPLOSION FINISHED
		g_Bomb = false;

		// Reset positions of the red squares
		// LEFT TOP SQUARE
		g_RedSquareX1 = g_BombX - g_SquareSize / 2;
		g_RedSquareY1 = g_BombY + g_SquareSize / 2;
		// TOP RIGHT SQUARE
		g_RedSquareX2 = g_BombX + g_SquareSize / 2;
		g_RedSquareY2 = g_BombY + g_SquareSize / 2;
		// BOTTOM LEFT SQUARE
		g_RedSquareX3 = g_BombX - g_SquareSize / 2;
		g_RedSquareY3 = g_BombY - g_SquareSize / 2;
		// BOTTOM RIGHT SQUARE
		g_RedSquareX4 = g_BombX + g_SquareSize / 2;
		g_RedSquareY4 = g_BombY - g_SquareSize / 2;

	}

}

#pragma endregion ownDefinitions