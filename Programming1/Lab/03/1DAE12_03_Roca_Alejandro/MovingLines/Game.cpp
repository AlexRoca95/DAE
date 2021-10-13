// Roca, Alejandro - 1DAE12
#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.39f, 0.39f, 0.66f);

	// Put your own draw statements here
	DrawWhiteLines();
	DrawYellowLines();


}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdateLines();

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

void DrawWhiteLines()
{
	// White color
	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(0, g_LinePosY, g_WindowWidth, g_LinePosY);	// TOP BAR	
	utils::DrawLine(0, g_PosLines, g_WindowWidth, g_PosLines);	 // BOTTOM BAR
	utils::DrawLine(g_PosLines, 0, g_PosLines, g_WindowHeight);	// LEFT
	utils::DrawLine(g_LinePosX, 0, g_LinePosX, g_WindowHeight);	// Right

}

// Draw the yellow square that follow the white lines
void DrawYellowLines()
{
	// Yellow color
	utils::SetColor(1.f, 1.f, 0.f);
	utils::DrawLine(g_LinePosX, g_WindowHeight, g_WindowWidth, g_PosLines); // Top - Right line
	utils::DrawLine(g_LinePosX, g_WindowHeight, 0, g_LinePosY);				// Top - Left
	utils::DrawLine(0, g_LinePosY, g_PosLines, 0);							// Left - Bottom
	utils::DrawLine(g_PosLines, 0, g_WindowWidth, g_PosLines);				// Bottom - Right
}

// Updates the Y of horizontal lines and the X of vertical lines using only the g_PosLines variable
void UpdateLines()
{
	g_PosLines++;		// Increment 1 pixel every frame
	g_PosLines = float(int(g_PosLines) % int(g_WindowHeight)); // Reset when it reaches the WindowHeight

	// Update pos of other lines
	g_LinePosY = g_WindowHeight - g_PosLines;
	g_LinePosX= g_WindowWidth - g_PosLines;

}

#pragma endregion ownDefinitions