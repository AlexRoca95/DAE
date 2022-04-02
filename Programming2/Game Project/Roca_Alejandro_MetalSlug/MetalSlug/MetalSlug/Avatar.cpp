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
	m_HorSpeed{200.f},
	m_JumpSpeed{200.f},
	m_MovingRight{ true },
	m_StartPosition{20.f, 300.f},
	m_MainActionState{ActionState::standing},
	m_SubActionState{ActionState::iddle},
	m_PreviousActionState{ActionState::standing}
	
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
		glScalef(-1, 1, 1);
		glTranslatef(-(m_pBottomSprite->GetDstRect().left + m_pBottomSprite->GetFrameWidth() / 2),
			-(m_pBottomSprite->GetDstRect().bottom + m_pBottomSprite->GetFrameHeight() / 2 ), 0.f);
	
		CheckSpritesToDraw();

		glPopMatrix();
	}
	else
	{
		CheckSpritesToDraw();
	}
	

	//DrawAvatar();
	

}



// Check if we have to draw one or two sprites of the avatar
void Avatar::CheckSpritesToDraw() const
{
	
	if (m_MainActionState != ActionState::crawling)
	{
		// Draw both parts of the sprite
		m_pBottomSprite->Draw();
		m_pTopSprite->Draw();

	}
	else
	{
		// Only one sprite drawing
		m_pBottomSprite->Draw();
	}
	
}

void Avatar::Update(float elapsedSeconds, const Level& level)
{

	level.HandleCollision(m_pBottomSprite->GetDstRect(), m_Velocity);
	

	HandleInput();
	UpdateSrcRects();

	// Update active frames
	m_pTopSprite->Update(elapsedSeconds);
	m_pBottomSprite->Update(elapsedSeconds);

	if (!level.IsOnGround(m_pBottomSprite->GetDstRect(), m_Velocity))
	{
		AvatarFalling(elapsedSeconds);
	}

	Move(elapsedSeconds);

	/*
	HandleInput();
	UpdateSrcRects();
	UpdateSprite(elapsedSeconds);
	Move(elapsedSeconds);


	m_Velocity.y += m_Acceleration.y * elapsedSeconds;
	m_DestRect.bottom += m_Velocity.y * elapsedSeconds;
	m_DestRect.left += m_Velocity.x * elapsedSeconds;   // Keep moving in the direction of the jump

	
	

	*/
}


// Update which part of the spritesheet we draw
void Avatar::UpdateSrcRects()
{
	switch (m_MainActionState)
	{
	case Avatar::ActionState::standing:  // Character is standing

		if (m_SubActionState == ActionState::moving)
		{
			// Marco Legs (Standing + moving)
			m_pBottomSprite->UpdateValues(12, 1, 12, 15.f, 30.f, 19.f, 44.f);


			// Marco Body (correct the position of the sprite)
			m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left + 14);
		
		}

		if(m_SubActionState == ActionState::iddle)
		{
			// Marco Legs (Standing + Iddle)
			m_pBottomSprite->UpdateValues(1, 1, 1, 15.f, 25.f, 15.f, 15.f);
			
			// Marco Body (Standing + Iddle)
			m_pTopSprite->UpdateValues(3, 1, 4, 5.f, 33.f, 29.f, 29.f);
			
			m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left);
		}

		if (m_SubActionState == ActionState::shooting)
		{

		}

		break;
	case Avatar::ActionState::crawling:
		if (m_SubActionState == ActionState::moving)
		{
			m_pBottomSprite->UpdateValues(7, 1, 1, 5.f, 36.f, 24.f, 168.f);
		}

		if (m_SubActionState == ActionState::iddle)
		{
			// Marco Body (Crawling + iddle)
			m_pBottomSprite->UpdateValues(4, 1, 1, 5.f, 36.f, 24.f, 144.f);
		}

		if (m_SubActionState == ActionState::shooting)
		{
			m_pBottomSprite->UpdateValues(7, 1, 1, 12.f, 50.f, 28.f, 197.f);
		}
		break;
	case Avatar::ActionState::jumping:
		//m_pBottomSprite->UpdateValues(6, 1, 1, 15.f, 25.f, 25.f, 100.f);
		// m_pBottomSprite->UpdateValues(6, 1, 1, 15.f, 32.f, 20.f, 120.f);
		break;
	}

	if (m_PreviousActionState != m_MainActionState)
	{
		// State changed from the previous one --> Reset sprite
		//ResetSprite();
	}

}

// Reset the sprite current frame and left pos of SrcRect so it draws correctly
void Avatar::ResetSprite()
{
	/*
	m_PreviousActionState = m_MainActionState;   // Save current state for next check

	m_CurrentFrame = 0;
	m_CurrentFrameTop = 0;
	m_SrcRect.left = (m_CurrentFrame * m_SrcRect.width);
	m_SrcRectTop.left = (m_CurrentFrameTop * m_SrcRectTop.width);
	*/
}

void Avatar::HandleInput()
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (pStates[SDL_SCANCODE_C])
	{
		// Jump
		m_MainActionState = ActionState::jumping;

		m_Velocity.y = m_JumpSpeed;
	}

	if (pStates[SDL_SCANCODE_DOWN])
	{
		// Crawling
		m_MainActionState = ActionState::crawling;
	}
	else
	{
		// Character up sprite
		m_MainActionState = ActionState::standing;
	}


	if (pStates[SDL_SCANCODE_RIGHT])
	{
		// Right Movement
		m_MovingRight = true;
		m_SubActionState = ActionState::moving;

		CheckMainActionState();		// Check which main action the character is doing
		
		if (pStates[SDL_SCANCODE_RIGHT] && pStates[SDL_SCANCODE_C])
		{
			m_Velocity.y = m_JumpSpeed;
		}

	}
	else if (pStates[SDL_SCANCODE_LEFT])
	{
		// Left Movement
		m_MovingRight = false;
		m_SubActionState = ActionState::moving;

		CheckMainActionState();


		if (pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_C])
		{
			m_Velocity.y = m_JumpSpeed;
		}
	}
	else
	{
		// No movement
		m_Velocity.x = 0.f;
		m_SubActionState = ActionState::iddle;
	}
}

// Check if the avatar is stading, crawling or jumping for the sprite drawing
void Avatar::CheckMainActionState()
{
	if (m_MainActionState == ActionState::standing || m_MainActionState == ActionState::jumping)
	{
		// Normal speed
		if (m_MovingRight)
		{
			m_Velocity.x = m_HorSpeed;
		}
		else
		{
			m_Velocity.x = -m_HorSpeed;
		}
		
	}

	if (m_MainActionState == ActionState::crawling)
	{
		// Reduced speed
		if (m_MovingRight)
		{
			m_Velocity.x = m_HorSpeed / 2;
		}
		else
		{
			m_Velocity.x = -m_HorSpeed / 2;
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
	m_pTopSprite->SetBottomDstRect(m_pBottomSprite->GetDstRect().bottom + m_pBottomSprite->GetFrameHeight() + 8 );



}


void Avatar::AvatarFalling(float elapsedSec)
{
	m_Velocity.y += m_Acceleration.y * elapsedSec;

	//Move(elapsedSec);
/*
	m_DestRect.bottom += m_Velocity.y * elapsedSec;
	m_DestRect.left += m_Velocity.x * elapsedSec;   // Keep moving in the direction of the jump
	*/
}

Rectf Avatar::GetShape()
{
	return m_pBottomSprite->GetDstRect();
}