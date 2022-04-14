#include "pch.h"
#include "EnemiesManager.h"
#include "Avatar.h"
#include "Helicopter.h"


EnemiesManager::EnemiesManager()
	:m_pEnemies{ }
{

	

}

EnemiesManager::~EnemiesManager()
{
	for (Enemy* ptr : m_pEnemies)
	{
		delete ptr;
	}

	m_pEnemies.clear();
}

void EnemiesManager::Draw() const
{

	for (Enemy* ptr : m_pEnemies)
	{
		if (ptr->GetIsActive())
		{
			ptr->Draw();
		}
		
	}

}
void EnemiesManager::Update(float elapsedSec, Avatar* avatar)
{
	for (Enemy* ptr : m_pEnemies)
	{

		if (ptr->GetIsActive())
		{
			ptr->Update(elapsedSec, avatar, m_VerticesLevel);
		}
	}
}

void EnemiesManager::AddEnemy( const Point2f& startPos, const GameObject::Type& type )
{
	Enemy* enemy{ };
	switch (type)
	{
		case GameObject::Type::enemyHelicopter:
			enemy = new Helicopter(startPos);
			enemy->SetIsActive(true);
		break;
	}

	m_pEnemies.push_back(enemy);
} 

std::vector <Enemy*> EnemiesManager::GetEnemies() const
{
	return m_pEnemies;
}


void EnemiesManager::SetVerticesLevel(std::vector<Point2f> vertices)
{
	m_VerticesLevel = vertices;
}

