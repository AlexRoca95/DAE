#include "pch.h"
#include "Avatar.h"
#include "Texture.h"
#include "utils.h"
#include "Level.h"
#include <iostream>

int Avatar::m_GameObjectCounter = 0;

Avatar::Avatar()
	:GameObject(m_GameObjectCounter + 1),
	m_Velocity{Point2f{0.f, 0.f}},
	m_Acceleration{Point2f{0.f, -981.f}},
	m_NormalSpeed{300.f},
	m_SlowSpeed{80.f},
	m_JumpSpeed{500.f},
	m_MovingRight{ true },
	m_StartPosition{80.f, 300.f},
	m_TopActionState{TopActionState::jumping},
	m_BotActionState{BottomActionState::jumping},
	m_CurrentTopAnimation{Animations::jumping},
	m_CurrentBotAnimation{ Animations::jumping },
	m_PreviousTopAnimation{ m_CurrentTopAnimation },
	m_PreviousBotAnimation{ m_CurrentBotAnimation },
	m_TopActionStateChanged{},
	m_BotActionStateChanged{},
	m_OnGround{},
	m_Offset{},
	m_Shooting{ false },
	m_Moving{ false }
{
	m_GameObjectCounter++;

	Initialize();
	
}

Avatar::~Avatar()
{
	m_GameObjectCounter--;

	delete m_pBottomSprite;
	delete m_pTopSprite;
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

}


void Avatar::Draw() const
{
	if (!m_MovingRight)
	{
		// Moving left --> Flip sprite to the left
		glPushMatrix();
		glTranslatef(m_pBottomSprite->GetDstRect().left + m_pBottomSprite->GetFrameWidth() / 2, 
			m_pBottomSprite->GetDstRect().bottom + m_pBottomSprite->GetFrameHeight() / 2 / 2, 0.f);
		glScalef(-1, 1, 1.f);
		glTranslatef(-(m_pBottomSprite->GetDstRect().left + m_pBottomSprite->GetFrameWidth() / 2),
			-(m_pBottomSprite->GetDstRect().bottom + m_pBottomSprite->GetFrameHeight() / 2 ), 0.f);
	
		DrawAvatar();

		glPopMatrix();
	}
	else
	{
		DrawAvatar();
	}
	
}



// Draw only one sprite if ActionState is crawling. Draw two otherwise
void Avatar::DrawAvatar() const
{
	
	if (m_TopActionState != TopActionState::crawling)
	{
		// Not Crawling --> Draw both parts of the sprite
		m_pBottomSprite->Draw();
		m_pTopSprite->Draw();

	}
	else
	{
		// Crawling --> Only one sprite drawing
		m_pBottomSprite->Draw();
	}
	
}

void Avatar::Update(float elapsedSeconds, const Level* level)
{

	HandleInput();

	UpdateFrames(elapsedSeconds);
	
	UpdateTopSrcRect();
	UpdateBotSrcRect();


	if (!level->IsOnGround(m_pBottomSprite->GetDstRect(), m_Velocity))
	{
		AvatarFalling(elapsedSeconds);
		m_OnGround = false;
	}
	else
	{
		m_OnGround = true;
	}

	Move(elapsedSeconds);
	level->HandleCollision(m_pBottomSprite->GetDstRect(), m_Velocity);

	if (m_Velocity.x == 0)
	{
		m_Moving = false;
	}

}

// Update the Source Rectangle of the Top Sprite
void Avatar::UpdateTopSrcRect()
{
	m_Offset = 0;

	switch (m_TopActionState)
	{
	case Avatar::TopActionState::iddle:
		
		if (m_Moving)
		{
			// Marco Body (Moving)
			m_pTopSprite->UpdateValues(12, 1, 12, 20.f, 40.f, 29.f, 87.f);
			m_Offset = 10;
		}
		else
		{
			// Marco Body (Iddle)
			m_pTopSprite->UpdateValues(3, 1, 3, 5.f, 33.f, 29.f, 29.f);
			m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left);
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
		m_pTopSprite->UpdateValues(10, 1, 10, 15.f, 60.f, 27.f, 275.f);
		m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left - 15);
		if (m_BotActionState == BottomActionState::jumping)
		{
			m_Offset = 28;
		}
		else
		{
			m_Offset = 14;
		}
		break;

	case Avatar::TopActionState::pointingUp:

		m_pTopSprite->UpdateValues(6, 1, 6, 15.f, 40.f, 29.f, 118.f);
		m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left - 15);
		m_Offset = 16;
		break;

	case Avatar::TopActionState::shootingUp:

		m_pTopSprite->UpdateValues(10, 1, 10, 15.f, 40.f, 70.f, 248.f);
		m_Offset = 14;
		break;
	}


	// Previous Action State different?
	if (m_TopActionStateChanged)
	{
		ResetSprite(m_pTopSprite, true);
	}
}


