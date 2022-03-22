#pragma once
#include "utils.h"

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
	static const int m_NrVertices{ 4 };
	std::vector<Point2f> m_Vertices;
	const float m_Width;
	const float m_Height;
	float m_Angle;
	float m_Scale;
	Point2f m_Translation;
	Point2f m_Mouse;
	bool m_Clicked;
	std::vector<Point2f> transformedVerts;

	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;
	void DrawPolyOpenGl() const;
	void DrawPolyMatrix2x3() const;
};