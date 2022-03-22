#pragma once

class Texture;
class HUD
{
public:
	HUD(const Point2f& topLeft, int totalPowerUps);
	HUD(const HUD& hud) = delete;
	HUD& operator=(const HUD& hud) = delete;
	~HUD();
	void Draw() const;
	void DrawPowerUpHit(int& idx, float& leftPos) const;
	void DrawPowerUpEmpty(int& idx, float& leftPos) const;
	void UpdatePos(const Point2f& newPos, const float windowHeight);
	void PowerUpHit();

private:
	Point2f m_BottomLeft;
	int m_TotalPowerUps;
	int m_HitPowerUps;
	const float m_Separation;
	Rectf m_RectPowerUpEmpty;
	Rectf m_RectPowerUp;
	Rectf m_DstRect;

	const Texture* m_pLeftTexture;
	const Texture* m_pRightTexture;
	const Texture* m_pPowerUpTexture;


};

