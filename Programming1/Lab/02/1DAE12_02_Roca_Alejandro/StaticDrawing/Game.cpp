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
	float rect1X{}, rect2X{}, rect3X{};									//X Positions
	float rectY;														// Y position (same for all)
	float rectW{}, rectH{};												// Sizes

	// Same values for all rectangles
	rectW = g_WindowWidth / 10;
	rectH = g_WindowHeight / 3;
	rectY = g_WindowHeight / 3;			

	// Black rectangle
	utils::SetColor(0.f, 0.f, 0.f);			// Black Color

	rect1X = g_border;						// X
	utils::FillRect(rect1X, rectY, rectW, rectH);

	// Yellow Rectangle
	utils::SetColor(1.f, 1.f, 0.f);			// Yellow Color

	rect2X = rect1X + rectW;				// X
	utils::FillRect(rect2X, rectY, rectW, rectH);

	// Red Rectangle
	utils::SetColor(1.f, 0.f, 0.f);			// Red Color

	rect3X = rect2X + rectW;				// X
	utils::FillRect(rect3X, rectY, rectW, rectH);
}

void DrawCheckerPattern()
{
	//Variables for squares
	float squareX{}, square1Y{}, square2Y{}, square3Y{}; // Positions
	float squareW{}, squareH{};							// Sizes
	float initialX{ g_border };									// Start X position for first colum of all rows
	squareW = 25;
	squareH = 25;

	// First Row
		square1Y = g_border;

		// Black rectangle (0,0)
		utils::SetColor(0.f, 0.f, 0.f);			// Black Color

		squareX = initialX;
		utils::FillRect(squareX, square1Y, squareW, squareH);

		// White rectangle (0,1)
		utils::SetColor(1.f, 1.f, 1.f);			// White Color

		squareX = squareX + squareW;
		utils::FillRect(squareX, square1Y, squareW, squareH);

		// Black rectangle (0,2)
		utils::SetColor(0.f, 0.f, 0.f);			

		squareX = squareX + squareW;
		utils::FillRect(squareX, square1Y, squareW, squareH);

	// Second Row
		square2Y = square1Y + squareH;

		// Rectangle (1,0)
		utils::SetColor(1.f, 1.f, 1.f);			

		squareX = initialX;
		utils::FillRect(squareX, square2Y, squareW, squareH);

		// Rectangle (1,1)
		utils::SetColor(0.f, 0.f, 0.f);

		squareX = squareX + squareW;
		utils::FillRect(squareX, square2Y, squareW, squareH);

		// Rectangle (1,2)
		utils::SetColor(1.f, 1.f, 1.f);

		squareX = squareX + squareW;
		utils::FillRect(squareX, square2Y, squareW, squareH);
	
	// Third Row
		square3Y = square2Y + squareH;
		// Rectangle (2,0)
		utils::SetColor(0.f, 0.f, 0.f);

		squareX = initialX;
		utils::FillRect(squareX, square3Y, squareW, squareH);

		// Rectangle (2,1)
		utils::SetColor(1.f, 1.f, 1.f);

		squareX = squareX + squareW;
		utils::FillRect(squareX, square3Y, squareW, squareH);

		// Rectangle (2,2)
		utils::SetColor(0.f, 0.f, 0.f);

		squareX = squareX + squareW;
		utils::FillRect(squareX, square3Y, squareW, squareH);
}

