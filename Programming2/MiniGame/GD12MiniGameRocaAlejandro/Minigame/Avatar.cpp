#include "pch.h"
#include "Avatar.h"
#include "utils.h"
#include "Level.h"
#include <iostream>

Avatar::Avatar()
	:m_Shape(Rectf{ 50, 280, 36, 97 }),
	m_HorSpeed(200.f),
	m_JumpSpeed(600.f),
	m_Velocity(Vector2f{ 0.0f,0.0f }),
	m_Acceleration(Vector2f{ 0.f, -981.f }),
	m_ActionState(ActionState::moving),
	m_AccuTransformSec(0.0f),
	m_MaxTransformSec(1.0f),
	m_Power(0)
{



}



void Avatar::Update(float elapsedSec, const Level& level)
{
	if (m_ActionState != ActionState::transforming)
	{
		if (level.IsOnGround(m_Shape))
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

	level.HandleCollision(m_Shape, m_Velocity);

}

void Avatar::UpdateAvatarFalling(float elapsedSec)
{
	m_ActionState = ActionState::moving;

	// Update Avatar's y position
	m_Velocity.y += m_Acceleration.y * elapsedSec;
	m_Shape.bottom += m_Velocity.y * elapsedSec;
	m_Shape.left += m_Velocity.x * elapsedSec;   // Keep moving in the direction of the jump
	

}

void Avatar::CalculateTransformingTime(float elapsedSec)
{
	m_AccuTransformSec += elapsedSec;
	if (m_AccuTransformSec >= m_MaxTransformSec)
	{
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

	utils::FillRect(m_Shape);

	DrawNumberPowerUps();

}

void Avatar::DrawNumberPowerUps() const
{
	const float size{ 5.f };
	Rectf powerUpRect{ m_Shape.left + size, m_Shape.bottom + size, size, size };
	for (int i{ 0 }; i < m_Power; i++)
	{
		utils::SetColor(Color4f{ 0.0f, 0.0f, 0.f, 1.0f });  // Black
		utils::FillRect(powerUpRect);

		powerUpRect.left += size * 2;
	}

}

void Avatar::PowerUpHit()
{
	m_ActionState = ActionState::transforming;

	m_Power++;

}

void Avatar::HandleMoveKeysState(float elapsedSec)
{
	m_ActionState = ActionState::moving;

	const Uint8* pStates = SDL_GetKeyboardState(nullptr);

	if (pStates[SDL_SCANCODE_RIGHT])
	{
		m_Velocity.x = m_HorSpeed;
		m_Shape.left += m_Velocity.x * elapsedSec;

		if (pStates[SDL_SCANCODE_RIGHT] && pStates[SDL_SCANCODE_UP])
		{
			m_Velocity.y = m_JumpSpeed;
			m_Shape.bottom += m_Velocity.y * elapsedSec;
		}
	}
	else
	{
		if (pStates[SDL_SCANCODE_LEFT])
		{
			m_Velocity.x =  -m_HorSpeed;
			m_Shape.left += m_Velocity.x * elapsedSec;

			if (pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
			{
				m_Velocity.y = m_JumpSpeed;
				m_Shape.bottom += m_Velocity.y * elapsedSec;
			}
		}
		else
		{
			if (pStates[SDL_SCANCODE_UP])
			{
				m_Velocity.y = m_JumpSpeed;
				m_Shape.bottom += m_Velocity.y * elapsedSec;
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





}

Rectf Avatar::GetShape() const
{
	return m_Shape;
}
