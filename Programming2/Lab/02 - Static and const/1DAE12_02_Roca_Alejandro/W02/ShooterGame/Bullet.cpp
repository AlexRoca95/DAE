#include "pch.h"
#include "Bullet.h"
#include "utils.h"
#include "Enemy.h"
#include <iostream>

Bullet::Bullet()
{

}
Bullet::Bullet(float width, float height)
	:m_Width(width),
	m_Height(height),
	m_IsActivated(false)
{

}
void Bullet::Draw() const
{

	if (m_IsActivated)
	{
		utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });
		utils::FillRect(m_Center.x - (m_Width + (m_Width/2)), m_Center.y - m_Height, m_Width, m_Height);
	}

}
void Bullet::Update(float elapsedSec, Enemy* pEnemies, int numEnemies)
{
	if (m_IsActivated)
	{
		m_Center.y += m_Velocity.y * elapsedSec;

		CheckEnemiesHit(pEnemies, numEnemies);
		CheckBoundaries();

	}
}
void Bullet::Shoot(const Point2f& center, const Vector2f& velocity)
{
	if (!m_IsActivated)
	{
		m_IsActivated = true;
		m_Center = center;
		m_Velocity = velocity;

	}
}
void Bullet::SetDimensions(float width, float height)
{
	m_Width = width;
	m_Height = height;
}
void Bullet::SetBondaries(const Rectf& boundaries)
{
	m_Boundaries = boundaries;
}

void Bullet::CheckBoundaries()
{
	if (m_Center.y - m_Width/2 >= m_Boundaries.height)
	{
		m_IsActivated = false;
	}
}

void Bullet::CheckEnemiesHit(Enemy* m_pEnemy, int numEnemies)
{
	
	for (int i{ 0 }; i < numEnemies; i++)
	{
		//m_pEnemy[i].DoHitTest(Rectf{ m_Center.x - (m_Width + (m_Width / 2)), m_Center.y - m_Height, m_Width, m_Height });
	
	}


}