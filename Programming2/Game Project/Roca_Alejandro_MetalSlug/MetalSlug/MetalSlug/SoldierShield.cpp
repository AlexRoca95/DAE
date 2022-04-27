#include "pch.h"
#include "SoldierShield.h"
#include "Shield.h"
#include "Level.h"



SoldierShield::SoldierShield(const Point2f& startPos, bool comingFromRight)
	:Enemy(GameObject::Type::soldierShield, startPos, 5, Point2f{ 150.f, 0.f },
		comingFromRight, Point2f{ 0.f, g_Gravity })   // Type, starting position, health, speed and accelerat
	, m_IsShieldOn { true }
	, m_IsFacingRight { false }
	, m_pShield {}
	, m_MaxTimeDeath{ 2.f }
	, m_SecondsDeath{ 0.f }
	, m_RunSpeed { 250.f }
{


	Initialize();

}


SoldierShield::~SoldierShield()
{
	delete m_pBottomSprite;

	if (m_pShield!= nullptr)
	{
		delete m_pShield;
	}
}



void SoldierShield::Initialize()
{
	
	m_pBottomSprite = new Sprite("Resources/sprites/enemies/soldierShield.png");
	m_pBottomSprite->UpdateValues(12, 1, 12, 15.f, 35.f, 41.f, 100.f); // Soldier with shield running
	//m_pBottomSprite->UpdateValues(6, 1, 6, 8.f, 34.6f, 40.f, 40.f); // Soldier with shield Iddle
	m_pBottomSprite->SetLeftDstRect(m_StartPosition.x);
	m_pBottomSprite->SetBottomDstRect(m_StartPosition.y);
	m_pBottomSprite->UpdateLeftSrcRect();


	//m_pBottomSprite->UpdateValues(12, 1, 12, 15.f, 35.f, 41.f, 100.f); // Soldier with shield running

	//m_pBottomSprite->UpdateValues(8, 1, 8, 10.f, 34.f, 38.f, 38.f);  // Flying shield
	//m_pBottomSprite->UpdateValues(16, 1, 16, 15.f, 54.f, 48.f, 156.f); // Soldier with shield atacking
	//m_pBottomSprite->UpdateValues(9, 1, 9, 10.f, 54.f, 48.f, 204.f); // Soldier with shield atacking back


}
void SoldierShield::Draw() const
{
	if (!m_IsShieldOn)
	{
		// Draw shield flying away
		m_pShield->Draw();
	}


	m_pBottomSprite->Draw();

}


void SoldierShield::Update(float elapsedSec, Avatar* avatar, const Level* level)
{

	if (!m_IsDying)
	{
	
		// Soldier is not dying
		m_pBottomSprite->Update(elapsedSec, true);
		
		if (m_IsShieldOn)
		{
			m_Velocity.x = - m_RunSpeed;
		}
	}
	else
	{
		// Soldier is dead
		KillSoldier(elapsedSec);
	}


	if (!m_IsShieldOn)
	{
		// Shield flying away
		m_pShield->Update(elapsedSec, level);
	}
	
	Falling(elapsedSec, level);
	Move(elapsedSec);
	level->HandleCollision(m_pBottomSprite->GetDstRect(), m_Velocity);
	
}

void SoldierShield::Move(float elapsedSec)
{
	m_pBottomSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left + m_Velocity.x * elapsedSec);
	m_pBottomSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_Velocity.y * elapsedSec);
}

void SoldierShield::Hit()
{
	m_Health--;

	if (m_Health == 0)
	{
		m_Velocity.x = 0.f;

		if (m_IsShieldOn)
		{
			// Soldier looses his shield
			m_pBottomSprite->UpdateValues(6, 1, 6, 8.f, 34.f, 40.f, 277.f);  
			m_pBottomSprite->ResetSprite();
			InitShield();

			m_Health = 1;   // Soldier life
		}
		else
		{
			// Soldier is dead 
			m_IsDying = true;

			m_pBottomSprite->UpdateValues(11, 1, 11, 8.f, 60.f, 44.f, 392.f);  // Change death animation
			m_pBottomSprite->ResetSprite();
			
		}


		
	
	}

}


void SoldierShield::KillSoldier(float elapsedSec)
{
	m_pBottomSprite->Update(elapsedSec, false);

	if (m_pBottomSprite->GetAnimationFinish())
	{
		m_SecondsDeath += elapsedSec;

		if (m_SecondsDeath >= m_MaxTimeDeath)
		{
			m_IsDead = true;
			m_pBottomSprite->ResetSprite();
			m_IsActive = false;
			m_SecondsDeath = 0.f;
		}
	}
}


// Create a flying shield and place it in the correct pos
void SoldierShield::InitShield()
{

	float xPos{};

	if (m_IsFacingRight)
	{

		xPos = m_pBottomSprite->GetDstRect().left + m_pBottomSprite->GetDstRect().width / 2;
	}
	else
	{
		xPos = m_pBottomSprite->GetDstRect().left - m_pBottomSprite->GetDstRect().width / 2;
	}

	Point2f startPos{ xPos, m_pBottomSprite->GetDstRect().bottom };
	m_pShield = new Shield(startPos);

	// Soldier doesn't have the shield anymore
	m_IsShieldOn = false;
}


void SoldierShield::CheckGameState()
{

}
