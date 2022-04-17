#pragma once
#include "Enemy.h"

class Avatar;
class Level;
class GameObjectManager
{

public:

	GameObjectManager();
	virtual ~GameObjectManager();
	GameObjectManager(const GameObjectManager& gameObjectManager) = delete;
	GameObjectManager(GameObjectManager&& GameObjectManager) = delete;
	GameObjectManager& operator=(const GameObjectManager& GameObjectManager) = delete;
	GameObjectManager& operator=(GameObjectManager&& GameObjectManager) = delete;


	void Draw() const;
	void Update(float elapsedSec, Avatar* avatar, const Level* level);

	void AddGameObject(const Point2f& startPos, const GameObject::Type& type);


	std::vector <GameObject*> GetGameObjects() const;


private:

	std::vector <GameObject*> m_pGameObjects;
	int m_TotalNrHelicopters;
	int m_TotalNrPrisoners;
	int m_TotalNrItems;


	void ActivateHelicopter();
	void RemoveGameObject();
	void DecrementTotalNrGameObject(const GameObject::Type& type);
	void AvatarReleasePrisoner(const Rectf& avatarShape);
	void GrabItem(Avatar* avatar);
	Point2f SetStartPosItem(const Rectf& prisonerShape);
	//void DropItem();


};

