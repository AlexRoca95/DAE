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
	m_NormalSpeed{400.f},
	m_SlowSpeed{80.f},
	m_JumpSpeed{500.f},
	m_MovingRight{ true },
	m_StartPosition{1000.f, 300.f},
	m_ActionState{ActionState::jumping},
	m_KeyPressed{},
	m_PreviousKey{},
	m_ActionStateChanged{},
	m_OnGround{},
	m_Offset{ 8 },
	m_Shooting{ false }
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
	
	if (m_ActionState != ActionState::crawling)
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
	UpdateSrcRects();

	UpdateFrames(elapsedSeconds);



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

}

void Avatar::UpdateFrames(float elapsedSeconds)
{
	bool repeat{ true };  // To know if the animation has to keep repeating or not

	switch (m_ActionState)
	{
	case Avatar::ActionState::standing:
		repeat = true;
		break;
	case Avatar::ActionState::crawling:
		repeat = true;
		break;
	case Avatar::ActionState::jumping:
		repeat = false;
		break;

	}

	
	// Update active frames
	m_pTopSprite->Update(elapsedSeconds, repeat);
	m_pBottomSprite->Update(elapsedSeconds, repeat);
}

// Update which part of the spritesheet we draw
void Avatar::UpdateSrcRects()
{
	switch (m_ActionState)
	{
	case Avatar::ActionState::standing:  // Character is standing
		m_Offset = 7;
		
		if(!m_Moving)
		{
			// Avatar not moving (Iddle)

			if (m_Shooting)
			{	
				// Marco Body (Standing + Shooting)
				m_pTopSprite->UpdateValues(13, 1, 13, 20.f, 54.f, 27.f, 82.f);
				// Marco Legs (Standing + Iddle)
				m_pBottomSprite->UpdateValues(1, 1, 1, 15.f, 25.f, 15.f, 15.f);

			}
			else
			{
				// Marco Legs (Standing + Iddle)
				m_pBottomSprite->UpdateValues(1, 1, 1, 15.f, 25.f, 15.f, 15.f);

				// Marco Body (Standing + Iddle)
				m_pTopSprite->UpdateValues(3, 1, 3, 5.f, 33.f, 29.f, 29.f);
			}
			m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left);
		}
		else
		{
			// Avatar moving
			// Marco Legs (Standing + moving)
			m_pBottomSprite->UpdateValues(12, 1, 12, 15.f, 30.f, 19.f, 44.f);

			// Marco Body (correct the position of the sprite)
			m_pTopSprite->UpdateValues(3, 1, 3, 5.f, 33.f, 29.f, 29.f);
			m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left + 14);
		}
		break;
		
	case Avatar::ActionState::crawling:
		m_Offset = 8;

		if (!m_Moving)
		{
			// Marco Body (Crawling + iddle)
			m_pBottomSprite->UpdateValues(4, 1, 4, 5.f, 36.f, 24.f, 144.f);

		}
		else
		{
			// Marco Body (Crawling + moving)
			m_pBottomSprite->UpdateValues(7, 1, 7, 5.f, 36.f, 24.f, 168.f);
		}
		break;

	case Avatar::ActionState::jumping:
		
		// Marco Body
		m_pTopSprite->UpdateValues(5, 1, 5, 11.f, 32.f, 25.f, 54.f);
		m_pTopSprite->SetLeftDstRect(m_pBottomSprite->GetDstRect().left - 18);

		// Marco Legs
		m_pBottomSprite->UpdateValues(6, 1, 6, 11.f, 25.f, 25.f, 100.f);

		m_Offset = 35;
		
		break;
		/*
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
		*/
	}

	// Previous Action State different?
	if (m_ActionStateChanged)
	{
		ResetSprite();
	}

}

// Reset the Active frame to zero when the animation sprite has changed
void Avatar::ResetSprite()
{
	m_pBottomSprite->ResetActFrame();
	m_pTopSprite->ResetActFrame();

	m_pBottomSprite->UpdateLeftSrcRect();
	m_pTopSprite->UpdateLeftSrcRect();

	m_ActionStateChanged = false;

}

