#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// Initial X - Y values for squares
		// Yellow Square
		g_YellowX = g_WindowWidth - g_SquareSize;
		g_InitialYellowX = g_YellowX;
		// Blue Square
		g_BlueX = g_WindowWidth - g_SquareSize;
		g_BlueY = g_WindowHeight - g_SquareSize;
		// Green Square
		g_GreenY = g_WindowHeight - g_SquareSize;
		g_InitialGreenY = g_GreenY;
		// Red square 
		// initialized with 0 - 0 values
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawBlueSquare();
	DrawYellowSquare();
	DrawRedSquare();
	DrawGreenSquare();


}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdateRedSquare();
	UpdateYellowSquare();
	UpdateGreenSquare();
	UpdateBlueSquare();
	
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

void DrawYellowSquare()
{
	utils::SetColor(0.88f, 0.92f, 0.38f, 0.8f);
	utils::FillRect(g_YellowX, g_YellowY, g_SquareSize, g_SquareSize);

	// Drawing surrounding lines
	utils::SetColor(0.f, 0.f, 0.f);
	utils::DrawLine(g_YellowX, g_YellowY, g_YellowX + g_SquareSize, g_YellowY);
	utils::DrawLine(g_YellowX, g_YellowY, g_YellowX, g_YellowY + g_SquareSize);
	utils::DrawLine(g_YellowX, g_YellowY + g_SquareSize, g_YellowX + g_SquareSize, g_YellowY + g_SquareSize);
	utils::DrawLine(g_YellowX + g_SquareSize, g_YellowY, g_YellowX + g_SquareSize, g_YellowY + g_SquareSize);


}

void DrawBlueSquare()
{
	utils::SetColor(0.30f, 0.34f, 0.97f, 0.8f);
	utils::FillRect(g_BlueX, g_BlueY, g_SquareSize, g_SquareSize);

	// Drawing surrounding lines
	utils::SetColor(0.f, 0.f, 0.f);
	utils::DrawLine(g_BlueX, g_BlueY, g_BlueX + g_SquareSize, g_BlueY);
	utils::DrawLine(g_BlueX, g_BlueY, g_BlueX, g_BlueY + g_SquareSize);
	utils::DrawLine(g_BlueX, g_BlueY + g_SquareSize, g_BlueX + g_SquareSize, g_BlueY + g_SquareSize);
	utils::DrawLine(g_BlueX + g_SquareSize, g_BlueY, g_BlueX + g_SquareSize, g_BlueY + g_SquareSize);
}

void DrawGreenSquare()
{
	utils::SetColor(0.30f, 0.93f, 0.38f, 0.8f);
	utils::FillRect(g_GreenX, g_GreenY, g_SquareSize, g_SquareSize);

	// Drawing surrounding lines
	utils::SetColor(0.f, 0.f, 0.f);
	utils::DrawLine(g_GreenX, g_GreenY, g_GreenX + g_SquareSize, g_GreenY);
	utils::DrawLine(g_GreenX, g_GreenY, g_GreenX, g_GreenY + g_SquareSize);
	utils::DrawLine(g_GreenX, g_GreenY + g_SquareSize, g_GreenX + g_SquareSize, g_GreenY + g_SquareSize);
	utils::DrawLine(g_GreenX + g_SquareSize, g_GreenY, g_GreenX + g_SquareSize, g_GreenY + g_SquareSize);

}

void DrawRedSquare()
{
	utils::SetColor(0.88f, 0.34f, 0.38f, 0.8f);
	utils::FillRect(g_RedX, g_RedY, g_SquareSize, g_SquareSize);

	// Drawing surrounding lines
	utils::SetColor(0.f, 0.f, 0.f);
	utils::DrawLine(g_RedX, g_RedY, g_RedX + g_SquareSize, g_RedY);
	utils::DrawLine(g_RedX, g_RedY, g_RedX, g_RedY + g_SquareSize);
	utils::DrawLine(g_RedX, g_RedY + g_SquareSize, g_RedX + g_SquareSize, g_RedY + g_SquareSize);
	utils::DrawLine(g_RedX + g_SquareSize, g_RedY, g_RedX + g_SquareSize, g_RedY + g_SquareSize);

}

// Move Red square Horintal: +1 pixel | Vertical: +1 pixel every frame
void UpdateRedSquare()
{

	g_RedX++;			

	g_RedX = float(int(g_RedX) % int(g_WindowWidth)); // Reach max width? then reset to 0 again
	g_RedY = g_RedX;			// Both pos move at the same speed and need the same values

}
// Move Yellow square Horintal: -1 pixel | Vertical: +1 pixel every frame
void UpdateYellowSquare()
{

	g_YellowY++;
	
	g_YellowY = float(int(g_YellowY) % int(g_WindowHeight));   // Reach max height? then reset to 0 again
	
	g_YellowX = g_InitialYellowX - g_YellowY;			// Pos X will change as the same time as Y value
	
}

// Move Green square Horintal: +1 pixel | Vertical: -1 pixel every frame
void UpdateGreenSquare()
{
	/*
	g_GreenX++;

	g_GreenX = float(int(g_GreenX) % int(g_WindowWidth)); // Reach max width? then reset to 0 again
	*/
	g_GreenX = g_RedX;									// Both use same pos and same speed
	g_GreenY = g_InitialGreenY - g_GreenX;				// Pos X will change as the same time as Y value

}
// Move Blue square Horintal: -1 pixel | Vertical: -1 pixel every frame
void UpdateBlueSquare()
{
	// We use the values of the other rectangles because they use the same values and at the same speed
	g_BlueX = g_YellowX;
	g_BlueY = g_GreenY;

}

#pragma endregion ownDefinitions