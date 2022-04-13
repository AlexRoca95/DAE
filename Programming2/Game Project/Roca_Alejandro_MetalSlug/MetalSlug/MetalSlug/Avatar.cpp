#include "pch.h"
#include "Avatar.h"
#include "Texture.h"
#include "Level.h"
#include "BulletManager.h"
#include <iostream>

int Avatar::m_GameObjectCounter = 0;

Avatar::Avatar()
	: GameObject( GameObject::Type::avatar )
	, m_Velocity{ Point2f{ 0.f, 0.f } }
	, m_Acceleration{ Point2f{ 0.f, -981.f } }
	, m_NormalSpeed{ 300.f }
	, m_SlowSpeed{ 80.f }
	, m_JumpSpeed{ 500.f }
	, m_IsMovingRight{ true }
	, m_StartPosition{ 80.f, 300.f }
	, m_TopActionState{ TopActionState::jumping }
	, m_BotActionState{ BotActionState::jumping }
	, m_ActTopAnimation{ Animations::jumping }
	, m_ActBotAnimation{ Animations::jumping }
	, m_PrevTopAnimation{ m_ActTopAnimation }
	, m_PrevBotAnimation{ m_ActBotAnimation }
	, m_TopSpriteChanged{ }
	, m_BotSpriteChanged{ }
	, m_IsOnGround{ }
	, m_Offset{ }
	, m_IsShooting{ false }
	, m_IsMoving{ false }
	, m_pBulletManager{ new BulletManager }
	, m_NrOfBullets { 20 }
{
	m_GameObjectCounter++;

	Initialize();
	
}

Avatar::~Avatar()
{
	m_GameObjectCounter--;

	delete m_pBottomSprite;
	delete m_pTopSprite;
	delete m_pBulletManager;
}


void Avatar::Initialize()
{
	// Marco Body (Iddle)
	m_pTopSprite = new Sprite("Resources/sprites/marco/MarcoBody.png");
	m_pTopSprite->UpdateValues(4, 1, 4, 7.f, 33.f, 29.f, 29.f);
	m_pTopSprite->SetLeftDstRect(m_StartPosition.x);
	m_pTopSprite->SetBottomDstRect(m_StartPosition.y);
	
	m_pTopSprite->UpdateLeftSrcRect();

	// Marco Legs (Iddle)
	m_pBottomSprite = new Sprite("Resources/sprites/marco/MarcoLegs.png");
	m_pBottomSprite->UpdateValues(1, 1, 1, 15.f, 25.f, 15.f, 15.f);
	m_pBottomSprite->SetLeftDstRect(m_pTopSprite->GetDstRect().left);
	m_pBottomSprite->SetBottomDstRect(m_pTopSprite->GetDstRect().bottom - m_pBottomSprite->GetFrameHeight() );

	m_pBottomSprite->UpdateLeftSrcRect();

	InitBulletManager();

}

void Avatar::InitBulletManager()
{

	Point2f startPos{ m_pBottomSprite->GetDstRect().left , m_pBottomSprite->GetDstRect().bottom };

	for (int i{ }; i < m_NrOfBullets; i++)
	{
		m_pBulletManager->AddBullet(startPos);
	}

}


void Avatar::Draw() const
{
	if (!m_IsMovingRight)
	{
		// Moving left --> Flip sprite to the left
		glPushMatrix();

			glTranslatef( m_pBottomSprite->GetDstRect().left + m_pBottomSprite->GetFrameWidth() / 2, 
				m_pBottomSprite->GetDstRect().bottom + m_pBottomSprite->GetFrameHeight() / 2 / 2, 0.f );

			glScalef( -1, 1, 1.f );

			glTranslatef( -( m_pBottomSprite->GetDstRect().left + m_pBottomSprite->GetFrameWidth() / 2 ),
				- ( m_pBottomSprite->GetDstRect().bottom + m_pBottomSprite->GetFrameHeight() / 2 ), 0.f );
	
			DrawAvatar();

		glPopMatrix();
	}
	else
	{
		DrawAvatar();
	}

	m_pBulletManager->Draw();
	
}



// Draw only one sprite if ActionState is crawling. Draw two otherwise
void Avatar::DrawAvatar() const
{
	
	if ( m_TopActionState != TopActionState::crawling )
	{
		// Not Crawling --> Draw both parts of the sprite
		m_pBottomSprite->Draw();
		m_pTopSprite->Draw();

	}
	else
	{
		// Crawling --> Draw only the bottom sprite
		m_pBottomSprite->Draw();
	}
	
}

