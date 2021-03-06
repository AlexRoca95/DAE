#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "DiceStats - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_HeightRect{};				// Height of the rectangles
int g_SeparationRect{};			// Separation between the draw of the first set of rects
int g_SeparationRect2Dice{};	// Separation between the draw of the second set of rects
// One dice variables
int g_Dice1_1{}, g_Dice1_2{}, g_Dice1_3{}, g_Dice1_4{}, g_Dice1_5{}, g_Dice1_6{};

// 2 dice variables
int g_Dice2_1{}, g_Dice2_2{}, g_Dice2_3{}, g_Dice2_4{}, g_Dice2_5{}, g_Dice2_6{}, g_Dice2_7{}, g_Dice2_8{};
int g_Dice2_9{}, g_Dice2_10{}, g_Dice2_11{}, g_Dice2_12{};

// Declare your own functions here
void Draw1Dice();
void Draw2Dice();
void Roll1Dice();
void Roll2Dice();

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
