#pragma once
#include "Vector2f.h"
class Level;

class Avatar
{

public:
	enum class ActionState {
		waiting,
		moving,
		transforming
	};

	Avatar();
	void Update(float elapsedSec, const Level& level);
	void Draw() const;
	void PowerUpHit();
	Rectf GetShape() const;

private:
	void HandleMoveKeysState(float elapsedSec);
	void UpdateAvatarFalling(float elapsedSec);
	void CalculateTransformingTime(float elapsedSec);

	void DrawNumberPowerUps() const;

	Rectf m_Shape;
	float m_HorSpeed;
	float m_JumpSpeed;
	Vector2f m_Acceleration;
	Vector2f m_Velocity;
	ActionState m_ActionState;
	float m_AccuTransformSec;
	float m_MaxTransformSec;
	int m_Power;
};