void DrawColorBand()
{
	// Variables
	float rectY1{}, rectY2{};
	float rectX1{}, rectX2{}, rectX3{}, rectX4{}, rectX5{}, rectX6{}, rectX7{}, rectX8{}, rectX9{};
	float rectW{}, rectH{};

	rectW = 25.f;
	rectH = 60.f;
	rectY1 = g_WindowHeight - rectH - g_border;

	// NORMAL RECTANGLES
	// 1º rectangle
	rectX1 = g_WindowWidth / 2;
	
	utils::SetColor(0.f, 0.f, 0.f);
	utils::FillRect(rectX1, rectY1, rectW, rectH);

	// 2º rectangle
	rectX2 = rectX1 + rectW;

	utils::SetColor(1.f, 0.f, 0.f);
	utils::FillRect(rectX2, rectY1, rectW, rectH);

	// 3º rectangle
	rectX3 = rectX2 + rectW;

	utils::SetColor(0.31f, 1.f, 0.f);
	utils::FillRect(rectX3, rectY1, rectW, rectH);

	// 4º rectangle
	rectX4 = rectX3 + rectW;

	utils::SetColor(0.f, 0.f, 1.f);
	utils::FillRect(rectX4, rectY1, rectW, rectH);

	// 5º rectangle
	rectX5 = rectX4 + rectW;

	utils::SetColor(1.f, 0.f, 1.f);
	utils::FillRect(rectX5, rectY1, rectW, rectH);

	// 6º rectangle
	rectX6 = rectX5 + rectW;

	utils::SetColor(1.f, 1.f, 0.f);
	utils::FillRect(rectX6, rectY1, rectW, rectH);

	// 7º rectangle
	rectX7 = rectX6 + rectW;

	utils::SetColor(0.f, 1.f, 0.f);
	utils::FillRect(rectX7, rectY1, rectW, rectH);

	// 8º rectangle
	rectX8 = rectX7 + rectW;

	utils::SetColor(0.f, 1.f, 1.f);
	utils::FillRect(rectX8, rectY1, rectW, rectH);

	// 9º rectangle
	rectX9 = rectX8 + rectW;

	utils::SetColor(1.f, 1.f, 1.f);
	utils::FillRect(rectX9, rectY1, rectW, rectH);

	// DARK RECTANGLES
	
	rectY2 = rectY1 - rectH;				// Down the other rectangles
	
	// 1º  Dark rectangle 
	rectX1 = g_WindowWidth / 2;

	utils::SetColor(0.f, 0.f, 0.f, 0.6f);
	utils::FillRect(rectX1, rectY2, rectW, rectH);

	// 2º rectangle
	rectX2 = rectX1 + rectW;

	utils::SetColor(1.f, 0.f, 0.f, 0.6f);
	utils::FillRect(rectX2, rectY2, rectW, rectH);

	// 3º rectangle
	rectX3 = rectX2 + rectW;

	utils::SetColor(0.31f, 1.f, 0, 0.6f);
	utils::FillRect(rectX3, rectY2, rectW, rectH);

	// 4º rectangle
	rectX4 = rectX3 + rectW;

	utils::SetColor(0.f, 0.f, 1.f, 0.6f);
	utils::FillRect(rectX4, rectY2, rectW, rectH);

	// 5º rectangle
	rectX5 = rectX4 + rectW;

	utils::SetColor(1.f, 0.f, 1.f, 0.6f);
	utils::FillRect(rectX5, rectY2, rectW, rectH);

	// 6º rectangle
	rectX6 = rectX5 + rectW;

	utils::SetColor(1.f, 1.f, 0.f, 0.6f);
	utils::FillRect(rectX6, rectY2, rectW, rectH);

	// 7º rectangle
	rectX7 = rectX6 + rectW;

	utils::SetColor(0.f, 1.f, 0.f, 0.6f);
	utils::FillRect(rectX7, rectY2, rectW, rectH);

	// 8º rectangle
	rectX8 = rectX7 + rectW;

	utils::SetColor(0.f, 1.f, 1.f, 0.6f);
	utils::FillRect(rectX8, rectY2, rectW, rectH);

	// 9º rectangle
	rectX9 = rectX8 + rectW;

	utils::SetColor(1.f, 1.f, 1.f, 0.6f);
	utils::FillRect(rectX9, rectY2, rectW, rectH);


	// YELLOW BORDER
	utils::SetColor(1.f, 1.f, 0.f);

	// TOP yellow border
	utils::DrawLine(rectX1, rectY1 + rectH, rectX9 + rectW, rectY1 + rectH, 2.f);

	// BOTTOM yellow border
	utils::DrawLine(rectX1, rectY2, rectX9 + rectW, rectY2, 2.f);

	// LEFT yellow border
	utils::DrawLine(rectX1, rectY2, rectX1, rectY1 + rectH, 2.f);

	// RIGHT yellow border
	utils::DrawLine(rectX9 + rectW, rectY2, rectX9 + rectW, rectY1 + rectH, 2.f);


}

void DrawPentagram()
{
	// Polar Coordinates (Unit Circle)
	// x = R. cos(alpha)
	// y = R. sin(alpha)
	//
	// x = r(radius) x cos(alpha) + offset.x
	// y = r/radius) x sin(alpha) + offset.y


	/*float radius{}, posX{}, posY{}, width{}, height{};


	radius = 40.f;					// Radius of the circle
	posX = ((g_WindowWidth / 3)*2) + radius;
	posY = (g_WindowHeight / 3)*2;
	width = 5;
	height = 5;
	utils::SetColor(1.f, 0.f, 0.50f);

	// First point (posX, radius)

	utils::FillRect(posX, posY, width, height);*/


}

void DrawColumChart()
{

	// % of people that plays videogames

	float rect1X{}, rect2X{}, rect3X{}, rect4X{};			// X Positions
	float rectY{ g_border };								// Y Position for all rectangles
	float rectW{};
	float maxValue{ 100.f };								// Max value for porcentages

	rectW = g_WindowWidth / 10;								// Width of rectangles

	float rect1H{}, rect2H{}, rect3H{}, rect4H{};
	float range0To20{}, range21To40{}, range41To60{}, older60{};

	std::cout << "% of people playing games " << std::endl;
	std::cout << "In the range [0, 20]? ";
	std::cin >> range0To20;
	std::cout << "In the range [20, 40]? ";
	std::cin >> range21To40;
	std::cout << "In the range [40, 60]? ";
	std::cin >> range41To60;
	std::cout << "Older than 60? ";
	std::cin >> older60;

	// First Colum [0, 20]
	utils::SetColor(0.f, 0.89f, 1.f);

	rect1X = g_WindowWidth / 2;
	rect1H = maxValue * (range0To20 / 100);					
	utils::FillRect(rect1X, rectY, rectW, rect1H);

	// Second Colum [20, 40]
	utils::SetColor(0.f, 0.60f, 0.80f);

	rect2X = rect1X + rectW;
	rect2H = maxValue * (range21To40 / 100);
	utils::FillRect(rect2X, rectY, rectW, rect2H);

	// Third Colum [40, 60]
	utils::SetColor(0.f, 0.75f, 1.f);

	rect3X = rect2X + rectW;
	rect3H = maxValue * (range41To60 / 100);
	utils::FillRect(rect3X, rectY, rectW, rect3H);

	// Fourth Colum [Older than 60]
	utils::SetColor(0.f, 0.55f, 0.80f);

	rect4X = rect3X + rectW;
	rect4H = maxValue * (older60 / 100);
	utils::FillRect(rect4X, rectY, rectW, rect4H);
	
}

#pragma endregion ownDefinitions