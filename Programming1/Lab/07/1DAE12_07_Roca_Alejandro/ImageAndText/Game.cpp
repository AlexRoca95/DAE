#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	// Loading a texture and check if it was loaded correctly
	// Using a relative path
	bool succesful = TextureFromFile("Resources/DAE.png", g_DAELogo); 

	if (!succesful)
		std::cout << "Loading failed" << std::endl;

	// Loading a text
	succesful = TextureFromString("Hello World", "Resources/DIN-Light.otf",48, Color4f{ 0,0,0,1 }, g_SomeText);
	if (!succesful)
		std::cout << "Loading Text failed" << std::endl;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	Point2f position{ 10, 10 };
	DrawTexture(g_DAELogo, position);		// Draw Texture

	position.y = 150;
	DrawTexture(g_SomeText, position);

	Rectf destinationRect{};
	destinationRect.bottom = 250;
	destinationRect.left = 10;
	destinationRect.height = 15;
	destinationRect.width = 150;
	// DestinationRect will be the place where the texture will be draw
	DrawTexture(g_DAELogo, destinationRect);		

	destinationRect.bottom = 250;
	destinationRect.left = 200;
	// The texture will fit better in the rectangle 
	destinationRect.height = g_DAELogo.height / 2;
	destinationRect.width = g_DAELogo.width / 2;
	DrawTexture(g_DAELogo, destinationRect);

	
	Rectf sourceRectangle{};
	// Check g_Positions using Paint of the image
	// Also check width and height with the select tool
	sourceRectangle.left = 55;
	sourceRectangle.bottom = 50;
	sourceRectangle.width = 30;
	sourceRectangle.height = 10;
	DrawTexture(g_DAELogo, g_FramePos, sourceRectangle);  // Draw a certain part of the texture
}

void Update(float elapsedSec)
{
	// process input, do physics 
	const float speed{ 50 };
	 //e.g. Check keyboard state
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );  // Uint8 --> unsigned int of 8 bits
	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		g_FramePos.x += speed * elapsedSec;
		//std::cout << "Right arrow key is down\n";
	}
	if ( pStates[SDL_SCANCODE_LEFT])
	{
		g_FramePos.x -= speed * elapsedSec;
		//std::cout << "Left and up arrow keys are down\n";
	}
}

void End()
{
	// free game resources here
	// Delete the texture
	DeleteTexture(g_DAELogo);
	DeleteTexture(g_SomeText);
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

#pragma endregion ownDefinitions