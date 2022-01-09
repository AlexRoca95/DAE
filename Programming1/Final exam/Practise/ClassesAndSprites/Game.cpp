#include "pch.h"
#include "Game.h"
#include "Sprite.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here


	InitArraySprites();
	
	bool success = TextureFromFile("Resources/DAE.png", g_DAE1);

	if(!success)
		std::cout << "Fail loading texture "<< std::endl;
	

	success = TextureFromString("Hello", "Resources/DIN-Light.otf", 12, Color4f{ 0, 0, 0, 1 }, g_Text);

	if(!success)
		std::cout << "Fail loading font " << std::endl;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	Point2f pos{ 10 , g_WindowHeight / 2 };
	
	for (int i{ 0 }; i < g_SizeArray; i++)
	{
		
		g_pArraSpr[i]->Draw(pos);

		pos.x += g_pArraSpr[i]->GetFrameWidth() * g_pArraSpr[i]->GetScale();
		
	}

	DrawLogo();

}

void Update(float elapsedSec)
{
	// process input, do physics 

	for (int i{ 0 }; i < g_SizeArray; i++)
	{
		if (g_pArraSpr != nullptr)
		{
			// Pointer initialized to a sprite
			g_pArraSpr[i]->Update(elapsedSec);
		}
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

	for (int i{ 0 }; i < g_SizeArray; i++)
	{
		g_pArraSpr[i] = nullptr;
	}

	DeleteTexture(g_DAE1);
	DeleteTexture(g_Text);
	
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

void InitArraySprites()
{

	g_pArraSpr[0] = new Sprite{ "Resources/RunningKnight.png", 8, 1, 1 / 10.f, 5 };
	g_pArraSpr[1] = new Sprite{ "Resources/RunningKnight.png", 8, 1, 1 / 10.f, 3 };
	g_pArraSpr[2] = new Sprite{ "Resources/RunningKnight.png", 8, 1, 1 / 10.f, 2 };
	g_pArraSpr[3] = new Sprite{ "Resources/Tibo.png", 5, 5, 1 / 15.f, 1 };
	g_pArraSpr[4] = new Sprite{ "Resources/Tibo.png", 5, 5, 1 / 15.f, 1 };

}

// Draw 3 times the DAE Logo
void DrawLogo()
{
	const float separation{ 10.f };

	Rectf destRect{};

	destRect.left = separation;
	destRect.bottom = separation;
	destRect.width = g_DAE1.width / 2;
	destRect.height = g_DAE1.height / 2;

	
	for (int i{ 0 }; i < 3; i++)
	{
		DrawTexture(g_DAE1, destRect);

		destRect.left += destRect.width + separation;
	}
}


#pragma endregion ownDefinitions