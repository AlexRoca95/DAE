#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "OxoGame - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
enum Letter {	// Options for the board
	X,
	O
};

enum Choice {
	// Holds the choices for the player
	greenO,
	whiteO,
	whiteX,
	greenX
};

struct Player {

	Point2f pos;			// pos of the texture
	bool active;			// To know if it is the player turn or not
	bool key_pressed;		// Key pressed to change selection
	Choice choice;			// Choice of the player 
};

struct Cell {
	Texture texture;
	Point2f pos;
	bool free;
};

Player g_PlayerLeft{}, g_PlayerRight{};
Texture g_Background{}, g_GreenO{}, g_GreenX{}, g_FreeCell{}, g_Win{}, g_WhiteO{}, g_WhiteX{};
Texture g_Choices[4];		// Holds all the choices for the player's (greenO, greenX, whiteO, whiteX)


const float g_Border{ 10.f };
const int g_BoardSize{ 9 };
const float g_CellSize{ 50.f };

Cell g_BoardArray[g_BoardSize]{};


// Declare your own functions here
void LoadResources();
void LoadTexture(Texture& texture, std::string path);
void InitGame();
void InitPlayers();
void InitBoard();

void DrawGame();
void DrawCell(const Texture& texture, const float xPos, const float yPos);
void DrawBackground();
void DrawBoard();
void DrawPlayers();

void UpdatePlayers();
void UpdateChoice(Player& player);

int GetIndex(int rowIdx, int colIdx, int nrCols);

void CheckMouse(float posX, float posY, Player&);
void SelectCell(Cell& selection);

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
