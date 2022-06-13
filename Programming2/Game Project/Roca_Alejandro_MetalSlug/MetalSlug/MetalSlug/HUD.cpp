#include "pch.h"
#include "HUD.h"
#include "Sprite.h"
#include "SoundManager.h"
#include "SoundEffect.h"
#include <iostream>

HUD::HUD(const Point2f& bottomLeft, const Point2f& windowSize, SoundManager* sounds, int totalPrisoners)
	:m_pWeapons{ new Sprite ("Resources/sprites/HUD/weapons.png") }
	, m_pPlayer{ new Sprite("Resources/sprites/HUD/lifes.png") }
	, m_pLevel{ new Sprite("Resources/sprites/HUD/level.png") }
	, m_pGo( new Sprite("Resources/sprites/HUD/GO.png") )
	, m_pNrLifes ( new Sprite("Resources/sprites/HUD/LifesCount.png") ) 
	, m_pPrisoners{ }
	, m_pSystemPoint { }
	, m_BottomLeft { bottomLeft }
	, m_WindowSize{ windowSize }
	, m_TopBorder { 35.f }
	, m_BottomBorder { 25.f }
	, m_LeftBorder { 45.f }
	, m_TotalPrisoners{ totalPrisoners }
	, m_Xpos { }
	, m_GoAnimation { false }
	, m_MaxTimeGoAnimat { 4.f }
	, m_TimeGoAnimat{ }
	, m_pSoundManager { sounds }
	, m_pGoSound{ sounds->GetEffect("Resources/sounds/GoSound.mp3") }
	, m_pTimer{}
	, m_TimerSeconds{ }
	, m_StartTime { 60 }
	, m_TimeLeft { m_StartTime }
	, m_TimeOver { false }
{

	Initialize();
	
}


HUD::~HUD()
{
	delete m_pWeapons;
	delete m_pPlayer;
	delete m_pLevel;
	delete m_pGo;
	delete m_pNrLifes;
	
	for (Sprite* spr : m_pSystemPoint)
	{
		delete spr;
	}

	for (Sprite* spr : m_pPrisoners)
	{
		delete spr;
	}

	for (Sprite* spr : m_pTimer)
	{
		delete spr;
	}
}


void HUD::Initialize()
{
	
	// Player Status
	m_pPlayer->UpdateValues(1, 1, 1, 1.f, m_pPlayer->GetTexture()->GetWidth(), m_pPlayer->GetTexture()->GetHeight(), m_pPlayer->GetTexture()->GetHeight());
	m_pPlayer->SetLeftDstRect(m_BottomLeft.x + m_LeftBorder);
	m_pPlayer->SetBottomDstRect(m_WindowSize.y - (m_pPlayer->GetTexture()->GetHeight() * g_Scale) - m_TopBorder);

	// POINT SYSTEM
	InitSystemPoint();
		
	// Nr of Lifes
	m_pNrLifes->UpdateValues(2, 1, 2, 1.f, 8.f, m_pNrLifes->GetTexture()->GetHeight(), m_pNrLifes->GetTexture()->GetHeight());
	m_pNrLifes->SetLeftDstRect( ( m_BottomLeft.x + m_LeftBorder + ( m_pPlayer->GetFrameWidth() * g_Scale) ) - m_pNrLifes->GetFrameWidth() * 1.8f * g_Scale  );
	m_pNrLifes->SetBottomDstRect( m_WindowSize.y - (m_pPlayer->GetTexture()->GetHeight() * g_Scale) - m_TopBorder + 2.f );

	// Weapons HUD
	m_pWeapons->UpdateValues(1, 1, 1, 1.f, m_pWeapons->GetTexture()->GetWidth(), m_pWeapons->GetTexture()->GetHeight(), m_pWeapons->GetTexture()->GetHeight());
	m_pWeapons->SetLeftDstRect( m_pPlayer->GetDstRect().left + m_pPlayer->GetDstRect().width );
	m_pWeapons->SetBottomDstRect(m_WindowSize.y - ( m_pWeapons->GetTexture()->GetHeight()/1.5f * g_Scale ) - m_TopBorder);

	// LEVEL INDICATOR
	m_pLevel->UpdateValues(1, 1, 1, 1.f, m_pLevel->GetTexture()->GetWidth(), m_pLevel->GetTexture()->GetHeight(), m_pLevel->GetTexture()->GetHeight());
	m_pLevel->SetLeftDstRect( ( m_WindowSize.y / 2.f ) + (m_pLevel->GetTexture()->GetWidth() / 2.f ) * g_Scale);
	m_pLevel->SetBottomDstRect(m_BottomLeft.y);

	// GO Text
	m_pGo->UpdateValues(9, 1, 9, 9.f, 33.8f, m_pGo->GetTexture()->GetHeight(), m_pGo->GetTexture()->GetHeight());
	m_pGo->SetLeftDstRect(m_BottomLeft.x + m_WindowSize.x - ( m_pGo->GetFrameWidth() * 2) * g_Scale );
	m_pGo->SetBottomDstRect(m_BottomLeft.y + m_WindowSize.y - m_TopBorder * 6);


	// Timer
	m_pTimer.push_back(new Sprite("Resources/sprites/HUD/timeNrs.png"));
	m_pTimer.push_back(new Sprite("Resources/sprites/HUD/timeNrs.png"));
	float xPos{ m_WindowSize.x / 2.f - (m_pTimer.at(0)->GetTexture()->GetWidth() / 10.f) };
	float separation{ (m_pTimer.at(0)->GetTexture()->GetWidth() / 10.f) * g_Scale };

	for (Sprite* spr : m_pTimer)
	{
		spr->UpdateValues(10, 1, 10, 9.f, spr->GetTexture()->GetWidth() / 10, spr->GetTexture()->GetHeight(), spr->GetTexture()->GetHeight());
		spr->SetLeftDstRect(xPos);
		spr->SetBottomDstRect(m_pWeapons->GetDstRect().bottom );
		
		xPos += separation;
	}

	int tens{ m_TimeLeft / 10 };
	int units{ m_TimeLeft % 10 };

	m_pTimer.at(0)->ChangeFrame(tens);
	m_pTimer.at(1)->ChangeFrame(units);

}

