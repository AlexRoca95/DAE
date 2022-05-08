#pragma once
#include "Game.h"

class Sprite;
class Menu
{
public:


	Menu(const Point2f& windowSize);
	~Menu();
	Menu(const Menu& menu) = delete;
	Menu(Menu&& menu) = delete;
	Menu& operator=(const Menu& menu) = delete;
	Menu& operator=(Menu&& menu) = delete;


	void Draw() const;
	void Update(float elapsedSec, Game::GameState& gameState);

	void SetPlaying(bool start);	
	bool GetStartPlaying() const;

private:

	// Sprites for the menu
	Sprite* m_pStartScreen;
	Sprite* m_pPushStart;

	const Point2f m_StartLettersPos;

	const float m_FlickeringMaxTime;
	float m_FlickeringSec;

	bool m_StartPlaying;
	bool m_DrawLetters;

	void Initialize();
	void UpdateFlicker(float elapsedSec);
};

