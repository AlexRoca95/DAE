// Base Class for all enemies
#include "GameObject.h"

#pragma once
class Avatar;
class Enemy : public GameObject
{

public:
	// Actions that the enemy can do
	enum class ActionState {

		state1,
		state2,
		state3,
		state4

	};

	Enemy(GameObject::Type id, const Point2f& startPos, int health, float speed);
	virtual ~Enemy() = default;
	Enemy(const Enemy & enemy) = delete;
	Enemy(Enemy && enemy) = delete;
	Enemy& operator=(const Enemy & enemy) = delete;
	Enemy& operator=(Enemy && enemy) = delete;


	virtual void Draw() const override = 0;
	virtual void Update(float elapsedSec, Avatar* avatar, const std::vector<Point2f>& vertices) = 0;

protected:

	ActionState m_ActionState;
	const Point2f m_StartPos;
	int m_Health;

};

