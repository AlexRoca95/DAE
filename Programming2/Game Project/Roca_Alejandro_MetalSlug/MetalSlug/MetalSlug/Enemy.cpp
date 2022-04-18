#include "pch.h"
#include "Enemy.h"


Enemy::Enemy(const GameObject::Type& id, const Point2f& startPos, int health, const Point2f& speed,
	bool comingFromRight, const Point2f& acceleration)
	: GameObject(id, startPos, speed, comingFromRight, acceleration)
	, m_Health { health }
	, m_ActionState { Enemy::ActionState::state1 }
	, m_PreviousAction { Enemy::ActionState::state1 }
{

}