void Avatar::Update( float elapsedSeconds, const Level* level )
{

	HandleInput();

	UpdateFrames(elapsedSeconds);
	
	UpdateTopSrcRect();
	UpdateBotSrcRect();


	if ( !level->IsOnGround( m_pBottomSprite->GetDstRect(), m_Velocity ) )
	{
		AvatarFalling( elapsedSeconds );
		m_IsOnGround = false;
	}
	else
	{
		m_IsOnGround = true;
	}

	Move (elapsedSeconds );
	level->HandleCollision( m_pBottomSprite->GetDstRect(), m_Velocity );

	if ( m_Velocity.x == 0 )
	{
		m_IsMoving = false;
	}

	m_pBulletManager->Update(elapsedSeconds, this);

}

// Update the Source Rectangle of the Top Sprite
void Avatar::UpdateTopSrcRect()
{
	m_Offset = 0;

	switch ( m_TopActionState )
	{
	case Avatar::TopActionState::iddle:
		
		if ( m_IsMoving )
		{
			// Marco Body (Moving)
			m_pTopSprite->UpdateValues( 12, 1, 12, 20.f, 40.f, 29.f, 87.f );
			m_Offset = 10;
		}
		else
		{
			
			// Marco Body (Iddle)
			m_pTopSprite->UpdateValues( 3, 1, 3, 5.f, 33.f, 29.f, 29.f );
			m_pTopSprite->SetLeftDstRect( m_pBottomSprite->GetDstRect().left );
			m_Offset = 7;
			

			
		}

		break;

	case Avatar::TopActionState::jumping:

		// Marco Body (JUMPING)
		m_pTopSprite->UpdateValues(5, 1, 5, 11.f, 32.f, 25.f, 54.f);
		m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left - 18);
		m_Offset = 35;
		break;

	case Avatar::TopActionState::shooting:

		// Marco Body ( Shooting)
		m_pTopSprite->UpdateValues( 10, 1, 10, 15.f, 60.f, 27.f, 275.f );
		m_pTopSprite->SetLeftDstRect( m_pBottomSprite->GetDstRect().left - 15 );

		if ( m_BotActionState == BotActionState::jumping )
		{
			m_Offset = 28;
		}
		else
		{
			m_Offset = 14;
		}
		break;

	case Avatar::TopActionState::pointingUp:

		m_pTopSprite->UpdateValues( 6, 1, 6, 15.f, 40.f, 29.f, 118.f );
		m_pTopSprite->SetLeftDstRect( m_pBottomSprite->GetDstRect().left - 15 );
		m_Offset = 16;
		break;

	case Avatar::TopActionState::shootingUp:

		m_pTopSprite->UpdateValues( 10, 1, 10, 15.f, 40.f, 70.f, 248.f );
		m_Offset = 14;
		break;
	}


	// Previous Action State different?
	if ( m_TopSpriteChanged )
	{
		ResetSprite( m_pTopSprite, true );
	}
}


// Update the Source Rectangle of the Sprite from Marco Legs (Bottom Sprite)
void Avatar::UpdateBotSrcRect()
{

	switch ( m_BotActionState )
	{
	case Avatar::BotActionState::iddle:

		if ( m_IsMoving )
		{
			// Marco Legs (Moving)
			m_pBottomSprite->UpdateValues( 12, 1, 12, 20.f, 30.f, 19.f, 44.f );
			m_pTopSprite->SetLeftDstRect( m_pBottomSprite->GetDstRect().left ); // (correct the position of the sprite)
		}
		else
		{
			// Marco Legs (Iddle)
			m_pBottomSprite->UpdateValues( 1, 1, 1, 15.f, 25.f, 15.f, 15.f );
		}
		break;

	case Avatar::BotActionState::crawling:

		if ( m_IsMoving )
		{
			// Crawling + IDDLE
			m_pBottomSprite->UpdateValues( 7, 1, 7, 5.f, 36.f, 24.f, 168.f );
		}
		else
		{
			// Crawling + Not Moving
			m_pBottomSprite->UpdateValues( 4, 1, 4, 5.f, 36.f, 24.f, 144.f );
		}
		break;

	case Avatar::BotActionState::jumping:

		m_pBottomSprite->UpdateValues( 6, 1, 6, 11.f, 25.f, 25.f, 100.f );
		break;

	case Avatar::BotActionState::shooting:  // Crawling Shooting

		m_pBottomSprite->UpdateValues( 7, 1, 7, 15.f, 50.f, 28.f, 197.f );
		break;

	}

	// Previous Action State different?
	if ( m_BotSpriteChanged )
	{
		ResetSprite( m_pBottomSprite, false );
	}
}

