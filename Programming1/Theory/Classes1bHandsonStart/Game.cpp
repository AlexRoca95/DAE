#include "pch.h"
#include "Game.h"
#include "BouncingCircle.h"
#include "Box.h"

//Basic game functions
#pragma region gameFunctions											

void Start()
{
	// initialize game resources here
	g_pCircle = new BouncingCircle{ Rectf {0,0, g_WindowWidth, g_WindowHeight} };
	Rectf r{ 10,10,100,100 };
	for (int i{}; i < g_NumberOfCircles; i++)
	{
		g_pManyCircles[i] = new BouncingCircle{ r, rand() % 20 + 10.f, Point2f{r.left+r.width / 2, r.bottom + r.height / 2 } };
	}

	r.left = 150;
	g_pBox1 = new Box{r};
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	if (g_pCircle)g_pCircle->DrawCircle();

	for (int i{}; i < g_NumberOfCircles; i++)
	{
		//g_pManyCircles[i]->DrawCircle();
	}

	g_pBox1->Draw();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	if(g_pCircle)g_pCircle->UpdateCircle(elapsedSec);

	for (int i{}; i < g_NumberOfCircles; i++)
	{
		g_pManyCircles[i]->UpdateCircle(elapsedSec);
	}

	g_pBox1->Update(elapsedSec);
	//g_pCircle->CheckCollisionCircle();
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

	delete g_pCircle;
	g_pCircle = nullptr;

	for (int i{}; i < g_NumberOfCircles; i++)
	{
		delete g_pManyCircles[i];
		g_pManyCircles[i] = nullptr;
	}

	delete g_pBox1;
	g_pBox1 = nullptr;
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		//std::cout << "Left mouse button released\n";
		Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
		bool isHit{ g_pCircle->IsHit(mousePos) };
		if (isHit)
		{
			delete g_pCircle;
			g_pCircle = nullptr;
		}
		break;
	}
	case SDL_BUTTON_RIGHT:
		//std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		//std::cout << "Middle mouse button released\n";
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions