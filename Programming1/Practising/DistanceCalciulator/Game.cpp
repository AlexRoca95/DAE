#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	g_RectHeight = 25;
	g_RectWidth = 50;

	// Initial pos of static rect
	g_RectX1 = 50;
	g_RectY1 = g_WindowHeight / 2;


	// Initial pos of moving rect
	g_RectX2 = g_WindowWidth / 2;
	g_RectY2 = g_WindowHeight / 2;
	
	int a = 10;
	std::cout << a++ << std::endl;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here

	DrawRectangles();

}

void Update(float elapsedSec)
{
	// process input, do physics 

	CalculateDist();

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
	
	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };

	MoveRect(mousePos.x, mousePos.y);

	
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


// Draw two rectangles in diferent pos
void DrawRectangles()
{

	utils::SetColor(0.f,0.f,0.f);

	// Static rectangle
	utils::FillRect(g_RectX1, g_RectY1, g_RectWidth, g_RectHeight);

	// Moving rectangle
	utils::FillRect(g_RectX2, g_RectY2, g_RectWidth, g_RectHeight);

}

// Calculate distance between the 2 rectangles using the Pithagoras Theorem
void CalculateDist()
{
	
	double posX{},posY{};
	int distance{};
	// Apply Pithagoras Theorem
	// X horizontal side (Left rectangle X position - right rectangle (moving rectangle)
	posX = (g_RectX1 + g_RectWidth) - g_RectX2;

	// Y vertical position
	posY = g_RectY1 - g_RectY2;


	// Hypothenuse = distance between two rect = sqrt((xf - xo)((xf - xo) + (yf - yo)(yf - yo))
	distance = int(sqrt((posX*posX) + (posY*posY)));

	std::cout << "Distance between rectangles: " << distance << " pixels." << std::endl;

}


void MoveRect(float mouseX, float mouseY)
{
	// Update position of rectangle 2
	g_RectX2 = mouseX;
	g_RectY2 = mouseY;


}

#pragma endregion ownDefinitions