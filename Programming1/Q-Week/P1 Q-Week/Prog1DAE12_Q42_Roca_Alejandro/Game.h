#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Q42 - Roca, Alejandro - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
// States of the circle
enum class Circlestates {

	growing,
	shrinking,
	waiting
};

// For holding the circle color values
struct ColorsCircle {

	float r;
	float g;
	float b;
};
ColorsCircle g_ColorCircle{};
Circlestates g_StatusCircle{};

bool g_ChangeValues{};					// True --> Values of circle have to change / False --> No changes
bool g_ChangeSpeed{};					// True --> More speed / False --> Less speed

Point2f g_MousePos{};					// Mouse X and Y position
int g_MaxRadius{};						// Max radius for the circle
float g_RadiusCircle{};					// The current radius of the circle
float g_Speed{};						// Speed of growing/shrinking of the radius
float g_Step{};							// Steps of speed


// Declare your own functions here

void PrintLetters();					// Print the alphabet and amount of letters per line given by the user


void CheckCircleStatus();				// Check if the circle is wainting and if it is true, change it to growing
void DrawCircle();						// Draws the circle
void GenerateNewValues();				// Generates a new random max radius [50, 150] and a new color
void UpdateSizeCircle();				// Update the radius of circle deppending on growing/shrinking
void CheckCollision();					// Check if circle has a collision with the window border
void ChangeSpeed();						// Change the speed of growing/shrinking


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
