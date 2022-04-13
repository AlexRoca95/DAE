#include "pch.h"
#include "BulletManager.h"
#include "Bullet.h"
#include "utils.h"
#include <iostream>


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
		if (ptr->GetIsActive())
		{
			ptr->Draw();
		}
	}

}
void BulletManager::Update(float elapsedSec, const Avatar* avatar)
{
	for (Bullet* ptr : m_pBullets)
	{
		if (ptr->GetIsActive())
		{
			ptr->Update(elapsedSec, avatar);
		}
		
	}

	CheckHitLevel();
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
			// We activate first bullet in the vector thats is not already activated
			ptr->SetIsActive(true);
			break;  
		}

	}

}

void BulletManager::CheckHitLevel()
{
	int randomHit{};
	for (Bullet* ptr : m_pBullets)
	{
		if (ptr->GetIsActive())
		{
			RandomCollision(randomHit);

			Point2f ray{ ptr->GetShape().left,  ptr->GetShape().bottom + ptr->GetShape().height / 2};
			Point2f rayEnd{ ptr->GetShape().left + ptr->GetShape().width + float(randomHit),  ptr->GetShape().bottom + ptr->GetShape().height / 2};

			utils::HitInfo hitInfo{};

			if (utils::Raycast(m_VerticesLevel, ray, rayEnd, hitInfo))
			{
				if (rayEnd.x >= hitInfo.intersectPoint.x)
				{
					ptr->Hit();
				}
			}
		}
	}
}

// Calculate a random value for the hit collision of the bullet
void BulletManager::RandomCollision(int& random)
{
	random = (rand() % 30) - 30; // Rand [-30, -1]
	random += (rand() % 10) + 1; // Rand [-30, 10]
}

void BulletManager::SetVerticesLevel(std::vector<Point2f> vertices)
{
	m_VerticesLevel = vertices;
}
