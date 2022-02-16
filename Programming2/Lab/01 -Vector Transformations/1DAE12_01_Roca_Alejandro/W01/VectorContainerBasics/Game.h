#pragma once
#include <vector>

class Card;

class Game final
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	~Game();

	void Update( float elapsedSec );
	void Draw( ) const;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e );
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e );
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e );
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e );
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e );

private:
	// DATA MEMBERS
	const Window m_Window;
	std::vector<int> m_VectorInts{};
	std::vector<Card*> m_Cards{};
	bool m_Shuffle;

	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;
	void AddElement();
	void RemoveElement();
	void PrintElements();
	void IncremElement();
	void DecElement();
	void AddCards();
	void DrawCards() const;
	int GetIndex(int rowIdx, int colIdx, int nrCols) const;
	void Shuffle(std::vector<Card*> vector, const int size, const int swaps);
	void Swap(std::vector<Card*> vector, const int size, const int idx1, const int idx2);
	int RandomNumber(const int size);
};