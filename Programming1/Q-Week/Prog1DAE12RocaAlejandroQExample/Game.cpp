#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	Generate();


	g_Border = 30;				// Border of the screen is 30 pixels


	// Initializing drawing elevator variables
	g_Wall_thickness = 10;
	g_Elevator_w = 40;
	g_Elevator_h = 60;

	// Interior space sizes
	g_Interior_w = g_Elevator_w - (g_Wall_thickness) * 2;
	g_Interior_h = g_Elevator_h - (g_Wall_thickness) * 2;


	// Initial position for elevator
	g_PosX = (int(g_WindowWidth) - g_Border) - g_Elevator_w;
	g_PosY = g_Border;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here

	DrawElevator();

}

void Update(float elapsedSec)
{
	// process input, do physics 

	g_TotalElapsedTime += elapsedSec;
	if (1 <= g_TotalElapsedTime)		
	{	
		// Whe have reach 1 sec
		// 
		// Check if we want to move elevator
		if (g_Direction != ElevatorDirect::Stop)
		{
			MoveElevator();
		}

		Generate();					// Generate random values

		g_TotalElapsedTime = 0;		// Reset the count
	}

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
	switch (key)
	{
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	case SDLK_n:
		Generate();		// Every time the n key is up we call the function
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		g_MousePos.x = float(e.x);
		g_MousePos.y = g_WindowHeight - e.y;
		CheckMouseElevator();
		break;
	}
	case SDL_BUTTON_RIGHT:
		std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << "Middle mouse button released\n";
		break;
	}
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

// Generate new values [0,9] for g_Even, g_Odd and g_Any
void Generate()
{
	int odd{}, even{}, any{};
	
	do {

		odd = rand() % 10;

	} while (odd % 2 == 0);			// If we got an even value, we get a new value again

	g_Odd = odd;

	do {

		even = rand() % 10;

	} while (even % 2 != 0);			// If we got an odd value, we get a new value again

	g_Even = even;

	g_Any = rand() % 10;

	PrintRandomNumbers();

}

// Print the random values of g_Odd, g_Any and g_Even
void PrintRandomNumbers()
{

	std::cout << "Even: " << g_Even << ", odd: " << g_Odd << ", any: " << g_Any << std::endl;

}


// Draw the elevator 
void DrawElevator()
{
	////std::cout << initialX << std::endl;
	// Elevator Wall
	utils::SetColor(0.2f, 0.2f, 0.9f);
	utils::FillRect(float(g_PosX), float(g_PosY), float(g_Elevator_w), float(g_Elevator_h));

	// Elevator interior part
	if (g_Direction == ElevatorDirect::Up)
	{
		utils::SetColor(1.f, 0.f, 0.f);
	}
	else
	{
		if (g_Direction == ElevatorDirect::Down)
		{
			utils::SetColor(1.f, 0.f, 1.f);
		}
		else
		{
			if (g_MoveElevator == false)
			{
				utils::SetColor(0.f, 0.f, 0.f);
			}
			
		}
	}
	
	utils::FillRect(float(g_PosX)+ float(g_Wall_thickness), float(g_PosY) + float(g_Wall_thickness), float(g_Interior_w), float(g_Interior_h));

}


// Check if the mouse is clicking inside the inner space of the elevator
void CheckMouseElevator()
{	
	
	int positionX = g_PosX + g_Wall_thickness;
	int positionY = g_PosY + g_Wall_thickness;
	
	if ( (g_MousePos.x >= float(positionX)) && (g_MousePos.x <= float(positionX) + float(g_Interior_w)) )
	{
		// Inside X coord
		if ((g_MousePos.y >= float(positionY)) && (g_MousePos.y <= float(positionY) + float(g_Interior_h)))
		{
			// Mouse clicking inside the interior space of elevator
			if (g_Direction == ElevatorDirect::Stop)
			{
				if (g_Direct == true)
				{
					g_Direction = ElevatorDirect::Down;
					
				}
				else
				{
					g_Direction = ElevatorDirect::Up;
				}
				
			}
			else
			{
				if (g_Direction == ElevatorDirect::Up)
				{
					g_Direction = ElevatorDirect::Stop;
					g_Direct = false;

				}
				else
				{
					if (g_Direction == ElevatorDirect::Down)
					{
						g_Direction = ElevatorDirect::Stop;
						g_Direct = true;
					}
				}
			}
		}

	}

}
// Moves the elevator 100 pixels every 1 second. 
void MoveElevator()
{
	if (g_Direction == ElevatorDirect::Up)
	{
		// Going up
		g_PosY += 100;
	}
	else
	{
		// Going down
		g_PosY -= 100;
	}

	CheckLimits();			// Check if elevator is outside limits
	
}

// Check if elevator is outside limits. Change direction if it is true
void CheckLimits()
{
	if (g_PosY >= g_WindowHeight - g_Border)
	{
		// Outside top limit
		g_Direction = ElevatorDirect::Down;
	}
	else
	{
		if (g_PosY <= g_Border)
		{
			// Outside bottom limit
			g_Direction = ElevatorDirect::Up;
		}
	}

}
#pragma endregion ownDefinitions