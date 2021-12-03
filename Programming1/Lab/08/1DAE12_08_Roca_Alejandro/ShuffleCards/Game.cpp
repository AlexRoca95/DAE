#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	LoadCards();

}

void Draw()
{
	ClearBackground();

	DrawCards();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	// process input, do physics 

	if(g_Shuffle==true)
	{
		Shuffle(g_ArrayCards, g_Size, 20); // Shuffle cards once

		g_Shuffle = false;
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

	// Free memory of all the textures from the array
	for (int i{ 0 }; i < g_Size; i++)
	{
		DeleteTexture(g_ArrayCards[i]);
	}

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
		g_Shuffle = true;
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

// Load cards textures into the array
void LoadCards()
{
	const int nrCols{ 13 }, nrRows{ 4 };  // 4 x 13 = 52 elements
	int rowIdx{  }, idx{}, colIdx{  };
	int cardNumber{};
	bool load{  };

	// 2D loop for load all the textures
	for (rowIdx; rowIdx < nrRows; rowIdx++)
	{
		for (colIdx = 0; colIdx < nrCols; colIdx++)
		{
			idx = GetIndex(rowIdx, colIdx, nrCols);
			
			cardNumber = (rowIdx + 1) * 100 + colIdx + 1;		// Get the card number to load

			load = TextureFromFile("Resources/Cards/" + std::to_string(cardNumber) + ".png", g_ArrayCards[idx]); // Load texture into the array pos

			if(!load)
				std::cout << "Loading failed" << std::endl;
		}
	}

}

void DrawCards()
{
	Rectf destinationRect{};
	
	const int nrCols{ 13 }, nrRows{ 4 };  // 4 x 13 = 52 elements
	int rowIdx{  }, idx{}, colIdx{  };
	
	// Size of each of the cards according with the size of the window
	float width{ g_WindowWidth / nrCols };
	float height{ g_WindowHeight / nrRows };

	// 2D loop 
	for (rowIdx = 0; rowIdx < nrRows; rowIdx++)
	{
		for (colIdx = 0; colIdx < nrCols; colIdx++)
		{
			idx = GetIndex(rowIdx, colIdx, nrCols);

			destinationRect.height = height;
			destinationRect.width = width;
			
			// Position for each card
			destinationRect.left = width * colIdx;
			destinationRect.bottom = height * rowIdx;

			DrawTexture(g_ArrayCards[idx], destinationRect);

		}
	}
	


}
// Get the index of the 2D array
int GetIndex(int rowIdx, int colIdx, int nrCols)
{
	int idx{};

	idx = rowIdx * nrCols + colIdx;

	return idx;
}


// Shuffle the elements in the array by swapping a number of times two random elements
void Shuffle(Texture* pArray, const int size, const int swaps)
{
	int idx1{}, idx2{};

	// Swap values the number of times determined by swaps
	for (int i{}; i < swaps; i++)
	{
		do {

			idx1 = RandomNumber(size);
			idx2 = RandomNumber(size);
			//std::cout << "First random number " << idx1 << std::endl;
			//std::cout << "Second random number " << idx2 << std::endl;
			// Keep generating random numbers until we get two different ones
		} while (idx1 == idx2);

		Swap(pArray, size, idx1, idx2);
	}

}

// Swap two elements from the array
void Swap(Texture* pArray, const int size, const int idx1, const int idx2)
{
	// Check if the indexs are inside the limits of the array
	if (idx1 < 0 || idx1 >= size)
	{
		std::cout << idx1 << " is out of the limits of the array." << std::endl;

		return;
	}

	if (idx2 < 0 || idx2 >= size)
	{
		std::cout << idx2 << " is out of the limits of the array." << std::endl;

		return;
	}

	Texture saveElement{};

	// Save the element from the array
	saveElement = pArray[idx1];
	pArray[idx1] = pArray[idx2];
	pArray[idx2] = saveElement;
}

// Generate a random number within the limits of the array
int RandomNumber(const int size)
{
	int random{};

	random = rand() % size;  // Random between 0 and the size - 1

	return random;
}

#pragma endregion ownDefinitions