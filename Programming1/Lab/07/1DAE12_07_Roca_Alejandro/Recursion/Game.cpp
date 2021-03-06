#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.30f);

	// Put your own draw statements here
	Point2f left{ 0.f, 0.f };
	Point2f right{ g_WindowWidth, 0.f };
	Point2f top{ g_WindowWidth / 2, g_WindowHeight };
	DrawSierpinskiTriangle(left, top, right);

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

// Draw a triangle with the given vertices and 3 inner triangles
void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f& right)
{	
	// Main triangle
	utils::DrawTriangle(left, top, right);

	if (utils::GetDistance(left, right) < 20.f)
	{
		// Base Case
		return;
	}

	// Recursive case
	Point2f middPoint1{}, middPoint2{};
	// Left red triangle
	middPoint1.x = (left.x + top.x) / 2;
	middPoint1.y = (left.y + top.y) / 2;
	middPoint2.x = (left.x + right.x) / 2;
	middPoint2.y = (left.y + right.y) / 2;

	utils::SetColor(1.0f, 0.f, 0.f);
	DrawSierpinskiTriangle(left, middPoint1, middPoint2);

	// Right blue triangle
	utils::SetColor(0.0f, 0.f, 1.f);
	middPoint1.x = (right.x + left.x) / 2;
	middPoint1.y = (right.y + left.y) / 2;
	middPoint2.x = (right.x + top.x) / 2;
	middPoint2.y = (right.y + top.y) / 2;
	DrawSierpinskiTriangle(middPoint1, middPoint2, right);

	// Top green triangle
	utils::SetColor(0.0f, 1.f, 0.f);
	middPoint1.x = (top.x + left.x) / 2;
	middPoint1.y = (top.y + left.y) / 2;
	middPoint2.x = (top.x + right.x) / 2;
	middPoint2.y = (top.y + right.y) / 2;
	DrawSierpinskiTriangle(middPoint1, top, middPoint2);

}

#pragma endregion ownDefinitions