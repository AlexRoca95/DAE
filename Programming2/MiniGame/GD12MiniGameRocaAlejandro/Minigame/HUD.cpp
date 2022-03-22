#include "pch.h"
#include "HUD.h"
#include "Texture.h"


HUD::HUD(const Point2f& topLeft, int totalPowerUps)
	:m_TotalPowerUps{totalPowerUps},
	m_pPowerUpTexture{new Texture{"resources/images/HudPowerUp.png"}},
	m_pRightTexture{ new Texture{"resources/images/HudRight.png"} },
	m_pLeftTexture{ new Texture{"resources/images/HudLeft.png"} },
	m_HitPowerUps{ 0 },
	m_BottomLeft{topLeft},
	m_Separation{20.f},
	m_RectPowerUpEmpty{28.f, 32.f, 28.f, 32.f},
	m_RectPowerUp{0.f, 32.f, 28.f, 32.f},
	m_DstRect{}
{

}


HUD::~HUD()
{
	delete m_pPowerUpTexture;
	delete m_pLeftTexture;
	delete m_pRightTexture;
}


void HUD::Draw() const
{
	float leftPos{ m_BottomLeft.x };

	m_pLeftTexture->Draw(m_BottomLeft);

	int i{};
	DrawPowerUpHit(i, leftPos);
	DrawPowerUpEmpty(i, leftPos);

	m_pRightTexture->Draw(Point2f{ leftPos, m_BottomLeft.y });

}

// Draw the textures of powerUpHit
void HUD::DrawPowerUpHit(int& idx, float& leftPos) const
{
	for (idx; idx < m_HitPowerUps; idx++)
	{
		if (idx == 0)
		{
			leftPos += m_pLeftTexture->GetWidth();
			m_pPowerUpTexture->Draw(Point2f{ leftPos, m_BottomLeft.y }, m_RectPowerUp);
		}
		else
		{
			m_pPowerUpTexture->Draw(Point2f{ leftPos, m_BottomLeft.y }, m_RectPowerUp);
		}

		leftPos += m_pPowerUpTexture->GetWidth() / 2;
	}
}

// Draw the empty powerUp texture
void HUD::DrawPowerUpEmpty(int& idx, float& leftPos) const
{
	for (idx; idx < m_TotalPowerUps; idx++)
	{
		if (idx == 0)
		{
			leftPos += m_pLeftTexture->GetWidth();
			m_pPowerUpTexture->Draw(Point2f{ leftPos, m_BottomLeft.y }, m_RectPowerUpEmpty);
		}
		else
		{
			m_pPowerUpTexture->Draw(Point2f{ leftPos, m_BottomLeft.y }, m_RectPowerUpEmpty);
		}

		leftPos += m_pPowerUpTexture->GetWidth() / 2;
	}
}

// Update the position of the HUD so it goes with the camera pos
void HUD::UpdatePos(const Point2f& newPos, const float windowHeight)
{
	m_BottomLeft.x = newPos.x + m_Separation;
	m_BottomLeft.y = newPos.y + windowHeight - m_pLeftTexture->GetHeight() - m_Separation;
}

void HUD::PowerUpHit()
{
	m_HitPowerUps++;
}