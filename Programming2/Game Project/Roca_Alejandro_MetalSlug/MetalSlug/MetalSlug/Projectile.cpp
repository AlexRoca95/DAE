#include "pch.h"
#include "Projectile.h"
#include "utils.h"

Projectile::Projectile(GameObject::Type type, float speed)
	:GameObject(type, speed)
	, m_MaxSeconds { 2.f }
	, m_Seconds { }
	, m_IsHit{ false }
	, m_IsInitialized { false }
{

}


void Projectile::Draw() const
{
	if (m_IsHit)
	{
		// Draw explosion
		m_pBottomSprite->Draw();
	}
	else
	{
		// Draw projectile 
		m_pTopSprite->Draw();

	}
}

void Projectile::Hit()
{
	m_IsHit = true;

	m_pBottomSprite->SetLeftDstRect(m_Position.x);
	m_pBottomSprite->SetBottomDstRect(m_Position.y);
}


void Projectile::DesactivateProjectile()
{
	m_IsActive = false;
	m_IsInitialized = false;
	m_Seconds = 0.f;
	m_Velocity = Vector2f{ 0.f, 0.f };
	m_IsHit = false;
}

bool Projectile::GetIsHit()
{
	return m_IsHit;
}