#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "FrameTime - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

// Circle variables
float g_CircleX{}, g_CircleY{};				// X & Y Positions of circle
float g_SpeedX{}, g_SpeedY{};
const float g_Radius{ 30.f };				// Radius of the circle

// Square variables
Point2f g_SquarePos{};
float g_Width{};
float g_Vel{};
float g_Gravity{ -9.8f };
bool g_Fall{};

float g_InitialY{ };

// Declare your own functions here

void DrawBall();
void DrawFreeFall();
void UpdateBall(float);
void UpdateFreeFall(float);

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
