#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	g_HeightRect = 17;
	g_SeparationRect = g_HeightRect;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	Draw1Dice();
	Draw2Dice();
	

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

void Roll1Dice()
{
	int random = rand() % (6 - 1 + 1) + 1;			// [6 - 1]

	switch (random) // Check which number we got 
	{
	case 1:
		g_Dice1_1++;
		break;
	case 2:
		g_Dice1_2++;
		break;
	case 3:
		g_Dice1_3++;
		break;
	case 4:
		g_Dice1_4++;
		break;
	case 5:
		g_Dice1_5++;
		break;
	case 6:
		g_Dice1_6++;
		break;
	}
}

// Draw the results of rolling 1 dice
void Draw1Dice()
{
	Roll1Dice();		// Roll the 1 dice

	utils::SetColor(1.f, 0.4f, 0.4f);

	g_SeparationRect = g_HeightRect;
	
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice1_1), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice1_2), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice1_3), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice1_4), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice1_5), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice1_6), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;

	g_SeparationRect2Dice = g_SeparationRect;		// Start for the rectangles of 2 dices


}

void Roll2Dice()
{
	int random = rand() % (12 - 1 + 1) + 1;			// [12 - 1]

	std::cout << random << std::endl;
	switch (random) // Check which number we got 
	{
	case 1:
		g_Dice2_1++;
		break;
	case 2:
		g_Dice2_2++;
		break;
	case 3:
		g_Dice2_3++;
		break;
	case 4:
		g_Dice2_4++;
		break;
	case 5:
		g_Dice2_5++;
		break;
	case 6:
		g_Dice2_6++;
		break;
	case 7:
		g_Dice2_7++;
		break;
	case 8:
		g_Dice2_8++;
		break;
	case 9:
		g_Dice2_9++;
		break;
	case 10:
		g_Dice2_10++;
		break;
	case 11:
		g_Dice2_11++;
		break;
	case 12:
		g_Dice2_12++;
		break;
	}
}

void Draw2Dice()
{
	Roll2Dice();		// Roll the 2 dice

	utils::SetColor(0.8f, 0.6f, 1.f);

	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_1), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_2), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_3), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_4), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_5), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_6), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_7), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_8), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_9), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_10), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_11), float(g_HeightRect));
	g_SeparationRect += g_HeightRect + 10;
	utils::FillRect(10, float(g_SeparationRect), float(g_Dice2_12), float(g_HeightRect));


}
#pragma endregion ownDefinitions