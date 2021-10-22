#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "EventsAndDrawing - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
enum class StateRect {
	 
	changePos,			// Change to random pos
	changeColor,		// Change to color green
	notChange,

};

enum class DrawARect {

	draw,
	notDraw
};

enum class MoveARect {

	move,				// Start moving rect
	noMove,				// Stop moving rect
};


StateRect stateRect{};
DrawARect drawRect{};
MoveARect moveRect{};
Color4f g_ColorRect{ };
Point2f g_MousePos{};
int g_DistanceBorder{};
int g_MinHeightRect{}, g_MinWidthRect{};
int g_WidthRect{}, g_HeightRect{}, g_PosX{}, g_PosY{};
int PosXRect2;

// Declare your own functions here

void DrawRandomRect();
void DrawNewRect();

void UpdateValuesRect();
void MoveRect();

void CheckMouseRect();
void CheckMoveRect();

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
