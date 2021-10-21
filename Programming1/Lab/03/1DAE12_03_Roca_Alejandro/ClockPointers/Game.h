#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Clock pointers - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

double g_BigAngleX{ 0 };
double g_BigAngleY{ 0 };
double g_SmallAngleX{ 0 };
double g_SmallAngleY{ 0 };
const double g_FullAngle{ 2 * M_PI };

double g_BigPosX{ 0 };
double g_BigPosY{ 0 };
double g_SmallPosX{ 0 };
double g_SmallPosY{ 0 };

// Declare your own functions here

void UpdateAngle();
void DrawBigClockWise();
void DrawSmallClockWise();

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
