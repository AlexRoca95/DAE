#include "pch.h"
#include "Enemy.h"


Enemy::Enemy(GameObject::Type id, const Point2f& startPos, int health, float speed)
	: GameObject(id, speed)
	, m_StartPos{ startPos }
	, m_Health { health }
	, m_ActionState { Enemy::ActionState::state1 }
	, m_PreviousAction { Enemy::ActionState::state1 }
{

}

