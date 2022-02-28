#include "pch.h"
#include "Enemy.h"
#include "utils.h"


Enemy::Enemy()
{

}
Enemy::Enemy(const Point2f& center, float width, float height)
	:m_Center(center),
	m_Width(width),
	m_Height(height),
	m_IsDead(false)
{

}
void Enemy::Draw() const
{
	if (!m_IsDead)
	{
		utils::SetColor(Color4f(1.f, 0.f, 0.f, 1.f));
		utils::DrawRect(m_Center.x - m_Width, m_Center.y - m_Height, m_Width, m_Height);
	}
}
bool Enemy::DoHitTest(const Rectf& other)
{
	Rectf enemyRect{ m_Center.x - m_Width, m_Center.y - m_Height, m_Width, m_Height };
	m_IsDead = utils::IsOverlapping(enemyRect, other);

	return m_IsDead;

}
void Enemy::SetCenter(const Point2f& center)
{
	m_Center = center;
}
void Enemy::SetDimensions(float width, float height)
{
	m_Width = width;
	m_Height = height;
}
bool Enemy::IsDead() const
{
	return m_IsDead;
}