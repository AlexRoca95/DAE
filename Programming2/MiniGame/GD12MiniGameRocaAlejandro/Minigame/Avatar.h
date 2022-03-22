#pragma once
#include "Vector2f.h"
class Level;
class Texture;

class Avatar final
{

public:
	enum class ActionState {
		waiting,
		moving,
		transforming
	};

	Avatar();
	Avatar(const Avatar& avatar) = delete;
	Avatar& operator=(const Avatar& avatar) = delete;  // Rule of three
	~Avatar();
	void Update(float elapsedSec, const Level& level);
	void Draw() const;
	void PowerUpHit();
	Rectf GetShape() const;

private:

	void Initialize();

	void HandleMoveKeysState(float elapsedSec);
	void UpdateAvatarFalling(float elapsedSec);
	void CalculateTransformingTime(float elapsedSec);

	void UpdateSprite(float elapsedSec);
	void UpdateSourceRect();
	void UpdateSpriteRow();

	void DrawAvatar() const;

	Rectf m_SrcRect;
	Rectf m_DstRect;
	float m_HorSpeed;
	float m_JumpSpeed;
	Vector2f m_Acceleration;
	Vector2f m_Velocity;
	ActionState m_ActionState;
	float m_AccuTransformSec;
	float m_MaxTransformSec;
	int m_Power;

	Texture* m_pSpritesTexture;
	float m_ClipHeight;
	float m_ClipWidth;
	int m_NrOfFrames;
	int m_NrFramesPerSec;
	float m_AnimTime;
	float m_FrameTime;
	int m_AnimFrame;
	int m_Row;

};

