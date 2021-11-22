#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "DrawFunctions - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_YPosGrad{};							// Position for rectangles in LinearGradient

const float g_Radian60{ 1.0472f};		    // Value of 60 degrees in radians

const float g_Border{ 10 };					// Window border size

const float g_LengthTriangle{ 80.f };		// Length of the sides of the triangles
// Declare your own functions here

void DrawSquares();		
void DrawSquare(Point2f, float, int);
void DrawEquilateralTriangles();
void DrawEquilateralTriangle(Point2f, float, bool, Color4f);
void DrawLinearGradients();
void DrawLinearGradient(Rectf, Color4f, Color4f);

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
