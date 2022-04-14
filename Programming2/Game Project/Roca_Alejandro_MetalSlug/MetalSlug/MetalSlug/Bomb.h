
// Bombs from the helicopter
#pragma once
#include "Projectile.h"


class Bomb final : public Projectile
{

public:
	Bomb( );
	virtual ~Bomb();
	Bomb( const Bomb& bomb ) = delete;
	Bomb(Bomb&& bomb) = delete;
	Bomb& operator=( const Bomb& bomb ) = delete;
	Bomb& operator=( Bomb&& bomb ) = delete;


	void Update(float elapsedSec, const Rectf& actorShape);

	Sprite* GetBotSprite();
	Sprite* GetTopSprite();

private:

	const float m_Gravity;
	float m_Velocity;

	void Initialize();
	void SetStartPos(const Rectf& helicopter);
	virtual void Move(float elapsedSec) override;

};

