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
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawSquares();

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


void DrawSquares()
{
	float squareSize{ 200.f };		// Size of the squares
	float border{ 10.f };			// Distance between border - window

	// Up right square
	utils::SetColor(0.13f,0.61f,0.13f);
	utils::FillRect(g_WindowWidth / 2, g_WindowHeight / 2, squareSize, squareSize);

	// Down left square
	utils::FillRect(border, border, squareSize, squareSize);

	// Drawing lines
	utils::SetColor(1.f, 1.f, 1.f);
	// Inner line betweew both squares
	utils::DrawLine(border, border, g_WindowWidth-border, g_WindowHeight - border);

	// Outer lines conecting both squares
	utils::DrawLine(border, g_WindowHeight / 2, g_WindowWidth / 2, g_WindowHeight - border);
	utils::DrawLine(g_WindowWidth / 2, border, g_WindowWidth - border, g_WindowHeight / 2);

	// Lines that surround squares
		// Up square
		utils::DrawLine(g_WindowWidth / 2, g_WindowHeight / 2, (g_WindowWidth) - border, g_WindowHeight / 2);
		utils::DrawLine(g_WindowWidth / 2, g_WindowHeight / 2, g_WindowWidth / 2, g_WindowHeight - border);
		utils::DrawLine(g_WindowWidth - border, g_WindowHeight / 2, (g_WindowWidth)-border, g_WindowHeight - border);
		utils::DrawLine(g_WindowWidth / 2, g_WindowHeight - border, (g_WindowWidth)-border, g_WindowHeight - border);

		// Down square
		utils::DrawLine(border, border, g_WindowWidth / 2, border);
		utils::DrawLine(border, border, border , g_WindowHeight / 2);
		utils::DrawLine(g_WindowWidth / 2, border, g_WindowWidth / 2, g_WindowHeight / 2);
		utils::DrawLine(border, g_WindowHeight / 2, g_WindowWidth / 2, g_WindowHeight / 2);
}

#pragma endregion ownDefinitions