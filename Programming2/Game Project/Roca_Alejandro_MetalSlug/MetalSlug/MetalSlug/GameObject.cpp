#include "pch.h"
#include "GameObject.h"


GameObject::GameObject( GameObject::Type id )
	: m_Id{ id }
	, m_pTopSprite{ }
	, m_pBottomSprite{ }
	, m_Scale{ 2.7f }
	, m_IsActive{ false }

{
	
}