// Update the Source Rectangle of the Sprite from Marco Legs (Bottom Sprite)
void Avatar::UpdateBotSrcRect()
{

	switch (m_BotActionState)
	{
	case Avatar::BottomActionState::iddle:

		if (m_Moving)
		{
			// Marco Legs (Moving)
			m_pBottomSprite->UpdateValues(12, 1, 12, 20.f, 30.f, 19.f, 44.f);
			m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left); // (correct the position of the sprite)
		}
		else
		{
			// Marco Legs (Iddle)
			m_pBottomSprite->UpdateValues(1, 1, 1, 15.f, 25.f, 15.f, 15.f);
		}
		break;

	case Avatar::BottomActionState::crawling:

		if (m_Moving)
		{
			// Crawling + IDDLE
			m_pBottomSprite->UpdateValues(7, 1, 7, 5.f, 36.f, 24.f, 168.f);
		}
		else
		{
			// Crawling + Not Moving
			m_pBottomSprite->UpdateValues(4, 1, 4, 5.f, 36.f, 24.f, 144.f);
		}
		break;

	case Avatar::BottomActionState::jumping:

		m_pBottomSprite->UpdateValues(6, 1, 6, 11.f, 25.f, 25.f, 100.f);
		break;

	case Avatar::BottomActionState::shooting:  // Crawling Shooting

		m_pBottomSprite->UpdateValues(7, 1, 7, 15.f, 50.f, 28.f, 197.f);
		break;

	}

	// Previous Action State different?
	if (m_BotActionStateChanged)
	{
		ResetSprite(m_pBottomSprite, false);
	}
}

// Update frames of the sprite
void Avatar::UpdateFrames(float elapsedSeconds)
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
		case Avatar::BottomActionState::jumping:
			repeatBot = false;
			break;

		case Avatar::BottomActionState::shooting:
			repeatBot = false;
			break;
	}

	// Update active frames
	m_pTopSprite->Update(elapsedSeconds, repeatTop);
	m_pBottomSprite->Update(elapsedSeconds, repeatBot);
	

	// Check if the shooting animation has finished
	if(m_Shooting && m_pTopSprite->GetAnimationFinish())
	{
		ResetSprite(m_pTopSprite, true);
		m_Shooting = false;
		m_TopActionState = TopActionState::iddle;
	}
}


// Reset the Active frame to zero when the sprite animation has changed
void Avatar::ResetSprite(Sprite* sprite, bool topSprite)
{
	sprite->ResetActFrame();
	sprite->UpdateLeftSrcRect();

	// Check wich sprite changed
	if (topSprite)
	{
		m_TopActionStateChanged = false;
	}
	else
	{
		m_BotActionStateChanged = false;
	}
}

