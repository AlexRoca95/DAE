#pragma once
#include "Enemy.h"

class Enemy;
class EnemiesManager
{

public:

	EnemiesManager();
	virtual ~EnemiesManager();
	EnemiesManager(const EnemiesManager & enemiesManager) = delete;
	EnemiesManager(EnemiesManager&& enemiesManager) = delete;
	EnemiesManager& operator=(const EnemiesManager& enemiesManager) = delete;
	EnemiesManager& operator=(EnemiesManager&& enemiesManager) = delete;

	void Draw() const;
	void Update(float elapsedSec);

	void AddEnemy(const Point2f& startPos, const GameObject::Type& type);


	std::vector <Enemy*> GetEnemies() const;

private:

	std::vector <Enemy*> m_pEnemies;
	//const int m_NrHelicopters;
	//const int m_NrSoldiers;


};

