#include "pch.h"
#include "Game.h"
#include <iostream>
#include <math.h>


//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	// Both angles of Big Clock wise initialized at full angle (360º / 2pi)
	g_BigAngleX = 2 * M_PI; 
	g_BigAngleY = 2 * M_PI;

	g_SmallAngleX = M_PI;
	g_SmallAngleY = M_PI;

}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawBigClockWise();
	DrawSmallClockWise();

	

}

void Update(float elapsedSec)
{
	UpdateAngle();


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

void UpdateAngle()
{
	std::cout << "RadiansX: " << g_SmallAngleX << std::endl;
	std::cout << "RadiansY: " << g_SmallAngleY << std::endl;

	// Calculate cos and sin of the angle and scale up the values +100 -100
	g_BigPosX = cos(g_BigAngleX) * 100;			
	g_BigPosY = sin(g_BigAngleY) * 100;

	g_SmallPosX = cos(g_SmallAngleX) * 100;
	g_SmallPosY = sin(g_SmallAngleY) * 100;

	//std::cout << "Cos: " << g_BigPosX << std::endl;
	//std::cout << "Sin: " << g_BigPosY << std::endl;

	// Translate those values into the center of the screen
	g_BigPosX += g_WindowWidth / 2;				
	g_BigPosY += g_WindowHeight / 2;

	g_SmallPosX += g_WindowWidth / 2;
	g_SmallPosY += g_WindowHeight / 2;


	std::cout << "PosX: " << g_SmallPosX << std::endl;
	std::cout << "PosY: " << g_SmallPosY << std::endl;

	// Angles are decremented each frame
	g_BigAngleX -= 0.0174533;
	g_BigAngleY -= 0.0174533;

	g_SmallPosX -= 0.0014544;
	g_SmallPosY -= 0.0014544;

}

void DrawBigClockWise()
{
	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(g_WindowWidth / 2, g_WindowHeight / 2, float(g_BigPosX), float(g_BigPosY));

}

void DrawSmallClockWise()
{
	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(g_WindowWidth / 2, g_WindowHeight / 2, float(g_SmallPosX), float(g_SmallPosY));
}

#pragma endregion ownDefinitions