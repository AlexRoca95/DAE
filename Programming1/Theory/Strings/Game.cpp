#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	char cString[]{ "SpaceX" };
	char cString2[]{ 'T', 'E', 'd' };
	std::cout << cString << " " << sizeof(cString) << std::endl;
	cString[6] = 'A';  // overwrite the \0 (so we dont indicate the end of the c-string
	std::cout << cString << " " << sizeof(cString) <<std::endl;

	std::string carBrand{ "Volkswagen" };
	const char* pChar{ carBrand.c_str() };
	std::cout << pChar << " " << sizeof(pChar) << std::endl;  // Sizeof pointer is 4 bytes

	g_NumberOfElem = 100;
	g_pNumbers = new int[g_NumberOfElem]{};  // Dynamic memory for the pointer (new)

	for (int i{}; i < g_NumberOfElem; i++)
	{
		//std::cout << g_pNumbers[i] << '\n';
	}

	// Generate random points
	g_pPoints = new Point2f[g_NumberOfElem]{};
	for (int i{}; i < g_NumberOfElem; i++)
	{
		g_pPoints[i] = Point2f{ float(rand() % int(g_WindowWidth)), float(rand() % int(g_WindowHeight)) };
	}


}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here

	// Conect all the points with lines
	for (int i{}; i < g_NumberOfElem-1; i++)  // -1 so we dont exceed the array size for the last element in (i+1)
	{
		DrawLine(g_pPoints[i], g_pPoints[i + 1]);
	}

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
	// Delete the dynamic memory created
	delete[] g_pNumbers;
	g_pNumbers = nullptr;
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

#pragma endregion ownDefinitions