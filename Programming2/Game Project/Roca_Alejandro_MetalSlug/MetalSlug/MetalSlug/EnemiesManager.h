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
	void Update(float elapsedSec, Avatar* avatar);

	void AddEnemy(const Point2f& startPos, const GameObject::Type& type);


	std::vector <Enemy*> GetEnemies() const;


	void SetVerticesLevel(std::vector<Point2f> vertices);

private:

	std::vector <Enemy*> m_pEnemies;
	std::vector<Point2f> m_VerticesLevel;			// For collisions with the level
	int m_TotalNrHelicopters;
	//const int m_NrSoldiers;


	void ActivateHelicopter();
	void RemoveEnemy();
	


};

