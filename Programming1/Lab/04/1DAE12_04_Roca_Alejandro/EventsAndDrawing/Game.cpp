#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_DistanceBorder = 50;					// Distance that the rectangle has to be from border

	// Minumum size of rectangle
	g_MinWidthRect = 60;
	g_MinHeightRect = 40;

	stateRect = StateRect::changePos;

	// Initial color of the rectangle Grey
	g_ColorRect.r = 0.50;
	g_ColorRect.g = 0.50;
	g_ColorRect.b = 0.50;

	drawRect = DrawARect::notDraw;
	moveRect = MoveARect::noMove;
}

void Draw()
{
	ClearBackground();

	DrawRandomRect();

	// Check if we have to draw a new rectangle on the other side
	if (drawRect == DrawARect::draw)
	{
		DrawNewRect();
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// We only update values when we click inside the rectangle and it is green
	if (stateRect == StateRect::changePos)
	{
		UpdateValuesRect();

		stateRect = StateRect::notChange;
	}

	if (moveRect == MoveARect::move)
	{
		MoveRect();
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

	switch (key)
	{
	case SDLK_r:
		if (moveRect == MoveARect::move)
		{
			// Rectangle already moving it. Stop moving it
			moveRect = MoveARect::noMove;
		}
		else
		{
			// Rectangle not moving. Move it
			moveRect = MoveARect::move;		// Move rectangle
		}
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		g_MousePos.x = float(e.x);
		g_MousePos.y = float(g_WindowHeight - e.y);
		CheckMouseRect();
		break;
	}
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

// Draw a random rectangle in a random position with the values calculated in UpdateValuesRect
void DrawRandomRect()
{
	if (stateRect == StateRect::changeColor)
	{
		// Color to green
		g_ColorRect.r = 0;
		g_ColorRect.g = 1;
		g_ColorRect.b = 0;
	}
	else
	{
		// Color to grey
		g_ColorRect.r = 0.50;
		g_ColorRect.g = 0.50;
		g_ColorRect.b = 0.50;
	}

	utils::SetColor(g_ColorRect.r, g_ColorRect.g, g_ColorRect.b);
	// Draw rectangle with random values
	utils::FillRect(float(g_PosX), float(g_PosY), float(g_WidthRect), float(g_HeightRect));

}

// Check if we click inside the rectangles
void CheckMouseRect()
{	// Check both X rectangles
	if (g_MousePos.x >= g_PosX && g_MousePos.x <= (g_PosX + g_WidthRect) || g_MousePos.x >= PosXRect2 && g_MousePos.x <= (PosXRect2 + g_WidthRect))
	{
		if (g_MousePos.y >= g_PosY && g_MousePos.y <= (g_PosY + g_HeightRect))
		{
			if (g_ColorRect.r == 0.50 && g_ColorRect.g == 0.50 && g_ColorRect.b == 0.50)
			{
				// Rectangle in grey color. Only change color
				stateRect = StateRect::changeColor;
			}
			else
			{
				// Rectangle in green. Generate a new random rectangle
				stateRect = StateRect::changePos;
			}
		}
	}

}


// Update the values of the rectangle (Width, Height, g_PosX etc) to random values
void UpdateValuesRect()
{
	int distanceX{}, distanceY{};

	// Random Pos X
	g_WidthRect = rand() % ((int(g_WindowWidth) - 100) - g_MinWidthRect + 1) + g_MinWidthRect;			// Random g_WidthRect [60 - 400]

	distanceX = int(g_WindowWidth) - g_WidthRect - g_DistanceBorder;		// Distance that rect has to be from border X

	g_PosX = rand() % (distanceX - g_DistanceBorder + 1) + g_DistanceBorder;	    // Position between [50 - distanceX (size rect + g_DistanceBorder pixels)]


	// Random Pos Y
	g_HeightRect = rand() % ((int(g_WindowHeight) - 100) - g_MinHeightRect + 1) + g_MinHeightRect;			// Random g_HeightRect [40 - 200]

	distanceY = int(g_WindowHeight) - g_HeightRect - g_DistanceBorder;  // Distance that rect has to be from border Y

	g_PosY = rand() % (distanceY - g_DistanceBorder + 1) + g_DistanceBorder;		// Position between [g_DistanceBorder - distanceY (size rect + 10 pixels)]

}

// Move rectangle when we press key 'R'
void MoveRect()
{
	// Move rect in x
	g_PosX++;

	CheckMoveRect();
}

// Check if the rectangle is outside the screen. 
// If it is true we star drawing a new one on the other side
void CheckMoveRect()
{
	if (g_PosX + g_WidthRect > g_WindowWidth)
	{
		drawRect = DrawARect::draw;
	}
}

// Draw a new rectangle when the other is outside the screen
void DrawNewRect()
{
	int width{};

	if (g_PosX <= g_WindowWidth)
	{
		width = (g_PosX + g_WidthRect) - int(g_WindowWidth); // Calculate the size we have to draw in the other side
		PosXRect2 = 0;		// X of the new rectangle
	}
	else
	{
		// All the width of the rectangle is outside the screen. Reset the initial X
		g_PosX = 0;
		drawRect = DrawARect::notDraw;
	}


	utils::FillRect(float(PosXRect2), float(g_PosY), float(width), float(g_HeightRect));

}
#pragma endregion ownDefinitions