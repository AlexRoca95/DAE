#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	// Initial X - Y values for squares
	g_YellowX = g_WindowWidth - g_SquareSize;
	
	g_BlueX = g_WindowWidth - g_SquareSize;
	g_BlueY = g_WindowHeight - g_SquareSize;

	g_GreenY = g_WindowHeight - g_SquareSize;

	// Red square initialized with 0 - 0 values
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawBlueSquare();
	DrawYellowSquare();
	DrawRedSquare();
	DrawGreenSquare();


}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdateRedSquare();
	UpdateYellowSquare();
	UpdateGreenSquare();
	UpdateBlueSquare();
	
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

void DrawYellowSquare()
{
	utils::SetColor(0.88f, 0.92f, 0.38f, 0.8f);
	utils::FillRect(g_YellowX, g_YellowY, g_SquareSize, g_SquareSize);

}

void DrawBlueSquare()
{
	utils::SetColor(0.30f, 0.34f, 0.97f, 0.8f);
	utils::FillRect(g_BlueX, g_BlueY, g_SquareSize, g_SquareSize);

}

void DrawGreenSquare()
{
	utils::SetColor(0.30f, 0.93f, 0.38f, 0.8f);
	utils::FillRect(g_GreenX, g_GreenY, g_SquareSize, g_SquareSize);



}

void DrawRedSquare()
{
	utils::SetColor(0.88f, 0.34f, 0.38f, 0.8f);
	utils::FillRect(g_RedX, g_RedY, g_SquareSize, g_SquareSize);

}

void UpdateRedSquare()
{

}

void UpdateYellowSquare()
{

}

void UpdateGreenSquare()
{

}

void UpdateBlueSquare()
{

}

#pragma endregion ownDefinitions