#pragma once
using namespace utils;				// We tell compiler that some functions will come from this namespace (No errors)
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "SDLAndOpenGL - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();						// Called once at the start of the app (Initialization things..)
void Draw();						// 2º
void Update(float elapsedSec);		// 1º
void End();							// Called once when we press x button to close app (Clean things)
#pragma endregion gameFunctions

// EVENTS
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key); 
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
