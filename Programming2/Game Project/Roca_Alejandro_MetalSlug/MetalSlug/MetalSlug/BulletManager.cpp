#include "pch.h"
#include "BulletManager.h"
#include "Bullet.h"


BulletManager::BulletManager()
	: m_pBullets{}
{

}



BulletManager::~BulletManager()
{

	for (Bullet* ptr : m_pBullets)
	{
		delete ptr;
	}

	m_pBullets.clear();  

}

void BulletManager::Draw() const
{
	for (Bullet* ptr : m_pBullets)
	{
		ptr->Draw();
	}
}
void BulletManager::Update(float elapsedSec, const Avatar* avatar)
{
	for (Bullet* ptr : m_pBullets)
	{
		ptr->Update(elapsedSec, avatar);
	}
}


void BulletManager::AddBullet(Point2f& startPos)
{

	m_pBullets.push_back( new Bullet(startPos) );

}

void BulletManager::ActivateBullet()
{
	
	for (Bullet* ptr : m_pBullets)
	{
		if (!ptr->GetIsActive())
		{
			ptr->SetIsActive(true);
			break;  // Exit loop when we activate a Bullet
		}

	}

}