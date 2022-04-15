#include "pch.h"
#include "Grenade.h"
#include "Soldier.h"
#include <iostream>



Grenade::Grenade()
	:Projectile(GameObject::Type::grenade, 400.f)
	, m_Angle { }
{
	Initialize();
	
}


Grenade::~Grenade()
{
	delete m_pBottomSprite;
	delete m_pTopSprite;
}


void Grenade::Initialize()
{
	m_Position.x = 1200.f * g_Scale;
	m_Position.y = 300.f;


	// Grenade sprite
	m_pTopSprite = new Sprite("Resources/sprites/enemies/grenade.png");
	m_pTopSprite->UpdateValues(1, 1, 1, 15.f, 19.f, 32.f, 32.f, 1.5f);
	m_pTopSprite->SetLeftDstRect(m_Position.x);
	m_pTopSprite->SetBottomDstRect(m_Position.y);
	m_pTopSprite->UpdateLeftSrcRect();

	// Explosion sprite
	m_pBottomSprite = new Sprite("Resources/sprites/enemies/Explosion.png");
	m_pBottomSprite->UpdateValues(5, 1, 5, 15.f, 35.2f, 64.f, 64.f, 2.7f);

	m_IsActive = true;

}

void Grenade::Draw() const
{
	if (m_IsHit)
	{
		// Draw explosion
		m_pBottomSprite->Draw();
	}
	else
	{
		// Draw rotating grenade
		glPushMatrix();

			m_pTopSprite->RotateSprite(m_Angle);
			m_pTopSprite->Draw();

		glPopMatrix();
	
	}
}

void Grenade::Update(float elapsedSec, const Soldier* soldier)
{
	// Rotation speed for the grenade
	m_Angle += 120 * elapsedSec;
}

void Grenade::SetStartPos(const Soldier* soldier)
{
	m_Position.x = soldier->GetBotShape().left - 10.f;
	m_Position.y = soldier->GetBotShape().bottom + 30.f;
}

void Grenade::Move(float elapsedSec)
{

}

void Grenade::CheckGameState()
{

}