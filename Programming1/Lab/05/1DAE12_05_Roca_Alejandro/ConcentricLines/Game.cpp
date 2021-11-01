#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	g_Color = Color::blue;
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawLines();

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
	switch (key)
	{
	case SDLK_RIGHT:
		SwitchColor();
		break;
	}
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
	// Track position of the mouse
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);

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

// Draw lines from the edges of the window to the mouse position
void DrawLines()
{
	int posX{ }, posY{};
	int space{ 9 };			// Space between lines
	
	DrawColor();		// Check the color of the lines
	// Bottom lines
	for (int i = 0; i < g_WindowWidth; i = i + space)
	{
		utils::DrawLine(float(posX + i), float(posY), g_MousePos.x, g_MousePos.y);
	}

	// Left lines
	for (int i = 0; i < g_WindowHeight; i = i + space)
	{
		utils::DrawLine(float(posX), float(posY + i), g_MousePos.x, g_MousePos.y);
	}

	// Right lines
	posX = int(g_WindowWidth);
	
	for (int i = 0; i < g_WindowHeight; i = i + space)
	{
		utils::DrawLine(float(posX), float(posY + i), g_MousePos.x, g_MousePos.y);
	}

	//Top Lines
	posY = int(g_WindowHeight);
	posX = 0;

	for (int i = 0; i < g_WindowWidth; i = i + space)
	{
		utils::DrawLine(float(posX + i), float(posY), g_MousePos.x, g_MousePos.y);
	}
}

// Switch Colors of the line depending on 
void SwitchColor()
{	
	switch (g_Color)  // Check color and change it to the next one in the enum
	{
		case Color::red:
			g_Color = Color::green;
			break;
		case Color::green:
			g_Color = Color::blue;
			break;
		case Color::blue:
			g_Color = Color::red;
			break;
	}
	
}

void DrawColor()
{
	switch (g_Color)
	{
	case Color::red:
		utils::SetColor(1.f, 0.f, 0.f);
		break;
	case Color::green:
		utils::SetColor(0.f, 1.f, 0.f);
		break;
	case Color::blue:
		utils::SetColor(0.2f, 0.2f, 0.50f);
		break;
	}

}

#pragma endregion ownDefinitions