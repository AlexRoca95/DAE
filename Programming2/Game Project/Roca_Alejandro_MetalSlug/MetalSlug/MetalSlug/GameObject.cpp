#include "pch.h"
#include "GameObject.h"

GameObject::GameStage GameObject::m_GameState = GameStage::moving;
bool GameObject::m_IsFirstHeliFightStart = false;
bool GameObject::m_IsSecondHeliFightStart = false;
bool GameObject::m_IsBossFightStart = false;

GameObject::GameObject( GameObject::Type id, float speed )
	: m_Id{ id }
	, m_pTopSprite{ }
	, m_pBottomSprite{ }
	, m_Scale{ 2.7f }
	, m_IsActive{ false }
	, m_IsDeath { false }
	, m_Velocity{ }
	, m_Speed{ speed }
{
	
}


bool GameObject::GetIsActive()
{
	return m_IsActive;
}

void GameObject::SetIsActive(bool active)
{
	m_IsActive = active;
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

GameObject::Type GameObject::GetType() const
{
	return m_Id;
}
