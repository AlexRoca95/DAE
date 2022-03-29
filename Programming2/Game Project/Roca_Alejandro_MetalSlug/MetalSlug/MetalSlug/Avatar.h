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


	virtual void InitDestRect() override;
	virtual void InitSrcRect() override;
	virtual void InitDestRectTop() override;
	virtual void InitSrcRectTop() override;
	
	void Initialize();
	void InitSpriteValuesLegs(int cols, int rows, int frames, float frameTime, float widht, float height, float spriteSheetTop);
	void InitSpriteValuesBody(int cols, int rows, int frames, float frameTime, float widht, float height, float spriteSheetTop);

	void UpdateSprite(float elapsedSeconds);
	void UpdateSrcRects();

	void HandleInput();
	void CheckMainActionState();
	void Move(float elapsedSec);
	void DrawAvatar() const;
	void CheckSpritesToDraw() const;
	void ResetSprite();


	Rectf GetShape();

private:

	// General
	static int m_GameObjectCounter;
	ActionState m_MainActionState;
	ActionState m_SubActionState;
	ActionState m_PreviousActionState;
	Point2f m_StartPosition{};

	// Sprite realated 
	const Texture* m_pSpritesBodyText;
	const Texture* m_pSpritesLegsText;

	// Physics variables
	Vector2f m_Velocity;
	Vector2f m_Acceleration; // For gravity when jumping
	const float m_HorSpeed;
	const float m_JumpSpeed;

	// Movement
	bool m_MovingRight;
	

};

