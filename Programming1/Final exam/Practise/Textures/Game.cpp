#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	// Loading a texture and check if it was loaded correctly
	bool succes = TextureFromFile("Resources/DAE.png", g_DAELogo);

	if (!succes)
		std::cout << "Fail loading DAE.png" << std::endl;

	// Loading a text with a font style
	// We indicate: what we want to write, the font-style, font-size, color, texture object
	succes = TextureFromString("Hola Mundo", "Resources/DIN-Light.otf", 22, Color4f{0, 0, 0, 1}, g_Text);

	if(!succes)
		std::cout << "Fail loading Din-Light.otf" << std::endl;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here


	// WORKING WITH A TEXTURE
	// Draw texture at a position
	Point2f pos{ 10 , 10};

	DrawTexture(g_DAELogo, pos);

	// We can create a rect where it will be the place where the texture will be draw
	Rectf rect{};
	// Coord rect
	rect.bottom = 250;
	rect.left = 10;
	// Size rect (size texture)
	rect.width = 100;
	rect.height = 10;

	DrawTexture(g_DAELogo, rect);


	rect.left = 200; 
	// If we work with the sizes of the texture, it will fit better
	rect.width = g_DAELogo.width / 2;		// Get width of the texture
	rect.height = g_DAELogo.height / 2;

	DrawTexture(g_DAELogo, rect);

	// Draw part of the texture
	// We use paint to get the positions and the widht and height
	Rectf partTexture{};
	// Checking values on paint with view and ruler
	partTexture.width = 101;
	partTexture.height = 12;
	partTexture.bottom = 50;
	partTexture.left = 100;

	DrawTexture(g_DAELogo, g_FramePos, partTexture);
	// Draw the text with the properties that we set
	pos.y = 100;
	DrawTexture(g_Text, pos);

}

void Update(float elapsedSec)
{
	// process input, do physics 

	CheckKeyStates(elapsedSec);
	
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

void CheckKeyStates(float elapsedSec)
{
	const float speed{ 50.f };
	// e.g. Check keyboard state
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (pStates[SDL_SCANCODE_RIGHT])
	{
		// New pos frame independent Position = position + speed * elapsedSec
		g_FramePos.x += speed * elapsedSec;
		
	}
	if (pStates[SDL_SCANCODE_LEFT])
	{
		g_FramePos.x -= speed * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_UP])
	{
		g_FramePos.y += speed * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_DOWN])
	{
		g_FramePos.y -= speed * elapsedSec;
	}


}

#pragma endregion ownDefinitions