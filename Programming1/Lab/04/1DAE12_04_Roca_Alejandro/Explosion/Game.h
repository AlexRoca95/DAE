#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Explosion - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
bool g_Bomb{};			// True --> Explision start / False --> Explosion ended

int g_SquareSize{}, g_BombX{}, g_BombY{};
// Red squares x and y pos
int g_RedSquareX1{}, g_RedSquareY1{}, g_RedSquareX2{}, g_RedSquareY2{}, g_RedSquareX3{}, g_RedSquareY3{};
int g_RedSquareX4{}, g_RedSquareY4{};
Point2f g_MousePos{};		// Mouse x and y pos 



// Declare your own functions here
void ProcessMouseClick();

void UpdateExplosion();

void DrawExplosion();
void DrawRedSquares();

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
