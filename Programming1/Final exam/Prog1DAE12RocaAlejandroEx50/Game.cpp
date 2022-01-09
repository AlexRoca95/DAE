#include "pch.h"
#include "Game.h"
#include "Tile.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	InitArrayTiles();

	bool succes = TextureFromFile("Resources/Names.png", g_AnimalsName);

	if(!succes)
		std::cout << "Error loading the textures Names.png " << std::endl;
	
}

void Draw()
{
	ClearBackground(0, 0, 0);

	// Put your own draw statements here
	DrawTiles();
	DrawPuzzleBorder();
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


	CheckMouseTiles();
	
}

void End()
{
	// free game resources here

	
	for (int i{ 0 }; i < g_TotalTiles; i++)
	{
		delete g_pArrayTiles[i];
		g_pArrayTiles[i] = nullptr;
	}
	

	DeleteTexture(g_AnimalsName);
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
	
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);

	

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
			Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
			CheckNextAnimal(mousePos);
			break;
		}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
 // Define your own functions here

void InitArrayTiles()
{
	const int nrCols{ 2 };
	const int nrRows{ 2 };
	
	int rowIdx{  }, idx{}, colIdx{  };

	Rectf position{};
	position.width = position.height = g_SizeTiles;		// Rectangular size
	
	position.left = g_StartLeftTiles;
	position.bottom = g_StartBottomTiles;

	
	// Init the 2d array
	for (rowIdx = 0; rowIdx < nrRows; rowIdx++)
	{
		// Rows 
		position.bottom -= position.height * rowIdx;

		for (colIdx = 0; colIdx < nrCols; colIdx++)
		{
			// Cols
			idx = GetIndex(rowIdx, colIdx, nrCols);

			position.left += position.width * colIdx;
			
			g_pArrayTiles[idx] = new Tile(position,"Resources/Tiles" + std::to_string(rowIdx) + std::to_string(colIdx) + ".png", g_TotalAnimals);

			if (colIdx == nrCols - 1) // Reset cols to start at the initial pos
				position.left = g_StartLeftTiles;

		}
	}
}

// Draw the 4 tiles in a 2x2 grid
void DrawTiles()
{

	for (int i{ 0 }; i < g_TotalTiles; i++)
	{
		g_pArrayTiles[i]->Draw();
	}

}

// Call the checkActivation methods from the tiles 
void CheckMouseTiles()
{
	if (g_SameAnimal == false)
	{
		for (int i{ 0 }; i < g_TotalTiles; i++)
		{

			g_pArrayTiles[i]->CheckActivation(g_MousePos);

		}
	}
}

// Call the check hit method from the tiles classes of the array
void CheckNextAnimal(const Point2f& pos)
{
	if (g_SameAnimal == false)
	{
		// Loop until end of array or we hit in one of the hitting rectangles from the tiles
		for (int i{ 0 }; i < g_TotalTiles && !g_CheckSolve; i++)
		{
			// Save the bool indicating if we hit the rectangle
			g_CheckSolve = g_pArrayTiles[i]->CheckHit(pos);

		}
	}

}

void DrawPuzzleBorder()
{

	if (g_CheckSolve)
	{
		
		g_SameAnimal = true;
		int saveNr{}, number{};
		// One tile change, So we check if the puzzle is solved
		for (int i{ 0 }; i < g_TotalTiles && g_SameAnimal!=false; i++)
		{
			number = g_pArrayTiles[i]->GetCurrentAnimal();

			if (i != 0)
			{
				if (number != saveNr)
				{
					// 2 tiles have diferent animal
					g_SameAnimal = false;
				}
				else
				{
					// Save number for check the next tile
					saveNr = number;
				}
			}
			else
			{
				saveNr = number;
			}
		}

		g_CheckSolve = false;
	}

	// Border around the tiles
	Rectf borderRect{};

	borderRect.left = g_StartLeftTiles;
	borderRect.bottom = g_StartBottomTiles - g_SizeTiles;
	borderRect.width =  g_SizeTiles * 2;
	borderRect.height = g_SizeTiles * 2;


	if (g_SameAnimal == true)
	{
		DeactivateTiles();
		// All the same animal. Green border
		utils::SetColor(0, 1.f, 0, 2.f);

		// Draw the name of the animal below
		Rectf srcRect{};
		srcRect.height = g_AnimalsName.height / g_TotalAnimals;
		srcRect.width = g_AnimalsName.width;
		srcRect.left = 0;
		srcRect.bottom = srcRect.height * ((g_pArrayTiles[0]->GetCurrentAnimal()) + 1);

		Rectf posRect{};
		posRect.height = srcRect.height;
		posRect.width = srcRect.width;
		posRect.left = g_StartLeftTiles;
		posRect.bottom = g_StartBottomTiles - g_SizeTiles - srcRect.height;

		DrawTexture(g_AnimalsName, posRect, srcRect);

	}
	else
	{

		utils::SetColor(1, 0, 0, 2.f);  // Red  color
	}
	utils::DrawRect(borderRect);

}

// Desactivate all the tiles
void DeactivateTiles()
{
	for (int i{ 0 }; i < g_TotalTiles; i++)
	{
		g_pArrayTiles[i]->Deactivate();
	}
}

// Get the index of the 2D array
int GetIndex(int rowIdx, int colIdx, int nrCols)
{
	int idx{};

	idx = rowIdx * nrCols + colIdx;

	return idx;
}
#pragma endregion ownDefinitions