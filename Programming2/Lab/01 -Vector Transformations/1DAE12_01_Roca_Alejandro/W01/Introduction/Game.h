#pragma once

class Ball;
class Texture;

struct Sprite
{
	Texture* texture;
	int frames;
	int cols;
	float frameTime;
	int currentFrame;
	float accumulatedTime;
	Point2f pos;
};

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
	static const int m_NrBalls{ 2 };		
	Ball* m_pBallArray[m_NrBalls]{};		// Nullpointer initiliazed array of two ball class
	Texture* m_pDAEImage{};
	Texture* m_pText{};
	Sprite m_Knight;
	float m_Angle{};

	// FUNCTIONS
	void Initialize( );
	void LoadResources();
	void Cleanup( );
	void ClearBackground( ) const;
	void DrawKnight() const;
	void MoveKnight(float elapsedSec);
	void VectorTest();
};