#pragma once
#include "Level.h"
#include "Camera.h"
#include "SoundEffect.h"
#include "SoundStream.h"


class GameObject;
class Avatar;
class Enemy;
class Soldier;
class GameObjectManager;
class SoundManager;
class Boss;
class HUD;
class Menu;
class Game final
{
public:

	enum class GameState {
		menu,
		playing,
		gameOver
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

	GameState m_GameState;			// State of the Game

	// GAME Pointers
	Menu* m_pMenu;
	Level* m_pLevel;
	HUD* m_pHUD;
	Avatar* m_pAvatar;
	Camera* m_pCamera;

	// Sounds && Effects
	SoundManager* m_pSoundManager;
	SoundStream* m_pMenuSong;
	SoundStream* m_pLevelSong;
	SoundEffect* m_pPistolFire;				// Shoot pistol effect
	SoundEffect* m_pMissionStartSound;

	// GameObjects
	GameObjectManager* m_pGameObjectManager;

	
	// FUNCTIONS

	// Init Data 
	void InitMenu();
	void Initialize( );
	void InitAvatar();
	void InitCamera();
	void InitHUD();
	void InitLevelSounds();
	void AddGameObjects();

	// PLAYING GAME STATE
	void DrawPlaying() const;
	void UpdatePlaying(float elapsedSec);

	void DisplayControlsInfo();				// Display info about the controls of the game

	void Cleanup( );
	void ClearBackground( ) const;
};