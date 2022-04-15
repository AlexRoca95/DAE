#include "pch.h"
#include "Soldier.h"
#include "Level.h"
#include "Avatar.h"
#include <iostream>



Soldier::Soldier(const Point2f& startPos)
	:Enemy(GameObject::Type::soldier, startPos, 1, 150.f)
	, m_RunSpeed { 250.f }
	, m_FacingRight { false }
	, m_RunAwayDist { 200.f }
	, m_ThrowGrenadeDist { 300.f }
	, m_MaxTimeRunAway { 3.f }
	, m_Seconds { -1.f }
{
	Initialize();
}


Soldier::~Soldier()
{
	delete m_pBottomSprite;
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

}

void Soldier::Update(float elapsedSec, Avatar* avatar, const Level* level)
{
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

	}

	UpdateFrames(elapsedSec);
	Falling(elapsedSec, level);
	Move(elapsedSec);
	level->HandleCollision(m_pBottomSprite->GetDstRect(), m_Velocity);



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
		repeat = true;
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
	
	Point2f avatarPos{ avatar->GetBotShape().left, avatar->GetBotShape().bottom };
	Point2f soldierPos{ m_pBottomSprite->GetDstRect().left, m_pBottomSprite->GetDstRect().bottom };


	if (utils::GetDistance(avatarPos, soldierPos) <= m_RunAwayDist)
	{
		// Run Away
		m_ActionState = ActionState::state3;
	}
	else
	{
		if (utils::GetDistance(avatarPos, soldierPos) <= m_ThrowGrenadeDist)
		{
			// Throw Grenade
			m_ActionState = ActionState::state2;
			m_Velocity.x = 0.f;
		}
		else
		{
			// Keep walking forward
			m_Velocity.x = -m_Speed;
		}
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

	Point2f avatarPos{ avatar->GetBotShape().left, avatar->GetBotShape().bottom };
	Point2f soldierPos{ m_pBottomSprite->GetDstRect().left, m_pBottomSprite->GetDstRect().bottom };

	if (utils::GetDistance(avatarPos, soldierPos) <= m_RunAwayDist)
	{
		// Run Away
		m_ActionState = ActionState::state3;
	}
	else
	{
		if (utils::GetDistance(avatarPos, soldierPos) <= m_ThrowGrenadeDist)
		{
			// Throw Grenade
			m_ActionState = ActionState::state2;
			m_Velocity.x = 0.f;
		}
	}
	
	CheckFacingRight(avatar);

	//std::cout << m_MovingRight << std::endl;

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

	Point2f avatarPos{ avatar->GetBotShape().left, avatar->GetBotShape().bottom };
	Point2f soldierPos{ m_pBottomSprite->GetDstRect().left, m_pBottomSprite->GetDstRect().bottom };

	if (m_Seconds >= m_MaxTimeRunAway || m_Seconds < 0.f)
	{
		if (utils::GetDistance(avatarPos, soldierPos) <= m_RunAwayDist)
		{
			// Run Away
			m_ActionState = ActionState::state3;
		}
		else
		{
			if (utils::GetDistance(avatarPos, soldierPos) <= m_ThrowGrenadeDist)
			{
				// Throw Grenade
				m_ActionState = ActionState::state2;
				m_Velocity.x = 0.f;
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