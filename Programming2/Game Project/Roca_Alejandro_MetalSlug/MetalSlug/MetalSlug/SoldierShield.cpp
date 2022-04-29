#include "pch.h"
#include "SoldierShield.h"
#include "Shield.h"
#include "Level.h"
#include "Avatar.h"



SoldierShield::SoldierShield(const Point2f& startPos, bool comingFromRight)
	:Enemy(GameObject::Type::soldierShield, startPos, 5, Point2f{ 150.f, 0.f },
		comingFromRight, Point2f{ 0.f, g_Gravity })   // Type, starting position, health, speed and accelerat
	, m_IsShieldOn { true }
	, m_IsFacingRight { false }
	, m_pShield {}
	, m_MaxTimeDeath{ 2.f }
	, m_SecondsDeath{ 0.f }
	, m_RunSpeed { 200.f }
	, m_AttackDist { 60.f }
	, m_IsAttackStarted { false }
{


	Initialize();

}


SoldierShield::~SoldierShield()
{
	delete m_pBottomSprite;

	if (m_pShield != nullptr)
	{
		delete m_pShield;
	}
}



void SoldierShield::Initialize()
{
	
	m_pBottomSprite = new Sprite("Resources/sprites/enemies/soldierShield.png");
	m_pBottomSprite->UpdateValues(12, 1, 12, 15.f, 35.f, 41.f, 100.f); // Soldier with shield running
	//m_pBottomSprite->UpdateValues(15, 1, 15, 15.f, 44.f, 37.f, 482.f);
	//m_pBottomSprite->UpdateValues(6, 1, 6, 8.f, 34.6f, 40.f, 40.f); // Soldier with shield Iddle

	//m_pBottomSprite->UpdateValues(12, 1, 12, 15.f, 58.f, 37.f, 482.f);  // Attacking without shield
	//m_pBottomSprite->UpdateValues(12, 1, 12, 15.f, 58.f, 37.f, 540.f);  // Attacking without shield pt 2
	m_pBottomSprite->SetLeftDstRect(m_StartPosition.x);
	m_pBottomSprite->SetBottomDstRect(m_StartPosition.y);
	m_pBottomSprite->UpdateLeftSrcRect();


	//m_pBottomSprite->UpdateValues(12, 1, 12, 15.f, 35.f, 41.f, 100.f); // Soldier with shield running

	//m_pBottomSprite->UpdateValues(8, 1, 8, 10.f, 34.f, 38.f, 38.f);  // Flying shield
	//m_pBottomSprite->UpdateValues(8, 1, 8, 15.f, 54.f, 48.f, 156.f); // Soldier with shield atacking
	//m_pBottomSprite->UpdateValues(8, 1, 8, 15.f, 54.f, 48.f, 210.f); // Soldier with shield atacking pt 2
	//m_pBottomSprite->UpdateValues(9, 1, 9, 10.f, 54.f, 48.f, 204.f); // Soldier with shield atacking back


}
void SoldierShield::Draw() const
{
	if (!m_IsShieldOn)
	{
		// Draw shield flying away
		m_pShield->Draw();
	}


	m_pBottomSprite->Draw();

}


void SoldierShield::Update(float elapsedSec, Avatar* avatar, const Level* level)
{
	CheckPreviousAction();

	if (!m_IsDying)
	{
		// Soldier is not dying
		switch (m_ActionState)
		{
		case Enemy::ActionState::state1:   // Run towards avatar
			DoRunningState( elapsedSec, avatar->GetBotShape() );
			break;
		case Enemy::ActionState::state2:  // Attack
			DoAttackState(elapsedSec, avatar->GetBotShape());
			break;
		case Enemy::ActionState::state3:
			break;
		}


		
	}
	else
	{
		// Soldier is dead
		KillSoldier(elapsedSec);
	}


	if (!m_IsShieldOn)
	{
		// Shield flying away
		m_pShield->Update(elapsedSec, level);
	}
	
	UpdateFrames(elapsedSec);
	Falling(elapsedSec, level);
	Move(elapsedSec);
	level->HandleCollision(m_pBottomSprite->GetDstRect(), m_Velocity);
	
}

void SoldierShield::Move(float elapsedSec)
{
	m_pBottomSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left + m_Velocity.x * elapsedSec);
	m_pBottomSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_Velocity.y * elapsedSec);

}

// Run towards the avatar
void SoldierShield::DoRunningState(float elapsedSec, const Rectf& avatarShape)
{
	if (m_BotSpriteChanged)
	{
		if (m_IsShieldOn)
		{
			ChangeSprite(12, 1, 12, 15.f, 35.f, 41.f, 100.f); // Soldier with shield running;
		}
		else
		{
			ChangeSprite(12, 1, 12, 10.f, 34.f, 40.f, 368.f);  // Soldier without sield running
		}
		
	}

	CheckDistanceAvatar(avatarShape);

	CheckFacingRight(avatarShape);

	// Move in the direction of the avatar
	if (m_IsFacingRight)
	{
		m_Velocity.x = m_RunSpeed;
	}
	else
	{
		m_Velocity.x = -m_RunSpeed;
	}


}

