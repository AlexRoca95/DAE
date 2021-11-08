#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "QWeek Example - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

int g_Even{}, g_Odd{}, g_Any{};
float g_TotalElapsedTime;				// Total time elapsed

int g_Border{};								// Border of the screen
Point2f g_MousePos{};						// Mouse X and Y 
int g_PosX{}, g_PosY{};						// Elevator X and Y positions

// Variables for drawing the elevator
int g_Interior_w{}, g_Interior_h{};			// Interior space sizes
int g_Elevator_w{}, g_Elevator_h{};			// Exterior width and height sizes of elevator
int g_Wall_thickness{};		

bool g_MoveElevator{};						// True --> Move elevator / False --> Dont move it
enum class ElevatorDirect {

	Up,
	Down,
	Stop
};
ElevatorDirect g_Direction{ ElevatorDirect::Stop };
bool g_Direct{};		// False --> Up / True --> Down For moving elevator memory

// Declare your own functions here
//1. Exercise
void Generate();					// Generate new values for g_Even, g_Odd and g_Any
void PrintRandomNumbers();			// Print the random values

void CheckMouseElevator();
void MoveElevator();
void CheckLimits();

//2. Exercise
void DrawElevator();				// Draws the elevator

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
