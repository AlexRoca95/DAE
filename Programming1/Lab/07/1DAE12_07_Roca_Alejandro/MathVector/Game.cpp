#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	std::string st = ToString(g_Vector);
	std::cout << st << std::endl;

	TestDotProduct();
	TestCrossProduct();
	TestLength();
	TestScale();
	TestNormalize();
	TestAngleBetween();
	TestAreEqual();
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.30f);

	DrawVectors();
	AddVectors();
	TestSubVectors();
	AnimationProjection();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}

	UpdateVector(elapsedSec);
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void DrawVectors()
{
	utils::SetColor(1.f, 1.f, 0.f); // Yellow
	Point2f start{ 20.f, 10.f };

	utils::DrawVector(g_Vector, start);
}

// Test the adding vectors function
void AddVectors()
{
	utils::SetColor(0.f, 1.f, 0.f); // Green

	// Second vector starts at the end of first one
	Vector2f vector1{ 100.0f, 10.0f };
	Vector2f vector2{ 50.0f,30.0f };

	// Third vector starts at the startPoint of first vector
	Vector2f vector3{ Add(vector1, vector2) };
	Point2f startPoint{ 50.0f, 10.0f };

	DrawVector(vector1, startPoint);
	DrawVector(vector2, Point2f{ startPoint.x + vector1.x, startPoint.y + vector1.y });
	DrawVector(vector3, startPoint);
}

// Test the subtraction of vectors function
void TestSubVectors()
{
	utils::SetColor(1.f, 1.f, 1.f); // White

	// Two vectors that start at the same initial Point
	Point2f startPoint{ 160.0f, 50.0f };
	Vector2f vector1{ 170.0f, 70.0f };
	Vector2f vector2{ 190.f,50.0f };

	// Subtract vector start at the end of the second vector
	Vector2f vector3{ Subtract(vector1, vector2) };
	Point2f endPoint{ startPoint.x + vector2.x, startPoint.y + vector2.y };

	DrawVector(vector1, startPoint);
	DrawVector(vector2, startPoint);
	DrawVector(vector3, endPoint);
}

// Test the dot product function with orthogonal vectors and no orthogonal 
void TestDotProduct()
{
	// Two orthogonal vectors
	Vector2f v1{ 80.f, 0.f }, v2{0.f, 50.f};
	float result{};

	// Should be 0 because both vectors are perpendicular
	result = DotProduct(v1, v2);

	std::cout << "Dot product: " << std::endl;
	std::cout << "Hor = [" << v1.x << ", " << v1.y << "]";
	std::cout << "Ver = [" << v2.x << ", " << v2.y << "]";
	std::cout << " Dot product: " << result << std::endl;

	// Two new vectors that are parallel
	v1.x = 0.f;
	v1.y = 50.f;
	v2.x = 0.f;
	v2.y = 25.f;

	result = DotProduct(v1, v2);

	std::cout << "Ver = [" << v1.x << ", " << v1.y << "]";
	std::cout << "Para = [" << v2.x << ", " << v2.y << "]";
	std::cout << " Dot product: " << result << std::endl;
	std::cout << std::endl;
}

// Test the cross Product function
void TestCrossProduct()
{
	Vector2f v1{ 80.f, 0.f }, v2{ 0.f, 50.f };
	float result{};

	result = CrossProduct(v1, v2);
	std::cout << "Cross product: " << std::endl;
	std::cout << "Hor = [" << v1.x << ", " << v1.y << "]";
	std::cout << "Ver = [" << v2.x << ", " << v2.y << "]";
	std::cout << " Cross product: " << result << std::endl;

	result = CrossProduct(v2, v1);
	std::cout << "Ver = [" << v1.x << ", " << v1.y << "]";
	std::cout << "Hor = [" << v2.x << ", " << v2.y << "]";
	std::cout << " Cross product: " << result << std::endl;
	std::cout << std::endl;
}
// Test the lenght function
void TestLength()
{
	Vector2f v{ 100.f, 30.f };
	float result{};

	result = Length(v);

	std::cout << "Length of [" << v.x << ", " << v.y << "] is " << result << std::endl;
	std::cout << std::endl;
}
// Test the Scale function
void TestScale()
{
	Vector2f v{ 100.f, 30.f }, v2{};
	float scalar{ 0.1f };

	v2 = Scale(v, scalar);

	std::cout << "Scaled of [" << v.x << ", " << v.y << "] is [" << v2.x << ", " << v2.y << "]" << std::endl;

	std::cout << std::endl;
}

void TestNormalize()
{
	Vector2f v{ 10.f, 3.f }, v2{};

	v2 = Normalize(v);

	std::cout << "Normalize of [" << v.x << ", " << v.y << "] is [" << v2.x << ", " << v2.y << "]" << std::endl;
	std::cout << std::endl;
}

void TestAngleBetween()
{
	Vector2f v1{ 10.f, 0.f }, v2{10.f, 10.f};
	float angle{};

	angle = AngleBetween(v1, v2);

	std::cout << "Angle between [" << v1.x << ", " << v1.y << "] and [" << v2.x << ", " << v2.y << "] is " << angle <<std::endl;
	std::cout << std::endl;
}


void TestAreEqual()
{
	Vector2f v1{ 10.f, 0.f }, v2{ 10.f, 0.f };
	bool equal{};

	equal = AreEqual(v1, v2);

	std::cout << equal << std::endl;

	v1.x = 10.f;
	v1.y = 0.f;
	v2.x = 20.f;
	v2.y = 0.f;

	equal = AreEqual(v1, v2);

	std::cout << equal << std::endl;

	v1.x = -10.f;
	v1.y = 0.f;
	v2.x = 10.f;
	v2.y = 0.f;

	equal = AreEqual(v1, v2);

	std::cout << equal << std::endl;

}


// We do the projection of one vector into another
void AnimationProjection()
{
	utils::SetColor(1.f, 1.f, 1.f); // White

	// Draw a vector in the middle 
	Point2f startPoint{ g_WindowWidth / 2, g_WindowHeight / 2 };

	DrawVector(g_V1Animation, startPoint);

	Vector2f v2Normalized{ 20.f, 10.f };

	// Normalize the vector
	v2Normalized = utils::Normalize(v2Normalized);

	// Calculate the dot product between the normalized vector and the other
	float dotVectors{};
	dotVectors = DotProduct(g_V1Animation, v2Normalized);

	// Multiply the normalized vector with the dotProduct
	v2Normalized = Scale(v2Normalized, dotVectors);


	utils::SetColor(1.0f, 0.f, 0.f);
	DrawVector(v2Normalized, startPoint);

}


// Makes the vector rotate framerate independent
void UpdateVector(float elapsedSec)
{
	g_Angle += (g_Step) * elapsedSec;  // 5 degrees each step
	
	// Rotate the vector frame rate independet
	// Calculates the x and y position in the circle with cos and sin.
	// Then we scale that position to the scale of the vector
	g_V1Animation.x = cos(g_Angle) * g_Scale;	
	g_V1Animation.y = sin(g_Angle) * g_Scale;


	if (g_Angle >= g_FullAngle)
	{
		// Reset angle to 1 degree when we reach 360 degrees
		g_Angle = g_Pi / 180;
	}

}
#pragma endregion ownDefinitions