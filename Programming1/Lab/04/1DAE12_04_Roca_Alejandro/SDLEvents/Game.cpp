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
	ClearBackground();
	DrawSquareInMouse();
	// Put your own draw statements here

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
	std::cout << "SDL_KEYUP" << std::endl;
	std::cout << std::endl;
}

void OnKeyUpEvent(SDL_Keycode key)
{
	std::cout << "SDL_KEYUP" << std::endl;
	std::cout << std::endl;
	switch (key)
	{
	case SDLK_LEFT:
		std::cout << "Left arrow key released\n";
		break;
	case SDLK_RIGHT:
		std::cout << "Right arrow key released\n";
		break;
	case SDLK_1:
	case SDLK_KP_1:
		std::cout << "Key 1 released\n";
		break;
	}

	std::cout << std::endl;
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	mousePos.x = float(e.x);
	mousePos.y = float(g_WindowHeight - e.y);

};



void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "SDL_MOUSEBUTTONDOWN" << std::endl;

	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
	std::cout << "[ " << mousePos.x << ", " << mousePos.y << " ]" << std::endl;

	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		std::cout << "Left mouse button went down\n";
		break;
	}
	case SDL_BUTTON_RIGHT:
		std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << "Middle mouse button released\n";
		break;
	}

	std::cout << std::endl;

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "SDL_MOUSEBUTTONUP" << std::endl;
	std::cout << std::endl;
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
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

void DrawSquareInMouse()
{

	utils::SetColor(0.8f, 0.2f, 0.2f);
	utils::FillRect(mousePos.x, mousePos.y, 10, 10);

}
#pragma endregion ownDefinitions