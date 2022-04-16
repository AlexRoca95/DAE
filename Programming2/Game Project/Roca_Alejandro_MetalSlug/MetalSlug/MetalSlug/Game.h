#pragma once
#include "Level.h"
#include "Camera.h"



class GameObject;
class Avatar;
class Enemy;
class Soldier;
class GameObjectManager;
class Game final
{
public:

	enum class GameState {
		start,
		firstHeliFight,
		secondHeliFight,
		bossFight
	};

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

	// All GameObjects from the game
	std::vector <GameObject*> m_pGameObjects;

	GameState m_GameState;

	// Level
	Level* m_Level;
	Avatar* m_Avatar;
	Camera* m_Camera;

	// Enemies
	const int m_NrHelicopters;
	GameObjectManager* m_pGameObjectManager;

	// FUNCTIONS

	void Initialize( );
	void InitAvatar();
	void InitCamera();
	void AddGameObjects();

	void Cleanup( );
	void ClearBackground( ) const;
};