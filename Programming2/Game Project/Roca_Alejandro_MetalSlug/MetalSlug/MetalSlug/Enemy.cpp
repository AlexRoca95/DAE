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


void Enemy::ChangeSprite(const int cols, const int rows, const int frames, const float frameSec, const float width,
	const float height, const float spriteSheetTop)
{
	m_pBottomSprite->UpdateValues(cols, rows, frames, frameSec, width, height, spriteSheetTop);
	m_pBottomSprite->ResetSprite();

	m_BotSpriteChanged = false;
}


