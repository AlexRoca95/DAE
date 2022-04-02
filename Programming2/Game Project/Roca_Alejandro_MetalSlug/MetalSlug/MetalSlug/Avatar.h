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
		jumping,
		moving,
		iddle,
		shooting
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

	void HandleInput();
	void CheckMainActionState();
	void Move(float elapsedSec);
	void CheckSpritesToDraw() const;
	void ResetSprite();
	void AvatarFalling(float elapsedSec);


	Rectf GetShape();

private:

	// General
	static int m_GameObjectCounter;
	ActionState m_MainActionState;
	ActionState m_SubActionState;
	ActionState m_PreviousActionState;
	Point2f m_StartPosition{};

	// Physics variables
	Vector2f m_Velocity;
	Vector2f m_Acceleration; // For gravity when jumping
	const float m_HorSpeed;
	const float m_JumpSpeed;

	// Movement
	bool m_MovingRight;
	

};

