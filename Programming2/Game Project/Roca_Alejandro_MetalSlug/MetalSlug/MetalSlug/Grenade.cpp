#include "pch.h"
#include "Grenade.h"
#include "Soldier.h"
#include "Avatar.h"
#include "utils.h"
#include <iostream>



Grenade::Grenade()
	:Projectile(GameObject::Type::grenade, Point2f{ 400.f, 300.f }, Point2f{100.f, g_Gravity})
	, m_Angle { }
	, m_IsMovingRight { false }
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
	m_Velocity.x = m_Speed.x;
	m_Velocity.y = m_Speed.y;

	// Grenade sprite
	m_pTopSprite = new Sprite("Resources/sprites/enemies/grenade.png");
	m_pTopSprite->UpdateValues(1, 1, 1, 15.f, 19.f, 32.f, 32.f, 1.3f);
	

	// Explosion sprite
	m_pBottomSprite = new Sprite("Resources/sprites/enemies/Explosion.png");
	m_pBottomSprite->UpdateValues(5, 1, 5, 15.f, 35.2f, 64.f, 64.f, 2.7f);

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

void Grenade::Update(float elapsedSec, Avatar* avatar, const Soldier* soldier, const std::vector<Point2f>& vertices)
{
	if (!m_IsHit)
	{
		// Rotation speed for the grenade
		m_Angle += 240 * elapsedSec;

		if (!m_IsInitialized)
		{
			m_IsMovingRight = soldier->GetFacingRight();
			m_IsInitialized = true;
		}

		Move(elapsedSec);
		CheckHitAvatar(avatar);
		CheckHitLevel(vertices);

	}
	else
	{
		m_pBottomSprite->Update(elapsedSec, false);

		if (m_pBottomSprite->GetAnimationFinish())
		{
			m_pBottomSprite->ResetAnimationFinish(false);
			m_pBottomSprite->ResetActFrame();
			DesactivateProjectile();
			m_Velocity.x = m_Speed.x;
			m_Velocity.y = m_Speed.y;
		}
	}



}

void Grenade::SetStartPos(const Point2f& soldierPos)
{
	m_Position = soldierPos;
	m_pTopSprite->SetLeftDstRect(m_Position.x);
	m_pTopSprite->SetBottomDstRect(m_Position.y);
}

// Grenade going a small parabola
void Grenade::Move(float elapsedSec)
{

	if (m_IsMovingRight)
	{
		m_Position.x += (m_Velocity.x * elapsedSec);
	}
	else
	{
		m_Position.x += (-m_Velocity.x * elapsedSec);
	}

	m_Velocity.y += m_Acceleration.y * elapsedSec;
	m_Position.y += m_Velocity.y * elapsedSec;

	m_pTopSprite->SetLeftDstRect(m_Position.x);
	m_pTopSprite->SetBottomDstRect(m_Position.y);

}

void Grenade::CheckHitLevel(const std::vector<Point2f>& vertices)
{

	Point2f ray{ m_pTopSprite->GetDstRect().left + m_pTopSprite->GetDstRect().width / 2, 
		m_pTopSprite->GetDstRect().bottom + m_pTopSprite->GetDstRect().height };
	Point2f rayEnd { m_pTopSprite->GetDstRect().left + m_pTopSprite->GetDstRect().width / 2,
		m_pTopSprite->GetDstRect().bottom  };

	utils::HitInfo hitInfo{};

	if (utils::Raycast(vertices, ray, rayEnd, hitInfo))
	{
		if ( rayEnd.y <= hitInfo.intersectPoint.y )
		{
			Hit();
		}
	}

}


void Grenade::CheckHitAvatar(Avatar* avatar)
{
	if (!avatar->GetIsDead())
	{
		if (utils::IsOverlapping(avatar->GetTopShape(), m_pTopSprite->GetDstRect()))
		{
			Hit();
			avatar->Hit();  // Kill avatar
		}
	}
	
}

void Grenade::CheckGameState()
{

}