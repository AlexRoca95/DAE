#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitGame();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here

	if (state == StateGame::Start)
	{
		// Draw menu 
	}

	if (state != StateGame::Start)
	{
		// Draw grids for player
		//DrawShipInGrid();
		DrawGrid(g_PlayerGrid);

		if (state == StateGame::Placing)
		{
			// Draw ship at mouse pos
			DrawShipPlacement();
		}
	}

	if (state == StateGame::Playing)
	{
		// 
		DrawGrid(g_EnemyGrid);
	}
	
}

void Update(float elapsedSec)
{
	// process input, do physics 
	if (state == StateGame::Placing)
	{
		// Placing ships
		UpdateShipPlacing();
		SelectShip();
		RotateShip();
		CheckShipPlacement();
		
	}
	
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
	delete[] g_pArrayShips;
	g_pArrayShips = nullptr;

}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_s:
		// Check if player press enter button to start the game
		if (state == StateGame::Start)
		{
			// Change state to placing ships
			state = StateGame::Placing;
		}
		break;

	case SDLK_r:
			// Rotate the ship
		if (state == StateGame::Placing)
		{
			// Rotate next ship
			g_RotateShip = true;
		}
		break;

	case SDLK_RIGHT:
		if (state == StateGame::Placing)
		{
			// Select next ship
			g_NextShip = true;
		}
		break;
	case SDLK_LEFT:
		if (state == StateGame::Placing)
		{
			// Select next ship
			g_PreviousShip = true;
		}
		break;
	
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	// Track mouse pos
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y) ;
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
			if (state == StateGame::Placing || state == StateGame::Playing)
			{
				// Left button clicked
				
				g_MouseClicked = true;
				g_MouseClickPos.x = float(e.x);
				g_MouseClickPos.y = float(g_WindowHeight - e.y);

				if (g_pArrayShips[g_ShipsIndex].rotate)
				{
					// Ship rotated
					g_MouseClickPos.x += 10.f;
					g_MouseClickPos.y -= g_CellSize / 2;
				}
				else
				{
					// Ship not rotated
					//g_MouseClickPos.x -= 10.f;

				}

				std::cout << "Mouse clicked X :" << g_MouseClickPos.x << std::endl;
				std::cout << "Mouse clicked Y :" << g_MouseClickPos.y << std::endl;
			}
			break;
		}
			
		
	
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

// Init all game resources
void InitGame()
{

	state = StateGame::Start;
	InitGrid(g_EnemyGrid, g_GridEnemyPos.x, g_GridEnemyPos.y);
	InitGrid(g_PlayerGrid, g_GridPlayerPos.x, g_GridPlayerPos.y);
	InitShips();
	
}

void InitGrid(GridCell* grid, float xPos, float yPos)
{
	int idx{};

	for (int rowIdx{}; rowIdx < g_GridSize; rowIdx++)
	{
		for (int colIdx{}; colIdx < g_GridSize; colIdx++)
		{
			idx = GetIndex(rowIdx, colIdx, g_GridSize);

			grid[idx].ship = false;
			grid[idx].shoot = false;
			grid[idx].pos.y = yPos;
			grid[idx].pos.x = xPos;

			xPos += g_CellSize;

			if (colIdx == g_GridSize - 1)
			{
				// Last cell of the row --> Next row
				xPos = g_GridPlayerPos.x;
				yPos += g_CellSize;
			}
		}
	}
}
// Init data for ships
void InitShips()
{
	g_pArrayShips = new Ship[g_ArraysShipSize];
	g_ShipsIndex = 2;

	// Carrier ship
	Ship carrier{};
	InitShip(carrier, 5, 0);  // Ship, size and index of the array

	// Battleship
	Ship battleship{};
	InitShip(battleship, 4, 1);

	// Destroyer
	Ship destroyer{};
	InitShip(destroyer, 3, 2);

	// Submarine
	Ship submarine{};
	InitShip(carrier, 3, 3);
	// Patrol Boat
	Ship patrolBoat{};
	InitShip(carrier, 2, 4);

}

// Initialice the data for the ship passed by parameter
void InitShip(Ship& ship, int size, int index)
{
	ship.type.left = 0.f;
	ship.type.bottom =0.f;
	ship.type.width = g_CellSize - g_CellSize / 4;
	ship.size = size;
	ship.type.height = g_CellSize * -(ship.size);  // Height according with the size of the ship
	ship.countHits = 0;

	g_pArrayShips[index] = ship;
}

