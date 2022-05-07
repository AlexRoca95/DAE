#include "pch.h"
#include "HUD.h"
#include "Texture.h"
#include "Sprite.h"

HUD::HUD(const Point2f& bottomLeft)
	:m_pWeapons(new Sprite("Resources/sprites/HUD/weapons.png"))
	, m_BottomLeft { bottomLeft }
{

	Initialize();

}


HUD::~HUD()
{
	delete m_pWeapons;
}


void HUD::Initialize()
{
	// Weapons HUD
	m_pWeapons->UpdateValues(1, 1, 1, 1.f, m_pWeapons->GetTexture()->GetWidth(), m_pWeapons->GetTexture()->GetHeight(), m_pWeapons->GetTexture()->GetHeight());
	m_pWeapons->SetLeftDstRect(m_BottomLeft.x);
	m_pWeapons->SetBottomDstRect(m_BottomLeft.y);


}

void HUD::Draw() const
{
	m_pWeapons->Draw();
}


void HUD::Update(float elapsedSec, Point2f& cameraPos)
{

	m_pWeapons->SetLeftDstRect(cameraPos.x);
	//m_BottomLeft.y = cameraPos.y;
}