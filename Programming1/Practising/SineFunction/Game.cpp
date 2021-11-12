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

	// Put your own draw statements here

	DrawSineFunction();
	DrawRectangle();

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// Next angle in the sin function (angle + pi / 180 rad)
	g_Angle += g_Step;

	// Check if we have reach the maximum angle (360 degrees)
	if (g_Angle >= g_FullAngle)
	{
		// Reset values. Infinite loop along the sin function
		g_Angle = 0;
		g_PosX = g_StartXSin;
		g_PosX2 = g_PosX + 1;
	}

	
	g_PosX++;
	// g_PosX2++;		// Only need it for drawing the sin function
	
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


// Calculates the Y positions for the sin function
void DrawSineFunction()
{
	utils::SetColor(0, 0, 0, 1);

	// Coeficients of general sin function
	float amplitude{ 50 };					// Stretches the sine function along y-axis
	float intercept{ g_WindowHeight / 2 };	// Shifts the sine function upwards (intercept >0) or downwards (intercept <0)
	
	
	g_PosY = amplitude * sin(g_Angle) + intercept;
	// posY2 defines the x-horiz streching of the function (initial phase) (only need it for drawing the sin function)
	g_PosY2 = amplitude * sin(g_Angle + g_Step) + intercept;

	
	//utils::DrawLine(g_PosX, g_PosY, g_PosX2, g_PosY2);

	//DrawRectangle();		// Draw a rectangle


	// Loop from 0 to 2*pi rad (This draws the sin function)
	/*for (float angle = 0; angle <= g_FullAngle; angle += step)
	{
		posY = amplitude * sin(angle) + intercept;
		// posY2 defines the x-horiz streching of the function
		posY2 = amplitude * sin(angle + step) + intercept;			

		//std::cout << sin(angle) << std::endl;
		utils::DrawLine(posX, posY, posX2, posY2);

	}*/

	
}


// Draw a moving rectangle alonside the sin function
void DrawRectangle()
{
	float width{ 50 }, height{ 10 };

	// Draw it at the sin function positions
	utils::FillRect(g_PosX, g_PosY, width, height);


}

#pragma endregion ownDefinitions