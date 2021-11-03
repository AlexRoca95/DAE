#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	g_Border = 20;
	g_MainPile = 21;						// Starts with 21 matches
	g_UserPile = g_ComputerPile = 0;		// Starts with 0 matches

	// Sizes of the matches
	g_MatchWidth = 5;
	g_MatchHeight = 40;
	g_SmallMatchH = 15;

	g_UserTookMatches = false;

	g_CountPlayer = "Player moves: ";
	g_CountComputer = "PC moves: ";

	g_PlayerWin = g_ComputerWin = false;
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawPileMatches();

}

void Update(float elapsedSec)
{
	// process input, do physics 

	UpdatePiles();
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
	case SDLK_1:		// Number 1 pressed
		g_MatchesToTake = 1;
		g_UserTookMatches = true;
		break;
	case SDLK_2:		// Number 2 pressed
		g_MatchesToTake = 2;
		g_UserTookMatches = true;
		break;
	case SDLK_3:		// Number 3 pressed
		g_MatchesToTake = 3;
		g_UserTookMatches = true;
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

// Draw the pile of matches (main pile, user pile and computer pile)
void DrawPileMatches()
{	
	// Initial X & Y positions for the piles
	float mainPileX{ g_Border }, mainPileY{ g_WindowHeight - (g_MatchHeight + g_SmallMatchH) - g_Border };
	float userPileX{ mainPileX }, userPileY{ g_Border };
	float computerPileX{ g_WindowWidth / 2 }, computerPileY{ g_Border };

	float space{  };		// Space between matches
	
	// Draw main pile
	for (int i = 0; i < g_MainPile; i++)
	{
		// Red part of the pile
		utils::SetColor(1.f, 0.4f, 0.4f);
		utils::FillRect(mainPileX + space, mainPileY, g_MatchWidth, g_MatchHeight);

		// Yellow part of the pile
		utils::SetColor(1.f, 1.f, 0.4f);
		utils::FillRect(mainPileX + space, mainPileY + g_MatchHeight, g_MatchWidth, g_SmallMatchH);

		space += 15;
	}

	space = 0;

	// Draw user pile
	for (int i = 0; i < g_UserPile; i++)
	{
		// Red part of the pile
		utils::SetColor(1.f, 0.4f, 0.4f);
		utils::FillRect(userPileX + space, userPileY, g_MatchWidth, g_MatchHeight);

		// Yellow part of the pile
		utils::SetColor(1.f, 1.f, 0.4f);
		utils::FillRect(userPileX + space, userPileY + g_MatchHeight, g_MatchWidth, g_SmallMatchH);

		space += 15;
	}

	space = 0;

	// Draw computer pile
	for (int i = 0; i < g_ComputerPile; i++)
	{
		// Red part of the pile
		utils::SetColor(1.f, 0.4f, 0.4f);
		utils::FillRect(computerPileX + space, computerPileY, g_MatchWidth, g_MatchHeight);

		// Yellow part of the pile
		utils::SetColor(1.f, 1.f, 0.4f);
		utils::FillRect(computerPileX + space, computerPileY + g_MatchHeight, g_MatchWidth, g_SmallMatchH);

		space += 15;
	}


}

// Check if the user took matches from the pile. 
//If it is true then the computer also takes randomly from the pile (if there are matches left)
void UpdatePiles()
{
	if (g_UserTookMatches == true)
	{
		// We only update piles if the user took matches

		if (g_MainPile >= g_MatchesToTake)
		{
			// Only take from the pile if there is more than the user requires
			g_MainPile -= g_MatchesToTake;		// Decrement main pile
			g_UserPile += g_MatchesToTake;		// Increment user pile

			g_CountPlayer += std::to_string(g_MatchesToTake);
			g_CountPlayer += " ";

			g_UserTookMatches = false;

			if (g_MainPile == 0)
			{
				g_ComputerWin = true;		// The computer won
				EndGame();					// The game ends
			}
			else
			{
				// Computer turn
				ComputerTurn();
			}
			
		}
	}

}

void ComputerTurn()
{
	int computerTake{ };
	bool valid{ false };

	do {

		computerTake = rand() % (3 - 1 + 1) + 1;		// Random between 1 - 3
		//std::cout << computerTake << std::endl;
		if (g_MainPile >= computerTake)			// Check if the computer used a valid number of matches
			valid = true;

	} while (valid != true);

	g_CountComputer += std::to_string(computerTake);
	g_CountComputer += " ";
	g_MainPile -= computerTake;		// Decrement main pile
	g_ComputerPile += computerTake;		// Increment computer pile

	if (g_MainPile == 0)
	{
		g_PlayerWin = true;			// The player won
		EndGame();					// The game ends
	}
	
}


// Print final results and the winner
void EndGame()
{
	std::cout << g_CountPlayer << std::endl;
	std::cout << g_CountComputer << std::endl;

	if (g_PlayerWin == true)
	{
		std::cout << "You win" << std::endl;
	}
	else
	{
		std::cout << "You loose" << std::endl;
	}
		
}

#pragma endregion ownDefinitions