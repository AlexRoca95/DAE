#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	PrintLetters();

	// Initial values 
	//Initialy the circle is waiting
	g_StatusCircle = Circlestates::waiting;

	g_Step = 0.2f;
	g_Speed = g_Step;						// Initial speed of the circle
	g_RadiusCircle = 0.f;				

}

void Draw()
{
	ClearBackground();

	if (g_StatusCircle != Circlestates::waiting)
	{
		// Only draw the circle while it is growing or shrinking
		DrawCircle();
	}
	
}

void Update(float elapsedSec)
{
	if (g_StatusCircle == Circlestates::growing && g_ChangeValues == true)
	{
		// Only update values if we havent done it already
		GenerateNewValues();
	}

	UpdateSizeCircle();				// Changes the size of the circle
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
	case SDLK_DOWN:
		g_ChangeSpeed = false;		// Less speed -0.4
		ChangeSpeed();
		break;
	case SDLK_UP:
		g_ChangeSpeed = true;		// More speed + 0.4
		ChangeSpeed();
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

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

	switch (e.button)
	{
		case SDL_BUTTON_LEFT: 
		{
			// Update mouse X and Y positions 
			if (g_StatusCircle == Circlestates::waiting)
			{
				// Only change values when not drawing the circle
				g_MousePos.x = float(e.x);
				g_MousePos.y = float(g_WindowHeight - e.y);

				
			}

			CheckCircleStatus();		// Check if the circle is waiting

			break;
		}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here


// Prints all the letters of the alphabet asking the number of characters that the user wants per line
void PrintLetters()
{
	int characters{};		// Holds the number of characters per line

	std::cout << "How many of characters per line? ";
	std::cin >> characters;

	char letter{ 'a' };		// Holds the letter to print. Starts at a

	for (int i = 0; i < 26; i++)
	{
		if (i != 0 && i % characters == 0)
		{
			// We create a jump everytime the division with the number written is 0
			std::cout << std::endl;
		}

		std::cout << letter;			// Print the letter

		letter += 1;					// Next letter of the alphabet

	}

	std::cout << std::endl;
}

// Check if the circle is waiting. If it is true, change status to growing and print on the screen
void CheckCircleStatus()
{

	if (g_StatusCircle == Circlestates::waiting)
	{
		// Start growing circle
		g_StatusCircle = Circlestates::growing;
		std::cout << "Growing state." << std::endl;

		g_ChangeValues = true;					// We have to change radius and color
	}
	
	


}

// Draw circle in the center of the mouse and with the current radius
void DrawCircle()
{
	// Draw with the random color generated or red if it reaches the window border
	utils::SetColor(g_ColorCircle.r, g_ColorCircle.g, g_ColorCircle.b);

	// Draw a circle where te mouse is and till the maximum random radius generated
	utils::FillEllipse(g_MousePos.x, g_MousePos.y, g_RadiusCircle, g_RadiusCircle);
}


// Generate a new  max radius for the circle to a random value between [50, 150].
// Also generates new random color for the circle
void GenerateNewValues()
{
	// Random radius
	g_MaxRadius = std::rand() % 101 + 50;			// Generate a random value [50, 150]

	std::cout << "The maximum radius is " << g_MaxRadius << std::endl;

	// Random color
	g_ColorCircle.r = rand() % 100 / 100.f;		// 0 - 99 and then we divide by 100 so we get floats that goes from 0.f to 1.f
	g_ColorCircle.g = rand() % 100 / 100.f;
	g_ColorCircle.b = rand() % 100 / 100.f;

	g_ChangeValues = false;						// No need to change radius again
}

// Updates the radius of the circle depending if it is growing or shrinking and with the speed indicated
void UpdateSizeCircle()
{ 

	if (g_StatusCircle == Circlestates::growing)
	{
		// Circle growing

		if (g_RadiusCircle + g_Speed <= float(g_MaxRadius))
		{
			g_RadiusCircle += g_Speed;
		}
		else
		{
			// To avoid going more than the radius
			g_RadiusCircle = float(g_MaxRadius);
		}
		
		CheckCollision();				// Check if circle collides with the window border	

		if (g_RadiusCircle == g_MaxRadius)
		{
			// Max radius reached. Start shrinking
			g_StatusCircle = Circlestates::shrinking;
			std::cout << "Shrinking state." << std::endl;

		}
	}
	else
	{
		if (g_StatusCircle == Circlestates::shrinking)
		{
			
			// Circle shrinking
			if (g_RadiusCircle - g_Speed >= 0.f)
			{
				g_RadiusCircle -= g_Speed;
			}
			else
			{
				// To avoid negative radius of the circle
				g_RadiusCircle = 0.f;
			}
			
			if (g_RadiusCircle == 0.f)
			{
				// Min radius reached. Stop drawing
				g_StatusCircle = Circlestates::waiting;
				std::cout << "Waiting state." << std::endl;
				std::cout << std::endl;
			}
		}
	}
}

// Check if circle has a collision with the window border. 
// If it is true then starts shrinking and the color changes to red
void CheckCollision()
{
	if (g_MousePos.x + g_RadiusCircle >= g_WindowWidth || g_MousePos.x - g_RadiusCircle <= 0)
	{
		// OUTSIDE THE WINDOW BORDER FOR THE X AXIS
		g_StatusCircle = Circlestates::shrinking;

		// Change color to red
		g_ColorCircle.r = 1.0f;
		g_ColorCircle.g = 0.f;
		g_ColorCircle.b = 0.f;

		std::cout << "Ouch!" << std::endl;
		std::cout << "Shrinking state." << std::endl;

	}
	else
	{
		if(g_MousePos.y + g_RadiusCircle >= g_WindowHeight || g_MousePos.y - g_RadiusCircle <= 0)
		{
			// OUTSIDE THE WINDOW BORDER FOR THE Y AXIS
			g_StatusCircle = Circlestates::shrinking;

			g_ColorCircle.r = 1.0f;
			g_ColorCircle.g = 0.f;
			g_ColorCircle.b = 0.f;

			std::cout << "Ouch!" << std::endl;
			std::cout << "Shrinking state." << std::endl;
		}
	}

}

// Change the speed of the growing/shrinking radius of the circle
void ChangeSpeed()
{
	float maxSpeed{ 5.0f }, minSpeed{ 0.2f };

	if (g_ChangeSpeed == true)
	{
		// We want to increase speed + 0.4
		if (g_Step + 0.4f <= maxSpeed)
		{
			// We can still add more speed
			g_Step += 0.4f;
			
		}
	}
	else
	{
		// We want to decrease speed - 0.4f
		if (g_Step - 0.4f >= minSpeed)
		{
			// We can still add more speed
			g_Step -= 0.4f;
			

		}

	}
	// Change speed
	g_Speed = g_Step;
	std::cout << "g_Speed = " <<  g_Speed << std::endl;
	
	


}


#pragma endregion ownDefinitions