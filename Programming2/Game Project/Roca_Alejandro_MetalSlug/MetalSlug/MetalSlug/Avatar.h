#pragma once

#include "GameObject.h"
#include "Vector2f.h"

class Texture;

class Avatar : public GameObject
{
public:
	enum class ActionState {
		waiting,
		moving,
		jumping
	};

	Avatar();
	~Avatar();

	virtual void InitDestRect() override;
	virtual void InitSrcRect() override;
	virtual void InitDestRectTop() override;
	virtual void InitSrcRectTop() override;
	virtual void Draw() const override;
	virtual void Update(float elapsedSeconds) override;

	void Initialize();
	void InitSpriteValuesLegs(int cols, int frames, float frameTime, float widht, float height, float spriteSheetTop);
	void InitSpriteValuesBody(int cols, int frames, float frameTime, float widht, float height, float spriteSheetTop);

	void UpdateSprite(float elapsedSeconds);

	void HandleInput();
	void Move(float elapsedSec);
	void DrawAvatar() const;
	void UpdateSrcRects();

private:

	// General
	static int m_GameObjectCounter;
	ActionState m_ActionState;
	ActionState m_PreviousActionState;
	Point2f m_StartPosition{};

	// Sprite realated 
	const Texture* m_pSpritesBodyText;
	const Texture* m_pSpritesLegsText;

	// Physics variables
	Vector2f m_Velocity;
	const float m_HorSpeed;

	// Movement
	bool m_MovingRight;
	

};

