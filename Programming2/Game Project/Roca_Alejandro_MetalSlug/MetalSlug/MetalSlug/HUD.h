#pragma once


class Sprite;
class HUD
{
public:


	HUD(const Point2f& bottomLeft);
	~HUD();
	HUD(const HUD& hud) = delete;
	HUD(HUD&& hud) = delete;
	HUD& operator=(const HUD& hud) = delete;
	HUD& operator=(HUD&& hud) = delete;


	void Draw() const;
	void Update(float elapsedSec, Point2f& cameraPos);

private:

	Point2f m_BottomLeft;    // Position of the bottom Left of the window

	Sprite* m_pWeapons;


	// PRIVATE FUNCTIONS
	void Initialize();

};