// Get the index of the 2D array
int GetIndex(int rowIdx, int colIdx, int nrCols)
{
	int idx{};

	idx = rowIdx * nrCols + colIdx;

	return idx;
}

// Draw the grid, ships, miss, hits 
void DrawGrid(GridCell* grid)
{
	int idx{};
	bool enemyMove{};
	Point2f p2{};
	
	//grid[0].shoot = true;
	for (int rowIdx{}; rowIdx < g_GridSize; rowIdx++)
	{
		for (int colIdx{}; colIdx < g_GridSize; colIdx++)
		{
			idx = GetIndex(rowIdx, colIdx, g_GridSize);

			// Check if enemy made any move
			enemyMove = DrawEnemyMove(grid, idx);

			if (enemyMove == false )
			{
				// Enemy didnt make any move
				// Normal cell color 
				utils::SetColor(0.f, 0.f, 1.f);
				utils::FillRect(grid[idx].pos.x, grid[idx].pos.y, g_CellSize, g_CellSize);

				utils::SetColor(0.f, 0.f, 0.f);
				// Bottom Line
				p2.x = grid[idx].pos.x + g_CellSize;
				p2.y = grid[idx].pos.y;
				utils::DrawLine(grid[idx].pos, p2);

				// Vertical Left 
				p2.x = grid[idx].pos.x;
				p2.y = grid[idx].pos.y + g_CellSize;
				utils::DrawLine(grid[idx].pos, p2);
			}
			
			// Check if there is a ship in the cell
			if (grid[idx].ship == true)
			{	
				// Draw the shape of the ship
				DrawShipInGrid(grid, idx, rowIdx, colIdx);
			}			

		}
	}

	utils::DrawRect(grid[0].pos.x, grid[0].pos.y, g_CellSize * g_GridSize, g_CellSize * g_GridSize, 2.0f);

}

// Check if enemy made any move ( hit or miss) and return a bool to know if it did it or not
bool DrawEnemyMove(GridCell* grid, int idx)
{
	bool EnemyMove = false;

	if (grid[idx].shoot == true)
	{
		// Enemy shoot the cell and hit the ship
		utils::SetColor(1.f, 0.f, 0.f);
		EnemyMove = true;
	}
	else
	{
		if (grid[idx].miss == true)
		{
			// Miss
			utils::SetColor(0.f, 1.f, 0.f);
			EnemyMove = true;
		}
	}

	utils::FillRect(grid[idx].pos.x, grid[idx].pos.y, g_CellSize, g_CellSize);

	return EnemyMove;
}

// Draw the ship in the grid according with his size and rotation
void DrawShipInGrid(GridCell* grid, int idx, int rowIdx, int colIdx)
{
	int idx2{};
	
	for (int i{ 0 }; i < grid[idx].shipInfo.size; i++)
	{
		if (grid[idx].shipInfo.rotate)
		{
			// Rotated. Cols have to change
			idx2 = GetIndex(rowIdx, colIdx - i, g_GridSize);
		}
		else
		{
			// Not Rotated. Rows have to change
			idx2 = GetIndex(rowIdx -i, colIdx, g_GridSize);
		}
		
		if (grid[idx2].shoot == true)
		{
			// Red color
			utils::SetColor(1.f, 0.f, 0.f);
		}
		else
		{
			// Ship color
			utils::SetColor(0.5f, 0.5f, 0.5f);
		}

		utils::FillRect(grid[idx2].pos.x, grid[idx2].pos.y, g_CellSize, g_CellSize);
	}
	
	utils::SetColor(0.5f, 0.5f, 0.5f);

}


// Draw ship at mouse position when placingShips state
void DrawShipPlacement()
{

	utils::SetColor(0.5f, 0.5f, 0.5f);
	utils::FillRect(g_pArrayShips[g_ShipsIndex].type);

}

// Update the pos of the ships acording with the mouse pos and the rotation of the ship
void UpdateShipPlacing()
{
	// Change pos ship with the mouse movement
	if (g_pArrayShips[g_ShipsIndex].rotate)
	{
		// Ship rotated
		g_pArrayShips[g_ShipsIndex].type.left = g_MousePos.x + 10.f;
		g_pArrayShips[g_ShipsIndex].type.bottom = g_MousePos.y - g_CellSize/2;
	}
	else
	{
		// Ship not rotated
		g_pArrayShips[g_ShipsIndex].type.left = g_MousePos.x;
		g_pArrayShips[g_ShipsIndex].type.bottom = g_MousePos.y;
	}


	//std::cout << "Ship X:" << g_pArrayShips[g_ShipsIndex].type.left << std::endl;
	//std::cout << "Ship Y:" << g_pArrayShips[g_ShipsIndex].type.bottom << std::endl;
}

