#pragma once
#include "Texture.h"
class Game
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=( Game&& other) = delete;
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
	// General properties
	const Window m_Window;

	// Sprite properties
	const Texture m_Texture;
	const float m_SpriteSheetLeft;
	const float m_SpriteSheetTop;
	const float m_SpriteSheetWidth;
	const float m_SpriteSheetHeight;
	const int m_Cols;
	const int m_Rows;
	int m_FramesPerSec;
	float m_FrameTime;
	float m_Scale;

	// Sprite related data members
	float m_AccuSec;
	int m_CurFrame;
	Rectf m_SrcRect;
	Rectf m_DestRect;
	Color4f m_BgColor;
	bool m_ShowInfo;

	// General functions
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;
	
	// Sprite related functions
	void UpdateSprite( float elapsedSec );
	void DrawSprite( ) const;
	void ChangeScale( bool zoomIn, float elapsedSec );
	void ChangeFrameRate( bool lower );
	void InitDestinationRect( );
	void InitSourceRect( );
	void UpdateSourceRect( );
	void ShowInfo( )const;
};