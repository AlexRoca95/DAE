// Alejandro, Roca Vande Sype - 1DAE12

#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();									// We can change background color from here

	// Put your own draw statements here
	
	// DRAW 2 RED DIAGONALS LINES
	utils::SetColor(1.f, 0.f, 0.f);								// RED COLOR
	utils::DrawLine(0.f, 0.f, g_WindowWidth, g_WindowHeight);   // From left down corner to right upper corner	

	utils::SetColor(1.f, 0.f, 0.f);								
	utils::DrawLine(g_WindowWidth, 0.f, 0.f, g_WindowHeight);   // From right down corner to upper left corner	

	// GREEN BORDER
	utils::SetColor(0.f, 1.f, 0.f);								// GREEN COLOR
	utils::DrawLine(g_WindowWidth, 0.f, g_WindowWidth, g_WindowHeight);		// RIGHT 

	utils::SetColor(0.f, 1.f, 0.f);								
	utils::DrawLine(0.f, 0.f, g_WindowWidth, 0.f);							// DOWN

	utils::SetColor(0.f, 1.f, 0.f);
	utils::DrawLine(1.f, g_WindowHeight-1, g_WindowWidth, g_WindowHeight-1);   // UP

	utils::SetColor(0.f, 1.f, 0.f);
	utils::DrawLine(1.f, 1.f, 0.f, g_WindowHeight);							// LEFT


	// BLUE RECTANGLE IN THE CENTER
	utils::SetColor(0.f, 0.f, 1.f);											// BLUE COLOR
	utils::FillRect((g_WindowWidth/2)-2, (g_WindowHeight/2)-2, 4.f, 4.f);	// X, Y, WIDTH, HEIGHT

	// Vertical lines
	utils::SetColor(1.f, 1.f, 1.f);												// White COLOR
	utils::DrawLine(g_WindowWidth/3, 0.f, g_WindowWidth/3, g_WindowHeight);			

	utils::SetColor(1.f, 1.f, 1.f);												
	utils::DrawLine(((g_WindowWidth)*2) / 3, 0.f, ((g_WindowWidth) * 2) / 3, g_WindowHeight);

	// Horizontal lines
	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(0.f, g_WindowHeight/3, g_WindowWidth, g_WindowHeight / 3);

	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawLine(0.f, ((g_WindowHeight) * 2) / 3, g_WindowWidth, ((g_WindowHeight) * 2) / 3);
	
}

void Update(float elapsedSec)
{
	// process input, do physics 

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
	case SDLK_LEFT:
		//std::cout << "Left arrow key released\n";
		break;
	case SDLK_RIGHT:
	//	std::cout << "Right arrow key released\n";
		break;
	case SDLK_1:
	case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
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

#pragma endregion ownDefinitions