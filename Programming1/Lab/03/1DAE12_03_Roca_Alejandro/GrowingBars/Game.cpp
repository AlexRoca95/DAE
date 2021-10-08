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
	ClearBackground(0.f, 0.f, 0.f);

	DrawYellowBar();
	DrawRedBar();
	

	

}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_NrFrames++;											// frame count

	// Update Bar sizes
	UpdateYellowBar();
	UpdateRedBar();

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

// Function that draws the bars
void DrawYellowBar()
{
	// Draw Yellowish bar
	utils::SetColor(1.f, 1.f, 0.f);
	utils::FillRect(g_Border, g_YellowBarY, g_YellowBarWidth, g_BarHeight);

	// Draw lines
	// Bottom
	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(g_Border, g_YellowBarY, g_MaxWidth, g_YellowBarY, 2.0f);
	
	//TOP
	utils::DrawLine(g_Border, g_YellowBarY + g_BarHeight, g_MaxWidth, g_YellowBarY + g_BarHeight, 2.0f);
	
	// Left
	utils::DrawLine(g_Border, g_YellowBarY, g_Border, g_YellowBarY + g_BarHeight, 2.0f);

	// Right
	utils::DrawLine(g_MaxWidth, g_YellowBarY, g_MaxWidth, g_YellowBarY + g_BarHeight, 2.0f);
}

void DrawRedBar()
{
	// Draw reddish bar
	utils::SetColor(1.f, 0.f, 0.f);
	utils::FillRect(g_Border, g_RedBarY, g_RedBarWidth, g_BarHeight);

	// Draw lines
	// Bottom
	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(g_Border, g_RedBarY, g_MaxWidth, g_RedBarY, 2.0f);

	//TOP
	utils::DrawLine(g_Border, (g_RedBarY) + g_BarHeight, g_MaxWidth, (g_RedBarY) + g_BarHeight, 2.0f);

	// Left
	utils::DrawLine(g_Border, g_RedBarY, g_Border, (g_RedBarY) + g_BarHeight, 2.0f);

	// Right
	utils::DrawLine(g_MaxWidth, g_RedBarY, g_MaxWidth, (g_RedBarY) + g_BarHeight, 2.0f);
}

// Updates the yellow Bar one pixel per frame
void UpdateYellowBar()
{
	// Incrementing sizes of the bars
	g_YellowBarWidth++;										// Width of yellowish bar grows 1 pixel every frame
	g_YellowBarWidth = float(int(g_YellowBarWidth) % int(g_MaxWidth)); // Reset size if we reach maximum size

}

// Updates the Red Bar 15 pixels every 30 frames
void UpdateRedBar()
{
	int frame30{}, value15{};

	frame30 = g_NrFrames % 30;		// Reset every 30 frames
	frame30++;						// [1 - 30] values
	value15 = frame30 / 30;			// value15 = 1 if frame30 == 30, value15 = 0 for the rest

	g_RedBarWidth += value15 * 15;  // Adds 15 pixels every 30 frame

	// Reset Red Bar Size when it reachs max width
	g_RedBarWidth = float(int(g_RedBarWidth) % int(g_MaxWidth));


}
#pragma endregion ownDefinitions