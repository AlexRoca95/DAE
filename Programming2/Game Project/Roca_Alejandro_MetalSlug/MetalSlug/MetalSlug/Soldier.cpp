#include "pch.h"
#include "Soldier.h"
#include "Level.h"
#include "Avatar.h"
#include "Grenade.h"
#include <iostream>



Soldier::Soldier(const Point2f& startPos)
	:Enemy(GameObject::Type::soldier, startPos, 1, 150.f)   // Type, starting position, health and speed
	, m_RunSpeed { 200.f }
	, m_FacingRight { false }
	, m_RunAwayDist { 200.f }
	, m_ThrowGrenadeDist { 300.f }
	, m_MaxTimeRunAway { 3.f }
	, m_Seconds { -1.f }
	, m_pGrenade { new Grenade }
{
	Initialize();
	m_IsActive = true;
}


Soldier::~Soldier()
{
	delete m_pBottomSprite;
	delete m_pGrenade;
}


void Soldier::Draw() const
{

	switch (m_ActionState)
	{
	case Enemy::ActionState::state2:
		if (!m_FacingRight)
		{
			// Flip to the left
			glPushMatrix();

			m_pBottomSprite->FlipSprite();
			m_pBottomSprite->Draw();

			glPopMatrix();
		}
		else
		{
			m_pBottomSprite->Draw();
		}
		break;
	case Enemy::ActionState::state3:
	case Enemy::ActionState::state1:
	case Enemy::ActionState::state4:
		if (m_FacingRight)
		{
			// Flip to the left
			glPushMatrix();

			m_pBottomSprite->FlipSprite();
			m_pBottomSprite->Draw();

			glPopMatrix();
		}
		else
		{
			m_pBottomSprite->Draw();
		}
		break;

	default:
		m_pBottomSprite->Draw();
		break;
	}

	m_pGrenade->Draw();

}

void Soldier::Update(float elapsedSec, Avatar* avatar, const Level* level)
{
	//std::cout << "Hola" << std::endl;
	CheckPreviousAction();

	if (!m_IsDying)
	{
		switch (m_ActionState)
		{
		case Enemy::ActionState::state1:
			// Walking
			DoWalkingState(elapsedSec, avatar);
			break;
		case Enemy::ActionState::state2:
			// Attack
			DoAttackState(elapsedSec, avatar);
			break;
		case Enemy::ActionState::state3:
			// Running Away
			DoRunAwayState(elapsedSec, avatar);
			break;
		}
	}
	else
	{
		KillSoldier(elapsedSec);
	}


	UpdateFrames(elapsedSec);
	Falling(elapsedSec, level);
	Move(elapsedSec);
	level->HandleCollision(m_pBottomSprite->GetDstRect(), m_Velocity);


	m_pGrenade->Update(elapsedSec, this);
}


void Soldier::CheckPreviousAction()
{
	if (m_ActionState != m_PreviousAction)
	{
		m_PreviousAction = m_ActionState;
		m_BotSpriteChanged = true;
	}
}


void Soldier::UpdateFrames(float elapsedSec)
{
	bool repeat{ true };

	if (m_ActionState == ActionState::state2 || m_IsDying)
	{
		repeat = false;
	}

	m_pBottomSprite->Update(elapsedSec, repeat);
}


void Soldier::Falling(float elasedSec, const Level* level)
{

	if (!level->IsOnGround(m_pBottomSprite->GetDstRect(), m_Velocity))
	{
		m_Velocity.y += m_Acceleration.y * elasedSec;
	}
}

void Soldier::DoWalkingState(float elapsedSec, Avatar* avatar)
{
	
	if (m_BotSpriteChanged)
	{
		m_pBottomSprite->UpdateValues(12, 1, 12, 10.f, 34.f, 40.f, 40.f);
		m_pBottomSprite->ResetActFrame();
		m_pBottomSprite->UpdateLeftSrcRect();
		m_BotSpriteChanged = false;

	}
	
	float avatarPos{ avatar->GetBotShape().left };
	float soldierPos{ m_pBottomSprite->GetDstRect().left };


	if (utils::GetDistanceX(avatarPos, soldierPos) <= m_RunAwayDist)
	{
		// Run Away
		m_ActionState = ActionState::state3;
	}
	else
	{
		if (utils::GetDistanceX(avatarPos, soldierPos) <= m_ThrowGrenadeDist)
		{
			// Throw Grenade
			m_ActionState = ActionState::state2;
			m_Velocity.x = 0.f;
		}
		else
		{
			m_ActionState = ActionState::state1;
		}
		
	}

	CheckFacingRight(avatar);

	if (m_FacingRight)
	{
		m_Velocity.x = m_Speed;
	}
	else
	{
		m_Velocity.x = -m_Speed;
	}
	
}

