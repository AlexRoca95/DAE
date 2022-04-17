#include "pch.h"
#include "Item.h"
#include "Avatar.h"
#include "Level.h"
#include "utils.h"
#include <iostream>


Item::Item(const Point2f& startPos)
	:GameObject(GameObject::Type::item, startPos, Point2f{}, false)
{
	Initialize();
}


Item::~Item()
{
	delete m_pBottomSprite;
}


void Item::Initialize()
{

	SelectTypeItem();
	
	m_pBottomSprite = new Sprite("Resources/sprites/Items.png");

	switch (m_ItemType)
	{
	case Item::ItemType::ammo:
		// Type Item --> Box ammo
		m_pBottomSprite->UpdateValues(6, 1, 6, 8.f, 32.f, 32.f, 32);
		break;
	case Item::ItemType::card:
		// Type Item --> Card
		m_pBottomSprite->UpdateValues(11, 1, 11, 10.f, 24.f, 24.f, 80.f);
		break;

	}

	m_pBottomSprite->SetLeftDstRect(m_StartPosition.x);
	m_pBottomSprite->SetBottomDstRect(m_StartPosition.y);
	m_pBottomSprite->UpdateLeftSrcRect();

}

// Select randomly the type of the item
void Item::SelectTypeItem()
{
	int randType = rand() % 2;

	m_ItemType = Item::ItemType(randType);   
}

void Item::Draw() const
{
	m_pBottomSprite->Draw();
}


void Item::Update(float elapsedSec, const Level* level)
{
	if (!m_IsDying)
	{
		m_pBottomSprite->Update(elapsedSec, true);
	}
	else
	{
		m_pBottomSprite->Update(elapsedSec, false);

		if (m_pBottomSprite->GetAnimationFinish())
		{
			m_IsActive = false;
			
		}

	}

	level->HandleCollision(m_pBottomSprite->GetDstRect(), m_Velocity);
	Fall(elapsedSec, level);
	
}

void Item::Hit()
{
	


}

void Item::GrabItem(Avatar* avatar)
{

	if ( utils::IsOverlapping( m_pBottomSprite->GetDstRect(), avatar->GetHitBox() ) )
	{

		if (m_ItemType == Item::ItemType::card)
		{
			m_IsActive = false;
			
		}
		else
		{
			if (!m_IsDying)
			{
				m_IsDying = true;
				m_pBottomSprite->UpdateValues(2, 1, 2, 6.f, 32.f, 32.f, 112.f);
				m_pBottomSprite->ResetActFrame();
			}
			
		}

		avatar->GrabItem(m_ItemType);
		
	}


}

// Item falls when it is dropped
void Item::Fall(float elapsedSec, const Level* level)
{
	if (!level->IsOnGround(m_pBottomSprite->GetDstRect(), m_Velocity))
	{
		m_Velocity.y += m_Acceleration.y * elapsedSec;
	}

	m_pBottomSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_Velocity.y * elapsedSec);
}

void Item::CheckGameState()
{

}
