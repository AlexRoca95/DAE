#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Sprites - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
// Hold information about animated sprite
struct Sprite
{
	Texture texture;
	int frames;
	int cols;
	float frameTime;
	int currentFrame;
	float accumulatedTime;
	float xPos;
};

Sprite g_KnightSprite{};
const float initialPos{ };
float g_KnightPos{};
const float g_KnightSpeed{ 10.f };


Sprite g_TiboSprite{};
float g_TiboPos{ 10.f };
// Declare your own functions here

void InitSprite(Sprite& sprite, std::string path, int cols, int frames, float frameTime, int currentFrame, float xPos);
void UpdateSprite(Sprite& sprite, float elapsedSec);

// Knight sprite
void DrawKnight();
void MoveKnight();

// Tibo Sprite
void DrawTibo();


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
