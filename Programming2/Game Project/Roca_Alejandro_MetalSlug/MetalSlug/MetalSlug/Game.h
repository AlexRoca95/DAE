#pragma once
#include <vector>
#include "Level.h"
#include "Camera.h"


class GameObject;
class Avatar;
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

	// All Objects from the game
	std::vector <GameObject*> m_pGameObjects;

	// Level
	Level m_Level;
	
	Avatar* m_Avatar;

	Camera m_Camera;
	// FUNCTIONS

	void Initialize( );
	void InitAvatar();
	void InitCamera();

	void Cleanup( );
	void ClearBackground( ) const;
};