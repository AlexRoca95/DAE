#include "pch.h"
#include "Game.h"
#include "Fraction.h"
#include "Light.h"
#include <iostream>


//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateFractions();
	PrintFractionsSum();
	CreateLights();
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawFractions();
	DrawLights();

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

	
}

void End()
{
	// free game resources here

	DeleteFractions();
	DeleteLights();
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		g_MousePos.x = float(e.x);
		g_MousePos.y = float(g_WindowHeight - e.y);
		HitLights(g_MousePos);
		break;
	}
	
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here


void CreateFractions()
{
	g_pFraction1 = new Fraction(4, 5);
	g_pArrayFractions[0] = g_pFraction1;
	g_pFraction2 = new Fraction(5, 10);
	g_pArrayFractions[1] = g_pFraction2;
	g_pFraction3 = new Fraction(2, 3);
	g_pArrayFractions[2] = g_pFraction3;
	g_pFraction4 = new Fraction(0, 6);
	g_pArrayFractions[3] = g_pFraction4;
	
}

void DeleteFractions()
{
	for (int i{}; i < g_TotalFractions; i++)
	{
		delete g_pArrayFractions[i];
		g_pArrayFractions[i] = nullptr;
	}

}

void PrintFractionsSum()
{
	float total{};


	for (int i{}; i < g_TotalFractions; i++)
	{

		total += g_pArrayFractions[i]->GetValue();

	}

	std::cout << "Total value of created Fraction objects: " << total << std::endl;
}

void DrawFractions()
{
	Point2f pos{ 10.f, g_WindowHeight / 2 };
	float size{ 20.f };

	for (int i{}; i < g_TotalFractions; i++)
	{
		g_pArrayFractions[i]->Draw(pos, size);

		pos.y -= size + 10.f;
	}
}

// Create 8 lights with limited sizes and random colors
void CreateLights()
{
	Color4f randColor{};
	Rectf rect{};
	int rowIdx{}, colIdx{}, idx;
	const float xSeparation{ 10.f };
	const float ySeparation{ 30.f };
	float rectX{g_WindowWidth / 2};

	rect.left = rectX;

	for (rowIdx = 0; rowIdx < g_Rows; rowIdx++)
	{
		rect.bottom += ySeparation;
		for (colIdx = 0; colIdx < g_Cols; colIdx++)
		{
			idx = GetIndex(rowIdx, colIdx, g_Cols);

			// Rect size and pos
			rect.left += rect.width + xSeparation;
			rect.width = float((std::rand() % 40) + 10);
			rect.height = float((std::rand() % 15) + 10);
			

			// Color rect
			randColor.r = (std::rand() % 10) / 10.f;
			randColor.g = (std::rand() % 10) / 10.f;
			randColor.b = (std::rand() % 10) / 10.f;
			g_pLightsArray[idx] = new Light(rect, randColor);

			// Check if last col of the row
			if (colIdx == g_Cols - 1)
			{
				// Reset X to initial value and the width for the next row
				rect.left = rectX;
				rect.width = 0.f;

			}
			
		}

		
	}

}

void DrawLights()
{

	for (int i{}; i < g_SizeLightsArray; i++)
	{
		g_pLightsArray[i]->Draw();
	}

}

// Get the index of the 2D array
int GetIndex(int rowIdx, int colIdx, int nrCols)
{
	int idx{};

	idx = rowIdx * nrCols + colIdx;

	return idx;
}


void HitLights(const Point2f& pos)
{
	bool hit{};

	// Loop until we reach the end of the array or we switch a light
	for (int i{}; i < g_SizeLightsArray && hit==false; i++)
	{
		// Return true if we switch a light
		hit = g_pLightsArray[i]->IsHit(pos);

		if (hit == true)
		{
			if (g_pLightsArray[i]->IsOn())
			{
				// One more light switched on
				g_LightsOnCount++;
			}
			else
			{
				// One light switched off
				g_LightsOnCount--;
			}
			
			PrintLightsOn();
		}
		
	}

	

}

void PrintLightsOn()
{

	std::cout << g_LightsOnCount << " lights are on" << std::endl;
}


// Free the memory for the array lights pointer
void DeleteLights()
{

	for (int i{}; i < g_SizeLightsArray; i++)
	{
		delete g_pLightsArray[i];
		g_pLightsArray[i] = nullptr;
	}

}

#pragma endregion ownDefinitions