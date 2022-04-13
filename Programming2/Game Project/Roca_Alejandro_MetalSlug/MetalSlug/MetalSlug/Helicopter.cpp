#include "pch.h"
#include "Helicopter.h"
#include <iostream>


Helicopter::Helicopter(const Point2f& startPos)
	:Enemy(GameObject::Type::enemyHelicopter, startPos, 15)
{

	Initialize();

}

Helicopter::~Helicopter()
{
	
	delete m_pBottomSprite;
}


void Helicopter::Initialize()
{
	m_pBottomSprite = new Sprite("Resources/sprites/enemies/helicopterv2.png");
	m_pBottomSprite->UpdateValues(5, 1, 5, 13.f, 100.f, 67.f, 67.f); // Iddle Helicopter
	m_pBottomSprite->SetLeftDstRect(m_StartPos.x);
	m_pBottomSprite->SetBottomDstRect(m_StartPos.y);
	m_pBottomSprite->UpdateLeftSrcRect();


}

void Helicopter::Draw() const
{
	m_pBottomSprite->Draw();	
	
}

void Helicopter::Update(float elapsedSec)
{
	if (!m_IsDeath)
	{
		m_pBottomSprite->Update(elapsedSec, true);
	}
	else
	{
		if (m_IsDeath)
		{

			m_pBottomSprite->Update(elapsedSec, false);

			if (m_pBottomSprite->GetAnimationFinish())
			{
				m_pBottomSprite->ResetAnimationFinish(false);
				m_pBottomSprite->ResetActFrame();
				m_IsActive = false;
			}
			
		}
	}
	

	

}


void Helicopter::Hit() 
{
	m_Health --;
	
	if (m_Health == 0)
	{
		m_IsDeath = true;
		m_pBottomSprite->UpdateValues(7, 1, 7, 12.f, 100.f, 72.f, 232.f);  // Change death animation
	}

}

