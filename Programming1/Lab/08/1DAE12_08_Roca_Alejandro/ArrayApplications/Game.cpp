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

	// Put your own draw statements here
	DrawPolygon();
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
	switch (e.button)
	{
		case SDL_BUTTON_LEFT:
		{
			Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
			AddClickedPoint(mousePos);
			g_DrawPolygon = true;
			break;
		}
	
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

// Store the mousePos in the array. If the array is full --> shift all elements to the left, so last one is free 
// and first element is lost
void AddClickedPoint(const Point2f& mousePos)
{
	if (g_IdxNext == g_MaxClicks - 1)
	{
		// Array full. Shift all elements one pos to the left
		for (int i = 0; i < g_MaxClicks-1; i++)
		{
			if (i != g_MaxClicks - 1) // Not last element
			{
				g_ArrayClicks[i] = g_ArrayClicks[i + 1];  // Shift elements to the left
			}
		}

		g_ArrayClicks[g_IdxNext] = mousePos;
		
	}
	else
	{
		// Add new mousePos at the index that we are 
		g_ArrayClicks[g_IdxNext] = mousePos;
		g_IdxNext++;
	}

	for (int i = 0; i < g_MaxClicks; i++)
	{
		std::cout << g_ArrayClicks[i].x << ", " << g_ArrayClicks[i].y << std::endl;
	}
}



void DrawPolygon()
{
	
	if (g_DrawPolygon == true)
	{
		const int nrVertices{ 5 };
		utils::SetColor(1.f, 0.43f, 0.43f);
		// Start drawing polygons

		for (int i{}; i < g_IdxNext; i++)
		{
			// Draw all polygons in the array
			
			utils::FillEllipse(g_ArrayClicks[i], 20, 20);
		}
	}
}

#pragma endregion ownDefinitions