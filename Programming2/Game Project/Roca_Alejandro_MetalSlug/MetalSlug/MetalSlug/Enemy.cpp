#include "pch.h"
#include "Enemy.h"


Enemy::Enemy(GameObject::Type id, const Point2f& startPos, int health, const Point2f& speed, const Point2f& acceleration)
	: GameObject(id, startPos, speed, acceleration)
	, m_Health { health }
	, m_ActionState { Enemy::ActionState::state1 }
	, m_PreviousAction { Enemy::ActionState::state1 }
{

}

