#include "pch.h"
#include "Helicopter.h"
#include "Avatar.h"
#include "Bomb.h"
#include "utils.h"
#include <iostream>


Helicopter::Helicopter(const Point2f& startPos)
	: Enemy( GameObject::Type::enemyHelicopter, startPos, 15, 200.f ) // Type, startPos, health and velocity
	, m_MaxHeight{ 400.f }
	, m_MaxTimerBombs { 3.f }
	, m_TimerBombs {  }
	, m_pBombs{ }
	, m_IsThrowingBombs{ false }
	, m_TimeThrowBomb { 0.3f}
	, m_Seconds{ m_TimeThrowBomb }
	, m_ExplosionCounter { 0 }
	, m_NewBombs { false }
{

	Initialize();

}

Helicopter::~Helicopter()
{
	delete m_pBottomSprite;

	for (Bomb* ptr : m_pBombs)
	{
		delete ptr;
	}
	m_pBombs.clear();
}


void Helicopter::Initialize()
{
	m_pBottomSprite = new Sprite("Resources/sprites/enemies/helicopterv2.png");
	m_pBottomSprite->UpdateValues(5, 1, 5, 11.f, 100.f, 67.f, 67.f); // Iddle Helicopter
	m_pBottomSprite->SetLeftDstRect(m_StartPos.x);
	m_pBottomSprite->SetBottomDstRect(m_StartPos.y);
	m_pBottomSprite->UpdateLeftSrcRect();

	// Add 3 bombs 
	m_pBombs.push_back(new Bomb);
	m_pBombs.push_back(new Bomb);
	m_pBombs.push_back(new Bomb);

}

void Helicopter::Draw() const
{
	if (m_IsThrowingBombs)
	{
		for (Bomb* ptr : m_pBombs)
		{
			if( ptr->GetIsActive() )
			{
				ptr->Draw();
			}
		}
	}

	m_pBottomSprite->Draw();
	
}

void Helicopter::Update(float elapsedSec, Avatar* avatar, const std::vector<Point2f>& vertices)
{
	std::cout << int(m_GameState) << std::endl;
	if (!m_IsDeath)
	{
		m_pBottomSprite->Update(elapsedSec, true);

		// Check which action do
		switch (m_ActionState)
		{
			case Enemy::ActionState::state1:
				// Positioning
				ColocateInPos(elapsedSec);
				break;
			case Enemy::ActionState::state2:
				// Move towards player
				Move(elapsedSec, avatar);
				CheckTimerBombs(elapsedSec);
				break;
		
		}

		if (m_IsThrowingBombs)
		{	
 			// Throw 3 bombs
			ThrowBombs(elapsedSec, this->GetBotShape());
			CheckBombCollision(avatar, vertices);
		}

	}
	else
	{
		DestroyHelicopter(elapsedSec);
	}

}

void Helicopter::DestroyHelicopter(float elapsedSec)
{
	m_pBottomSprite->Update(elapsedSec, false);

	if (m_pBottomSprite->GetAnimationFinish())
	{
		m_pBottomSprite->ResetAnimationFinish(false);
		m_pBottomSprite->ResetActFrame();
		m_IsActive = false;
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

// Throw 3 bombs towards ground
void Helicopter::ThrowBombs(float elapsedSec, const Rectf& actorShape)
{
	m_Seconds += elapsedSec;

	if (m_Seconds >= m_TimeThrowBomb)
	{
		m_Seconds = 0.f;

		// Throw a Bomb

		for (int i{}; i < m_pBombs.size(); i++)
		{
			// Active a Bomb
			if (!m_pBombs[i]->GetIsActive() && m_NewBombs)
			{
				m_pBombs[i]->SetIsActive(true);

				if (i + 1 == m_pBombs.size())
				{
					// Wait until all bombs have exploded to throw the next ones
					m_NewBombs = false;
				}
				break;
			}

		}
		
	}
		for (Bomb* ptr : m_pBombs)
		{	
			if (ptr->GetIsActive())
			{
				ptr->Update(elapsedSec, actorShape);

			}
		}
}

void Helicopter::ColocateInPos(float elapsedSec)
{
	// Helicopter appears from the top outside window
	if ( m_pBottomSprite->GetDstRect().bottom  > m_MaxHeight)
	{
		m_Velocity.y = - m_Speed;

		m_pBottomSprite->SetBottomDstRect( m_pBottomSprite->GetDstRect().bottom + (m_Velocity.y * elapsedSec) );
	}
	else
	{
		m_Velocity.y = 0;
		m_ActionState = ActionState::state2; // Move State
	}

}

void Helicopter::Move(float elapsedSec, const Avatar* avatar)
{
	
	if ((m_pBottomSprite->GetDstRect().left + m_pBottomSprite->GetDstRect().width / 2 )
			< avatar->GetTopShape().left + avatar->GetTopShape().width)
	{
			m_Velocity.x = m_Speed;
	}
	else
	{
		m_Velocity.x = -m_Speed;
	}

	m_pBottomSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left + (m_Velocity.x * elapsedSec));
	
}

void Helicopter::CheckTimerBombs(float elapsedSec)
{
	m_TimerBombs += elapsedSec;

	if (m_TimerBombs >= m_MaxTimerBombs  && !m_IsThrowingBombs)
	{
	
		m_IsThrowingBombs = true;
		m_NewBombs = true;
		m_TimerBombs = 0.f;
		
	}


}

void Helicopter::CheckBombCollision(Avatar* avatar, const std::vector<Point2f>& vertices)
{
	// Check collision with the ground
	for (int i{}; i < m_pBombs.size(); i++)
	{
		if (m_pBombs[i]->GetIsActive())
		{
			// Ray from the middle of the sprite to the bottom
			Point2f ray{ m_pBombs[i]->GetTopShape().left + m_pBombs[i]->GetTopShape().width / 2, m_pBombs[i]->GetTopShape().bottom + m_pBombs[i]->GetTopShape().height / 2 };
			Point2f rayBottom{ m_pBombs[i]->GetTopShape().left + m_pBombs[i]->GetTopShape().width / 2, m_pBombs[i]->GetTopShape().bottom + 1 };

			utils::HitInfo hitInfo{}; // Info about the intersection point

			if (utils::Raycast(vertices, ray, rayBottom, hitInfo))
			{
				if (rayBottom.y <= hitInfo.intersectPoint.y)
				{
					m_pBombs[i]->Hit();
					m_ExplosionCounter = i + 1;
				}
			}
		}

	}


	// Check collision with Avatar	
	for (int i{}; i < m_pBombs.size(); i++)
	{
		if (m_pBombs[i]->GetIsActive())
		{
			//std::cout << m_pBombs[i]->GetTopSprite()->GetDstRect().bottom << std::endl;
			if (utils::IsOverlapping(m_pBombs[i]->GetTopSprite()->GetDstRect(), avatar->GetTopShape()))
			{
				m_pBombs[i]->Hit();
				m_ExplosionCounter = i + 1;
				avatar->Hit();
			}
		}
	}

	
	// Check if all bombs have exploded or not
	if (m_ExplosionCounter == m_pBombs.size())
	{
		if (!m_pBombs[m_ExplosionCounter - 1]->GetIsActive())
		{
			m_IsThrowingBombs = false;
			m_NewBombs = true;
			m_ExplosionCounter = 0;
		}
		
	}
	
}

void Helicopter::CheckGameState() 
{

}