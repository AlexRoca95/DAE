#include "pch.h"
#include "Boss.h"
#include <iostream>



Boss::Boss(const Point2f& startPos, bool comingFromRight, SoundManager* sounds)
	:Enemy(GameObject::Type::boss, startPos, 1, Point2f{ },
		comingFromRight, Point2f{ 0.f, g_Gravity }, sounds)
	, m_FightState { State::sleeping }
	, m_PreviousState { State::sleeping }
	, m_Seconds { }
	, m_NrOfShots { }
	, m_NrOfChargings { }
{

	Initialize();
}


void Boss::Initialize()
{

	m_pBottomSprite = new Sprite("Resources/sprites/enemies/Boss/boss.png");
	//
	//
	//
	//
	m_pBottomSprite->UpdateValues(1, 1, 1, 20.f, 90.f, 70.f, 210.f);  // Iddle
	m_pBottomSprite->SetLeftDstRect(m_StartPosition.x);
	m_pBottomSprite->SetBottomDstRect(m_StartPosition.y);
	m_pBottomSprite->UpdateLeftSrcRect();

	/*
	m_pTopSprite = new Sprite("Resources/sprites/enemies/Boss/projectiles.png");
	//m_pTopSprite->UpdateValues(3, 1, 3, 8.f, 10.f, 10.f, 20.f);     // Flying bullet
	//m_pTopSprite->UpdateValues(4, 1, 4, 10.f, 80.f, 26.f, 50.f);  // Ground bullet
	m_pTopSprite->SetLeftDstRect(m_StartPosition.x);
	m_pTopSprite->SetBottomDstRect(m_StartPosition.y);
	m_pTopSprite->UpdateLeftSrcRect();
	*/
	m_pTopSprite = new Sprite("Resources/sprites/enemies/Boss/Cloth.png");
	m_pTopSprite->UpdateValues(1, 1, 1, 10.f, 120.f, 93.f, 108.f);  // Cloth iddle
	//m_pTopSprite->UpdateValues(15, 1, 15, 7.f, 120.f, 103.f, 230.f);  // Cloth flying away
	m_pTopSprite->SetLeftDstRect(m_StartPosition.x + 120.f);
	m_pTopSprite->SetBottomDstRect(m_StartPosition.y - 30.f);
	m_pTopSprite->UpdateLeftSrcRect();

}

Boss::~Boss()
{
	delete m_pBottomSprite;
	delete m_pTopSprite;
}


 void Boss::Draw() const
{
	 m_pBottomSprite->Draw();

	 if (m_FightState == State::sleeping || m_FightState == State::starting)
	 {
		 m_pTopSprite->Draw();
	 }
	

	 switch (m_FightState)
	 {
	 case Boss::State::starting:
		
		 break;
	 case Boss::State::firingUp:
		 break;
	 case Boss::State::waiting:
		 break;
	 case Boss::State::firingBot:
		 break;

	 }
	
}


void Boss::Hit()
{
	
	m_pTopSprite->UpdateValues(15, 1, 15, 7.f, 120.f, 103.f, 230.f);  // Cloth flying away
	m_pTopSprite->UpdateLeftSrcRect();

	if (m_FightState == State::sleeping)
	{
		// Start fight if it hasn't started yet
		m_FightState = State::starting;
		m_PreviousState = State::sleeping;
	}
	
}

void Boss::CheckGameState()
{

}

void Boss::Update(float elapsedSec, Avatar* avatar, const Level* level)
{
	switch (m_FightState)
	{
	case Boss::State::starting:   // Boss starting fight 
		StartFight(elapsedSec);
		break;
	case Boss::State::firingUp:
		FiringUp(elapsedSec);
		break;
	case Boss::State::waiting:
		Waiting(elapsedSec);
		break;
	case Boss::State::chargingShot:
		ChargingShot(elapsedSec);
		break;
	case Boss::State::firingBot:
		FiringBot(elapsedSec);
		break;
	}


}

void Boss::StartFight(float elapsedSec)
{
	m_pTopSprite->Update(elapsedSec, false);

	if (m_pTopSprite->GetAnimationFinish())
	{
		m_pTopSprite->SetLeftDstRect(m_pTopSprite->GetDstRect().left + 150.f * elapsedSec);

		m_Seconds += elapsedSec;

		if (m_Seconds >= 2.f)
		{
			m_FightState = State::firingUp;
			m_PreviousState = State::starting;
			m_Seconds = 0.f;
		}
	}
}

void Boss::FiringUp(float elapsedSec)
{

	if (m_PreviousState == State::waiting || m_PreviousState == State::starting)
	{
		m_pBottomSprite->ResetSprite();
		m_pBottomSprite->UpdateValues(24, 1, 24, 11.f, 90.f, 70.f, 70.f);   // Firing up

		m_PreviousState = State::firingUp;
	}


	m_pBottomSprite->Update(elapsedSec, false);

	if ( m_pBottomSprite->GetAnimationFinish() )
	{
		m_NrOfShots++;		 // One shot done

		m_FightState = State::waiting;
		m_PreviousState = State::firingUp;
		
	}
}

void Boss::Waiting(float elapsedSec)
{
	if (m_PreviousState == State::firingUp)
	{
		m_pBottomSprite->ResetSprite();
		m_pBottomSprite->UpdateValues(9, 1, 9, 11.f, 90.f, 70.f, 140.f);   // Going back firing up
		m_PreviousState = State::waiting;
	}
	else
	{
		if (m_PreviousState == State::firingBot)
		{
			m_pBottomSprite->ResetSprite();
			m_pBottomSprite->UpdateValues(1, 1, 1, 20.f, 90.f, 70.f, 210.f);  // Iddle
			m_PreviousState = State::waiting;
		}
	}
	
	m_pBottomSprite->Update(elapsedSec, false);


	if (m_pBottomSprite->GetAnimationFinish())
	{
		if (m_NrOfShots >= 3)
		{
			// Change to firing Bottom
			m_FightState = State::chargingShot;
			m_PreviousState = State::waiting;
			m_NrOfShots = 0;
		}
		else
		{
			// Change to firing Up
			m_FightState = State::firingUp;
			m_PreviousState = State::waiting;
		}

	
	}

	
}

void Boss::ChargingShot(float elapsedSec)
{
	if (m_PreviousState == State::waiting)
	{
		m_pBottomSprite->ResetSprite();
		m_pBottomSprite->UpdateValues(3, 1, 3, 20.f, 90.f, 70.f, 350.f);	// Charging shot

		m_PreviousState = State::chargingShot;
	}

	m_pBottomSprite->Update(elapsedSec, false);

	if (m_pBottomSprite->GetAnimationFinish())
	{
		m_NrOfChargings++;

		if (m_NrOfChargings >= 10)
		{
			// Fire Bullet
			m_NrOfChargings = 0;
			m_FightState = State::firingBot;
			m_PreviousState = State::chargingShot;
		}

		m_pBottomSprite->ResetSprite();
	}

}

void Boss::FiringBot(float elapsedSec)
{
	if (m_PreviousState == State::chargingShot)
	{
		m_pBottomSprite->ResetSprite();
		m_pBottomSprite->UpdateValues(11, 1, 11, 10.f, 90.f, 70.f, 280.f);  // Firing Bot

		m_PreviousState = State::firingBot;
	}

	m_pBottomSprite->Update(elapsedSec, false);

	if (m_pBottomSprite->GetAnimationFinish())
	{
		m_FightState = State::waiting;
		m_PreviousState = State::firingBot;
	}

}

Point2f Boss::GetStartPos() const
{
	return m_StartPosition;
}