void Avatar::HandleInput()
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	
	if (pStates[SDL_SCANCODE_DOWN])
	{
		// Crawling
		m_ActionState = ActionState::crawling;
		m_Moving = false;
		m_KeyPressed = 1;
		m_Velocity.x = 0;
	

		// Check if Crawling + Moving
		if (pStates[SDL_SCANCODE_DOWN] && pStates[SDL_SCANCODE_RIGHT])
		{
			m_Moving = true;
			m_MovingRight = true;
			m_KeyPressed = 2;
			m_Velocity.x = m_SlowSpeed;  // Reduce speed movement
		}
		
		if (pStates[SDL_SCANCODE_DOWN] && pStates[SDL_SCANCODE_LEFT])
		{
			m_Moving = true;
			m_MovingRight = false;
			m_KeyPressed = 3;
			m_Velocity.x = - m_SlowSpeed;
		}


		
	}
	else
	{
		if (pStates[SDL_SCANCODE_RIGHT])
		{
			
			if (m_OnGround)
			{
				// Only change animation when on Ground
				m_ActionState = ActionState::standing;
				m_KeyPressed = 4;
			}

			m_Velocity.x = m_NormalSpeed;
			m_Moving = true;		// Moving 
			m_MovingRight = true;  // and moving Right
			
			
			// Check if Moving + Crawling
			if (pStates[SDL_SCANCODE_RIGHT] && pStates[SDL_SCANCODE_DOWN])
			{
				if (m_OnGround)
				{
					m_ActionState = ActionState::crawling;
					m_KeyPressed = 5;
					m_Velocity.x = m_SlowSpeed;
				}
				
			}

			// Check if Moving + Jumping
			if (pStates[SDL_SCANCODE_RIGHT] && pStates[SDL_SCANCODE_C])
			{
				if (m_OnGround)
				{
					m_ActionState = ActionState::jumping;
					m_KeyPressed = 6;
					m_Velocity.y = m_JumpSpeed;
					m_Velocity.x = +m_NormalSpeed;	// Jump increases horizontal speed

				}

			}

			// Moving + shotting
			if (pStates[SDL_SCANCODE_RIGHT] && pStates[SDL_SCANCODE_X])
			{

				//m_Shooting = true;

			}
			
		}
		else
		{
			if (pStates[SDL_SCANCODE_LEFT])
			{
			
				if (m_OnGround)
				{
					m_ActionState = ActionState::standing;
					m_KeyPressed = 7;
				}

				m_Velocity.x = -m_NormalSpeed;
				m_Moving = true;		// Moving 
				m_MovingRight = false;  // To the left
				

				if (pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_DOWN])
				{
					m_ActionState = ActionState::crawling;
					m_KeyPressed = 8;
					m_Velocity.x = -m_SlowSpeed;
				}

				// Check if Moving + Jumping
				if (pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_C])
				{
					if (m_OnGround)
					{
						m_ActionState = ActionState::jumping;
						m_KeyPressed = 9;
						m_Velocity.y = m_JumpSpeed;
						m_Velocity.x = -m_NormalSpeed;
					}

				}
			}
			else
			{
				if (pStates[SDL_SCANCODE_C])
				{
					if (m_OnGround)
					{
						m_ActionState = ActionState::jumping;
						m_KeyPressed = 10;
						m_Velocity.y = m_JumpSpeed;
						
					}
				}
				else
				{
					if (m_OnGround)  // Keep moving forward until it reaches the ground
					{
						// Not Moving
						m_ActionState = ActionState::standing;
						m_Moving = false;
						m_KeyPressed = 11;
						m_Velocity.x = 0;
						

						if (pStates[SDL_SCANCODE_X])
						{
							//m_KeyPressed = 12;
							//m_Shooting = true;
						}
					}
				}
				
			}
		}
	}

	// Check if player pressed a different key
	CheckPreviousKey();


}

// Check if player pressed a different key
void Avatar::CheckPreviousKey()
{
	if (m_KeyPressed != m_PreviousKey)
	{
		m_PreviousKey = m_KeyPressed;
		m_ActionStateChanged = true;
	}
}

// Check if the avatar is stading, crawling or jumping for the sprite drawing
void Avatar::CheckActionState()
{   
	if (m_ActionState == ActionState::standing /* || m_MainActionState == ActionState::jumping */)
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

	if (m_ActionState == ActionState::crawling)
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