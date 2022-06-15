#include "pch.h"
#include "BossBullet.h"


BossBullet::BossBullet(bool airBullet, const Point2f& startPos, SoundManager* sounds)
	:Projectile(GameObject::Type::bossBullet, startPos, Point2f{ 350.f , 1500.f}, sounds, Point2f{0.f, g_Gravity})
	, m_BulletType{ BulletType::airBullet }
{
	if (airBullet)
	{
		m_BulletType = BulletType::airBullet;
	}
	else
	{
		m_BulletType = BulletType::groundBullet;
	}

	Initialize();
}


BossBullet::~BossBullet()
{
	delete m_pBottomSprite;
}


void BossBullet::Initialize()
{
	m_pBottomSprite = new Sprite("Resources/sprites/enemies/Boss/projectiles.png");

	if (m_BulletType == BulletType::airBullet)
	{
		m_pBottomSprite->UpdateValues(3, 1, 3, 8.f, 10.f, 10.f, 20.f);     // Flying bullet
	}
	else
	{
		m_pBottomSprite->UpdateValues(4, 1, 4, 10.f, 80.f, 26.f, 50.f);   // Ground Bullet
	}

	// Start Position
	m_pBottomSprite->SetLeftDstRect(m_StartPosition.x);
	m_pBottomSprite->SetBottomDstRect(m_StartPosition.y);

}


void BossBullet::CheckGameState()
{

}

void BossBullet::Update(float elapsedSec)
{

}

void BossBullet::Draw() const
{

}

void BossBullet::Move(float elapsedSec)
{

}