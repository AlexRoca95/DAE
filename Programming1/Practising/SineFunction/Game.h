#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Sine Function - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

float g_FullAngle{ 2 * g_Pi };				// Full angle = Full circle = 360 degrees
float g_Angle{ 0 };							// Keeps track of Angle for the sin function
float g_Step{ (g_Pi / 180) };					// 1 degree = pi / 180 rad = step


float g_StartXSin{ 50 };
float g_PosY{}, g_PosY2{};
float g_PosX{ g_StartXSin }, g_PosX2{ g_PosX + 1 };   // X positions for the sine function

// Declare your own functions here

void DrawSineFunction();
void DrawRectangle();

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
