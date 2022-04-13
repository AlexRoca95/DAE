#include "pch.h"
#include "GameObject.h"


GameObject::GameObject( GameObject::Type id )
	: m_Id{ id }
	, m_pTopSprite{ }
	, m_pBottomSprite{ }
	, m_Scale{ 2.7f }
	, m_IsActive{ false }
	, m_IsDeath { false }

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
