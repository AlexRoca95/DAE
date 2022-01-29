#include "pch.h"
#include "Game.h"
#include "Vehicle.h"
#include <iostream>


//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitGame();
	PrintInfoGame();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawBackground();
	DrawChicken();
	DrawVehicles();

	switch (g_GameState)
	{
	case GameState::pause:
		// Game paused
		DrawFont(g_PauseText);
		break;
	case GameState::win:
		// Player wins!
		DrawFont(g_WinText);
		break;
	case GameState::lose:
		// Player loose
		DrawFont(g_LoseText);
		break;
	}
	
}

void Update(float elapsedSec)
{
	// process input, do physics 

	if (g_GameState == GameState::reset)
	{
		ResetChickenPos();
		g_GameState = GameState::play;

	}

	if (g_GameState == GameState::play)
	{
		moveChicken(elapsedSec);
	}

	if(g_GameState != GameState::pause)
		moveVehicles(elapsedSec);
	
}

void End()
{
	// free game resources here
	DeleteTexture(g_WinText);
	DeleteTexture(g_LoseText);
	DeleteTexture(g_PauseText);
	DeleteTexture(g_Chicken.image);
	DeleteTexture(g_Background);

	for (int i{ 0 }; i < g_TotalVehicles; i++)
	{
		delete g_Vehicles[i];
		g_Vehicles[i] = nullptr;
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
	case SDLK_r:
		// Reset the game
		g_GameState = GameState::reset;
		ActivateVehicles();
		break;
	case SDLK_p:
		// Pause/Unpause the game
		if (g_GameState == GameState::pause)
		{
			g_GameState = GameState::play;
		}
		else
		{
			if(g_GameState == GameState::play)
				g_GameState = GameState::pause;
		}
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


// Initialize everything needed for the game
void InitGame()
{
	LoadResources();
	InitChicken();
	InitVehicles();

	// Initial state of the game
	g_GameState = GameState::reset;

}

// Init data for the chicken
void InitChicken()
{
	g_Chicken.nFrames = 3;
	g_Chicken.speed = 100;
	g_Chicken.currentFrame = 0;			// Start with the leftmost frame
	g_Chicken.scale = 20.f;

	g_Chicken.position.left = g_WindowWidth / 2;
	g_Chicken.position.bottom = g_WindowHeight - 20;
	g_Chicken.position.width = g_Chicken.scale;				// Rescale the size of the texture
	g_Chicken.position.height = g_Chicken.scale;

	g_Chicken.srcRect.width = g_Chicken.image.width / g_Chicken.nFrames;
	g_Chicken.srcRect.height = g_Chicken.image.height;
	g_Chicken.srcRect.left = g_Chicken.srcRect.width * (g_Chicken.currentFrame % g_Chicken.nFrames);
	g_Chicken.srcRect.bottom = g_Chicken.srcRect.height;



}


// Init data for all vehicles and colocate them in the correct Y pos
void InitVehicles()
{
	float separation = g_PavementSize;

	for (int i{ 0 }; i < g_TotalVehicles; i++)
	{
		g_Vehicles[i] = new Vehicle{i + 1};
		g_Vehicles[i]->SetYPos(separation);

		separation += 45;	// Size of each lane

	}


}

// Load all the resources
void LoadResources()
{
	LoadTexture(g_Background,"Resources/street.png");
	LoadTexture(g_Chicken.image, "Resources/Chicken.bmp");
	LoadFont(g_WinText, "The chicken survived!", "Resources/consola.ttf");
	LoadFont(g_LoseText, "The chicken died!", "Resources/consola.ttf");
	LoadFont(g_PauseText, "Pause", "Resources/consola.ttf");

}

// Try to load the texture passed by parameter
void LoadTexture(Texture& image, const std::string path)
{
	bool load{};

	load = TextureFromFile(path, image);

	if (!load)
		std::cout << "Error at loading texture " << path << std::endl;

}

// Try to load a font
void LoadFont(Texture& image, const std::string text, const std::string path)
{
	bool load{};
	int fontSize{ 40 };
	Color4f fontColor{ 1, 1, 1, 1 };

	load = TextureFromString(text, path, fontSize, fontColor, image);

	if (!load)
		std::cout << "Error at loading font " << path << std::endl;

}

// Draw the background texture
void DrawBackground()
{
	Point2f pos{ 0, 0 };
	DrawTexture(g_Background, pos);
}

// Draw the chicken
void DrawChicken()
{
	DrawTexture(g_Chicken.image, g_Chicken.position, g_Chicken.srcRect);
}


// Draw the text with a semitransparent black background
void DrawFont(const Texture& image)
{
	// Middle of the screen
	Point2f pos{ (g_WindowWidth/2) - image.width/2 , (g_WindowHeight / 2) - (image.height / 2)};

	// Background
	Color4f color{ 0.f, 0.f, 0.f, 0.5f }; // Semitransparent black color
	Rectf background{ pos.x, pos.y, image.width, image.height };
	utils::SetColor(color);
	utils::FillRect(background);

	// Text
	DrawTexture(image, pos);

}
// Draw all the vehicles
void DrawVehicles()
{
	for (int i{ 0 }; i < g_TotalVehicles; i++)
	{
		g_Vehicles[i]->Draw();
	}
}

// Reset the position of the chicken to his initial pos everytime the 'R' key is pressed
void ResetChickenPos()
{
	g_Chicken.position.left = g_WindowWidth / 2;
	g_Chicken.position.bottom = g_WindowHeight - 20;
}

// Activate all the vehicles and change his speed and X-pos
void ActivateVehicles()
{
	for (int i{ 0 }; i < g_TotalVehicles; i++)
	{
		g_Vehicles[i]->Reset();
	}
}
// Update the movement of the chicken
void moveChicken(float elapsedSec)
{
	// e.g. Check keyboard state
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		g_Chicken.position.left += g_Chicken.speed * elapsedSec;
	}

	if ( pStates[SDL_SCANCODE_LEFT])
	{
		g_Chicken.position.left -= g_Chicken.speed * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_DOWN])
	{
		g_Chicken.position.bottom -= g_Chicken.speed * elapsedSec;
		
	}

	
	if (g_Chicken.position.bottom + g_Chicken.position.height <= g_PavementSize)
	{
		// Chicken has reached the lower pavement
		g_GameState = GameState::win;

	}

	checkCollision();

}

void moveVehicles(float elapsedSec)
{
	for (int i{ 0 }; i < g_TotalVehicles; i++)
	{
		g_Vehicles[i]->Update(elapsedSec, g_WindowWidth);
	}
}

// Check collision between the vehicles and the chicken
void checkCollision()
{
	// Middle position of the chicken
	Point2f chickenPos{ g_Chicken.position.left + g_Chicken.position.width/2,  g_Chicken.position.bottom + g_Chicken.position.height/2};
	bool collision{};

	for (int i{ 0 }; i < g_TotalVehicles && collision==false; i++)
	{
		collision = g_Vehicles[i]->IsIntersecting(chickenPos);

		if (collision)
		{
			// Collision between the vehicle and the chicken
			g_Vehicles[i]->SetActive(false);
			g_GameState = GameState::lose;
		}
	}

}

// Print the key binding and the isntructions of the game
void PrintInfoGame()
{

	std::cout << "Press r to reset." << std::endl;
	std::cout << "Press p to pause/unpause." << std::endl;
	std::cout << "Use the arrow keys to move the chicken." << std::endl;
}

#pragma endregion ownDefinitions