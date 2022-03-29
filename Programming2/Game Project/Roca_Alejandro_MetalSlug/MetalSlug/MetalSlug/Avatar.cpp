#include "pch.h"
#include "Avatar.h"
#include "Texture.h"
#include "utils.h"
#include "Level.h"
#include <iostream>

int Avatar::m_GameObjectCounter = 0;

Avatar::Avatar()
	:GameObject(m_GameObjectCounter + 1),
	m_pSpritesBodyText{new Texture("Resources/sprites/marco/MarcoBody.png")},
	m_pSpritesLegsText{ new Texture("Resources/sprites/marco/MarcoLegs.png") },
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

void Avatar::Initialize()
{
	m_Scale = 2.7f;

	// Marco Body (Iddle)
	InitSpriteValuesBody(4, 1, 4, 7.f, 33.f, 27.f, 29.f);
	m_CurrentFrameTop = 0;
	m_AccumTimeTop = 0.f;

	m_DestRectTop.left = m_StartPosition.x;
	m_DestRectTop.bottom = m_StartPosition.y;
	InitDestRectTop();
	m_SrcRectTop.left = m_WidthTop * m_CurrentFrameTop;
	InitSrcRectTop();

	// Marco Legs (Iddle)
	InitSpriteValuesLegs(1, 1, 1, 15.f, 25.f, 15.f, 15.f);
	m_CurrentFrame = 0;
	m_AccumTime = 0.f;

	m_DestRect.left = m_DestRectTop.left;
	InitDestRect();
	m_SrcRect.left = m_CurrentFrame * m_Width;
	InitSrcRect();
	
	
}

// Initialize all data needed for the Legs sprite (except currentFrame and accumTime)
void Avatar::InitSpriteValuesLegs(int cols, int rows, int frames, float frameTime, float width,
	float height, float spriteSheetTop)
{

	m_Frames = frames;
	m_Cols = cols;
	m_Rows = rows;
	m_FrameTime = 1 / frameTime;
	m_Width = width;
	m_Height = height;
	m_SpriteSheetTop = spriteSheetTop;

}

void Avatar::InitSpriteValuesBody(int cols, int rows, int frames, float frameTime, float width,
	float height, float spriteSheetTop)
{

	m_FramesTop = frames;
	m_ColsTop = cols;
	m_RowsTop = rows;
	m_FrameTimeTop = 1 / frameTime;
	m_WidthTop = width;
	m_HeightTop = height;
	m_SpriteSheetTop2 = spriteSheetTop;

}


void Avatar::InitDestRect()
{
	
	m_DestRect.bottom = m_DestRectTop.bottom - m_Height - 6;
	m_DestRect.width = m_Width * m_Scale;
	m_DestRect.height = m_Height * m_Scale;

}

void Avatar::InitSrcRect()
{

	m_SrcRect.width = m_Width;
	m_SrcRect.height = m_Height;
	m_SrcRect.bottom = m_SpriteSheetTop;

}

void Avatar::InitSrcRectTop()
{

	m_SrcRectTop.width = m_WidthTop;
	m_SrcRectTop.height = m_HeightTop;
	m_SrcRectTop.bottom = m_SpriteSheetTop2;

}

void Avatar::InitDestRectTop()
{
	m_DestRectTop.width = m_WidthTop * m_Scale;
	m_DestRectTop.height = m_HeightTop * m_Scale;

}



Avatar::~Avatar()
{
	m_GameObjectCounter--;

	delete m_pSpritesBodyText;
	delete m_pSpritesLegsText;
	
}


void Avatar::Draw() const
{

	DrawAvatar();
	

}

void Avatar::DrawAvatar() const
{
	if (!m_MovingRight)
	{
		// Flip sprite to the left

		glPushMatrix();

		glTranslatef(m_DestRect.left + m_Width / 2, m_DestRect.bottom + m_Height / 2, 0.f);
		glScalef(-1, 1, 1);
		glTranslatef(-(m_DestRect.left + m_Width / 2), -(m_DestRect.bottom + m_Height / 2), 0.f);

		CheckSpritesToDraw();
		
		glPopMatrix();
	}
	else
	{
		CheckSpritesToDraw();
	}
	
}


