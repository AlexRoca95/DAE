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
	ClearBackground(0.32f, 0.13f, 0.32f);		// Background color

	// Put your own draw statements here
	DrawHouse();
	DrawFlag();
	DrawCheckerPattern();
	DrawColorBand();
	DrawPentagram();
	DrawColumChart();
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

void DrawHouse()
{


}

void DrawFlag()
{
	//Variables for rectangles
	float rect1X{}, rect1Y{}, rect2X{}, rect2Y{}, rect3X{}, rect3Y{};	// Positions
	float rectW{}, rectH{};												// Sizes

	rectW = g_WindowWidth / 10;
	rectH = g_WindowHeight / 3;

	// Black rectangle
	utils::SetColor(0.f, 0.f, 0.f);			// Black Color

	rect1X = 0.f;							// X
	rect1Y = g_WindowHeight / 3;			// Y
	utils::FillRect(rect1X, rect1Y, rectW, rectH);

	// Yellow Rectangle
	utils::SetColor(1.f, 1.f, 0.f);			// Yellow Color

	rect2X += rectW;						// X
	rect2Y = rect1Y;						// Y
	utils::FillRect(rect2X, rect2Y, rectW, rectH);

	// Red Rectangle
	utils::SetColor(1.f, 0.f, 0.f);			// Red Color

	rect3X = rect2X + rectW;				// X
	rect3Y = rect1Y;						// Y
	utils::FillRect(rect3X, rect3Y, rectW, rectH);
}

void DrawCheckerPattern()
{
	//Variables for squares
	float squareX{}, square1Y{}, square2Y{}, square3Y{}; // Positions
	float squareW{}, squareH{};							// Sizes

	squareW = 25;
	squareH = 25;

	// First Row
		square1Y = 0.f;

		// Black rectangle (0,0)
		utils::SetColor(0.f, 0.f, 0.f);			// Black Color

		squareX = 0.f;
		utils::FillRect(squareX, square1Y, squareW, squareH);

		// White rectangle (0,1)
		utils::SetColor(1.f, 1.f, 1.f);			// White Color

		squareX = squareW;
		utils::FillRect(squareX, square1Y, squareW, squareH);

		// Black rectangle (0,2)
		utils::SetColor(0.f, 0.f, 0.f);			

		squareX = squareW * 2;
		utils::FillRect(squareX, square1Y, squareW, squareH);

	// Second Row
		square2Y = squareH;

		// Rectangle (1,0)
		utils::SetColor(1.f, 1.f, 1.f);			

		squareX = 0.f;
		utils::FillRect(squareX, square2Y, squareW, squareH);

		// Rectangle (1,1)
		utils::SetColor(0.f, 0.f, 0.f);

		squareX = squareW;
		utils::FillRect(squareX, square2Y, squareW, squareH);

		// Rectangle (1,2)
		utils::SetColor(1.f, 1.f, 1.f);

		squareX = squareW * 2;
		utils::FillRect(squareX, square2Y, squareW, squareH);
	
	// Third Row
		square3Y = squareH * 2;
		// Rectangle (2,0)
		utils::SetColor(0.f, 0.f, 0.f);

		squareX = 0.f;
		utils::FillRect(squareX, square3Y, squareW, squareH);

		// Rectangle (2,1)
		utils::SetColor(1.f, 1.f, 1.f);

		squareX = squareW;
		utils::FillRect(squareX, square3Y, squareW, squareH);

		// Rectangle (2,2)
		utils::SetColor(0.f, 0.f, 0.f);

		squareX = squareW * 2;
		utils::FillRect(squareX, square3Y, squareW, squareH);
}

void DrawColorBand()
{

}

void DrawPentagram()
{
	// Polar Coordinates (Unit Circle)
	// x = R. cos(alpha)
	// y = R. sin(alpha)
	//
	// x = r(radius) x cos(alpha) + offset.x
	// y = r/radius) x sin(alpha) + offset.y


}

void DrawColumChart()
{

	// % of people that plays videogames

	float rect1X{}, rect2X{}, rect3X{}, rect4X{};		// X Positions
	float rect1Y{}, rect2Y{}, rect3Y{}, rect4Y{};

	// First Colum [0, 20]
	utils::SetColor(0.f, 0.89f, 1.f);


	// Second Colum [20, 40]


	// Third Colum [40, 60]


	// Fourth Colum [Older than 60]



}

#pragma endregion ownDefinitions