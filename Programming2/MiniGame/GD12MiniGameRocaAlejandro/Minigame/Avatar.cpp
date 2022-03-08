#include "pch.h"
#include "Avatar.h"
#include "utils.h"
#include "Level.h"
#include "Texture.h"
#include <iostream>

Avatar::Avatar()
	:m_DstRect{},
	m_SrcRect{},
	m_HorSpeed(200.f),
	m_JumpSpeed(600.f),
	m_Velocity(Vector2f{ 0.0f,0.0f }),
	m_Acceleration(Vector2f{ 0.f, -981.f }),
	m_ActionState(ActionState::moving),
	m_AccuTransformSec(0.0f),
	m_MaxTransformSec(1.0f),
	m_Power(0),
	m_ClipHeight(97.0f),
	m_ClipWidth(72.0f),
	m_NrOfFrames(10), 
	m_NrFramesPerSec(10),
	m_AnimFrame{},
	m_AnimTime{},
	m_Row{  },
	m_pSpritesTexture(new Texture{"resources/images/AvatarSheet.png"})
{
	Initialize();
	

}

void Avatar::Initialize()
{
	m_FrameTime = 1.0f / m_NrFramesPerSec;

	m_DstRect.width = m_ClipWidth;
	m_DstRect.height = m_ClipHeight;
	m_DstRect.left = 50;
	m_DstRect.bottom = 280;

	m_SrcRect.width = m_ClipWidth;
	m_SrcRect.height = m_ClipHeight;
	UpdateSourceRect();

}
Avatar::~Avatar()
{
	delete m_pSpritesTexture;
}

void Avatar::Update(float elapsedSec, const Level& level)
{
	UpdateSprite(elapsedSec);
	

	if (m_ActionState != ActionState::transforming)
	{
		level.HandleCollision(m_DstRect, m_Velocity);

		if (level.IsOnGround(m_DstRect))
		{
			// In the ground
			HandleMoveKeysState(elapsedSec);
			
		}
		else
		{
			// Not in the ground
			UpdateAvatarFalling(elapsedSec);

		}

	}
	else
	{
		// Avatar transforming
		CalculateTransformingTime(elapsedSec);
	}

	

}

void Avatar::UpdateAvatarFalling(float elapsedSec)
{
	m_ActionState = ActionState::moving;

	// Update Avatar's y position
	m_Velocity.y += m_Acceleration.y * elapsedSec;
	m_DstRect.bottom += m_Velocity.y * elapsedSec;
	m_DstRect.left += m_Velocity.x * elapsedSec;   // Keep moving in the direction of the jump
	
	//std::cout << m_DstRect.bottom << std::endl;

}

void Avatar::UpdateSprite(float elapsedSec)
{
	UpdateSpriteRow();

	m_AnimTime += elapsedSec; // Inc elapsed time

	if (m_AnimTime > m_FrameTime )
	{
		++m_AnimFrame %= m_NrOfFrames;
		m_AnimTime -= m_FrameTime;
		UpdateSourceRect();
	}

}

void Avatar::UpdateSourceRect()
{
	
	m_SrcRect.left = m_ClipWidth + m_AnimFrame % m_NrOfFrames * m_SrcRect.width;
	m_SrcRect.bottom = ((m_AnimFrame / m_NrOfFrames + 1) * m_SrcRect.height) * (m_Row+1);

	m_SrcRect.bottom += m_Power * (3 * m_ClipHeight);

}

void Avatar::UpdateSpriteRow()
{
	switch (m_ActionState)
	{
	case Avatar::ActionState::waiting:
		m_Row = 0;
		break;
	case Avatar::ActionState::moving:
		m_Row = 1;
		break;
	case Avatar::ActionState::transforming:
		m_Row = 2;
		break;
	default:
		break;
	}

	UpdateSourceRect();
}

void Avatar::CalculateTransformingTime(float elapsedSec)
{
	m_AccuTransformSec += elapsedSec;
	if (m_AccuTransformSec >= m_MaxTransformSec)
	{
		m_Power++;
		m_ActionState = ActionState::waiting;
		m_AccuTransformSec = 0.f;
	}
}

void Avatar::Draw() const
{
	switch (m_ActionState)
	{
	case Avatar::ActionState::waiting:
		utils::SetColor(Color4f{ 1.0f, 1.0f, 0.f, 1.0f });  // Yellow
		break;
	case Avatar::ActionState::moving:
		utils::SetColor(Color4f{ 1.0f, 0.0f, 0.f, 1.0f }); // Red
		break;
	case Avatar::ActionState::transforming:
		utils::SetColor(Color4f{ 0.0f, 1.0f, 1.f, 1.0f }); // Blue
		break;

	}

	DrawAvatar();

}

void Avatar::DrawAvatar() const
{
	if (m_Velocity.x < 0)
	{
		glPushMatrix();

		glTranslatef(m_DstRect.left + m_ClipWidth/2, m_DstRect.bottom + m_ClipHeight/2, 0.f);
		glScalef(-1, 1, 1);
		glTranslatef( -(m_DstRect.left + m_ClipWidth / 2), -(m_DstRect.bottom + m_ClipHeight / 2), 0.f);
		
		m_pSpritesTexture->Draw(m_DstRect, m_SrcRect);


		glPopMatrix();

	}
	else
	{
		m_pSpritesTexture->Draw(m_DstRect, m_SrcRect);
	}
}


void Avatar::PowerUpHit()
{
	m_ActionState = ActionState::transforming;
}

void Avatar::HandleMoveKeysState(float elapsedSec)
{
	m_ActionState = ActionState::moving;

	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (pStates[SDL_SCANCODE_RIGHT])
	{
		m_Velocity.x = m_HorSpeed;		

		if (pStates[SDL_SCANCODE_RIGHT] && pStates[SDL_SCANCODE_UP])
		{
			m_Velocity.y = m_JumpSpeed;
		}
	}
	else
	{
		if (pStates[SDL_SCANCODE_LEFT])
		{
			m_Velocity.x =  -m_HorSpeed;
		

			if (pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
			{
				m_Velocity.y = m_JumpSpeed;
			}
		}
		else
		{
			if (pStates[SDL_SCANCODE_UP])
			{
				m_Velocity.y = m_JumpSpeed;
			}
			else
			{
				// No key pressed
				m_ActionState = ActionState::waiting;
				m_Velocity.x = 0.f;
				m_Velocity.y = 0.f;
			}
		}
	}

	m_DstRect.left += m_Velocity.x * elapsedSec;
	m_DstRect.bottom += m_Velocity.y * elapsedSec;



}

Rectf Avatar::GetShape() const
{
	return m_DstRect;
}