// Check if we have to draw one or two sprites of the avatar
void Avatar::CheckSpritesToDraw() const
{
	if (m_MainActionState != ActionState::crawling)
	{
		m_pSpritesLegsText->Draw(m_DestRect, m_SrcRect);
		m_pSpritesBodyText->Draw(m_DestRectTop, m_SrcRectTop);

	}
	else
	{
		// Only one sprite drawing
		m_pSpritesBodyText->Draw(m_DestRectTop, m_SrcRectTop);
	}
}

void Avatar::Update(float elapsedSeconds, const Level& level)
{
	
	HandleInput();
	UpdateSrcRects();
	UpdateSprite(elapsedSeconds);
	Move(elapsedSeconds);

	m_Velocity.y += m_Acceleration.y * elapsedSeconds;
	m_DestRect.bottom += m_Velocity.y * elapsedSeconds;
	m_DestRect.left += m_Velocity.x * elapsedSeconds;   // Keep moving in the direction of the jump

	
	level.HandleCollision(m_DestRect, m_Velocity);

	
}

// Updates both sprites with different frame rates
void Avatar::UpdateSprite(float elapsedSeconds)
{

	m_AccumTime += elapsedSeconds;
	m_AccumTimeTop += elapsedSeconds;
	
	// Marco Legs
	if (m_AccumTime > m_FrameTime)
	{
		// Elapsed time more than framerate --> Next frame 
		++m_CurrentFrame %= m_Frames;		// Check if we reach the limit of frames  (if so reset to 0)
		m_AccumTime -= m_FrameTime; 
		m_SrcRect.left = (m_CurrentFrame  * m_SrcRect.width);

	}

	// Marco Body
	if (m_AccumTimeTop > m_FrameTimeTop)
	{
		++m_CurrentFrameTop %= m_FramesTop;
		m_AccumTimeTop -= m_FrameTimeTop;
		m_SrcRectTop.left = (m_CurrentFrameTop * m_SrcRectTop.width);
	}
	
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
			InitSpriteValuesLegs(6, 1, 18, 15.f, 30.f, 19.f, 44.f);


			// Marco Body (correct the position of the sprite)
			//InitSpriteValuesBody(4, 1, 4, 5.f, 34.f, 32.f, 290.f);
			m_DestRectTop.left = m_DestRect.left + 14;
		}

		if(m_SubActionState == ActionState::iddle)
		{
			// Marco Legs (Standing + Iddle)
			InitSpriteValuesLegs(1, 1, 1, 15.f, 25.f, 15.f, 15.f);

			// Marco Body (Standing + Iddle)
			InitSpriteValuesBody(10, 1, 3, 4.f, 33.f, 29.f, 29.f);
			m_DestRectTop.left = m_DestRect.left;
		}

		if (m_SubActionState == ActionState::shooting)
		{

		}

		break;
	case Avatar::ActionState::crawling:
		if (m_SubActionState == ActionState::moving)
		{

		}

		if (m_SubActionState == ActionState::iddle)
		{
			// Marco Body (Crawling + iddle)
			InitSpriteValuesBody(4, 1, 4, 7.f, 36.f, 24.f, 204.f);
		}

		if (m_SubActionState == ActionState::shooting)
		{

		}
		break;
	case Avatar::ActionState::jumping:
		break;
	}



	// Marco Body
	InitDestRectTop();
	InitSrcRectTop();

	// Marco legs
	InitDestRect();
	InitSrcRect();
	

	if (m_PreviousActionState != m_MainActionState)
	{
		// State changed from the previous one --> Reset sprite
		ResetSprite();
	}

}

// Reset the sprite current frame and left pos of SrcRect so it draws correctly
void Avatar::ResetSprite()
{
	m_PreviousActionState = m_MainActionState;   // Save current state for next check

	m_CurrentFrame = 0;
	m_CurrentFrameTop = 0;
	m_SrcRect.left = (m_CurrentFrame * m_SrcRect.width);
	m_SrcRectTop.left = (m_CurrentFrameTop * m_SrcRectTop.width);
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
	m_DestRect.left += m_Velocity.x * elapsedSec;
	m_DestRect.bottom += m_Velocity.y * elapsedSec;
	m_DestRectTop.left += m_Velocity.x * elapsedSec;
	m_DestRectTop.bottom += m_Velocity.y * elapsedSec;
}


Rectf Avatar::GetShape()
{
	return m_DestRect;
}