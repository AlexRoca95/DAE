#include "pch.h"
#include "Bullet.h"
#include "Avatar.h"
#include <iostream>



Bullet::Bullet(const Point2f& startPos)
	: Projectile( GameObject::Type::bullet, 1000.f )
{
	Initialize();
}

Bullet::~Bullet()
{
	delete m_pBottomSprite;
	delete m_pTopSprite;
}


void Bullet::Initialize()
{
	// Bullet sprite
	m_pTopSprite = new Sprite( "Resources/sprites/marco/Projectiles2.png" );
	m_pTopSprite->UpdateValues(1, 1, 1, 15.f, 11.f, 7.f, 7.f, 2.7f);
	m_pTopSprite->SetLeftDstRect( m_Position.x );
	m_pTopSprite->SetBottomDstRect( m_Position.y );

	m_pTopSprite->UpdateLeftSrcRect();

	// Explosion sprite
	m_pBottomSprite = new Sprite("Resources/sprites/marco/pistolHit.png");
	m_pBottomSprite->UpdateValues(10, 1, 10, 25.f, 23.f, 28.f, 28.f, 2.7f);
	m_pBottomSprite->SetLeftDstRect(m_Position.x);
	m_pBottomSprite->SetBottomDstRect(m_Position.y);

	m_pBottomSprite->UpdateLeftSrcRect();


}



void Bullet::Update(float elapsedSeconds, const Avatar* avatar)
{
	
	if(!m_IsHit)
	{
		if (!m_IsInitialized)
		{
			SetStartPos(avatar);
		}

		Move(elapsedSeconds);

		m_Seconds += elapsedSeconds;

		if (m_Seconds >= m_MaxSeconds)
		{
			DesactivateProjectile();
		}
	}
	else
	{
		m_pBottomSprite->Update(elapsedSeconds, false);

		if (m_pBottomSprite->GetAnimationFinish())
		{
			m_pBottomSprite->ResetAnimationFinish(false);
			m_pBottomSprite->ResetActFrame();
			DesactivateProjectile();
		}
	}

}


// Change the Bullet pos to the correct start position according with the pos of the Avatar
void Bullet::SetStartPos( const Avatar* avatar )
{
	Point2f startPos{ };

	switch ( avatar->GetActiveAnimation() )
	{
		case Avatar::Animations::shooting:  // Pointing Horizontally
			
			m_pTopSprite->SetSrcRect(7.f, 11.f, 7.f);  // Change Bullet sprite
			m_pTopSprite->SetDstRect(11.f, 7.f);
			m_IsMovingUp = false;

			startPos.y = ( avatar->GetTopShape().bottom + avatar->GetTopShape().height/2 ) 
				- m_pTopSprite->GetFrameHeight()/3;

			if (avatar->GetIsMovingRight())
			{
				startPos.x = ( avatar->GetTopShape().left + avatar->GetTopShape().width ) 
					- m_pTopSprite->GetFrameWidth() * 2;

				m_Velocity.x = m_Speed;
			}
			else
			{
				startPos.x = avatar->GetTopShape().left - avatar->GetTopShape().width
					+ m_pTopSprite->GetFrameWidth() * 5;

				m_Velocity.x = - m_Speed;
			}

		break;

		case Avatar::Animations::shootingUp:  // Pointing Vertically

			m_pTopSprite->SetSrcRect( 18.f, 7.f, 11.f);  // Change Bullet sprite
			m_pTopSprite->SetDstRect(7.f, 11.f);
			m_IsMovingUp = true;
			m_Velocity.y = m_Speed;

			startPos.y = (avatar->GetTopShape().bottom + avatar->GetTopShape().height)
				- m_pTopSprite->GetFrameHeight();

			if (avatar->GetIsMovingRight())
			{
				startPos.x = (avatar->GetTopShape().left + avatar->GetTopShape().width / 2)
					- m_pTopSprite->GetFrameWidth() * 2;
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

	m_pTopSprite->SetLeftDstRect(startPos.x);
	m_pTopSprite->SetBottomDstRect(startPos.y);
	
}

void Bullet::Move( float elapsedSec )
{
	if (m_IsMovingUp)
	{
		// Move Verti
		m_Position.y += m_Velocity.y * elapsedSec;
		m_pTopSprite->SetBottomDstRect(m_Position.y);
	}
	else
	{
		// Move Horiz
		m_Position.x += m_Velocity.x * elapsedSec;
		m_pTopSprite->SetLeftDstRect(m_Position.x);
	}
}



