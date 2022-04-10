#pragma once

#include "GameObject.h"
#include "Vector2f.h"

class Texture;
class Level;
class Avatar final : public GameObject
{
public:
	
	// All animations --> To keep track of changing animations
	enum class Animations { 
		iddle, 
		movingRight, 
		movingLeft, 
		jumping, 
		crawlingIddle, 
		crawlingLeft, 
		crawlingRight, 
		crawlingShooting, 
		shooting, 
		pointingUp, 
		shootingUp
	};

	// Action State for the Top sprite
	enum class TopActionState {   
		iddle,
		crawling,		// Top sprite not being used for this state
		jumping,
		shooting,
		pointingUp,
		shootingUp
	};
	// Action State for the Bottom sprite
	enum class BottomActionState {   
		iddle,
		crawling,		
		jumping,
		shooting		// Only when crawling this state happens
	};

	Avatar();
	Avatar(const Avatar& avatar) = delete;
	Avatar(Avatar&& avatar) = delete;
	Avatar& operator=(const Avatar& avatar) = delete;
	Avatar& operator=(Avatar&& avatar) = delete;
	~Avatar();

	virtual void Draw() const override;
	virtual void Update(float elapsedSeconds, const Level& level);

	void Shoot();

	Rectf GetShape();

private:

	// General
	static int m_GameObjectCounter;
	Point2f m_StartPosition{};

	// Sprite Related
	TopActionState m_TopActionState;				// Current action state for the Top sprite
	BottomActionState m_BotActionState;
	Animations m_CurrentTopAnimation;
	Animations m_CurrentBotAnimation;
	Animations m_PreviousTopAnimation;				// To keep track if the animation changed
	Animations m_PreviousBotAnimation;
	float m_Offset;									// To recolocate the top Sprite when changing sprites

	// Physics variables
	Vector2f m_Velocity;
	Vector2f m_Acceleration;						// For gravity when jumping
	const float m_NormalSpeed;
	const float m_SlowSpeed;
	const float m_JumpSpeed;
	
	// Booleans
	bool m_MovingRight;								// Moving right or not (for OpenGL)
	bool m_Moving;									// Indicates if character is moving or not (for sprites)
	bool m_TopActionStateChanged;					// Indicates if TopActionState has changed or not
	bool m_BotActionStateChanged;					// Indicates if BotActionState has changed or not
	bool m_OnGround;								// Avatar is in the ground or not
	bool m_Shooting;

	// PRIVATE functions
	void Initialize();

	// Sprite related
	void UpdateTopSrcRect();
	void UpdateBotSrcRect();
	void UpdateFrames(float elapsedSeconds);
	void ResetSprite(Sprite* sprite, bool topSprite);
	void CorrectTopSprite();
	void CheckPreviousState();
	void CheckCrawling();
	void CheckShooting();

	// Input and actions
	void HandleInput();
	void Move(float elapsedSec);
	void AvatarFalling(float elapsedSec);

	void DrawAvatar() const;
};

