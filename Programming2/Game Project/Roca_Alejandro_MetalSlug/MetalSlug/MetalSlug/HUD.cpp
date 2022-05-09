#include "pch.h"
#include "HUD.h"
#include "Sprite.h"
#include <iostream>

HUD::HUD(const Point2f& bottomLeft, const Point2f& windowSize)
	:m_pWeapons( new Sprite("Resources/sprites/HUD/weapons.png") )
	, m_pLifes( new Sprite("Resources/sprites/HUD/lifes.png") )
	, m_pLevel( new Sprite("Resources/sprites/HUD/level.png") )
	, m_pPrisoners( new Sprite("Resources/sprites/HUD/prisoner.png") )
	, m_BottomLeft { bottomLeft }
	, m_WindowSize{ windowSize }
	, m_TopBorder { 35.f }
	, m_BottomBorder { 25.f }
	, m_LeftBorder { 45.f }
	, m_PrisonersReleased { }
{

	Initialize();

}


HUD::~HUD()
{
	delete m_pWeapons;
	delete m_pLifes;
	delete m_pLevel;
	delete m_pPrisoners;
}


void HUD::Initialize()
{
	// LIFES
	m_pLifes->UpdateValues(1, 1, 1, 1.f, m_pLifes->GetTexture()->GetWidth(), m_pLifes->GetTexture()->GetHeight(), m_pLifes->GetTexture()->GetHeight());
	m_pLifes->SetLeftDstRect(m_BottomLeft.x + m_LeftBorder);
	m_pLifes->SetBottomDstRect(m_WindowSize.y - (m_pLifes->GetTexture()->GetHeight() * g_Scale) - m_TopBorder);

	// Weapons HUD
	m_pWeapons->UpdateValues(1, 1, 1, 1.f, m_pWeapons->GetTexture()->GetWidth(), m_pWeapons->GetTexture()->GetHeight(), m_pWeapons->GetTexture()->GetHeight());
	m_pWeapons->SetLeftDstRect( m_pLifes->GetDstRect().left + m_pLifes->GetDstRect().width );
	m_pWeapons->SetBottomDstRect(m_WindowSize.y - ( m_pWeapons->GetTexture()->GetHeight()/1.5f * g_Scale ) - m_TopBorder);


	// LEVEL INDICATOR
	m_pLevel->UpdateValues(1, 1, 1, 1.f, m_pLevel->GetTexture()->GetWidth(), m_pLevel->GetTexture()->GetHeight(), m_pLevel->GetTexture()->GetHeight());
	m_pLevel->SetLeftDstRect( ( m_WindowSize.y / 2.f ) + (m_pLevel->GetTexture()->GetWidth() / 2.f ) * g_Scale);
	m_pLevel->SetBottomDstRect(m_BottomLeft.y);

	// Prisoners released
	m_pPrisoners->UpdateValues(1, 1, 1, 1.f, m_pPrisoners->GetTexture()->GetWidth(), m_pPrisoners->GetTexture()->GetHeight(), m_pPrisoners->GetTexture()->GetHeight());
	m_pPrisoners->SetLeftDstRect(m_BottomLeft.x + m_LeftBorder);
	m_pPrisoners->SetBottomDstRect(m_BottomLeft.y + m_BottomBorder );
	
}

void HUD::Draw() const
{
	m_pWeapons->Draw();
	m_pLifes->Draw();
	m_pLevel->Draw();

	DrawPrisoners();
	
	
}

void HUD::DrawPrisoners() const
{
	for (int i{}; i < m_PrisonersReleased; i++)
	{
		m_pPrisoners->Draw();
	}
}

void HUD::Update(float elapsedSec)
{

	//m_pWeapons->SetLeftDstRect(cameraPos.x);
	//m_BottomLeft.y = cameraPos.y;
}