// Update frames of the sprite
void Avatar::UpdateFrames( float elapsedSeconds )
{
	// To know if the current animation needs to be repeat or not
	bool repeatBot{ true };  
	bool repeatTop{ true };

	switch (m_TopActionState)
	{
		case Avatar::TopActionState::jumping:
			repeatTop = false;
			break;
		case Avatar::TopActionState::shooting:
			repeatTop = false;
			break;
		case Avatar::TopActionState::pointingUp:
			repeatTop = false;
			break;
		case Avatar::TopActionState::shootingUp:
			repeatTop = false;
			break;
	}
	
	switch (m_BotActionState)
	{
		case Avatar::BotActionState::jumping:
			repeatBot = false;
			break;

		case Avatar::BotActionState::shooting:
			repeatBot = false;
			break;
	}

	// Update active frames
	m_pTopSprite->Update( elapsedSeconds, repeatTop );
	m_pBottomSprite->Update( elapsedSeconds, repeatBot );
	

	// Check if the shooting animation has finished
	if( m_IsShooting && m_pTopSprite->GetAnimationFinish() )
	{
		ResetSprite( m_pTopSprite, true );
		m_IsShooting = false;
		m_TopActionState = TopActionState::iddle;
	}
}


// Reset the Active frame to zero when the sprite animation has changed
void Avatar::ResetSprite( Sprite* sprite, bool topSprite )
{
	sprite->ResetActFrame();
	sprite->UpdateLeftSrcRect();

	// Check wich sprite changed
	if ( topSprite )
	{
		m_TopSpriteChanged = false;
	}
	else
	{
		m_BotSpriteChanged = false;
	}
}

void Avatar::HandleInput()
{
	const Uint8* pStates = SDL_GetKeyboardState( nullptr );

	if ( !m_IsMoving  && m_IsOnGround )
	{
		// NO MOVEMENT
		m_TopActionState = TopActionState::iddle;
		m_BotActionState = BotActionState::iddle;
		m_ActTopAnimation = Animations::iddle;
		m_ActBotAnimation = Animations::iddle;
		m_IsMoving = false;

	}


	
	if ( pStates[SDL_SCANCODE_C] )
	{
		// JUMP
		if (m_IsOnGround)
		{
			// Only jump when on ground
			m_TopActionState = TopActionState::jumping;
			m_BotActionState = BotActionState::jumping;
			m_ActTopAnimation = Animations::jumping;
			m_ActBotAnimation = Animations::jumping;
			m_Velocity.y = m_JumpSpeed;
		}

	}

	if ( m_BotActionState != BotActionState::jumping )
	{
		// Only if not jumping 

		if ( pStates[SDL_SCANCODE_UP] )
		{
			// POINTING WEAPON UPWARDS
			m_TopActionState = TopActionState::pointingUp;
			m_ActTopAnimation = Animations::pointingUp;

		}
		else
		{
			if ( pStates[SDL_SCANCODE_DOWN] )
			{
				// CRAWLING
				m_TopActionState = TopActionState::crawling;
				m_BotActionState = BotActionState::crawling;
				m_ActTopAnimation = Animations::crawlingIddle;
				m_ActBotAnimation = Animations::crawlingIddle;
			}
		}
	}


	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		// MOVING RIGHT
		m_IsMoving = true;
		m_IsMovingRight = true;
		CheckCrawling();

		m_ActTopAnimation = Animations::movingRight;
		m_ActBotAnimation = Animations::movingRight;


		if ( ( m_BotActionState == BotActionState::jumping ) && m_IsOnGround )
		{
			// Only change the sprite when avatar is on ground after jumping
			m_TopActionState = TopActionState::iddle;
			m_BotActionState = BotActionState::iddle;
			m_ActTopAnimation = Animations::iddle;
			m_ActBotAnimation = Animations::iddle;

		}

		if ( pStates[SDL_SCANCODE_C] )
		{
			// JUMP + MOVE RIGHT
			if ( m_IsOnGround )
			{
				m_TopActionState = TopActionState::jumping;
				m_BotActionState = BotActionState::jumping;
				m_ActTopAnimation = Animations::jumping;
				m_ActBotAnimation = Animations::jumping;
				m_Velocity.y = m_JumpSpeed;

			}

		}
		
	}
	else
	{
		if ( pStates[SDL_SCANCODE_LEFT] )
		{
			// MOVING LEFT
			m_IsMoving = true;
			m_IsMovingRight = false;
			CheckCrawling();

			m_ActTopAnimation = Animations::movingLeft;
			m_ActBotAnimation = Animations::movingLeft;

			if ( ( m_BotActionState == BotActionState::jumping ) && m_IsOnGround)
			{
				// Change animation after jumping when ONGROUND
				m_TopActionState = TopActionState::iddle;
				m_BotActionState = BotActionState::iddle;
				m_ActTopAnimation = Animations::iddle;
				m_ActBotAnimation = Animations::iddle;
			}

			if ( pStates[SDL_SCANCODE_C] )
			{
				// JUMP + MOVE LEFT
				if ( m_IsOnGround )
				{
					m_TopActionState = TopActionState::jumping;
					m_BotActionState = BotActionState::jumping;
					m_ActTopAnimation = Animations::jumping;
					m_ActBotAnimation = Animations::jumping;
					m_Velocity.y = m_JumpSpeed;

				}
			}
		}
		else
		{
			// NO MOVEMENT
			if ( m_IsOnGround )
			{
				m_Velocity.x = 0;
			}
		}
	}
	
	// Check if shooting
	CheckShooting();

	// Check if an Action State has changed
	CheckPreviousState();

}


