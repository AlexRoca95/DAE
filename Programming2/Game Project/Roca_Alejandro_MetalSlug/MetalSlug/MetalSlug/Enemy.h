// Base Class for all enemies
#include "GameObject.h"

#pragma once
class Enemy : public GameObject
{

public:


	Enemy(GameObject::Type id, const Point2f& startPos, int health);
	virtual ~Enemy() = default;
	Enemy(const Enemy & enemy) = delete;
	Enemy(Enemy && enemy) = delete;
	Enemy& operator=(const Enemy & enemy) = delete;
	Enemy& operator=(Enemy && enemy) = delete;


	virtual void Draw() const override = 0;
	virtual void Update(float elapsedSec) = 0;

protected:

	const Point2f m_StartPos;
	int m_Health;

};

