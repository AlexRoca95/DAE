#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	// Initial pos for Circle
	g_CircleX = g_WindowWidth / 2;
	g_CircleY = g_WindowHeight / 2;

	// Speed for the circle
	g_SpeedX = 100.f;
	g_SpeedY = 80.f;


	// Square
	g_Width = 20.f;
	g_InitialY = g_WindowHeight - g_Width;
	g_SquarePos.x = 50.f; 
	g_SquarePos.y = g_InitialY;
	g_Fall = false;

}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawBall();
	DrawFreeFall();
}

void Update(float elapsedSec)
{
	/*
	g_CountFrame++;

	if (g_CountFrame >= 100)
	{
		std::cout << "Number of frames: " << g_CountFrame << std::endl;		// Number of frames
		std::cout << "Accumulated time: " << elapsedSec  << std::endl;		// Accumulated time
		std::cout << "Framerate: " << 1 / elapsedSec << std::endl;			// Framerate

		g_CountFrame = 0;
		elapsedSec = 0;
	}
	*/

	UpdateBall(elapsedSec);
	if(g_Fall)
	UpdateFreeFall(elapsedSec);
	
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
	
	case SDLK_s:
		if (g_Fall == false)
			g_Fall = true;
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

// Draw a Ball 
void DrawBall()
{
	utils::SetColor(0.83f, 0.33f, 0.f);

	utils::FillEllipse(g_CircleX, g_CircleY, g_Radius, g_Radius);
}

// Draw a square
void DrawFreeFall()
{

	utils::SetColor(1.0f, 1.0f, 0.f);

	utils::FillRect(g_SquarePos.x, g_SquarePos.y, g_Width, g_Width);


}

// Update Ball position using elapsed time (frame independent).
// Checks limits of the window and changes direction if it leaves the window
void UpdateBall(float elapsedSec)
{
	// Speed horizontal = 100 pixels / frame
	g_CircleX += g_SpeedX * elapsedSec;

	// Vertical Speed = 80 pixels / frame
	g_CircleY += g_SpeedY * elapsedSec;

	// X position limits check
	if (g_CircleX - g_Radius <= 0)
	{
		g_SpeedX = 100.f;
	}
	else
	{
		if (g_CircleX + g_Radius >= g_WindowWidth)
		{
			g_SpeedX = -100.f;
		}
	}

	// Y vertical position limits check. If one of the statements is true, then change direction
	if (g_CircleY - g_Radius <= 0)
	{
		g_SpeedY = 80.f;
	}
	else
	{
		if (g_CircleY + g_Radius >= g_WindowHeight)
		{
			g_SpeedY = -80.f;
		}
	}

}

// Free fall of a square. Take into account the gravity that increases every second.
void UpdateFreeFall(float elapsedSec)
{
	g_SquarePos.y += g_Vel * elapsedSec;

	// Velocity accelarates
	g_Vel += g_Gravity * elapsedSec;
	
	if (g_SquarePos.y <= 0)
	{
		g_SquarePos.y = g_InitialY;
		g_Fall = false;
		g_Vel = 0;
	}
}

#pragma endregion ownDefinitions