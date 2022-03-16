#include "pch.h"
#include "Avatar.h"
#include "Texture.h"
#include "utils.h"
#include <iostream>

int Avatar::m_GameObjectCounter = 0;

Avatar::Avatar()
	:GameObject(m_GameObjectCounter + 1),
	m_pSpritesBodyText{new Texture("Resources/sprites/marco/MarcoBody.png")},
	m_pSpritesLegsText{ new Texture("Resources/sprites/marco/MarcoLegs.png") },
	m_Velocity{Point2f{0.f, 0.f}},
	m_HorSpeed{100.f},
	m_MovingRight{ true },
	m_StartPosition{20.f, 200.f},
	m_ActionState{ActionState::waiting},
	m_PreviousActionState{ActionState::waiting}
	
{
	m_GameObjectCounter++;

	Initialize();
	
}

void Avatar::Initialize()
{

	// Marco Body (Iddle)
	InitSpriteValuesBody(4, 4, 7.f, 33.f, 27.f, 27.f);
	m_CurrentFrameTop = 0;
	m_AccumTimeTop = 0.f;

	m_DestRectTop.left = m_StartPosition.x;
	m_DestRectTop.bottom = m_StartPosition.y;
	InitDestRectTop();
	m_SrcRectTop.left = m_WidthTop * m_CurrentFrameTop;
	InitSrcRectTop();

	// Marco Legs (Iddle)
	InitSpriteValuesLegs(1, 1, 15.f, 25.f, 15.f, 15.f);
	m_CurrentFrame = 0;
	m_AccumTime = 0.f;

	m_DestRect.left = m_DestRectTop.left;
	InitDestRect();
	m_SrcRect.left = m_CurrentFrame * m_Width;
	InitSrcRect();

}

// Initialize all data needed for the Legs sprite (except currentFrame and accumTime)
void Avatar::InitSpriteValuesLegs(int cols, int frames, float frameTime, float width,
	float height, float spriteSheetTop)
{

	m_Frames = frames;
	m_ColsTop = cols;
	m_FrameTime = 1 / frameTime;
	m_Width = width;
	m_Height = height;
	m_SpriteSheetTop = spriteSheetTop;

}

void Avatar::InitSpriteValuesBody(int cols, int frames, float frameTime, float width,
	float height, float spriteSheetTop)
{

	m_FramesTop = frames;
	m_ColsTop = cols;
	m_FrameTimeTop = 1 / frameTime;
	m_WidthTop = width;
	m_HeightTop = height;
	m_SpriteSheetTop2 = spriteSheetTop;

}


void Avatar::InitDestRect()
{
	
	m_DestRect.bottom = m_DestRectTop.bottom - m_Height + 7;
	m_DestRect.width = m_Width;
	m_DestRect.height = m_Height;

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
	m_DestRectTop.width = m_WidthTop;
	m_DestRectTop.height = m_HeightTop;

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

		if (m_Crawling)
		{
			m_pSpritesBodyText->Draw(m_DestRectTop, m_SrcRectTop);
		}
		else
		{
			m_pSpritesLegsText->Draw(m_DestRect, m_SrcRect);
			m_pSpritesBodyText->Draw(m_DestRectTop, m_SrcRectTop);
		}
		

		glPopMatrix();
	}
	else
	{
		if (m_Crawling)
		{
			m_pSpritesBodyText->Draw(m_DestRectTop, m_SrcRectTop);
		}
		else
		{
			m_pSpritesLegsText->Draw(m_DestRect, m_SrcRect);
			m_pSpritesBodyText->Draw(m_DestRectTop, m_SrcRectTop);
		}
	}
	
}

void Avatar::Update(float elapsedSeconds)
{
	HandleInput();
	UpdateSrcRects();
	UpdateSprite(elapsedSeconds);
	Move(elapsedSeconds);
	
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

void Avatar::UpdateSrcRects()
{
	switch (m_ActionState)
	{
	case Avatar::ActionState::waiting:

		if (m_Crawling)
		{
			// Marco Body (Crawling)
			InitSpriteValuesBody(4, 4, 7.f, 36.f, 24.f, 204.f);

		}
		else
		{
			// Marco Legs (Iddle)
			InitSpriteValuesLegs(1, 1, 15.f, 25.f, 15.f, 15.f);

			// Marco Body (Iddle)
			InitSpriteValuesBody(4, 4, 7.f, 33.f, 27.f, 27.f);
			m_DestRectTop.left = m_DestRect.left;
		}
		
		break;
	case Avatar::ActionState::moving:
		// Marco Legs (moving)
		InitSpriteValuesLegs(18, 18, 15.f, 30.f, 19.f, 44.f);


		// Marco Body
		m_DestRectTop.left = m_DestRect.left + 5;
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

	if (m_PreviousActionState != m_ActionState)
	{
		// State changed from the previous one --> Reset sprite
		ResetSprite();
	}

}

// Reset the sprite current frame and left pos of SrcRect so it draws correctly
void Avatar::ResetSprite()
{
	m_PreviousActionState = m_ActionState;   // Save current state for next check

	m_CurrentFrame = 0;
	m_CurrentFrameTop = 0;
	m_SrcRect.left = (m_CurrentFrame * m_SrcRect.width);
	m_SrcRectTop.left = (m_CurrentFrameTop * m_SrcRectTop.width);
}

void Avatar::HandleInput()
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (pStates[SDL_SCANCODE_RIGHT])
	{
		m_MovingRight = true;
		m_ActionState = ActionState::moving;
		m_Velocity.x = m_HorSpeed;
	}
	else if (pStates[SDL_SCANCODE_LEFT])
	{
		m_MovingRight = false;
		m_ActionState = ActionState::moving;
		m_Velocity.x = -m_HorSpeed;
	}
	else
	{
		// No movement
		m_Velocity.x = 0.f;
		m_ActionState = ActionState::waiting;
	}


	if ((pStates[SDL_SCANCODE_UP]))
	{
		// Jump
		m_ActionState = ActionState::jumping;
	}

	if ((pStates[SDL_SCANCODE_DOWN]))
	{
		// Crawling
		m_Crawling = true;
	}
	else
	{
		m_Crawling = false;
	}
}

void Avatar::Move(float elapsedSec)
{
	m_DestRect.left += m_Velocity.x * elapsedSec;
	m_DestRectTop.left += m_Velocity.x * elapsedSec;
}