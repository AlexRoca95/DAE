#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	// Circle
	g_Circle.radius = 50.f;
	g_Circle.center = GetRandomPos(g_Circle.radius, g_Circle.radius);

	// Rectangle
	g_Rect.width = 50.f;
	g_Rect.height = 25.f;
	Point2f pos = GetRandomPos(g_Rect.width, g_Rect.height);
	g_Rect.left = pos.x;
	g_Rect.bottom = pos.y;



}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawFilledCircle();
	DrawCircleBorder();

	DrawRectangle();
	DrawRectBorder();

}

void Update(float elapsedSec)
{
	// process input, do physics 
	TestPointInCircle();
	TestPointInRect();
	
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
	// Get mouse position
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);

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


void DrawFilledCircle()
{
	utils::SetColor(1.f, 1.f, 1.f); // White

	FillEllipse(g_Circle.center, g_Circle.radius, g_Circle.radius);

}


// Draw a red border for the circle if the mouse is inside the circle
void DrawCircleBorder()
{
	
	if (g_InsideCircle)
	{
		// Mouse inside circle. Red border
		utils::SetColor(1.0f, 0.f, 0.f);
		DrawEllipse(g_Circle.center, g_Circle.radius, g_Circle.radius, 2.0f);
	}

}

// Random pos between the limits of the screen and the size of the object
Point2f GetRandomPos(float width, float height)
{
	Point2f pos{};
	float limitX{ g_WindowWidth - width - width };
	float limitY{ g_WindowHeight - height - height };

	pos.x = float(rand() % int(limitX) + int(width));  // [0, g_WindowWidth - Radius]
	pos.y = float(rand() % int(limitY) + int(height)); // [0, g_WindowHeight - Radius]

	return pos;
}

// Check if mouse is inside Circle
void TestPointInCircle()
{
	g_InsideCircle = IsPointInCircle(g_MousePos, g_Circle);
	
}

// Draw a rectangle in a random pos
void DrawRectangle()
{
	utils::SetColor(1.f, 1.f, 1.f); // White

	utils::FillRect(g_Rect);


}

// Draw a red border for the rectangle if mouse is inside of it
void DrawRectBorder()
{
	if (g_InsideRect)
	{
		// Mouse inside rectangle. Red border
		utils::SetColor(1.0f, 0.f, 0.f);
		DrawRect(g_Rect, 2.0f);
	}
}
// Check if mouse is inside the rectangle
void TestPointInRect()
{
	g_InsideRect = IsPointInRect(g_MousePos, g_Rect);
}
#pragma endregion ownDefinitions