void Avatar::HandleInput()
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (m_Moving == false)
	{
		if (m_OnGround)
		{
			// NO MOVEMENT
			m_TopActionState = TopActionState::iddle;
			m_BotActionState = BottomActionState::iddle;
			m_CurrentTopAnimation = Animations::iddle;
			m_CurrentBotAnimation = Animations::iddle;
			m_Moving = false;

		}
		
	}


	
	if (pStates[SDL_SCANCODE_C])
	{
		// JUMP
		if (m_OnGround)
		{
			// Only jump when on ground
			m_TopActionState = TopActionState::jumping;
			m_BotActionState = BottomActionState::jumping;
			m_CurrentTopAnimation = Animations::jumping;
			m_CurrentBotAnimation = Animations::jumping;
			m_Velocity.y = m_JumpSpeed;
		}

	}

	if (m_BotActionState != BottomActionState::jumping)
	{
		// Only if not jumping 

		if (pStates[SDL_SCANCODE_UP])
		{
			// POINTING WEAPON UPWARDS
			m_TopActionState = TopActionState::pointingUp;
			m_CurrentTopAnimation = Animations::pointingUp;

		}
		else
		{
			if (pStates[SDL_SCANCODE_DOWN])
			{
				// CRAWLING
				m_TopActionState = TopActionState::crawling;
				m_BotActionState = BottomActionState::crawling;
				m_CurrentTopAnimation = Animations::crawlingIddle;
				m_CurrentBotAnimation = Animations::crawlingIddle;
			}
		}
	}


	if (pStates[SDL_SCANCODE_RIGHT])
	{
		// MOVING RIGHT
		m_Moving = true;
		m_MovingRight = true;
		CheckCrawling();

		m_CurrentTopAnimation = Animations::movingRight;
		m_CurrentBotAnimation = Animations::movingRight;


		if (m_BotActionState == BottomActionState::jumping && m_OnGround)
		{
			// ONLY CHANGE THE ANIMATION WHEN ONGROUND AFTER JUMP
			m_TopActionState = TopActionState::iddle;
			m_BotActionState = BottomActionState::iddle;
			m_CurrentTopAnimation = Animations::iddle;
			m_CurrentBotAnimation = Animations::iddle;

		}

		if (pStates[SDL_SCANCODE_C])
		{
			// JUMP + MOVE RIGHT
			if (m_OnGround)
			{
				m_TopActionState = TopActionState::jumping;
				m_BotActionState = BottomActionState::jumping;
				m_CurrentTopAnimation = Animations::jumping;
				m_CurrentBotAnimation = Animations::jumping;
				m_Velocity.y = m_JumpSpeed;

			}

		}
		
	}
	else
	{
		if (pStates[SDL_SCANCODE_LEFT])
		{
			// MOVING LEFT
			m_Moving = true;
			m_MovingRight = false;
			CheckCrawling();

			m_CurrentTopAnimation = Animations::movingLeft;
			m_CurrentBotAnimation = Animations::movingLeft;

			if (m_BotActionState == BottomActionState::jumping && m_OnGround)
			{
				// Change animation after jumping when ONGROUND
				m_TopActionState = TopActionState::iddle;
				m_BotActionState = BottomActionState::iddle;
				m_CurrentTopAnimation = Animations::iddle;
				m_CurrentBotAnimation = Animations::iddle;
			}

			if (pStates[SDL_SCANCODE_C])
			{
				// JUMP + MOVE LEFT
				if (m_OnGround)
				{
					m_TopActionState = TopActionState::jumping;
					m_BotActionState = BottomActionState::jumping;
					m_CurrentTopAnimation = Animations::jumping;
					m_CurrentBotAnimation = Animations::jumping;
					m_Velocity.y = m_JumpSpeed;

				}
			}
		}
		else
		{
			// NO MOVEMENT
			if (m_OnGround)
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
	if (m_Shooting)
	{
		if (m_BotActionState == BottomActionState::crawling)
		{
			m_BotActionState = BottomActionState::shooting;
			m_CurrentBotAnimation = Animations::crawlingShooting;
		}
		else
		{
			if (m_TopActionState == TopActionState::pointingUp)
			{
				m_TopActionState = TopActionState::shootingUp;
				m_CurrentTopAnimation = Animations::shootingUp;
			}
			else
			{
				m_TopActionState = TopActionState::shooting;
				m_CurrentTopAnimation = Animations::shooting;
			}
		}

	}
}

// Check if Sprite has changed from the previous one. 
void Avatar::CheckPreviousState()
{
	// TOP SPRITE CHECK
	if (m_CurrentTopAnimation != m_PreviousTopAnimation)
	{
		if (m_PreviousTopAnimation == Animations::shooting && m_CurrentTopAnimation == Animations::shootingUp)
		{
			m_TopActionState = TopActionState::pointingUp;
			m_Shooting = false;
		}
		else
		{
			if (m_PreviousTopAnimation == Animations::shootingUp && m_CurrentTopAnimation == Animations::shooting)
			{
				m_TopActionState = TopActionState::iddle;
				m_Shooting = false;
			}
		}

		m_PreviousTopAnimation = m_CurrentTopAnimation;
		m_TopActionStateChanged = true;
	}

	// BOTTOM SPRITE CHECK
	if (m_CurrentBotAnimation != m_PreviousBotAnimation)
	{
		m_PreviousBotAnimation = m_CurrentBotAnimation;
		m_BotActionStateChanged = true;
	}

}

// Check if Avatar Crawling, reduce speed if so
void Avatar::CheckCrawling()
{   
	if (m_BotActionState == BottomActionState::crawling)
	{
		// Speed is reduced when crawling
		if (m_MovingRight)
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
		if (m_MovingRight)
		{
			m_Velocity.x = m_NormalSpeed;
		}
		else
		{
			m_Velocity.x = -m_NormalSpeed;
		}
	}
}

void Avatar::Move(float elapsedSec)
{
	// Legs
	m_pBottomSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left + m_Velocity.x * elapsedSec);
	m_pBottomSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_Velocity.y * elapsedSec);

	// Body
	m_pTopSprite->SetLeftDstRect(m_pTopSprite->GetDstRect().left + m_Velocity.x * elapsedSec);
	CorrectTopSprite();

}

void Avatar::Shoot()
{
	m_Shooting = true;
	m_pTopSprite->ResetAnimationFinish(false);
	ResetSprite(m_pTopSprite, true);
}

// Correct the top sprite so it draws it correctly
void Avatar::CorrectTopSprite()
{
	m_pTopSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_pBottomSprite->GetFrameHeight() + m_Offset);

}

// Gravity
void Avatar::AvatarFalling(float elapsedSec)
{
	m_Velocity.y += m_Acceleration.y * elapsedSec;

}

Rectf Avatar::GetShape()
{
	return m_pBottomSprite->GetDstRect();
}


