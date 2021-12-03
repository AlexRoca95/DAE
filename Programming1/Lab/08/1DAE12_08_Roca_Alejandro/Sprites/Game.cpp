#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	// Init data for the Knight sprite. 
	InitSprite(g_KnightSprite, "Resources/RunningKnight.png", 8, 8, 1 / 10.f, 0, g_KnightPos);
	// Init data for the Tibo Sprite
	InitSprite(g_TiboSprite, "Resources/Tibo.png", 5, 25, 1 / 15.f, 0, g_TiboPos);
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawKnight();
	DrawTibo();
}

void Update(float elapsedSec)
{
	// process input, do physics 

	UpdateSprite(g_KnightSprite,elapsedSec);
	MoveKnight();

	UpdateSprite(g_TiboSprite, elapsedSec);

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

	DeleteTexture(g_KnightSprite.texture);
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

void DrawKnight()
{
	// Part of the texture that corresponds with the current frame number
	Rectf srcRect{};

	// Width of one frame  from the texture
	srcRect.width = g_KnightSprite.texture.width / g_KnightSprite.cols;
	srcRect.height = g_KnightSprite.texture.height;
	srcRect.left = srcRect.width * g_KnightSprite.currentFrame;
	srcRect.bottom = srcRect.height;

	// Draw it at the top of the window
	const float scale{ 5.0f };		// Scale sprite x5
	const float border{ 10.0f };
	Rectf destRect{};

	destRect.left = g_KnightPos;
	destRect.bottom = g_WindowHeight - border - (g_KnightSprite.texture.height * scale);
	destRect.width = srcRect.width * scale;
	destRect.height = srcRect.height * scale;

	DrawTexture(g_KnightSprite.texture, destRect, srcRect);

}

// Move Knight sprite to the right frame independent (10 fps) until it leaves the window
void MoveKnight()
{
	// Move sprite 
	g_KnightPos += g_KnightSpeed * g_KnightSprite.accumulatedTime;

	if (g_KnightPos >= g_WindowWidth)
	{
		// When it leaves the window, it starts again at the left
		g_KnightPos = initialPos;
	}

}

// Load a texture for a Sprite and initialize all the data needed
void InitSprite(Sprite& sprite, std::string path, int cols, int frames, float frameTime, int currentFrame, float xPos)
{
	bool loaded{};

	loaded = TextureFromFile(path, sprite.texture);

	if (!loaded) // Check if texture was loaded or not
	{
		std::cout << "Failed to load image " << path << std::endl;
	}

	sprite.cols = cols;
	sprite.frames = frames;				// Number of frames for the animation
	sprite.currentFrame = currentFrame;
	sprite.frameTime = frameTime;		// Framerate for the animation	


	sprite.xPos = initialPos;			// Initial X pos for the sprite
}


void DrawTibo()
{
	// Part of the texture that corresponds with the current frame number
	Rectf srcRect{};
	srcRect.width = g_TiboSprite.texture.width / g_TiboSprite.cols;
	srcRect.height = g_TiboSprite.texture.height / (g_TiboSprite.frames / g_TiboSprite.cols);

	// Columns of the sprite
	srcRect.left = srcRect.width * (g_TiboSprite.currentFrame % g_TiboSprite.cols);
	// Rows of the sprite
	srcRect.bottom = srcRect.height * (g_TiboSprite.currentFrame / g_TiboSprite.cols + 1);

	// Draw it at the bottom of the window
	const float border{ 10.0f };
	Rectf destRect{};

	destRect.left = g_TiboPos;
	destRect.bottom = border;
	destRect.width = srcRect.width;
	destRect.height = srcRect.height;

	DrawTexture(g_TiboSprite.texture, destRect, srcRect);

}

// Update the frames from the sprite passed
void UpdateSprite(Sprite& sprite, float elapsedSec)
{
	// Hold info about the elapsed time
	sprite.accumulatedTime += elapsedSec;

	// Check if the elapsed time is larger than the framerate (
	if (sprite.accumulatedTime > sprite.frameTime)
	{
		// Elapsed time more than framerate --> Next frame 
		++sprite.currentFrame %= sprite.frames;		// Check if we reach the limit of frames  (if so reset to 0)

		sprite.accumulatedTime -= sprite.frameTime; // Reset accumulatedTime so it counts again
	}
}

#pragma endregion ownDefinitions