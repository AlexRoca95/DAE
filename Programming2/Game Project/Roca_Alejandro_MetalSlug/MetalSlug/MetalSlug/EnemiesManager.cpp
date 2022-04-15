#include "pch.h"
#include "EnemiesManager.h"
#include "Avatar.h"
#include "Helicopter.h"
#include <iostream>


EnemiesManager::EnemiesManager()
	:m_pEnemies{ }
	, m_TotalNrHelicopters { }
{

	

}

EnemiesManager::~EnemiesManager()
{
	if (!m_pEnemies.empty())
	{
		for (Enemy* ptr : m_pEnemies)
		{
			delete ptr;
		}

		m_pEnemies.clear();
	}
}

void EnemiesManager::Draw() const
{
	if (!m_pEnemies.empty())
	{
		for (Enemy* ptr : m_pEnemies)
		{
			if (ptr->GetIsActive())
			{
				ptr->Draw();
			}
		}
	}
	

}
void EnemiesManager::Update(float elapsedSec, Avatar* avatar)
{
	if (!m_pEnemies.empty())
	{
		for (Enemy* ptr : m_pEnemies)
		{
			if (ptr->GetIsActive())
			{
				ptr->Update(elapsedSec, avatar, m_VerticesLevel);
			}
		}

		if (m_TotalNrHelicopters > 0)   // Still helicopters left
		{
			ActivateHelicopter();
		}

		// Erase enemy from the vector if is Dead
		RemoveEnemy();
		

	}

}

void EnemiesManager::AddEnemy( const Point2f& startPos, const GameObject::Type& type )
{
	Enemy* enemy{ };
	switch (type)
	{
		case GameObject::Type::enemyHelicopter:
			enemy = new Helicopter(startPos);
			m_TotalNrHelicopters++;
		break;

		case GameObject::Type::enemySoldier:
		break;
	}

	m_pEnemies.push_back(enemy);
} 

// Erase enemy from the vector if is Dead
void EnemiesManager::RemoveEnemy()
{
	for (int i{ }; i < m_pEnemies.size(); i++)
	{
		if (m_pEnemies[i]->GetIsDead())   // Enemy dead
		{
			delete m_pEnemies[i];
			m_pEnemies.erase(m_pEnemies.begin() + i);
		}
	}
}
// Activate a helicopter if the the game is in the correct stage
void EnemiesManager::ActivateHelicopter()
{
	if (m_pEnemies[0]->GetGameStageChanged())  // Stage changed
	{
		if (m_pEnemies[0]->GetGameStage() == GameObject::GameStage::firstHeliFight
			|| m_pEnemies[0]->GetGameStage() == GameObject::GameStage::secondHeliFight)
		{
			for (Enemy* ptr : m_pEnemies)
			{
				if (ptr->GetType() == GameObject::Type::enemyHelicopter)
				{
					// Activate the helicopter
					ptr->SetIsActive(true);
					ptr->SetGameStageChanged(false);
					break;
				}
			}
		}
	}
}

std::vector <Enemy*> EnemiesManager::GetEnemies() const
{
	return m_pEnemies;
}


void EnemiesManager::SetVerticesLevel(std::vector<Point2f> vertices)
{
	m_VerticesLevel = vertices;
}

