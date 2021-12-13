#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Battleship - Roca,Alejandro_ - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 1000 };
float g_WindowHeight{ 720 };
#pragma endregion gameInformation


// States of the Game
enum class StateGame {

	Start,				// Start of the Game --> MENU
	Placing,			// Placing ships
	Playing,			// Game Start
	EndGame				// Game fnish 

};

// Holds info about the ships
struct Ship {

	Point2f firstCell;		// Pos from the cell the player clicked
	int size;				// Size of the ship
	int countHits;			// Count of hits 
	Texture text;
	Rectf type;				// Type of the ship
	bool rotate;			// Ship rotated or not
	bool placed;			// Ship placed into the grid or not
};

// Holds info about the cells from the grid
struct GridCell {

	Ship shipInfo;		// All data from the ship placed in the cell
	bool ship;			// True --> Ship in the cell / False --> No ship
	bool shoot;			// True --> Cell shooted / False --> Not shooted yet
	bool miss;			// True --> Enemy shoot here and missed
	Point2f pos;		// Pos of the cell
	bool first;			// True --> First cell for the ship	

};


struct Player {

	int shipsLeft;
};

struct Enemy {

	int shipsLeft;
	bool lastShoot;		// Hit last shoot?
	int lastRow;
	int lastCol;
};

#pragma region ownDeclarations
// Declare your own global variables here

//		 GRID VARIABLES
const int g_GridSize{ 10 };
const float g_CellSize{ 34 };
const Point2f g_GridPlayerPos{ g_WindowWidth/2 - ((g_GridSize / 2) * g_CellSize), 10.f};
const Point2f g_GridEnemyPos{ g_GridPlayerPos.x, (g_WindowHeight / 2) + 10.f };
GridCell g_PlayerGrid[g_GridSize * g_GridSize]{};
GridCell g_EnemyGrid[g_GridSize * g_GridSize]{};


Point2f g_MousePos{};					// Info about mouse pos when me move it
Point2f g_MouseClickPos{};				// info about the mouse pos when we left click

Player g_Player{};
int g_PlayerCountHits{};
Enemy g_Enemy{};
int g_EnemyCountHits{};

int g_MaxHits{ 17 };

//		SHIPS VARIABLES
const int g_ArraysShipSize{ 5 };
int g_ShipsLeft{ };						// Ships left
int g_ShipsIndex{};
bool g_NextShip{};						// Select next ship or not (Placing state)
bool g_PreviousShip{};
bool g_RotateShip{};
bool g_MouseClicked{};
bool g_PlayerTurn{};

//Ship g_ArrayShips[g_ArraysShipSize]{};   // Array containing all the ships
Ship* g_pPlayerArrayShips{};
Ship* g_pEnemyArrayShips{};
StateGame state{};


Texture g_StartScreen{}, g_WinText{}, g_LooseText{};
Texture g_Ships{}, g_CarrierText{}, g_BattleshipText{}, g_DestroyerText{}, g_SubmarineText{}, g_PatrolBoatText{};
// Declare your own functions here

// Init functions
void InitGame();
void InitGrid(GridCell* grid, float startX, float startY);
void InitShips();
void InitShip(Ship* arrayShips, Ship& ship, int size, int index);

// Draw functions
void DrawGrid(GridCell* grid);
void DrawShipPlacement();
void DrawShipInGrid(GridCell* grid, int idx, int rowIdx, int colIdx);
bool DrawEnemyMove(GridCell* grid, int idx);

// Update functions
void UpdateShipPlacing();
void SelectShip();
void RotateShip();
void CheckShipPlacement();
void SafeInfoShipInGrid(GridCell* grid, int idx, float offSetX, float offSetY, int rowIdx, int colIdx);
void PlayerShoot(GridCell* grid);
void EnemyShoot();

void PlaceEnemyShips();


int GetIndex(int rowIdx, int colIdx, int nrCols);

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
