#include "pch.h"
#include "GameObject.h"
#include "Level.h"

GameObject::GameStage GameObject::m_GameState = GameStage::moving;
bool GameObject::m_IsFirstHeliFightStart = false;
bool GameObject::m_IsSecondHeliFightStart = false;
bool GameObject::m_IsBossFightStart = false;
bool GameObject::m_IsStageChanged = false;

GameObject::GameObject( const GameObject::Type& id, const Point2f& startPos, const Point2f& speed,  bool comingFromRight, 
	const Point2f& acceleration)
	: m_Id{ id }
	, m_StartPosition { startPos }
	, m_pTopSprite{ }
	, m_pBottomSprite{ }
	, m_IsActive{ false }
	, m_IsDead { false }
	, m_IsDying { false }
	, m_BotSpriteChanged{ false }
	, m_TopSpriteChanged{ false }
	, m_Velocity{ }
	, m_Acceleration{ acceleration }
	, m_Speed { speed }
	, m_IsComingFromRight { comingFromRight }
{
	
}





// Gravity for the gameObjects
void GameObject::Falling(float elapsedSec, const Level* level)
{
	if (!level->IsOnGround(m_pBottomSprite->GetDstRect(), m_Velocity))
	{
		m_Velocity.y += m_Acceleration.y * elapsedSec;
	}

	m_pBottomSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_Velocity.y * elapsedSec);
}

void GameObject::SetIsActive(bool active)
{
	m_IsActive = active;
}

void GameObject::SetGameStageChanged(bool stageChanged)
{
	m_IsStageChanged = stageChanged;
}



Rectf GameObject::GetTopShape() const
{
	return m_pTopSprite->GetDstRect();
}

Rectf GameObject::GetBotShape() const
{
	return m_pBottomSprite->GetDstRect();
}

GameObject::GameStage& GameObject::GetGameStage() const
{
	return m_GameState;
}

bool GameObject::GetGameStageChanged() const
{
	return m_IsStageChanged;
}

GameObject::Type GameObject::GetType() const
{
	return m_Id;
}

bool GameObject::GetIsDying() const
{
	return m_IsDying;
}

bool GameObject::GetIsComingFromRight() const
{
	return m_IsComingFromRight;
}

bool GameObject::GetIsActive() const
{
	return m_IsActive;
}

bool GameObject::GetIsDead() const
{
	return m_IsDead;
}