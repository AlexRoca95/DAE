#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "SlidingRectangles - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const unsigned int g_SquareSize{ 100 };			// Sizes of the squares

// Yellow Square X - Y values
float g_YellowX{ 0 };
float g_YellowY{ 0 };
// Red Square X - Y values
float g_RedX{ 0 };
float g_RedY{ 0 };
// Blue Square X - Y values
float g_BlueX{ 0 };
float g_BlueY{ 0 };
// Green Square X - Y values
float g_GreenX{ 0 };
float g_GreenY{ 0 };

// Declare your own functions here

// Drawing functions
void DrawRedSquare();
void DrawYellowSquare();
void DrawGreenSquare();
void DrawBlueSquare();

// Update functions
void UpdateRedSquare();
void UpdateYellowSquare();
void UpdateGreenSquare();
void UpdateBlueSquare();

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
