#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	
	InitGame();

}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here

	DrawGame();

}

void Update(float elapsedSec)
{
	// process input, do physics 

	UpdatePlayers();

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
	DeleteTexture(g_Background);
	DeleteTexture(g_GreenX);
	DeleteTexture(g_GreenO);
	DeleteTexture(g_WhiteO);
	DeleteTexture(g_WhiteX);
	DeleteTexture(g_Win);
	DeleteTexture(g_FreeCell);
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
	case SDLK_a:
		// Left player press 'a' key
		if (g_PlayerLeft.active)  // Only if it is the active player
			g_PlayerLeft.key_pressed = true;
		break;
	case SDLK_l:
		// Right player press 'l' key
		if (g_PlayerRight.active)
			g_PlayerRight.key_pressed = true;
		break;
	}
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
		// Check which player clicked and where 
		if (g_PlayerLeft.active)
		{
			CheckMouse(float(e.x), float(g_WindowHeight - e.y), g_PlayerLeft);
		}
		else
		{
			CheckMouse(float(e.x), float(g_WindowHeight - e.y), g_PlayerRight);
		}
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

// Load a texture into the game
void LoadTexture(Texture& texture, std::string path)
{
	bool load{};

	load = TextureFromFile(path, texture);

	if (!load)
		std::cout << "Error at loading texture " << path << std::endl;

}

// Load all the textures needed for the game
void LoadResources()
{
	LoadTexture(g_Background, "Resources/OXO/OXO.png");
	LoadTexture(g_FreeCell, "Resources/OXO/FreeCell.png");
	LoadTexture(g_WhiteO, "Resources/OXO/WhiteO.png");
	LoadTexture(g_WhiteX, "Resources/OXO/WhiteX.png");
	LoadTexture(g_GreenX, "Resources/OXO/GreenX.png");
	LoadTexture(g_GreenO, "Resources/OXO/GreenO.png");
	LoadTexture(g_Win, "Resources/OXO/Win.png");
}

// Draw the background image
void DrawBackground()
{
	Rectf destinationRect{};

	// All the window size
	destinationRect.height = g_WindowHeight;
	destinationRect.width = g_WindowWidth;
	destinationRect.left = 0.f;
	destinationRect.bottom = 0.f;

	DrawTexture(g_Background, destinationRect);



}

// Draw the corresponding texture of the cell at the position indicated
void DrawCell(const Texture& texture, const float xPos, const float yPos)
{
	Rectf destinationRect{};

	destinationRect.height = g_CellSize;
	destinationRect.width = g_CellSize;

	destinationRect.left = xPos;
	destinationRect.bottom = yPos;


	DrawTexture(texture, destinationRect);

}
// Draw the board
void DrawBoard()
{
	const int nrCols{ 3 }, nrRows{ 3 };  // 3 x 3 = 9 elements
	int rowIdx{  }, idx{}, colIdx{  };
	const float initX{ (g_WindowWidth / 2) - (g_CellSize * 2) };
	float boardCellX{ initX }, boardCellY{ (g_WindowHeight / 2) + (g_CellSize * 2) };

	for (int rowIdx = 0; rowIdx < nrRows; rowIdx++)
	{
		boardCellY -= g_CellSize + g_Border;

		for (int colIdx = 0; colIdx < nrCols; colIdx++)
		{
			idx = GetIndex(rowIdx, colIdx, nrCols);

			DrawCell(g_BoardArray[idx].texture, boardCellX, boardCellY);

			// Save position of the cell
			g_BoardArray[idx].pos.x = boardCellX;
			g_BoardArray[idx].pos.y = boardCellY;

			boardCellX += g_CellSize + g_Border;

			if (colIdx == nrCols - 1)
				boardCellX = initX;  // Next row. X reset to init value
		}
	}

}

void DrawPlayers()
{
	DrawCell(g_Choices[g_PlayerLeft.choice], g_PlayerLeft.pos.x, g_PlayerLeft.pos.y);
	DrawCell(g_Choices[g_PlayerRight.choice], g_PlayerRight.pos.x, g_PlayerRight.pos.y);
}

void DrawGame()
{
	DrawBackground();
	DrawBoard();
	DrawPlayers();
}

// Initialize everything needed for the game
void InitGame()
{
	// Load resources for the game
	LoadResources();
	InitBoard();
	InitPlayers();

}

void InitBoard()
{
	for (int i{ 0 }; i < g_BoardSize; i++)
	{
		// Initialize board array with Free Cell texture
		g_BoardArray[i].texture = g_FreeCell;
		g_BoardArray[i].free = true;			// Cell Free
	}

}

// Init data for the players
void InitPlayers()
{
	// Init the g_Choices for the player's
	g_Choices[Choice::greenO] = g_GreenO;
	g_Choices[Choice::whiteO] = g_WhiteO;
	g_Choices[Choice::whiteX] = g_WhiteX;
	g_Choices[Choice::greenX] = g_GreenX;

	// Left Player
	g_PlayerLeft.pos.x = g_Border;
	g_PlayerLeft.pos.y = g_Border;
	g_PlayerLeft.active = false;
	g_PlayerLeft.key_pressed = false;
	g_PlayerLeft.choice = Choice::whiteO;

	// Right Player
	g_PlayerRight.pos.x = g_WindowWidth - g_CellSize - g_Border;
	g_PlayerRight.pos.y = g_Border;
	g_PlayerRight.active = true;
	g_PlayerRight.key_pressed = false;
	g_PlayerRight.choice = Choice::greenX;

}
// Get the index of the 2D array
int GetIndex(int rowIdx, int colIdx, int nrCols)
{
	int idx{};

	idx = rowIdx * nrCols + colIdx;

	return idx;
}


// Update player's stuff
void UpdatePlayers()
{
	// Check the active player
	if (g_PlayerLeft.active)
	{
		UpdateChoice(g_PlayerLeft);
	}
	else
	{
		UpdateChoice(g_PlayerRight);
	}
	
}

// Update the player choice according to the current one
void UpdateChoice(Player& player)
{
	
	if (player.key_pressed)
	{
		// Check the current choice
		if (player.choice == Choice::greenO)
		{
			player.choice = greenX;
		}
		else
		{
			player.choice = greenO;
		}

	}

	player.key_pressed = false;
}

// Check if the player clicked on a free cell from the board
void CheckMouse(float posX, float posY, Player& player)
{	
	for (int i{}; i < g_BoardSize; i++)
	{
		std::cout << g_BoardArray[i].pos.x << " " << g_BoardArray[i].pos.x + g_CellSize << std::endl;
		if (g_BoardArray[i].free)
		{
			// Cell free --> Check if we clicked in it
			if (posX > g_BoardArray[i].pos.x && posX < g_BoardArray[i].pos.x + g_CellSize)
			{
				if (posY > g_BoardArray[i].pos.y && posY < g_BoardArray[i].pos.y + g_CellSize)
				{
				
					SelectCell(g_BoardArray[i]);
				}
			}
		}
	}
}

void SelectCell(Cell& selection)
{
	if (g_PlayerLeft.active)
	{
		selection.texture = g_Choices[g_PlayerLeft.choice];
		g_PlayerLeft.active = false;
		g_PlayerRight.active = true;
	}
	else
	{
		selection.texture = g_Choices[g_PlayerRight.choice];
		g_PlayerRight.active = false;
		g_PlayerLeft.active = true;
	}
}
#pragma endregion ownDefinitions