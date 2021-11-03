#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Matches Game - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

float g_Border{};										// Space between border and drawing
float g_MainPile{}, g_UserPile{}, g_ComputerPile{};		// Hold the number of matches
float g_MatchWidth{}, g_MatchHeight{}, g_SmallMatchH{};		// Sizes of the match
std::string g_CountPlayer{}, g_CountComputer{};

int g_MatchesToTake{};									// Number of matches the player takes
bool g_UserTookMatches{};								// To know if the user took matches or not
bool g_PlayerWin{}, g_ComputerWin{};					// To know who looses and wins

// Declare your own functions here
void DrawPileMatches();					// Draw the pile of matches
void UpdatePiles();
void ComputerTurn();
void EndGame();


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
