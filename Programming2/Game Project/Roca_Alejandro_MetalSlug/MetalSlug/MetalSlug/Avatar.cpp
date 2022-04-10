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
	UpdateFrames(elapsedSeconds);
	
	

	UpdateSrcRects();


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

}

void Avatar::UpdateFrames(float elapsedSeconds)
{
	bool repeatBottom{ true };  // To know if the animation has to keep repeating or not
	bool repeatTop{ true };

	switch (m_ActionState)
	{
	case Avatar::ActionState::standing:
		repeatBottom = true;
		repeatTop = true;
		break;
	case Avatar::ActionState::crawling:
		repeatBottom = true;
		repeatTop = true;
		break;
	case Avatar::ActionState::jumping:
		repeatBottom = false;
		repeatTop = false;
		break;

	}

	
	if (m_Shooting)
	{
		repeatTop = false;
		repeatBottom = true;
	}
	
	// Update active frames
	m_pTopSprite->Update(elapsedSeconds, repeatTop);
	m_pBottomSprite->Update(elapsedSeconds, repeatBottom);

	if(m_Shooting && m_pTopSprite->GetAnimationFinish())
	{
		ResetSprite();
		m_Shooting = false;
		
		//m_pTopSprite->ResetAnimationFinish(false);
		
	}
	
	

	if (m_pTopSprite->GetAnimationFinish())
	{
		std::cout << "Top Sprite finish? Yes " << std::endl;
	}
	else
	{
		std::cout << "Top Sprite finish? No " << std::endl;
	}

	if (m_pBottomSprite->GetAnimationFinish())
	{
		std::cout << "Bottom Sprite finish? Yes " << std::endl;
	}
	else
	{
		std::cout << "Bottom Sprite finish? No " << std::endl;
	}
	
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

}

// Reset the Active frame to zero when the animation sprite has changed
void Avatar::ResetSprite()
{

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

void Avatar::Shoot()
{
	m_Shooting = true;
	m_KeyPressed = 12;

	// Check if player pressed a different key
	CheckPreviousKey();
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


