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

	// Draw menu 
	Rectf destinationRect{};
	destinationRect.bottom = 0;
	destinationRect.left = 0;
	destinationRect.height = g_WindowHeight;
	destinationRect.width = g_WindowWidth;
	// DestinationRect will be the place where the texture will be draw
	DrawTexture(g_StartScreen, destinationRect);


	if (state == StateGame::Playing || state == StateGame::Placing)
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
		// Game Start. Draw the enemy grid
		DrawGrid(g_EnemyGrid);
		DrawGrid(g_PlayerGrid);
	}



	if (state == StateGame::EndGame)
	{
		Point2f position{ (g_WindowWidth / 2) - 110, 200 };

		if (g_PlayerCountHits == g_MaxHits)
		{
			
			DrawTexture(g_LooseText, position);
		}
		else
		{
			DrawTexture(g_WinText, position);
		}
	}

	
}

void Update(float elapsedSec)
{
	// process input, do physics 
	if (state == StateGame::Placing)
	{	
		if (g_ShipsLeft >0)
		{
			// Still ships to be placed
			
			// Placing ships
			UpdateShipPlacing();

			SelectShip();	

			RotateShip();
			CheckShipPlacement();

			if (g_ShipsLeft == 0)
			{
				// All ships placed

				// Ships of the enemy
				PlaceEnemyShips();

				// Game Start
				state = StateGame::Playing;
			}
			
		}
		
	}


	if (state == StateGame::Playing)
	{
		if (g_PlayerTurn)
		{
			// Is player's turn
			PlayerShoot(g_EnemyGrid);
			
		}
		
		if(g_PlayerTurn == false)
		{
			// Enemy's turn
			EnemyShoot();
			g_PlayerTurn = true;
		}
	}

	if (state == StateGame::EndGame)
	{
		
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
	delete[] g_pPlayerArrayShips;
	g_pPlayerArrayShips = nullptr;

	delete[] g_pEnemyArrayShips;
	g_pEnemyArrayShips = nullptr;

	DeleteTexture(g_WinText);
	DeleteTexture(g_LooseText);
	DeleteTexture(g_StartScreen);

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

				if (state == StateGame::Placing)
				{
					if (g_pPlayerArrayShips[g_ShipsIndex].rotate)
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
				}
				//std::cout << "Mouse clicked X :" << g_MouseClickPos.x << std::endl;
				//std::cout << "Mouse clicked Y :" << g_MouseClickPos.y << std::endl;
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
	bool succesful = TextureFromFile("Resources/battleship.png", g_StartScreen);

	if (!succesful)
		std::cout << "Loading failed" << std::endl;

	// Loading a text
	succesful = TextureFromString("You Win!", "Resources/DIN-Light.otf", 60, Color4f{ 0,0,1,1 }, g_WinText);
	if (!succesful)
		std::cout << "Loading Text failed" << std::endl;

	succesful = TextureFromString("Game Over", "Resources/DIN-Light.otf", 60, Color4f{ 1,0,0,1 }, g_LooseText);
	if (!succesful)
		std::cout << "Loading Text failed" << std::endl;

	succesful = TextureFromFile("Resources/ship_sprites.png", g_Ships);
	if (!succesful)
		std::cout << "Loading failed" << std::endl;

	g_PlayerTurn = true;  // The player's start
	g_Player.shipsLeft = g_ArraysShipSize;
	g_Enemy.shipsLeft = g_ArraysShipSize;

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
			grid[idx].first = false;

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
	g_pPlayerArrayShips = new Ship[g_ArraysShipSize];
	g_ShipsIndex = 2;
	g_ShipsLeft = g_ArraysShipSize;

	// Carrier ship
	Ship carrier{};
	carrier.text = g_Ships;
	InitShip(g_pPlayerArrayShips, carrier, 5, 0);  // Ship, size and index of the array
	
	// Battleship
	Ship battleship{};
	battleship.text = g_Ships;
	InitShip(g_pPlayerArrayShips, battleship, 4, 1);

	// Destroyer
	Ship destroyer{};
	destroyer.text = g_Ships;
	InitShip(g_pPlayerArrayShips, destroyer, 3, 2);

	// Submarine
	Ship submarine{};
	submarine.text = g_Ships;
	InitShip(g_pPlayerArrayShips,submarine, 3, 3);

	// Patrol Boat
	Ship patrolBoat{};
	patrolBoat.text = g_Ships;
	InitShip(g_pPlayerArrayShips, patrolBoat, 2, 4);

	g_pEnemyArrayShips = new Ship[g_ArraysShipSize];

	// Carrier ship
	Ship carrier2{};
	carrier2.text = g_Ships;
	InitShip(g_pEnemyArrayShips, carrier2, 5, 0);  // Ship, size and index of the array

	// Battleship
	Ship battleship2{};
	battleship2.text = g_Ships;
	InitShip(g_pEnemyArrayShips, battleship2, 4, 1);

	// Destroyer
	Ship destroyer2{};
	destroyer2.text = g_Ships;
	InitShip(g_pEnemyArrayShips, destroyer2, 3, 2);

	// Submarine
	Ship submarine2{};
	submarine2.text = g_Ships;
	InitShip(g_pEnemyArrayShips, submarine2, 3, 3);
	// Patrol Boat
	Ship patrolBoat2{};
	patrolBoat2.text = g_Ships;
	InitShip(g_pEnemyArrayShips, patrolBoat2, 2, 4);

}

// Initialice the data for the ship passed by parameter
void InitShip(Ship* arrayShips, Ship& ship, int size, int index)
{
	ship.type.left = 0.f;
	ship.type.bottom = 0.f;
	ship.type.width = g_CellSize - g_CellSize / 4;
	ship.size = size;
	ship.type.height = g_CellSize * -(ship.size);  // Height according with the size of the ship
	ship.countHits = 0;

	arrayShips[index] = ship;
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
			
			// Check if there is a ship in the cell and if it is the first cell for a ship
			if (grid[idx].ship == true && grid[idx].first == true)
			{	
			
				// Draw the shape of the ship (only for the player)
				if(grid == g_PlayerGrid)
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
			utils::SetColor(0.72f, 0.82f, 0.93f);
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
	utils::FillRect(g_pPlayerArrayShips[g_ShipsIndex].type);


}

// Update the pos of the ships acording with the mouse pos and the rotation of the ship
void UpdateShipPlacing()
{
	// Change pos ship with the mouse movement
	if (g_pPlayerArrayShips[g_ShipsIndex].rotate)
	{
		// Ship rotated
		g_pPlayerArrayShips[g_ShipsIndex].type.left = g_MousePos.x + 10.f;
		g_pPlayerArrayShips[g_ShipsIndex].type.bottom = g_MousePos.y - g_CellSize/2;
	}
	else
	{
		// Ship not rotated
		g_pPlayerArrayShips[g_ShipsIndex].type.left = g_MousePos.x;
		g_pPlayerArrayShips[g_ShipsIndex].type.bottom = g_MousePos.y;
	}


	//std::cout << "Ship X:" << g_pArrayShips[g_ShipsIndex].type.left << std::endl;
	//std::cout << "Ship Y:" << g_pArrayShips[g_ShipsIndex].type.bottom << std::endl;
}

// Select next or previous ship depending on the key the player pressed
void SelectShip()
{
	if (g_NextShip)
	{
		// Want to select next ship available
		do {

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

			// Do it until we find a ship that hasnt been placed yet
		} while (g_pPlayerArrayShips[g_ShipsIndex].placed);

		g_NextShip = false;
	}
	else
	{
		if (g_PreviousShip)
		{
			do {
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

			} while (g_pPlayerArrayShips[g_ShipsIndex].placed);
			

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
		float safe{ g_pPlayerArrayShips[g_ShipsIndex].type.width };
		g_pPlayerArrayShips[g_ShipsIndex].type.width = g_pPlayerArrayShips[g_ShipsIndex].type.height;
		g_pPlayerArrayShips[g_ShipsIndex].type.height = safe;
		
		// Change from rotated/notRotated to NoRotated/Rotated
		if (g_pPlayerArrayShips[g_ShipsIndex].rotate)
		{
			g_pPlayerArrayShips[g_ShipsIndex].rotate = false;
		}
		else
		{
			g_pPlayerArrayShips[g_ShipsIndex].rotate = true;
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
		float offSetX{}, offSetY{};

		for (int rowIdx{}; rowIdx < g_GridSize; rowIdx++)
		{
			for (int colIdx{}; colIdx < g_GridSize; colIdx++)
			{
				idx = GetIndex(rowIdx, colIdx, g_GridSize);

				if (g_MouseClickPos.x > g_PlayerGrid[idx].pos.x && g_MouseClickPos.x < g_PlayerGrid[idx].pos.x + g_CellSize)
				{
					if (g_MouseClickPos.y > g_PlayerGrid[idx].pos.y && g_MouseClickPos.y < g_PlayerGrid[idx].pos.y + g_CellSize)
					{
					
						if (g_pPlayerArrayShips[g_ShipsIndex].rotate == false)
						{
							// Ship not rotated
							offSetX = 0;
							offSetY = g_CellSize;
							SafeInfoShipInGrid(g_PlayerGrid, idx, offSetX, offSetY, rowIdx, colIdx);
						
						}
						else
						{
							// Ship rotated
							offSetX = g_CellSize;
							offSetY = 0;
							SafeInfoShipInGrid(g_PlayerGrid, idx, offSetX, offSetY, rowIdx, colIdx);
						}
						
						g_pPlayerArrayShips[g_ShipsIndex].placed = true;
						g_ShipsLeft--;		// One less ship to place
						if (g_ShipsLeft > 0)
						{
							g_NextShip = true;
							SelectShip();
						}
						
					}
				}
			}
		}

		g_MouseClicked = false;
	}
}

// Safe info about the ship into the grid
void SafeInfoShipInGrid(GridCell* grid, int idx, float offSetX, float offSetY, int rowIdx, int colIdx)
{
	
	int idx2{};

	// We place the ship correctly into the grid according to his rotation
	g_pPlayerArrayShips[g_ShipsIndex].firstCell.x = grid[idx].pos.x + offSetX;
	g_pPlayerArrayShips[g_ShipsIndex].firstCell.y = grid[idx].pos.y + offSetY;

	// Save into the cell the info about the ship placed
	for (int i{ 0 }; i < g_pPlayerArrayShips[g_ShipsIndex].size; i++)
	{
		if (grid[idx].shipInfo.rotate)
		{
			// Rotated. Cols have to change
			idx2 = GetIndex(rowIdx, colIdx - i, g_GridSize);
		}
		else
		{
			// Not Rotated. Rows have to change
			idx2 = GetIndex(rowIdx - i, colIdx, g_GridSize);
		}

		grid[idx2].shipInfo = g_pPlayerArrayShips[g_ShipsIndex];
		grid[idx2].ship = true;

		if (i == 0)
		{
			// This cell is the first to draw for the ship
			grid[idx2].first = true;
		}
	}



	//std::cout << "Grid X: " << g_PlayerGrid[idx].pos.x << std::endl;
	//std::cout << "Grid Y: " << g_PlayerGrid[idx].pos.y << std::endl;
}

// Place the enemy ships randomly inside the grid of the enemy
void PlaceEnemyShips()
{
	int randRow{}, randCol{}, randRotate{}, idx{};
	bool repeat{};
	g_ShipsLeft = g_ArraysShipSize;
	

	for (g_ShipsIndex = 0; g_ShipsIndex < g_ArraysShipSize; g_ShipsIndex++)
	{
		//g_pEnemyArrayShips[g_ShipsIndex].rotate = randRotate = std::rand() % 2;
		
		if (g_pEnemyArrayShips[g_ShipsIndex].rotate)
		{
			// Ship rotated
			randRow = std::rand() % g_GridSize;
			do {

				if (randCol - g_pEnemyArrayShips[g_ShipsIndex].size < 0)
				{
					// Not enough size for the ship
					repeat = true;
				}
				else
				{
					// Check we dont place a ship in a cell where already is a ship
					for (int i{}; i < g_pEnemyArrayShips[g_ShipsIndex].size; i++)
					{
						idx = GetIndex(randRow, randCol-i, g_GridSize);

						if (g_EnemyGrid[idx].ship)
						{
							repeat = true;
							break;
						}
						else
						{
							repeat = false;
						}
					}
				}

			} while (repeat);
		}
		else
		{ 
			// Ship not rotated
			randCol = std::rand() % g_GridSize;
			do {

				randRow = std::rand() % g_GridSize;

				if (randRow - g_pEnemyArrayShips[g_ShipsIndex].size < 0)
				{
					// Not enough size for the ship
					repeat = true;
				}
				else
				{
					for (int i{}; i < g_pEnemyArrayShips[g_ShipsIndex].size; i++)
					{
						idx = GetIndex(randRow-i, randCol, g_GridSize);

						if (g_EnemyGrid[idx].ship)
						{
							repeat = true;
							break;
						}
						else
						{
							repeat = false;
						}
					}
				}
				
				
			} while (repeat);
		}
		

		idx = GetIndex(randRow, randCol, g_GridSize);
		
		

		// Safe the info into the enemy grid
		SafeInfoShipInGrid(g_EnemyGrid, idx, 0, 0, randRow, randCol);
	
	}
	



	//std::cout << randRow << std::endl;
	//std::cout << randCol << std::endl;
}


void PlayerShoot(GridCell* grid)
{
	if (g_MouseClicked)
	{
		int idx{}, idx2{};

		for (int rowIdx{}; rowIdx < g_GridSize; rowIdx++)
		{
			for (int colIdx{}; colIdx < g_GridSize; colIdx++)
			{
				idx = GetIndex(rowIdx, colIdx, g_GridSize);

				if (g_MouseClickPos.x > grid[idx].pos.x && g_MouseClickPos.x < grid[idx].pos.x + g_CellSize)
				{
					if (g_MouseClickPos.y > grid[idx].pos.y && g_MouseClickPos.y < grid[idx].pos.y + g_CellSize)
					{
						// Clicked inside the grid

						if (grid[idx].ship && !grid[idx].shoot)
						{
							// There is a ship and we didnt shoot it already
							// Ship hit
							grid[idx].shoot = true;
							g_EnemyCountHits++;

							//std::cout << g_EnemyCountHits << std::endl;
							if (g_EnemyCountHits == 17)
							{
								// Game over. No ships left for the enemy
								state = StateGame::EndGame;
							}

						}
						else
						{
							if (grid[idx].ship == false && !grid[idx].miss)
							{
								// No ship and not already missed
								// Miss
								grid[idx].miss = true;
							}
						}

					}
				}
			}
		}

		g_MouseClicked = false;
		g_PlayerTurn = false;
	}


}

// Enemy shoots
void EnemyShoot()
{

	int randRow{}, randCol{}, idx;
	bool shoot{};

	do {
		randCol = std::rand() % g_GridSize;
		randRow = std::rand() % g_GridSize;

		idx = GetIndex(randRow, randCol, g_GridSize);

		if (g_PlayerGrid[idx].ship && !g_PlayerGrid[idx].shoot)
		{
			// There is a ship and we didnt shoot it already
			// Ship hit
			g_PlayerGrid[idx].shoot = true;

			g_PlayerCountHits++;

			if (g_PlayerCountHits == 17)
			{
				// Game over.
				state = StateGame::EndGame;
			}

			shoot = true;

		}
		else
		{
			if (g_PlayerGrid[idx].ship == false && !g_PlayerGrid[idx].miss)
			{
				// No ship and not already missed
				// Miss
				g_PlayerGrid[idx].miss = true;
				shoot = true;
			}
			else
			{
				shoot = false;
			}
		}
	} while (shoot == false);


}
#pragma endregion ownDefinitions