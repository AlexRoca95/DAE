#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	
	

}

void Draw()
{
	ClearBackground();

	// Concentric squares
	DrawSquares();
	
	// Draw equilateral triangles
	DrawEquilateralTriangles();

	//Linear Gradient
	DrawLinearGradients();

	

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

// Draw 3 concentric squares
void DrawSquares()
{
	// Concentric squares
	float outermostSize = 80.f;		 // Size of the outer square
	float size = outermostSize;		 // Reference size for calculating the Y pos for all rectangles
	int amount{ 10 };				 // Amount of rectangles to draw
	Point2f pos{ pos.x = g_Border, pos.y = g_WindowHeight - g_Border - size };

	for (int i = 0; i < 3; i++)
	{
		DrawSquare(pos, outermostSize, amount);

		pos.x += outermostSize + g_Border;
		amount = int(amount / 1.5f);
		outermostSize /= 1.5f;

	}

}

void DrawSquare(Point2f pos, float outermostSize, int squares)
{

	utils::SetColor(0.f, 0.f, 0.f);

	// We draw the outermost square 
	utils::DrawLine(pos.x, pos.y, pos.x + outermostSize, pos.y);
	utils::DrawLine(pos.x, pos.y, pos.x, pos.y + outermostSize);
	utils::DrawLine(pos.x + outermostSize, pos.y, pos.x + outermostSize, pos.y + outermostSize);
	utils::DrawLine(pos.x, pos.y + outermostSize, pos.x + outermostSize, pos.y + outermostSize);

	int space{ };

	space += (int(outermostSize) / squares) / 2;

	// Draw the number squares indicated by argument (-1 because the outer is already been drawn)
	for (int i = 0; i < squares - 1; i++)
	{

		utils::DrawLine(pos.x + space, pos.y + space, pos.x + outermostSize - space, pos.y + space);
		utils::DrawLine(pos.x + space, pos.y + space, pos.x + space, pos.y + outermostSize - space);
		utils::DrawLine(pos.x + outermostSize - space, pos.y + space, pos.x + outermostSize - space, pos.y + outermostSize - space);
		utils::DrawLine(pos.x + space, pos.y + outermostSize - space, pos.x + outermostSize - space, pos.y + outermostSize - space);

		space += (int(outermostSize) / squares) / 2;  // Space between squares
	}


}

// Draw three filled triangles with different lengths and colors
void DrawEquilateralTriangles()
{
	float size{ 80.f };			
	float length{ 80.f };		// Length sides of the triangle
	bool filled = true;
	int offset = 8;
	Point2f posVert{ posVert.x = g_WindowWidth / 2, posVert.y = g_WindowHeight - g_Border - size };
	Color4f color{ color.r = 1.f, color.g = 0.f, color.b = 0.f, color.a = 1.0f };

	// Draw three filled triangles 
	for (int i = 0; i < 3; i++)
	{
		DrawEquilateralTriangle(posVert, length, filled, color);

		// Next drawing of the triangle
		posVert.x += offset;
		posVert.y += offset;
		length -= 2 * offset;

		// Diferent colors
		if (color.g == 0.f)
		{
			// Green
			color.r = 0.f;
			color.g = 1.0f;
		}
		else
		{
			if (color.b == 0.f)
			{
				// Blue
				color.g = 0.0f;
				color.b = 1.0f;
			}
		}
	}

	/*
	length = g_LengthTriangle;
	filled = true;
	posVert.x += g_LengthTriangle + g_Border;

	color.g = 1.0f;
	color.b = 1.0f;

	DrawEquilateralTriangle(posVert, length/2, filled, color);
	*/
	

}

// Draw an equilateral triangle (filled or not) applying trigonometry. 
void DrawEquilateralTriangle(Point2f vertex1, float length, bool filled, Color4f color)
{
	utils::SetColor(color);

	// Coordinates of the triangle.
	float x{ vertex1.x + (length * cosf(g_Radian60)) };  // Cos for X
	float y{ vertex1.y + (length * sinf(g_Radian60)) };  // Sin for y
	Point2f p2{x, y};		// Middle vertex
	
	Point2f p3{ vertex1.x + length, vertex1.y};			 // 3 point at same Y pos

	// Check if we want a filled triangle or not
	if (filled)
	{
		FillTriangle(vertex1, p2, p3);
	}
	else
	{
		DrawTriangle(vertex1, p2, p3);
	}
	
}

// Draw all the linear gradients
void DrawLinearGradients()
{
	// Position for first gradient linear
	g_YPosGrad = (g_WindowHeight / 2) + 30;

	// First gradients
	Rectf rectangle{ rectangle.left = g_Border, rectangle.bottom = g_YPosGrad, rectangle.height = 60, rectangle.width = 18 };
	Color4f colorL{ colorL.r = 0.f, colorL.g = 0.f, colorL.b = 0.f, colorL.a = 1.f };
	Color4f colorR{ colorR.r = 1.0f, colorR.g = 1.0f, colorR.b = 1.0f, colorR.a = 0.f };
	DrawLinearGradient(rectangle, colorL, colorR);

	// Second gradient 
	Rectf rectangle2{ rectangle2.left = g_Border, rectangle2.bottom = g_YPosGrad, rectangle2.height = 100, rectangle2.width = 18 };
	colorL.r = 1.f;
	colorL.g = 0.f;
	colorL.b = 0.05f;
	colorL.a = 1.f;

	colorR.r = 1.0f;
	colorR.g = 0.f;
	colorR.b = 1.0f;
	colorR.a = 0.f;
	DrawLinearGradient(rectangle2, colorL, colorR);

	// Third gradient 
	Rectf rectangle3{ rectangle3.left = g_Border, rectangle3.bottom = g_YPosGrad, rectangle3.height = 130, rectangle3.width = 18 };
	colorL.r = 0.48f;
	colorL.g = 0.47f;
	colorL.b = 0.07f;
	colorL.a = 1.f;

	colorR.r = 0.99f;
	colorR.g = 0.47f;
	colorR.b = 0.46f;
	colorR.a = 0.f;
	DrawLinearGradient(rectangle3, colorL, colorR);

	// last gradient 
	Rectf rectangle4{ rectangle4.left = g_Border, rectangle4.bottom = g_YPosGrad, rectangle4.height = 150, rectangle4.width = 18 };
	colorL.r = 0.05f;
	colorL.g = 0.2f;
	colorL.b = 0.99f;
	colorL.a = 1.f;

	colorR.r = 0.82f;
	colorR.g = 0.58f;
	colorR.b = 0.66f;
	colorR.a = 0.f;
	DrawLinearGradient(rectangle4, colorL, colorR);

}


//Draw a linear gradient with two lineas which have different transparency
void DrawLinearGradient(Rectf rectangle, Color4f leftC, Color4f rightC)
{
	Point2f startLine{}, endLine{};			// Start and end of the line
	float colourShift{ 1.0f / rectangle.width };

	rightC.a = 0;

	// We are drawing till the size of the rectangle
	for (int i = 1; i < rectangle.width; i++)
	{	
		// Vertical line with the size of the rectangle.
		// Drawing from the bottom to the top. 
		startLine.x = rectangle.left + i;
		startLine.y = g_YPosGrad;
		endLine.x = rectangle.left + i;
		endLine.y = g_YPosGrad + rectangle.height;

		utils::SetColor(leftC);			// Left color
		utils::DrawLine(startLine, endLine);

		utils::SetColor(rightC);		// Right color
		utils::DrawLine(startLine, endLine);

		// We change the transparency for each line in order to get the gradient
		leftC.a -= colourShift;
		rightC.a += colourShift;

	}

	// Update the Y position for the next linear gradient
	g_YPosGrad -= rectangle.height + 5;

}

#pragma endregion ownDefinitions