// Select next or previous ship depending on the key the player pressed
void SelectShip()
{
	if (g_NextShip)
	{
		if (g_ShipsIndex == g_ArraysShipSize - 1)
		{
			// Reset index when it reachs max array size
			g_ShipsIndex = 0;
		}
		else
		{
			// Next ship
			g_ShipsIndex++;
		}

		g_NextShip = false;
	}
	else
	{
		if (g_PreviousShip)
		{
			
			if (g_ShipsIndex == 0)  
			{
				// Reset to the final pos of the array
				g_ShipsIndex = g_ArraysShipSize - 1;
			}
			else
			{
				// Previous ship
				g_ShipsIndex--;
			}

			g_PreviousShip = false;
		}
	}
}

// Rotate the ship
void RotateShip()
{
	if (g_RotateShip)
	{
		// Player wants to rotate
		
		// Exchange width and height values
		float safe{ g_pArrayShips[g_ShipsIndex].type.width };
		g_pArrayShips[g_ShipsIndex].type.width = g_pArrayShips[g_ShipsIndex].type.height;
		g_pArrayShips[g_ShipsIndex].type.height = safe;
		
		// Change from rotated/notRotated to NoRotated/Rotated
		if (g_pArrayShips[g_ShipsIndex].rotate)
		{
			g_pArrayShips[g_ShipsIndex].rotate = false;
		}
		else
		{
			g_pArrayShips[g_ShipsIndex].rotate = true;
		}

		g_RotateShip = false;

	}
}



// Check if the left mouse was clicked and try to place a ship in the grid
void CheckShipPlacement()
{
	if (g_MouseClicked)
	{
		// Left mouse clicked. We want to place a ship in the grid
		int idx{};
		for (int rowIdx{}; rowIdx < g_GridSize; rowIdx++)
		{
			for (int colIdx{}; colIdx < g_GridSize; colIdx++)
			{
				idx = GetIndex(rowIdx, colIdx, g_GridSize);

				if (g_MouseClickPos.x > g_PlayerGrid[idx].pos.x && g_MouseClickPos.x < g_PlayerGrid[idx].pos.x + g_CellSize)
				{
					if (g_MouseClickPos.y > g_PlayerGrid[idx].pos.y && g_MouseClickPos.y < g_PlayerGrid[idx].pos.y + g_CellSize)
					{

						if (g_pArrayShips[g_ShipsIndex].rotate == false)
						{
							// Ship not rotated
							// Save into the cell the info about the ship placed
							g_PlayerGrid[idx].shipInfo = g_pArrayShips[g_ShipsIndex];
							g_PlayerGrid[idx].ship = true;

							g_pArrayShips[g_ShipsIndex].firstCell.x = g_PlayerGrid[idx].pos.x ;
							// We place the ship one row above in order to draw in the exact pos of the mouse clicking
							g_pArrayShips[g_ShipsIndex].firstCell.y = g_PlayerGrid[idx].pos.y + g_CellSize;

							std::cout << "Grid X: " << g_PlayerGrid[idx].pos.x << std::endl;
							std::cout << "Grid Y: " << g_PlayerGrid[idx].pos.y << std::endl;
						}
						else
						{
							// Ship rotated
							
							// Save into the cell the info about the ship placed
							g_PlayerGrid[idx].shipInfo = g_pArrayShips[g_ShipsIndex];
							g_PlayerGrid[idx].ship = true;

							g_pArrayShips[g_ShipsIndex].firstCell.x = g_PlayerGrid[idx].pos.x + g_CellSize;
							g_pArrayShips[g_ShipsIndex].firstCell.y = g_PlayerGrid[idx].pos.y;

							std::cout << "Grid X: " << g_PlayerGrid[idx].pos.x << std::endl;
							std::cout << "Grid Y: " << g_PlayerGrid[idx].pos.y << std::endl;
						}
							
							
							
						
					}
				}
			}
		}

		g_MouseClicked = false;
	}
}

#pragma endregion ownDefinitions