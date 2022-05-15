#pragma once


class Sprite;
class SoundManager;
class SoundEffect;
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
	void Update(float elapsedSec);

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
	Sprite* m_pLifes;
	Sprite* m_pLevel;
	Sprite* m_pPrisoners;
	Sprite* m_pGo;
	
	// Sounds
	SoundManager* m_pSoundManager;

	// PRIVATE FUNCTIONS
	void Initialize();
	void DrawPrisoners() const;

};

