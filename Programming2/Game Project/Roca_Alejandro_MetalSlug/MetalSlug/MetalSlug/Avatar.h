#pragma once

#include "GameObject.h"
#include "Vector2f.h"

class Texture;
class Level;
class Avatar final : public GameObject
{
public:
	
	enum class ActionState {   // Main action of the character
		standing,
		crawling,
		jumping
	};

	Avatar();
	Avatar(const Avatar& avatar) = delete;
	Avatar(Avatar&& avatar) = delete;
	Avatar& operator=(const Avatar& avatar) = delete;
	Avatar& operator=(Avatar&& avatar) = delete;
	~Avatar();

	virtual void Draw() const override;
	virtual void Update(float elapsedSeconds, const Level& level);

	
	void Initialize();

	void UpdateSrcRects();
	void UpdateFrames(float elapsedSeconds);
	void CorrectTopSprite();
	void HandleInput();
	void CheckPreviousKey();
	void CheckActionState();
	void Move(float elapsedSec);
	void DrawAvatar() const;
	void ResetSprite();
	void AvatarFalling(float elapsedSec);


	Rectf GetShape();

private:

	// General
	static int m_GameObjectCounter;
	ActionState m_ActionState;			// Current action state
	Point2f m_StartPosition{};

	// Physics variables
	Vector2f m_Velocity;
	Vector2f m_Acceleration;		// For gravity when jumping
	const float m_NormalSpeed;
	const float m_SlowSpeed;
	const float m_JumpSpeed;
	
	float m_Offset;

	// Booleans
	bool m_MovingRight;				// Moving right or not (for OpenGL)
	bool m_Moving;					// Indicates if character is moving or not (for sprites)
	bool m_ActionStateChanged;      // Indicates if ActionState has changed or not
	bool m_OnGround;				// Avatar is in the ground or not
	bool m_Shooting;

	// In order to know when player press a different key
	unsigned int m_KeyPressed;
	unsigned int m_PreviousKey;
};

