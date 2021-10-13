#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "GrowingBars - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
unsigned int g_NrFrames{};							// Frame Count
const float g_Border{ 10.f };						// Window Border

// Bar variables
const float g_MaxWidth{ g_WindowWidth - g_Border };		// Bars Max Width Size
const float g_BarHeight{ 50.f };						// Bars Max Height 
const float g_YellowBarY{(g_WindowHeight / 3) * 2 };	// Yello Bar Y pos
const float g_RedBarY{ g_Border + 40 };					// Red Bar Y pos

float g_YellowBarWidth{ 0.f };						// Yellow Bar Width					
float g_RedBarWidth{ 0.f };							// Red Bar Width


// Declare your own functions here
void DrawYellowBar();
void DrawRedBar();

void UpdateYellowBar();
void UpdateRedBar();
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
