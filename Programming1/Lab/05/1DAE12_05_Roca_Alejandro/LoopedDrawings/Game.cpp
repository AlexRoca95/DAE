#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	g_Border = 20;
	g_MaxSpace = 250 - g_Border;			// 230 maximum space (taking into account borders of the window)
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f); //Black background

	// Put your own draw statements here
	DrawConcentricSquares();
	DrawStair();
	DrawSpiral();
	DrawSpinningLines();
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

// Draw 5 concentric squares with a loop
void DrawConcentricSquares()
{

	utils::SetColor(0.6f, 1.f, 0.8f);

	int space = 0;		// Space between each concentric line

	for (int i = 0; i < 5; i++) // Draw five lines
	{
		utils::DrawLine(float(g_Border + space), float(g_Border + space), float(g_MaxSpace - space), float(g_Border + space));
		utils::DrawLine(float(g_Border + space), float(g_Border + space), float(g_Border + space), float(g_MaxSpace - space));
		utils::DrawLine(float(g_MaxSpace - space), float(g_Border + space), float(g_MaxSpace - space), float(g_MaxSpace - space));
		utils::DrawLine(float(g_Border + space), float(g_MaxSpace - space), float(g_MaxSpace - space), float(g_MaxSpace - space));
		
		space += 20;		// Next space between lines
	}
	

}
// Draw a stair having 5 steps with alternating color
void DrawStair()
{
	int size{ 44 }; // Step size of the stair
	int space{};    // Space between every pair of steps
	
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
		{	
			// If even then stair painted this color
			utils::SetColor(1.f, 0.6f, 0.6f);
		}
		else
		{
			// if odd, the other color is used
			utils::SetColor(0.6f, 0.8f, 1.f);
		}

		// Draw pair of steps
		utils::DrawLine(float(g_Border + space), float(g_MaxSpace + g_Border + space), float(g_Border + size + space), float(g_MaxSpace + g_Border + space));
		utils::DrawLine(float(g_Border + size + space), float(g_MaxSpace + g_Border + space), float(g_Border + size + space), float(g_MaxSpace + g_Border + size + space));

		space += size;	// Next pair of steps
	}

}

// Draw a Spiral having 5 loops
void DrawSpiral()
{
	int size{ g_MaxSpace - g_Border };		// Size of the lines (responsive with the size of the screen)
	int initialX{ g_MaxSpace + g_Border };	// Initial start of the spiral for X
	int initialY{ g_Border };				// Initial start of the spiral for Y
	int space{}, space2{};					// Spaces between every loop of the spiral

	utils::SetColor(0.6f, 0.8f, 1.f);

	for (int i = 0; i < 5; i++)  // 5 spirals
	{
		// Bottom and Right lines
		utils::DrawLine(float(initialX + space), float(initialY + space), float(initialX + size - space), float(initialY + space));
		utils::DrawLine(float(initialX + size - space), float(initialY + space), float(initialX + size - space), float(initialY + size - space));

		space += 20;

		// Top and left lines
		utils::DrawLine(float(initialX + size - space2), float(initialY + size - space2), float((initialX)+space), float(initialY + size - space2));
		utils::DrawLine(float((initialX)+space), float(initialY + size - space2), float((initialX)+space), float(initialY + space));

		space2 += 20;
	}
}

// Draw 4 sets of 5 spinning lines, each set having another color
void DrawSpinningLines()
{
	int size{ g_MaxSpace - g_Border };				// Size of the lines
	int initialX{ g_MaxSpace + g_Border };
	int initialTopY{ int(g_WindowHeight) - g_Border };
	int initialBotY{ g_MaxSpace + g_Border };
	int turn{};										// Distance we have to turn lines
	
	for (int i = 0; i < 5; i++)
	{

		utils::SetColor(0.6f, 0.8f, 1.f); // Blue
		utils::DrawLine(float(initialX), float(initialTopY - turn), float(initialX + size - turn), float(initialTopY));

		utils::SetColor(0.85f, 0.85f, 0.52f); // Yellow
		utils::DrawLine(float(initialX), float(initialTopY - turn), float(initialX + turn), float(initialBotY));

		utils::SetColor(0.6f, 1.f, 0.8f); // Green
		utils::DrawLine(float(initialX + size - turn), float(initialTopY), float(initialX + size), float(initialBotY + turn));

		utils::SetColor(1.f, 0.6f, 0.6f); // Red
		utils::DrawLine(float(initialX + turn), float(initialBotY), float(initialX + size), float(initialBotY + turn));

		turn += 44;
	}



}


#pragma endregion ownDefinitions