void Soldier::DoAttackState(float elapsedSec, Avatar* avatar)
{
	if (m_BotSpriteChanged)
	{
		m_pBottomSprite->UpdateValues(14, 1, 14, 15.f, 40.f, 46.f, 191.f);
		m_pBottomSprite->ResetActFrame();
		m_pBottomSprite->UpdateLeftSrcRect();
		m_BotSpriteChanged = false;
	}

	float avatarPos{ avatar->GetBotShape().left };
	float soldierPos{ m_pBottomSprite->GetDstRect().left };

	if (utils::GetDistanceX(avatarPos, soldierPos) <= m_RunAwayDist)
	{
		// Run Away
		m_ActionState = ActionState::state3;
	}
	else
	{
		if (utils::GetDistanceX(avatarPos, soldierPos) <= m_ThrowGrenadeDist)
		{
			// Throw Grenade
			m_ActionState = ActionState::state2;
			m_Velocity.x = 0.f;
		}
		else
		{
			// Follow player
			m_ActionState = ActionState::state1;
		}
	}
	
	CheckFacingRight(avatar);

}

void Soldier::DoRunAwayState(float elapsedSec, Avatar* avatar)
{
	if (m_BotSpriteChanged)
	{
		m_pBottomSprite->UpdateValues(12, 1, 12, 10.f, 40.f, 38.f, 288.f);
		m_pBottomSprite->ResetActFrame();
		m_pBottomSprite->UpdateLeftSrcRect();
		m_BotSpriteChanged = false;

	}

	m_Seconds += elapsedSec;

	float avatarPos{ avatar->GetBotShape().left };
	float soldierPos{ m_pBottomSprite->GetDstRect().left };

	if ( m_Seconds >= m_MaxTimeRunAway )
	{
		m_Seconds = 0.f;

		if (utils::GetDistanceX(avatarPos, soldierPos) <= m_RunAwayDist)
		{
			// Run Away
			m_ActionState = ActionState::state3;
		}
		else
		{
			if (utils::GetDistanceX(avatarPos, soldierPos) <= m_ThrowGrenadeDist)
			{
				// Throw Grenade
				m_ActionState = ActionState::state2;
				m_Velocity.x = 0.f;
			}
			else
			{
				m_ActionState = ActionState::state1;
			}
		}
	}
	


	CheckFacingRight(avatar);

	if (m_FacingRight)
	{
		m_Velocity.x = - m_RunSpeed;
	}
	else
	{
		m_Velocity.x = m_RunSpeed;
	}

}


void Soldier::Move(float elapsedSec)
{
	m_pBottomSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left + m_Velocity.x * elapsedSec);
	m_pBottomSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_Velocity.y * elapsedSec);
}


void Soldier::CheckFacingRight(Avatar* avatar)
{
	if (avatar->GetBotShape().left + avatar->GetBotShape().width 
		> m_pBottomSprite->GetDstRect().left + m_pBottomSprite->GetDstRect().width)
	{
		m_FacingRight = true;
	}
	else
	{
		m_FacingRight = false;
	}

}

void Soldier::Hit()
{
	m_Health--;

	if (m_Health == 0)
	{
		m_IsDying = true;
		m_Velocity.x = 0.f;
		m_pBottomSprite->UpdateValues(11, 1, 11, 5.f, 60.f, 44.f, 357.f);  // Change death animation
		m_pBottomSprite->ResetActFrame();
		m_pBottomSprite->UpdateLeftSrcRect();
		m_ActionState = ActionState::state4;  // Death state
	}

}


void Soldier::KillSoldier(float elapsedSec)
{
	m_pBottomSprite->Update(elapsedSec, false);

	if (m_pBottomSprite->GetAnimationFinish())
	{
		m_IsDead = true;

		m_pBottomSprite->ResetAnimationFinish(false);
		m_pBottomSprite->ResetActFrame();
		m_IsActive = false;

	}


}

void Soldier::CheckGameState()
{

}


void Soldier::Initialize()
{
	m_pBottomSprite = new Sprite("Resources/sprites/enemies/soldierv2.png");
	m_pBottomSprite->UpdateValues(12, 1, 12, 10.f, 34.f, 40.f, 40.f); // Walking Soldier
	m_pBottomSprite->SetLeftDstRect(m_StartPos.x);
	m_pBottomSprite->SetBottomDstRect(m_StartPos.y);
	m_pBottomSprite->UpdateLeftSrcRect();


	
}