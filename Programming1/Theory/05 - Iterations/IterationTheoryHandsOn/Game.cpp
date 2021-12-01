#include "pch.h"
#include "Game.h"
#include <iostream>
#include <cmath>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
/*
	const int maxValue{ 1000 };
	int value{ 1 }, count{};
	while (value < maxValue)
	{
		value += value;
		++count;
	}

	std::cout << count << std::endl;

	int toGuess{};
	count = 0;
	std::cin >> toGuess;
	int randomNumber{};
	do 
	{
		randomNumber = rand();
		++count;

	}
	while (toGuess != randomNumber);

	std::cout << "Number of guesses: " << count << std::endl;


	count = 0;
	//toGuess = 0;
	randomNumber = rand();
	while (toGuess != randomNumber)
	{
		randomNumber = rand();
		++count;
	}

	std::cout << "Number of guesses: " << count << std::endl;

	*/

}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	SetColor(0, 0, 0, 1);
	float scale{ 100 };
	Point2f translation{ 100, g_WindowHeight / 2};
	float posX{ translation.x };
	float posX2{ translation.x + 1};
	float step{ g_Pi / 180 };			// 1 degree each step
	for (float angle{}; angle < g_Pi * 2; angle += step)  // Angle between 0 and 360 (Full angle)
	{
		float posY1{ sin(angle) * scale + translation.y };
		float posY2{ sin(angle + step) * scale + translation.y };
		utils::DrawLine(posX, posY1, posX2, posY2);
		++posX;
		++posX2;
	}

	// Draws a circle
	for (float angle{}; angle < g_Pi * 2; angle += step)
	{
		float posY1{ sin(angle) * scale + translation.y };
		float posY2{ sin(angle + step) * scale + translation.y };
		float posX{ cos(angle) * scale + translation.x };
		float posX2{ cos(angle + step) * scale + translation.x };
		utils::DrawLine(posX, posY1, posX2, posY2);
	}


	utils::FillRect(10, translation.y + sin(g_Angle) * 50, 50, 10);  // We move rect along the Y axis
}

void Update(float elapsedSec)
{
	// process input, do physics 

	g_Angle += 0.01f;

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

#pragma endregion ownDefinitions