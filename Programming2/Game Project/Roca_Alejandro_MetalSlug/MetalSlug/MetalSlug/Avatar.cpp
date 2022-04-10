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
	m_KeyPressed{},
	m_PreviousKey{},
	m_TopActionStateChanged{},
	m_BotActionStateChanged{},
	m_OnGround{},
	m_Offset{ 8 },
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



// Check how many sprites do we have to draw depending on the ActionState
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

void Avatar::Update(float elapsedSeconds, const Level& level)
{

	HandleInput();
	UpdateFrames(elapsedSeconds);
	
	UpdateTopSrcRect();
	UpdateBotSrcRect();

	//UpdateSrcRects();


	if (!level.IsOnGround(m_pBottomSprite->GetDstRect(), m_Velocity))
	{
		AvatarFalling(elapsedSeconds);
		m_OnGround = false;
	}
	else
	{
		m_OnGround = true;
	}

	//std::cout << m_OnGround << std::endl;

	Move(elapsedSeconds);
	level.HandleCollision(m_pBottomSprite->GetDstRect(), m_Velocity);

	//std::cout << m_pTopSprite->GetActFrame() << std::endl;

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
			// Avatar Moving
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
	case Avatar::TopActionState::crawling:   // Nothing to do here for Top Sprite
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
		m_Offset = 14;
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
void Avatar::UpdateFrames(float elapsedSeconds)
{
	bool repeatBot{ true };  // To know if the animation has to keep repeating or not
	bool repeatTop{ true };


	switch (m_TopActionState)
	{
	case Avatar::TopActionState::iddle:
		repeatTop = true;
		break;
	case Avatar::TopActionState::crawling:
		repeatTop = true;
		break;
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
	default:
		break;
	}
	

	switch (m_BotActionState)
	{
	case Avatar::BottomActionState::iddle:
		repeatBot = true;
		break;
	case Avatar::BottomActionState::crawling:
		repeatBot = true;
		break;
	case Avatar::BottomActionState::jumping:
		repeatBot = false;
		break;
	case Avatar::BottomActionState::shooting:
		repeatBot = true;
		break;
	}

	
	// Update active frames
	m_pTopSprite->Update(elapsedSeconds, repeatTop);
	m_pBottomSprite->Update(elapsedSeconds, repeatBot);
	
	if(m_Shooting && m_pTopSprite->GetAnimationFinish())
	{
		ResetSprite(m_pTopSprite, true);
		m_Shooting = false;
		
		m_TopActionState = TopActionState::iddle;
		
	}
}

// Update which part of the spritesheet we draw
void Avatar::UpdateSrcRects()
{
	/*
	switch (m_ActionState)
	{
	case Avatar::ActionState::standing:  // Character is standing
		m_Offset = 7;
		
		if(!m_Moving)
		{
			// Avatar not moving (Iddle)
			if (m_Shooting)
			{	
				m_Offset = 14;
				// Marco Body ( Shooting)
				m_pTopSprite->UpdateValues(10, 1, 10, 15.f, 60.f, 27.f, 275.f);
				m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left - 15);
			}
			else
			{
				// Marco Body (Standing + Iddle)
				m_pTopSprite->UpdateValues(3, 1, 3, 5.f, 33.f, 29.f, 29.f);
				m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left);
				//m_pTopSprite->UpdateValues(6, 1, 6, 15.f, 40.f, 29.f, 118.f);   // Pointing Up
				//m_pTopSprite->UpdateValues(4, 1, 4, 15.f, 40.f, 29.f, 147.f);   // Holding
				//m_pTopSprite->UpdateValues(6, 1, 6, 15.f, 40.f, 29.f, 176.f);   // Going down 
				//m_pTopSprite->UpdateValues(10, 1, 10, 15.f, 40.f, 70.f, 248.f);   // Shooting Up
				//m_pTopSprite->UpdateValues(5, 1, 5, 15.f, 36.f, 30.f, 307.f);	// Grenade
			}

			// Marco Legs (Standing + Iddle)
			m_pBottomSprite->UpdateValues(1, 1, 1, 15.f, 25.f, 15.f, 15.f);
			
		}
		else
		{

			if (m_Shooting)
			{
				m_Offset = 18;
				// Marco Body (Shooting)
				m_pTopSprite->UpdateValues(10, 1, 10, 15.f, 60.f, 27.f, 275.f);
			}
			else
			{
				// Marco Body Moving 
				m_pTopSprite->UpdateValues(12, 1, 12, 20.f, 40.f, 29.f, 87.f);
				
			}
			// Avatar moving
			// Marco Legs (Standing + moving)
			m_pBottomSprite->UpdateValues(12, 1, 12, 20.f, 30.f, 19.f, 44.f);
			m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left); // (correct the position of the sprite)
			
		}
		break;
		
	case Avatar::ActionState::crawling:
		m_Offset = 8;

		if (!m_Moving)
		{

			// Marco Body (Crawling + iddle)
			m_pBottomSprite->UpdateValues(4, 1, 4, 5.f, 36.f, 24.f, 144.f);
			//m_pBottomSprite->UpdateValues(16, 1, 16, 15.f, 40.f, 40.f, 242.f);  // Dying

		}
		else
		{
			// Marco Body (Crawling + moving)
			m_pBottomSprite->UpdateValues(7, 1, 7, 5.f, 36.f, 24.f, 168.f);
		}

		if (m_Shooting)
		{
			m_pBottomSprite->UpdateValues(7, 1, 7, 15.f, 50.f, 28.f, 197.f);
		}

		break;

	case Avatar::ActionState::jumping:
		
		m_Offset = 35;
		if (m_Shooting)
		{
			m_Offset = 18;
			// Marco Body (Shooting)
			m_pTopSprite->UpdateValues(10, 1, 10, 15.f, 60.f, 27.f, 275.f);
			m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left - 18);
		}
		else
		{
			// Marco Body
			m_pTopSprite->UpdateValues(5, 1, 5, 11.f, 32.f, 25.f, 54.f);
			m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left - 18);
		}
		

		// Marco Legs
		m_pBottomSprite->UpdateValues(6, 1, 6, 11.f, 25.f, 25.f, 100.f);

	
		
		break;	
	}

	// Previous Action State different?
	if (m_ActionStateChanged)
	{
		ResetSprite();
	}
	*/
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

	
	/*
	if (m_Shooting)
	{

		// Only reset the Top sprite for shooting
		m_pTopSprite->ResetActFrame();
		
		m_pTopSprite->UpdateLeftSrcRect();

	}
	else
	{
		// Reset both sprites
		m_pBottomSprite->ResetActFrame();
		m_pTopSprite->ResetActFrame();

		m_pBottomSprite->UpdateLeftSrcRect();
		m_pTopSprite->UpdateLeftSrcRect();
	}
	

	m_TopActionStateChanged = false;
	*/

}

void Avatar::HandleInput()
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);


	if (m_Moving == false)
	{
		if (m_OnGround)
		{
			// BASE ANIMATION --> Not Moving
			m_TopActionState = TopActionState::iddle;
			m_BotActionState = BottomActionState::iddle;
			m_Moving = false;


			m_CurrentTopAnimation = Animations::iddle;
			m_CurrentBotAnimation = Animations::iddle;

		}
		
	}

	if (m_OnGround)
	{
		if (pStates[SDL_SCANCODE_UP])
		{
			// Pointing UP
			m_TopActionState = TopActionState::pointingUp;
			m_CurrentTopAnimation = Animations::pointingUp;

		}
		else
		{
			// Crawling
			if (pStates[SDL_SCANCODE_DOWN])
			{

				m_TopActionState = TopActionState::crawling;
				m_BotActionState = BottomActionState::crawling;

				m_CurrentTopAnimation = Animations::crawlingIddle;
				m_CurrentBotAnimation = Animations::crawlingIddle;
			}
		}
	}

	// Jumping
	if (pStates[SDL_SCANCODE_C])
	{
		if (m_OnGround)
		{

			m_TopActionState = TopActionState::jumping;
			m_BotActionState = BottomActionState::jumping;
			m_Velocity.y = m_JumpSpeed;
			m_CurrentTopAnimation = Animations::jumping;
			m_CurrentBotAnimation = Animations::jumping;
		}
		
	}

	if (pStates[SDL_SCANCODE_RIGHT])
	{
		// MOVING RIGHT
		m_Moving = true;
		m_MovingRight = true;
		m_Velocity.x = m_NormalSpeed;

		m_CurrentTopAnimation = Animations::movingRight;
		m_CurrentBotAnimation = Animations::movingRight;


		if (m_BotActionState == BottomActionState::jumping && m_OnGround)
		{
			// Change animation after jumping
			m_TopActionState = TopActionState::iddle;
			m_BotActionState = BottomActionState::iddle;
			m_CurrentTopAnimation = Animations::iddle;
			m_CurrentBotAnimation = Animations::iddle;

		}

		if (pStates[SDL_SCANCODE_C])
		{
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
			m_Velocity.x = -m_NormalSpeed;

			m_CurrentTopAnimation = Animations::movingLeft;
			m_CurrentBotAnimation = Animations::movingLeft;

			if (m_BotActionState == BottomActionState::jumping && m_OnGround)
			{
				// Change animation after jumping
				m_TopActionState = TopActionState::iddle;
				m_BotActionState = BottomActionState::iddle;
				m_CurrentTopAnimation = Animations::iddle;
				m_CurrentBotAnimation = Animations::iddle;
			}

			if (pStates[SDL_SCANCODE_C])
			{
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
			if (m_OnGround)
			{
				m_Velocity.x = 0;
			}
		}
	}
	


	// Avatar shooting
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


	// Check if an Action State has changed
	CheckPreviousState();

}