// Set up the Point system
void HUD::InitSystemPoint()
{
	m_pSystemPoint.push_back( new Sprite("Resources/sprites/HUD/Points.png") );  // Units
	m_pSystemPoint.push_back( new Sprite("Resources/sprites/HUD/Points.png") );  // Tens
	m_pSystemPoint.push_back( new Sprite("Resources/sprites/HUD/Points.png") );  // Hundreds
	m_pSystemPoint.push_back( new Sprite("Resources/sprites/HUD/Points.png") ); // Thousands
	m_pSystemPoint.push_back(new Sprite("Resources/sprites/HUD/Points.png")); // Ten Thousands

	float separation{ ( m_pSystemPoint[0]->GetTexture()->GetWidth() / 10) * 2.3f};
	float xPos{ m_BottomLeft.x + (m_pPlayer->GetTexture()->GetWidth() * g_Scale) + separation };

	for (Sprite* spr : m_pSystemPoint)
	{
		spr->UpdateValues(1, 1, 1, 9.f, 9.4f, spr->GetTexture()->GetHeight(), spr->GetTexture()->GetHeight());
		spr->SetLeftDstRect( xPos );
		spr->SetBottomDstRect(m_pPlayer->GetDstRect().bottom + (m_pPlayer->GetTexture()->GetHeight() * g_Scale) - spr->GetTexture()->GetHeight());
	
		xPos -= separation;
	}
	
}

void HUD::Draw() const
{
	m_pWeapons->Draw();
	m_pPlayer->Draw();
	m_pLevel->Draw();
	m_pNrLifes->Draw();

	if (m_GoAnimation)
	{
		m_pGo->Draw();
	}
	
	DrawPrisoners();
	DrawSystemPoint();

	for (Sprite* spr : m_pTimer)
	{
		spr->Draw();
	}
	
}

void HUD::DrawSystemPoint() const
{
	for (const Sprite* spr : m_pSystemPoint)
	{
		spr->Draw();
	}
}

void HUD::DrawPrisoners() const
{
	for (Sprite* spr : m_pPrisoners)
	{
		spr->Draw();
	}

}

void HUD::Update(float elapsedSec, const int nrLifes, unsigned int totalPoints, unsigned int totalPrisoners)
{

	UpdatePrisoners(totalPrisoners);
	UpdateGoText(elapsedSec);
	m_pNrLifes->ChangeFrame(nrLifes);
	UpdateSystemPoints(elapsedSec, totalPoints);

	UpdateTimer(elapsedSec);

	
}

void HUD::UpdatePrisoners(unsigned int totalPrisoners)
{

	if (totalPrisoners != m_TotalPrisoners)
	{
		// A prisoner was released --> Update the HUD
		m_TotalPrisoners--;

		Sprite* prisoner{ new Sprite("Resources/sprites/HUD/prisoner.png") };
		prisoner->UpdateValues(1, 1, 1, 1.f, prisoner->GetTexture()->GetWidth(), prisoner->GetTexture()->GetHeight(), prisoner->GetTexture()->GetHeight());
		m_Xpos += prisoner->GetFrameWidth() * g_Scale;
		prisoner->SetLeftDstRect(m_Xpos);
		prisoner->SetBottomDstRect(m_BottomLeft.y + m_BottomBorder);
		m_pPrisoners.push_back(prisoner);
	}
}

void HUD::ActivateGoTextAnimation()
{
	m_GoAnimation = true;

}

// Do the animation for the Go Texture
void HUD::UpdateGoText(float elapsedSec)
{
	if (m_GoAnimation)
	{
		m_pGo->Update(elapsedSec, true);

		if (m_TimeGoAnimat <= m_MaxTimeGoAnimat)
		{
			m_TimeGoAnimat += elapsedSec;
		}
		else
		{
			m_TimeGoAnimat = 0;
			m_GoAnimation = false;
		}
	}
}

void HUD::UpdateSystemPoints(float elapsedSec, unsigned int totalPoints)
{
	for (int i{}; i < m_pSystemPoint.size(); i++)
	{
		if (i == m_pSystemPoint.size() - 1)
		{
			// Last element
			m_pSystemPoint[i]->ChangeFrame(totalPoints / 10);
		}
		else
		{
			if (i != 0)
			{
				// Not first element
				totalPoints /= 10;
			}
			m_pSystemPoint[i]->ChangeFrame(totalPoints % 10);
		}
	}
	
}

void HUD::UpdateTimer(float elapsedSec)
{
	m_TimerSeconds += elapsedSec;

	if (m_TimerSeconds > 4.f)  // Every 4 seconds we decrement one 
	{
		m_TimerSeconds = 0.f;
		m_TimeLeft--;

		if (m_TimeLeft == 0)
		{
			m_TimeOver = true;
		}

		int tens{ m_TimeLeft / 10 };
		int units{ m_TimeLeft % 10 };

		m_pTimer.at(0)->ChangeFrame(tens);
		m_pTimer.at(1)->ChangeFrame(units);
		m_pTimer.at(0)->UpdateLeftSrcRect();
		m_pTimer.at(1)->UpdateLeftSrcRect();
	}
}

bool HUD::GetTimeOver() const
{
	return m_TimeOver;
}