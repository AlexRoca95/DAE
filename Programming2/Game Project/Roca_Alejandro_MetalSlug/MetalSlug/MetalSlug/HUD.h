#pragma once
#include <vector>

class Sprite;
class SoundManager;
class SoundEffect;
class Texture;
class HUD
{
public:


	HUD(const Point2f& bottomLeft, const Point2f& windowSize, SoundManager* sounds);
	~HUD();
	HUD(const HUD& hud) = delete;
	HUD(HUD&& hud) = delete;
	HUD& operator=(const HUD& hud) = delete;
	HUD& operator=(HUD&& hud) = delete;


	void Draw() const;
	void Update(float elapsedSec, const int nrLifes, unsigned int totalPoints);

	void ActivateGoTextAnimation();

private:

	const Point2f m_BottomLeft;    // Position of the bottom Left of the window
	const Point2f m_WindowSize;

	const float m_TopBorder;
	const float m_LeftBorder;
	const float m_BottomBorder;


	int m_PrisonersReleased;

	// GO Text animation
	bool m_GoAnimation;
	float m_MaxTimeGoAnimat;
	float m_TimeGoAnimat;
	SoundEffect* m_pGoSound;

	// SPRITES FOR THE HUD
	Sprite* m_pWeapons;
	Sprite* m_pPlayer;
	Sprite* m_pLevel;
	Sprite* m_pPrisoners;
	Sprite* m_pGo;
	Sprite* m_pNrLifes;

	Texture* m_ContinueFont;

	// Points system
	std::vector<Sprite*> m_SystemPoint;

	int m_UnitValue;
	int m_TenValue;
	int m_HundredValue;
	int m_ThousandValue;

	// Sounds
	SoundManager* m_pSoundManager;

	// PRIVATE FUNCTIONS
	void Initialize();
	void InitSystemPoint();
	void DrawPrisoners() const;
	void DrawSystemPoint() const;

	void UpdateGoText(float elapsedSec);
	void UpdateSystemPoints(float elapsedSec, unsigned int totalPoints);

};

