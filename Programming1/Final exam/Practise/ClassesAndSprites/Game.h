#pragma once
using namespace utils;

class Sprite;  // Class forward declaration
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Sprites and Classes - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const int g_SizeArray{ 5 };
Sprite* g_pArraSpr[g_SizeArray]{ nullptr };

Texture g_DAE1{}, g_Text{};

// Declare your own functions here

void InitArraySprites();
void DrawLogo();
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
