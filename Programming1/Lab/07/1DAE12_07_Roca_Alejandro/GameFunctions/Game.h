#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Game Functions - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

Point2f g_MousePos{ };
Circlef g_Circle{};
bool g_InsideCircle{};

Rectf g_Rect{};
bool g_InsideRect{};

Rectf g_MouseRect{};
bool g_OverlappinRect{};

Circlef g_MouseCircle{};
bool g_OverlappinCircle{};

// Declare your own functions here
void DrawFilledCircle();
void DrawCircleBorder();
Point2f GetRandomPos(float width, float height);
void TestPointInCircle();
void DrawRectangle();
void TestPointInRect();
void DrawRectBorder();

void CheckColor(bool);
void DrawRectMouse();
void DrawCircleMouse();
void TestOverlappingRect();

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
