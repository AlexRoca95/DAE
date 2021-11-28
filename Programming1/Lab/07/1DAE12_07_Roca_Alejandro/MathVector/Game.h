#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Math Vector - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Vector2f g_Vector{ 100.f, 50.f };


Vector2f g_V1Animation{ 50.f, 0.f };
const float g_Step{ 0.3141f };				//20 degrees each step
float g_Angle{ g_Step };
const float g_Scale{ g_V1Animation.x };
const float g_FullAngle{ g_Pi * 2 };
Point2f translation{g_Scale, g_Scale };


// Declare your own functions here

void DrawVectors();
void AddVectors();
void TestSubVectors();
void TestDotProduct();
void TestCrossProduct();
void TestLength();
void TestScale();
void TestNormalize();
void TestAngleBetween();
void TestAreEqual();

void AnimationProjection();
void UpdateVector(float elapsedSec);
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
