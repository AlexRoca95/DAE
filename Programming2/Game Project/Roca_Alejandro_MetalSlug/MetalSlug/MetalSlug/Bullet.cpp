#include "pch.h"
#include "Bullet.h"
#include "Avatar.h"
#include <iostream>



Bullet::Bullet(const Point2f& startPos)
	: GameObject( GameObject::Type::Bullet )
	, m_Position{ startPos }
	, m_IsInitialized { false }
	, m_MaxSeconds{ 2.f }
	, m_Seconds { }
	, m_IsMovingUp{ }
	, m_Velocity{ }
	, m_Speed { 1000.f }
{
	Initialize();
}

Bullet::~Bullet()
{
	delete m_pBottomSprite;
}


void Bullet::Initialize()
{

	m_pBottomSprite = new Sprite( "Resources/sprites/marco/Projectiles.png" );
	m_pBottomSprite->UpdateValues(1, 1, 1, 15.f, 47.f, 47.f, 47.f, 0.8f);
	m_pBottomSprite->SetLeftDstRect( m_Position.x );
	m_pBottomSprite->SetBottomDstRect( m_Position.y );

	m_pBottomSprite->UpdateLeftSrcRect();


}

void Bullet::Draw() const
{
	if (m_IsActive)
	{
		m_pBottomSprite->Draw();
	}
	
}
void Bullet::Update(float elapsedSeconds, const Level* level)
{

}

void Bullet::Update(float elapsedSeconds, const Avatar* avatar)
{
	if (m_IsActive)
	{
		if (!m_IsInitialized)
		{
			SetStartPos(avatar);
		}

		Move(elapsedSeconds);
		
		m_Seconds += elapsedSeconds;

		if (m_Seconds >= m_MaxSeconds)
		{
			DesactivateBullet();
		}
	}
}


// Change the Bullet pos to the correct start position according with the pos of the Avatar
void Bullet::SetStartPos( const Avatar* avatar )
{
	Point2f startPos{ };

	switch (avatar->GetActiveAnimation())
	{
		case Avatar::Animations::shooting:  // Pointing Horizontally
			
			m_pBottomSprite->SetSrcRect(47.f);  // Change Bullet sprite
			m_IsMovingUp = false;

			startPos.y = ( avatar->GetTopShape().bottom + avatar->GetTopShape().height/2 ) 
				- m_pBottomSprite->GetFrameHeight()/3;

			if (avatar->GetIsMovingRight())
			{
				startPos.x = ( avatar->GetTopShape().left + avatar->GetTopShape().width ) 
					- m_pBottomSprite->GetFrameWidth() / 3;

				m_Velocity.x = m_Speed;
			}
			else
			{
				startPos.x = avatar->GetTopShape().left - avatar->GetTopShape().width
					+ m_pBottomSprite->GetFrameWidth() / 3;

				m_Velocity.x = - m_Speed;
			}

		break;

		case Avatar::Animations::shootingUp:  // Pointing Vertically

			m_pBottomSprite->SetSrcRect(94.f);  // Change Bullet sprite
			m_IsMovingUp = true;
			m_Velocity.y = m_Speed;

			startPos.y = (avatar->GetTopShape().bottom + avatar->GetTopShape().height)
				- m_pBottomSprite->GetFrameHeight() / 3;

			if (avatar->GetIsMovingRight())
			{
				startPos.x = (avatar->GetTopShape().left + avatar->GetTopShape().width / 2)
					- m_pBottomSprite->GetFrameWidth() / 2;
			}
			else
			{
				startPos.x = avatar->GetTopShape().left;
			}

		break;
	}

	// Position from the bullet start moving
	m_Position = startPos;
	m_IsInitialized = true;

	m_pBottomSprite->SetLeftDstRect(startPos.x);
	m_pBottomSprite->SetBottomDstRect(startPos.y);
	
}

void Bullet::Move( float elapsedSec )
{
	if (m_IsMovingUp)
	{
		// Move Verti
		m_Position.y += m_Velocity.y * elapsedSec;
		m_pBottomSprite->SetBottomDstRect(m_Position.y);
	}
	else
	{
		// Move Horiz
		m_Position.x += m_Velocity.x * elapsedSec;
		m_pBottomSprite->SetLeftDstRect(m_Position.x);
	}
}


void Bullet::DesactivateBullet()
{
	m_IsActive = false;
	m_IsInitialized = false;
	m_Seconds = 0.f;
	m_Velocity = Point2f{ 0.f, 0.f };
}

void Bullet::SetIsActive(bool active)
{
	m_IsActive = active;
}

bool Bullet::GetIsActive() const
{
	return m_IsActive;
}


