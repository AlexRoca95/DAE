#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_Border = 10;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawRectangles();
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

void DrawRectangles()
{
	// Random colors
	float r{}, g{}, b{};


	for(int i=0; i<100; i++)
	{
		r = rand() % 100 / 100.f;		// 0 - 99 and then we divide by 100 so we get floats that goes from 0.f to 1.f
		g = rand() % 100 / 100.f;
		b = rand() % 100 / 100.f;
		utils::SetColor(r, g, b);		// Put random color

		// Random Pos X
		int width{}, height{}, distanceX{}, posX{}, distanceY, posY;

		width = rand() % ((int(g_WindowWidth) - 100) - 10 + 1) + 10;			// Random width [10 - 700]

		distanceX = int(g_WindowWidth) - width - g_Border;	// Distance that rect has to be from border X

		posX = rand() % (distanceX - 10 + 1) + 10;	    // Position between [10 - distanceX (size rect + 10 pixels)]


		// Random Pos Y
		height = rand() % ((int(g_WindowHeight) - 100) - 10 + 1) + 10;			// Random height [10 - 400]

		distanceY = int(g_WindowHeight) - height - g_Border;  // Distance that rect has to be from border Y

		posY = rand() % (distanceY - 10 + 1) + 10;		// Position between [10 - distanceY (size rect + 10 pixels)]


		// Draw rectangle with random values
		utils::FillRect(float(posX), float(posY), float(width), float(height));

		utils::SetColor(0.f, 0.f, 0.f);
		utils::DrawLine(float(posX), float(posY), float(posX+width), float(posY));
		utils::DrawLine(float(posX+width), float(posY), float(posX + width), float(posY+height));
		utils::DrawLine(float(posX), float(posY + height), float(posX + width), float(posY + height));
		utils::DrawLine(float(posX), float(posY), float(posX), float(posY + height));
		Sleep(1);
	}
	
}

#pragma endregion ownDefinitions