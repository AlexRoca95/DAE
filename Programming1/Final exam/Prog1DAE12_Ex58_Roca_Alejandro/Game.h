#pragma once
using namespace utils;

class Vehicle;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "EX58 - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Texture g_Background{}, g_WinText, g_LoseText, g_PauseText;

const float g_PavementSize{ 43.f };

struct Chicken {

	Texture image;
	Rectf position;			// Position of the chicken
	Rectf srcRect;			// Frame rect values
	float speed;
	int nFrames;			//Number of frames
	int currentFrame;		
	float scale;				// Scale of the chicken


};
Chicken g_Chicken{};

const int g_TotalVehicles{ 5 };
Vehicle* g_Vehicles[g_TotalVehicles]{};


// States of the game
enum class GameState {

	play,
	pause,
	win,
	lose,
	reset

};
GameState g_GameState{};

// Declare your own functions here

void InitGame();
void InitChicken();
void InitVehicles();

void LoadResources();
void LoadTexture(Texture& image, const std::string path);
void LoadFont(Texture& image, const std::string text, const std::string path);

void ResetChickenPos();
void ActivateVehicles();

void DrawBackground();
void DrawChicken();
void DrawFont(const Texture& image);
void DrawVehicles();

void PrintInfoGame();

void moveChicken(float elapsedSec);
void moveVehicles(float elapsedSec);
void checkCollision();

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