// Check if shooting and which type of shooting is doing
void Avatar::CheckShooting()
{
	if ( m_IsShooting )
	{
		if ( m_BotActionState == BotActionState::crawling )
		{
			m_BotActionState = BotActionState::shooting;
			m_ActBotAnimation = Animations::crawlingShooting;
		}
		else
		{
			if ( m_TopActionState == TopActionState::pointingUp )
			{
				m_TopActionState = TopActionState::shootingUp;
				m_ActTopAnimation = Animations::shootingUp;
			}
			else
			{
				m_TopActionState = TopActionState::shooting;
				m_ActTopAnimation = Animations::shooting;
			}
		}

	}
}

// Check if Sprite has changed from the previous one. 
void Avatar::CheckPreviousState( )
{
	// TOP SPRITE CHECK
	if ( m_ActTopAnimation != m_PrevTopAnimation )
	{
		if ( ( m_PrevTopAnimation == Animations::shooting ) && ( m_ActTopAnimation == Animations::shootingUp ) )
		{
			m_TopActionState = TopActionState::pointingUp;
			m_IsShooting = false;
		}
		else
		{
			if ( (m_PrevTopAnimation == Animations::shootingUp ) && ( m_ActTopAnimation == Animations::shooting ) )
			{
				m_TopActionState = TopActionState::iddle;
				m_IsShooting = false;
			}
		}

		m_PrevTopAnimation = m_ActTopAnimation;
		m_TopSpriteChanged = true;
	}

	// BOTTOM SPRITE CHECK
	if ( m_ActBotAnimation != m_PrevBotAnimation )
	{
		m_PrevBotAnimation = m_ActBotAnimation;
		m_BotSpriteChanged = true;
	}

}

// Check if Avatar Crawling, reduce speed if so
void Avatar::CheckCrawling()
{   
	if  (m_BotActionState == BotActionState::crawling )
	{
		// Speed is reduced when crawling
		if ( m_IsMovingRight )
		{
			m_Velocity.x = m_SlowSpeed;
		}
		else
		{
			m_Velocity.x = -m_SlowSpeed;
		}
	}
	else
	{
		if ( m_IsMovingRight )
		{
			m_Velocity.x = m_NormalSpeed;
		}
		else
		{
			m_Velocity.x = -m_NormalSpeed;
		}
	}
}

void Avatar::Move( float elapsedSec )
{
	// Legs
	m_pBottomSprite->SetLeftDstRect( m_pBottomSprite->GetDstRect().left + m_Velocity.x * elapsedSec );
	m_pBottomSprite->SetBottomDstRect( m_pBottomSprite->GetDstRect().bottom + m_Velocity.y * elapsedSec );

	// Body
	m_pTopSprite->SetLeftDstRect(m_pTopSprite->GetDstRect().left + m_Velocity.x * elapsedSec);
	CorrectTopSprite();

}

void Avatar::Shoot()
{
	m_IsShooting = true;
	m_pTopSprite->ResetAnimationFinish( false );
	ResetSprite( m_pTopSprite, true );

	m_pBulletManager->ActivateBullet();
}

// Correct the top sprite so it draws it correctly
void Avatar::CorrectTopSprite()
{
	m_pTopSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_pBottomSprite->GetFrameHeight() + m_Offset);
}

// Gravity
void Avatar::AvatarFalling( float elapsedSec )
{
	m_Velocity.y += m_Acceleration.y * elapsedSec;

}

void Avatar::Hit()
{

}

const bool Avatar::GetIsMovingRight() const
{
	return m_IsMovingRight;
}

const Avatar::Animations Avatar::GetActiveAnimation() const
{
	return m_ActTopAnimation;
}

BulletManager* Avatar::GetBullets()
{
	return m_pBulletManager;
}


void Avatar::SetVerticesLevel(std::vector<Point2f> vertices)
{
	m_pBulletManager->SetVerticesLevel(vertices);
}
