#include "pch.h"
#include "Boss.h"
#include "BossBullet.h"
#include <iostream>



Boss::Boss(const Point2f& startPos, bool comingFromRight, SoundManager* soundManager)
	:Enemy(GameObject::Type::boss, startPos, 1, Point2f{ },
		comingFromRight, Point2f{ 0.f, g_Gravity }, soundManager)
	, m_FightState { State::sleeping }
	, m_PreviousState { State::sleeping }
	, m_Seconds { }
	, m_NrOfShots { }
	, m_NrOfChargings { }
	, m_pWaterBullet2{ new BossBullet(false, Point2f{ startPos.x - 40.f, startPos.y + 40.f }, soundManager) }
	, m_pAirBullets2{ }
	, m_pWaterBullet { }
	, m_FireBottom { false }
	, m_BulletBotPos{  }
	, m_BulletAirPos{ startPos.x + 130.f, startPos.y + 130.f }
	, m_WaterBulletSpeed { 350.f }
	, m_BulletAirSpeed{ 200.f, 500.f }
	, m_CloathSpeed { 150.f }
	, m_pAirBullets { }
	, m_AirSeconds{ }
{

	Initialize();
}


void Boss::Initialize()
{
	m_Velocity.y = 1500.f;
	// BOSS
	m_pBottomSprite = new Sprite("Resources/sprites/enemies/Boss/boss.png");
	m_pBottomSprite->UpdateValues(1, 1, 1, 20.f, 90.f, 70.f, 210.f);  // Iddle
	m_pBottomSprite->SetLeftDstRect(m_StartPosition.x);
	m_pBottomSprite->SetBottomDstRect(m_StartPosition.y);
	m_pBottomSprite->UpdateLeftSrcRect();

	// Water Bullet
	m_pWaterBullet = new Sprite("Resources/sprites/enemies/Boss/projectiles.png");

	//m_pBullet->UpdateValues(4, 1, 4, 10.f, 80.f, 26.f, 50.f);  // Ground bullet
	m_pWaterBullet->SetLeftDstRect(m_BulletBotPos.x);
	m_pWaterBullet->SetBottomDstRect(m_BulletBotPos.y);
	m_pWaterBullet->UpdateLeftSrcRect();
	
	// Air Bullets
	for (int i{}; i < 3; i++)
	{
		m_pAirBullets.push_back(std::make_pair(new Sprite("Resources/sprites/enemies/Boss/projectiles.png"), false));
		m_pAirBullets.at(i).first->SetLeftDstRect(m_BulletAirPos.x);
		m_pAirBullets.at(i).first->SetBottomDstRect(m_BulletAirPos.y);
		m_AirSeconds.push_back(0.f);
	}

	// CLOTH
	m_pTopSprite = new Sprite("Resources/sprites/enemies/Boss/Cloth.png");
	m_pTopSprite->UpdateValues(1, 1, 1, 10.f, 120.f, 93.f, 108.f);  // Cloth iddle
	m_pTopSprite->SetLeftDstRect(m_StartPosition.x + 120.f);
	m_pTopSprite->SetBottomDstRect(m_StartPosition.y - 30.f);
	m_pTopSprite->UpdateLeftSrcRect();

}

Boss::~Boss()
{
	delete m_pBottomSprite;
	delete m_pTopSprite;
	delete m_pWaterBullet;
	delete m_pWaterBullet2;

	for (std::pair<Sprite*, bool> spr : m_pAirBullets)
	{
		delete spr.first;
	}
}


 void Boss::Draw() const
{
	 m_pBottomSprite->Draw();

	 if (m_FightState == State::sleeping || m_FightState == State::starting)
	 {
		 m_pTopSprite->Draw();
	 }

	 if (m_FireBottom)
	 {
		 m_pWaterBullet->Draw();
	 }

	 for (std::pair<Sprite*, bool> spr : m_pAirBullets)
	 {
		 if (spr.second == true)
		 {
			 spr.first->Draw();
		 }
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


	if (m_FireBottom)
	{
		// Fire Bottom Bullet
		m_pWaterBullet->UpdateValues(4, 1, 4, 10.f, 80.f, 26.f, 50.f);
		m_pWaterBullet->Update(elapsedSec, true);
		m_Seconds += elapsedSec;

		if (m_Seconds >= 2.5f)
		{
			m_FireBottom = false;
			m_Seconds = 0;
			m_pWaterBullet->SetLeftDstRect(m_BulletBotPos.x);
		}
		else
		{
			m_pWaterBullet->SetLeftDstRect(m_pWaterBullet->GetDstRect().left - (m_WaterBulletSpeed * elapsedSec));
		}
		
	}

	for (int i{}; i < m_pAirBullets.size(); i++)
	{
		if (m_pAirBullets.at(i).second == true)
		{
			// Fire air bullet
			m_pAirBullets.at(i).first->UpdateValues(3, 1, 3, 8.f, 10.f, 10.f, 20.f);     // Flying bullet
			m_pAirBullets.at(i).first->Update(elapsedSec, true);
			m_AirSeconds.at(i) += elapsedSec;

			if (m_AirSeconds.at(i) >= 2.5f)
			{
				m_AirSeconds.at(i) = 0;
				m_pAirBullets.at(i).second = false;
				m_pAirBullets.at(i).first->SetLeftDstRect(m_BulletAirPos.x);
				m_pAirBullets.at(i).first->SetBottomDstRect(m_BulletAirPos.y);
			}
			else
			{
				m_Velocity.y += m_Acceleration.y * elapsedSec;
				m_pAirBullets.at(i).first->SetBottomDstRect(m_pAirBullets.at(i).first->GetDstRect().bottom + (m_Velocity.y * elapsedSec));
				m_pAirBullets.at(i).first->SetLeftDstRect(m_pAirBullets.at(i).first->GetDstRect().left - (m_BulletAirSpeed.x * elapsedSec));
			}
		}
	}

}

void Boss::StartFight(float elapsedSec)
{
	m_pTopSprite->Update(elapsedSec, false);

	if (m_pTopSprite->GetAnimationFinish())
	{
		m_pTopSprite->SetLeftDstRect(m_pTopSprite->GetDstRect().left + m_CloathSpeed * elapsedSec);

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
	//std::cout << m_pBottomSprite->GetActFrame() << std::endl;

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
	else
	{
		if (m_pBottomSprite->GetActFrame() == 10 || m_pBottomSprite->GetActFrame() == 15 ||
			m_pBottomSprite->GetActFrame() == 20 )
		{
			
			for (std::pair<Sprite*, bool>& spr : m_pAirBullets)
			{
				if (!spr.second)
				{
					spr.second = true;
					break;
				}
				
			}
		}
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
		m_FireBottom = true;

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
