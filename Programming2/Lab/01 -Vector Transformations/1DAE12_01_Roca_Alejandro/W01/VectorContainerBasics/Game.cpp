#include "pch.h"
#include "Game.h"
#include "Card.h"
#include <iostream>


Game::Game( const Window& window ) 
	:m_Window{ window },
	m_Shuffle{false}
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	AddCards();

}

void Game::Cleanup( )
{

	for (int i{ 0 }; i < m_Cards.size(); i++)
	{
		delete m_Cards[i];
		m_Cards[i] = nullptr;
	}

}

void Game::Update( float elapsedSec )
{
	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}


	if (m_Shuffle == true)
	{
		Shuffle(m_Cards, 52, 20); // Shuffle cards once

		m_Shuffle = false;
	}
}

void Game::Draw( ) const
{
	ClearBackground( );
	
	DrawCards();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	switch ( e.keysym.sym )
	{
	
	case SDLK_PLUS:
		AddElement();
		break;
	case SDLK_MINUS:
		RemoveElement();
		break;
	case SDLK_UP:
		IncremElement();
		break;
	case SDLK_DOWN:
		DecElement();
		break;
	case SDLK_s:
		m_Shuffle = true;
		break;
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

// Add element at the end of the vector
void Game::AddElement()
{
	int value{ rand() % 31 };

	m_VectorInts.push_back(value);

	PrintElements();
	
}

// Remove an element from the end of the vector
void Game::RemoveElement()
{

	m_VectorInts.pop_back();

	PrintElements();

}

void Game::PrintElements()
{
	/*
	for (int i{ 0 }; i < m_VectorInts.size(); i++)
	{
		std::cout << m_VectorInts[i] << " ";
	}

	*/

	// Ranged based for loop
	for (int value : m_VectorInts)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;

}

void Game::IncremElement()
{
/*
	for (int i{ 0 }; i < m_VectorInts.size(); i++)
	{
		m_VectorInts[i]++;
	}
	*/

	// If we dont put & it wont modify the elements because we work with copies
	for (int& value : m_VectorInts)
	{
		value++;
	}

	PrintElements();

}

void Game::DecElement()
{

	for (int i{ 0 }; i < m_VectorInts.size(); i++)
	{
		m_VectorInts[i]--;
	}

	PrintElements();
}

void Game::AddCards()
{
	int totalRows{ 4 };			// 4 diferent suits
	int totalCols{ 13 };		// 13 ranks

	Card::Suit suit{ 1 };

	for (int i{ 1 }; i <= totalRows; i++)
	{
		suit = Card::Suit(i);
		for (int j{ 1 }; j <= totalCols; j++)
		{
			m_Cards.push_back(new Card(suit, j));
		}
	}

}

void Game::DrawCards() const
{
	Rectf destRect{};
	const int nrCols{ 13 }, nrRows{ 4 };
	int rowIdx{  }, idx{}, colIdx{  };

	// Size of each of the cards according with the size of the window
	float width{ m_Window.width / nrCols };
	float height{ m_Window.height / nrRows };


	// 2D loop 
	for (rowIdx = 0; rowIdx < nrRows; rowIdx++)
	{
		for (colIdx = 0; colIdx < nrCols; colIdx++)
		{
			idx = GetIndex(rowIdx, colIdx, nrCols);

			destRect.height = height;
			destRect.width = width;

			// Position for each card
			destRect.left = (destRect.width/2 * colIdx);
			destRect.bottom = destRect.height * rowIdx;

			m_Cards[idx]->Draw(destRect);

		}
	}


}

// Get the index of the 2D vector
int Game::GetIndex(int rowIdx, int colIdx, int nrCols) const
{
	int idx{};

	idx = rowIdx * nrCols + colIdx;

	return idx;
}

void Game::Shuffle(std::vector<Card*> vector, const int size, const int swaps)
{
	int idx1{}, idx2{};

	// Swap values the number of times determined by swaps
	for (int i{}; i < swaps; i++)
	{
		do {

			idx1 = RandomNumber(size);
			idx2 = RandomNumber(size);
			//std::cout << "First random number " << idx1 << std::endl;
			//std::cout << "Second random number " << idx2 << std::endl;
			// Keep generating random numbers until we get two different ones
		} while (idx1 == idx2);

		Swap(vector, size, idx1, idx2);
	}

}


// Swap two elements from the vector
void Game::Swap(std::vector<Card*> vector, const int size, const int idx1, const int idx2)
{
	// Check if the indexs are inside the limits of the array
	if (idx1 < 0 || idx1 >= size)
	{
		std::cout << idx1 << " is out of the limits of the array." << std::endl;

		return;
	}

	if (idx2 < 0 || idx2 >= size)
	{
		std::cout << idx2 << " is out of the limits of the array." << std::endl;

		return;
	}

	 

	// Save the element from the array
	Card* saveElement = vector[idx1];
	vector[idx1] = vector[idx2];
	vector[idx2] = saveElement;
}

// Generate a random number within the limits of the array
int Game::RandomNumber(const int size)
{
	int random{};

	random = rand() % size;  // Random between 0 and the size - 1

	return random;
}