// Check if Action State has changed from the previous one
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

// Check if the avatar is stading, crawling or jumping for the sprite drawing
void Avatar::CheckActionState()
{   
	if (m_TopActionState == TopActionState::iddle)
	{
		// Normal speed
		if (m_MovingRight)
		{
			m_Velocity.x = m_NormalSpeed;
		}
		else
		{
			m_Velocity.x = -m_NormalSpeed;
		}
		
	}

	if (m_TopActionState == TopActionState::crawling)
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
}

void Avatar::Move(float elapsedSec)
{

	
	// Legs
	m_pBottomSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left + m_Velocity.x * elapsedSec);
	m_pBottomSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_Velocity.y * elapsedSec);

	// Body
	m_pTopSprite->SetLeftDstRect(m_pTopSprite->GetDstRect().left + m_Velocity.x * elapsedSec);
	CorrectTopSprite();

	


	//std::cout << m_Velocity.x << std::endl;

}

void Avatar::Shoot()
{
	m_Shooting = true;
	m_pTopSprite->ResetAnimationFinish(false);
	ResetSprite(m_pTopSprite, true);

}

void Avatar::CorrectTopSprite()
{
	m_pTopSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_pBottomSprite->GetFrameHeight() + m_Offset);

}


void Avatar::AvatarFalling(float elapsedSec)
{
	m_Velocity.y += m_Acceleration.y * elapsedSec;

}

Rectf Avatar::GetShape()
{
	return m_pBottomSprite->GetDstRect();
}


