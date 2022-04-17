#include "pch.h"
#include "GameObjectManager.h"
#include "Helicopter.h"
#include "Soldier.h"
#include "Prisoner.h"
#include "Avatar.h"
#include "Item.h"
#include <iostream>


GameObjectManager::GameObjectManager()
	:m_pGameObjects{ }
	, m_TotalNrHelicopters{ }
	, m_TotalNrPrisoners{ }
	, m_TotalNrItems{ }
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
				switch (pGameObject->GetType())
				{
					case GameObject::Type::helicopter:
					case GameObject::Type::soldier:
					case GameObject::Type::prisoner:
					{
						Enemy* pEnemy{ dynamic_cast<Enemy*>(pGameObject) };
						if (pEnemy != nullptr)
						{
							pEnemy->Update(elapsedSec, avatar, level);
						}

						break;
					}
					case GameObject::Type::item:
					{
						Item* pItem{ dynamic_cast<Item*>(pGameObject) };
						if (pItem != nullptr)
						{
							pItem->Update(elapsedSec, level);
						}
						break;
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

		if (m_TotalNrItems > 0)
		{
			GrabItem(avatar);
		}

		// Erase enemy from the vector if is Dead
		RemoveGameObject();


	}

}

void GameObjectManager::AddGameObject(const Point2f& startPos, const GameObject::Type& type)
{
	GameObject* gameObject{ };
	GameObject* item{ };

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
		// Create also an Item next to the position of the prisoner
		Point2f starPosItem = SetStartPosItem(gameObject->GetBotShape());
		item = new Item(starPosItem);
		m_TotalNrItems++;
		break;
	}

	
	m_pGameObjects.push_back(gameObject);

	if (type == GameObject::Type::prisoner)
	{
		// Item will be positioned in the vector right after the prisoner
		m_pGameObjects.push_back(item);
	}
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


void GameObjectManager::GrabItem(Avatar* avatar)
{
	for (GameObject* pGameObject : m_pGameObjects)
	{
		if (pGameObject->GetType() == GameObject::Type::item)
		{
			if (pGameObject->GetIsActive())
			{
				Item* pItem{ dynamic_cast<Item*>(pGameObject) };
				if (pItem != nullptr)
				{
					pItem->GrabItem(avatar);
				}
			}
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

		case GameObject::Type::item:
			m_TotalNrItems--;
			break;
	}
}

// Check if avatar overlaps with prisoner to release it
void GameObjectManager::AvatarReleasePrisoner(const Rectf& avatarShape)
{

	for (int i{ }; i < m_pGameObjects.size(); i++)
	{
		if (m_pGameObjects[i]->GetType() == GameObject::Type::prisoner)
		{
			if (m_pGameObjects[i]->GetIsActive())
			{
				Prisoner* pPrisoner{ dynamic_cast<Prisoner*>(m_pGameObjects[i]) };
				if (pPrisoner != nullptr)
				{
					pPrisoner->CheckAvatarRelease(avatarShape);

					if (pPrisoner->GetDropItem())
					{
						if ( m_pGameObjects[i + 1] != nullptr && (i +1) < m_pGameObjects.size() )
						{
							m_pGameObjects[i + 1]->SetIsActive(true);  // Activate the item to show
							pPrisoner->ItemDropped();				// Item Dropped
							
						}
						
					}
					
				}
			}
		}
	}

}

Point2f GameObjectManager::SetStartPosItem(const Rectf& prisonerShape)
{
	Point2f starPos{};

	starPos.x = prisonerShape.left - prisonerShape.width / 2.f;
	starPos.y = prisonerShape.bottom + prisonerShape.height / 3.f;
	return starPos;

}

std::vector <GameObject*> GameObjectManager::GetGameObjects() const
{
	return m_pGameObjects;
}


