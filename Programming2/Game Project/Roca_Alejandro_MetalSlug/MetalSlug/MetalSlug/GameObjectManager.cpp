#include "pch.h"
#include "GameObjectManager.h"
#include "Helicopter.h"
#include "Soldier.h"
#include "Prisoner.h"
#include "Avatar.h"
#include <iostream>


GameObjectManager::GameObjectManager()
	:m_pGameObjects{ }
	, m_TotalNrHelicopters{ }
	, m_TotalNrPrisoners{ }
{

}


GameObjectManager::~GameObjectManager()
{
	if (!m_pGameObjects.empty())
	{
		for (GameObject* pGameObject : m_pGameObjects)
		{
			delete pGameObject;
		}

		m_pGameObjects.clear();
	}
}



void GameObjectManager::Draw() const
{
	if (!m_pGameObjects.empty())
	{
		for (GameObject* pGameObject : m_pGameObjects)
		{
			if (pGameObject->GetIsActive())
			{
				pGameObject->Draw();
			}
		}
	}


}

void GameObjectManager::Update(float elapsedSec, Avatar* avatar, const Level* level)
{
	if (!m_pGameObjects.empty())
	{
		for (GameObject* pGameObject : m_pGameObjects)
		{
			if (pGameObject->GetIsActive())
			{

				if (pGameObject->GetType() == GameObject::Type::helicopter ||
					pGameObject->GetType() == GameObject::Type::soldier || 
					pGameObject->GetType() == GameObject::Type::prisoner )
				{
					Enemy* pEnemy{ dynamic_cast<Enemy*>(pGameObject) };
					if (pEnemy != nullptr)
					{
						pEnemy->Update(elapsedSec, avatar, level);
					}
				}
			}
	
		}

		
		if (m_TotalNrHelicopters > 0)   // Still helicopters left
		{
			ActivateHelicopter();
		}

		if (m_TotalNrPrisoners > 0)   // Still prisoners left
		{
			AvatarReleasePrisoner(avatar->GetBotShape());
		}

		// Erase enemy from the vector if is Dead
		RemoveGameObject();


	}

}

void GameObjectManager::AddGameObject(const Point2f& startPos, const GameObject::Type& type)
{
	GameObject* gameObject{ };
	switch (type)
	{
	case GameObject::Type::helicopter:
		gameObject = new Helicopter(startPos);
		m_TotalNrHelicopters++;
		break;

	case GameObject::Type::soldier:
		gameObject = new Soldier(startPos);
		break;

	case GameObject::Type::prisoner:
		gameObject = new Prisoner(startPos);
		m_TotalNrPrisoners++;
		break;
	}

	
	m_pGameObjects.push_back(gameObject);
}

// Erase enemy from the vector if is Dead
void GameObjectManager::RemoveGameObject()
{
	for (int i{ }; i < m_pGameObjects.size(); i++)
	{
		if (m_pGameObjects[i]->GetIsDead())   // Enemy dead
		{
			DecrementTotalNrGameObject(m_pGameObjects[i]->GetType());
			delete m_pGameObjects[i];
			m_pGameObjects.erase(m_pGameObjects.begin() + i);
		}
	}
}
// Activate a helicopter if the the game is in the correct stage
void GameObjectManager::ActivateHelicopter()
{
	if (m_pGameObjects[0]->GetGameStageChanged())  // Stage changed
	{
		if (m_pGameObjects[0]->GetGameStage() == GameObject::GameStage::firstHeliFight
			|| m_pGameObjects[0]->GetGameStage() == GameObject::GameStage::secondHeliFight)
		{
			for (GameObject* pGameObject : m_pGameObjects)
			{
				if (pGameObject->GetType() == GameObject::Type::helicopter)
				{
					// Activate the helicopter
					pGameObject->SetIsActive(true);
					pGameObject->SetGameStageChanged(false);
					break;
				}
			}
		}
	}
}

// Decrement the total Number of the gameobject according with his type
void GameObjectManager::DecrementTotalNrGameObject(const GameObject::Type& type)
{

	switch (type)
	{
		case GameObject::Type::helicopter:
			m_TotalNrHelicopters--;
			break;

		case GameObject::Type::prisoner:
			m_TotalNrPrisoners--;
			break;
	}
}

// Check if avatar overlaps with prisoner to release it
void GameObjectManager::AvatarReleasePrisoner(const Rectf& avatarShape)
{
	for (GameObject* pGameObject : m_pGameObjects)
	{
		if (pGameObject->GetType() == GameObject::Type::prisoner)
		{
			if (pGameObject->GetIsActive())
			{
				Prisoner* pPrisoner{ dynamic_cast<Prisoner*>(pGameObject) };
				if (pPrisoner != nullptr)
				{
					pPrisoner->CheckAvatarRelease(avatarShape);
					break;
				}
			}
		}
	}

}

std::vector <GameObject*> GameObjectManager::GetGameObjects() const
{
	return m_pGameObjects;
}


