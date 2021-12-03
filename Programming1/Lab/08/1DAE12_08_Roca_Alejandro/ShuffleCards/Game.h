#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Shuffle Cards - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_Size{ 52 };
Texture	g_ArrayCards[g_Size]{};
bool g_Shuffle{};

// Declare your own functions here

void LoadCards();
int GetIndex(int rowIdx, int colIdx, int nrCols);
void DrawCards();
void Shuffle(Texture* pArray, const int size, const int swaps);
void Swap(Texture* pArray, const int size, const int idx1, const int idx2);
int RandomNumber(const int size);


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