void SoldierShield::DoAttackState(float elapsedSec, const Rectf& avatarShape)
{
	if (m_BotSpriteChanged)
	{
		m_Velocity.x = 0.f;
		
		// Start attack animation
		if (m_IsShieldOn)
		{
			ChangeSprite(8, 1, 8, 15.f, 54.f, 48.f, 156.f); // Soldier attack with shield
			m_IsAttackStarted = true;
		}
		else
		{
			ChangeSprite(12, 1, 12, 15.f, 58.f, 37.f, 482.f);  // Soldier without sield attacking
			m_IsAttackStarted = true;
		}
	}
	else
	{
		//if (m_IsAttackStarted && m_pBottomSprite->GetAnimationFinish())
	}

	if (m_IsAttackStarted && m_pBottomSprite->GetAnimationFinish())
	{
		// Finish the attack animation
		m_IsAttackStarted = false;
		if (m_IsShieldOn)
		{
			ChangeSprite(8, 1, 8, 15.f, 54.f, 48.f, 210.f); // Soldier attack with shield pt2
			
		}
		else
		{
			ChangeSprite(11, 1, 11, 15.f, 58.f, 37.f, 540.f);  // Soldier without sield attacking pt2
			
		}

	}
	
}


void  SoldierShield::UpdateFrames(float elapsedSec)
{
	bool repeat{ true };

	if (m_ActionState == ActionState::state2 || m_IsDying)
	{
		// No loop animation for this actions
		repeat = false;
	}

	m_pBottomSprite->Update(elapsedSec, repeat);
}


// Check into which direction is the soldier loocking
void SoldierShield::CheckFacingRight(const Rectf& avatarShape)
{
	if ( avatarShape.left + avatarShape.width  >
		m_pBottomSprite->GetDstRect().left + m_pBottomSprite->GetDstRect().width)
	{
		m_IsFacingRight = true;
	}
	else
	{
		m_IsFacingRight = false;
	}




}

// Check distance between soldier and avatar and change action according to this
void SoldierShield::CheckDistanceAvatar(const Rectf& avatarShape)
{
	float avatarPos{ avatarShape.left };
	float soldierPos{ m_pBottomSprite->GetDstRect().left };

	if ( utils::GetDistanceX(avatarPos, soldierPos) <= m_AttackDist )
	{
		// Attack state
		m_ActionState = ActionState::state2;
	}
	else
	{
		// Keep running towards the avatar
		m_ActionState = ActionState::state1;
		
	}
}

// Check if soldier changed action in order to reset sprite correctly
void SoldierShield::CheckPreviousAction()
{
	if (m_ActionState != m_PreviousAction)
	{
		m_PreviousAction = m_ActionState;
		m_BotSpriteChanged = true;
	}
}

void SoldierShield::Hit()
{
	m_Health--;

	if (m_Health == 0)
	{
		if (m_IsShieldOn)
		{
			// Soldier looses his shield ( Check to which sprite to change )

			switch (m_ActionState)
			{
			case Enemy::ActionState::state1:
				ChangeSprite(12, 1, 12, 10.f, 34.f, 40.f, 368.f);  // Soldier without sield running
				break;
			case Enemy::ActionState::state2:
				ChangeSprite(12, 1, 12, 15.f, 58.f, 37.f, 482.f);  // Soldier without sield attacking
				break;
			}
			
			m_pBottomSprite->ResetSprite();
			InitShield();

			m_Health = 1;   // Soldier life without shield
		}
		else
		{
			// Soldier is dead 
			m_IsDying = true;
			m_Velocity.x = 0.f;
			m_pBottomSprite->UpdateValues(11, 1, 11, 8.f, 60.f, 44.f, 425.f);  // Change death animation
			m_pBottomSprite->ResetSprite();
			
		}


		
	
	}

}


void SoldierShield::KillSoldier(float elapsedSec)
{
	m_pBottomSprite->Update(elapsedSec, false);

	if (m_pBottomSprite->GetAnimationFinish())
	{
		m_SecondsDeath += elapsedSec;

		if (m_SecondsDeath >= m_MaxTimeDeath)
		{
			m_IsDead = true;
			m_pBottomSprite->ResetSprite();
			m_IsActive = false;
			m_SecondsDeath = 0.f;
		}
	}
}


// Create a flying shield and place it in the correct pos
void SoldierShield::InitShield()
{

	float xPos{};

	if (m_IsFacingRight)
	{

		xPos = m_pBottomSprite->GetDstRect().left + m_pBottomSprite->GetDstRect().width / 2;
	}
	else
	{
		xPos = m_pBottomSprite->GetDstRect().left - m_pBottomSprite->GetDstRect().width / 2;
	}

	Point2f startPos{ xPos, m_pBottomSprite->GetDstRect().bottom };
	m_pShield = new Shield(startPos);

	// Soldier doesn't have the shield anymore
	m_IsShieldOn = false;
}


void SoldierShield::CheckGameState()
{

}
