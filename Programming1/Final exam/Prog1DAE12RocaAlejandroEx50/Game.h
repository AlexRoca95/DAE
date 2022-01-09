#pragma once
using namespace utils;

class Tile;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "EX50 - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_TotalAnimals{ 6 };		// Total number of animals in the tile
const float g_SizeTiles{ 128.f };	// Size of the rectangular tiles
const float g_StartLeftTiles{ (g_WindowWidth / 2) - g_SizeTiles };
const float g_StartBottomTiles{ g_WindowHeight / 2 };
bool g_SameAnimal{};
const int g_TotalTiles{ 4 };
Tile* g_pArrayTiles[g_TotalTiles]{nullptr};

Point2f g_MousePos{};
bool g_CheckSolve{};

Texture g_AnimalsName{};

// Declare your own functions here

void InitArrayTiles();			// Initialize the array holding the tiles
void DrawTiles();
void DrawPuzzleBorder();
void CheckMouseTiles();
void CheckNextAnimal(const Point2f& pos);
int GetIndex(int rowIdx, int colIdx, int nrCols);
void DeactivateTiles();
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
