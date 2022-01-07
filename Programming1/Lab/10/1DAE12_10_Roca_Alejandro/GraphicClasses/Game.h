#pragma once
using namespace utils;

class Light;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Graphic Classes - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation


#pragma region ownDeclarations
// Declare your own global variables here
class Fraction;			// Class forward declaration (compiler only needs to know that the class exist)

const int g_TotalFractions{4};
Fraction* g_pArrayFractions[g_TotalFractions]{};
Fraction* g_pFraction1{ nullptr};
Fraction* g_pFraction2{nullptr};
Fraction* g_pFraction3{ nullptr };
Fraction* g_pFraction4{ nullptr };


const int g_Rows{ 4 };
const int g_Cols{ 2 };
const int g_SizeLightsArray{ g_Rows * g_Cols };
Light* g_pLightsArray[g_SizeLightsArray]{};
Point2f g_MousePos{};
int g_LightsOnCount{};



// Declare your own functions here
void CreateFractions();
void DeleteFractions();
void PrintFractionsSum();
void DrawFractions();
void CreateLights();
void DeleteLights();
void DrawLights();
void HitLights(const Point2f& pos);
void PrintLightsOn();
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
