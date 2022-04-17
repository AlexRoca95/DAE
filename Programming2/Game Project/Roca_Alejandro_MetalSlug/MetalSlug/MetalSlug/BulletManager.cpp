#include "pch.h"
#include "BulletManager.h"
#include "Bullet.h"
#include "utils.h"
#include "GameObject.h"
#include "Enemy.h"
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

			Point2f ray{ ptr->GetTopShape().left,  ptr->GetTopShape().bottom + ptr->GetTopShape().height / 2};
			Point2f rayEnd{ ptr->GetTopShape().left + ptr->GetTopShape().width + float(randomHit),  ptr->GetTopShape().bottom + ptr->GetBotShape().height / 2};

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

// Check collision of the bullet with the enemies
void BulletManager::CheckHitGameObjects(std::vector<GameObject*> gameObjects)
{

	for (Bullet* bulletPtr : m_pBullets)
	{
		if (bulletPtr->GetIsActive() && !bulletPtr->GetIsHit())
		{
			for (GameObject* pGameObject : gameObjects)
			{
				if ( pGameObject->GetIsActive() && !pGameObject->GetIsDying() &&
					pGameObject->GetType() != GameObject::Type::item)  // Object active, not dying and not an item
				{
					// X axis
					if ( ( bulletPtr->GetTopShape().left ) >
						pGameObject->GetBotShape().left			&&  
						bulletPtr->GetTopShape().left < ( pGameObject->GetBotShape().left +
							pGameObject->GetBotShape().width ) )
					{
						// Y axis
						if (bulletPtr->GetTopShape().bottom  >
							pGameObject->GetBotShape().bottom &&
							bulletPtr->GetTopShape().bottom < (pGameObject->GetBotShape().bottom +
								pGameObject->GetBotShape().height))
						{
							bulletPtr->Hit();
							pGameObject->Hit();
							break;
						}
					}


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
