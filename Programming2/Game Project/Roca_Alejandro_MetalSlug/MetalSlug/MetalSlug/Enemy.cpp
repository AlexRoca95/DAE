#include "pch.h"
#include "Enemy.h"


Enemy::Enemy(GameObject::Type id, const Point2f& startPos, int health)
	: GameObject(id)
	, m_StartPos{ startPos }
	, m_Health { health }
{

}

