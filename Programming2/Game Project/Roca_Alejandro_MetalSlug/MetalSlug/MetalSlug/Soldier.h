#pragma once
#include "Enemy.h"

class Grenade;
class Soldier final : public Enemy
{

public:

	Soldier(const Point2f& startPos, bool comingFromRight);
	~Soldier();
	Soldier(const Soldier& soldier) = delete;
	Soldier(Soldier&& soldier) = delete;
	Soldier& operator=(const Soldier& soldier) = delete;
	Soldier& operator=(Soldier&& soldier) = delete;


	virtual void Draw() const override;
	virtual void Hit() override;
	virtual void CheckGameState() override;

	virtual void Update(float elapsedSec, Avatar* avatar, const Level* level) override;


	bool GetFacingRight() const;


private:

	const float m_RunSpeed;
	const float m_RunAwayDist;
	const float m_ThrowGrenadeDist;
	bool m_FacingRight;						// Is soldier loocking to the right or not
	bool m_IsReset;							// Animation has been reset already

	// TIMERS
	// Time the soldier runs Away from avatar
	const float m_MaxTimeRunAway;
	float m_Seconds;

	// Time soldier body remains in ground
	const float m_MaxTimeDeath;
	float m_SecondsDeath;

	// Time soldier waits until throws another grenade
	const float m_MaxTimeWait;
	float m_SecondsWaiting;

	Grenade* m_pGrenade;

	void Initialize();
	void Move(float elapsedSec);

	void ChangeSprite(const int cols, const int rows, const int frames, const float frameSec, const float width,
		const float height, const float spriteSheetTop);
	void ActivateGrenade();

	// Action States (AI) for soldier
	void DoWalkingState(float elapsedSec, const Rectf& avatarShape);
	void DoAttackState(float elapsedSec, const Rectf& avatarShape);
	void DoRunAwayState(float elapsedSec, const Rectf& avatarShape);
	void DoWaitingState(float elapsedSec, const Rectf& avatarShape);

	// Gravity
	void Falling(float elapsedSec, const Level* level);

	void UpdateFrames(float elapsedSec);

	void CheckPreviousAction();
	void CheckFacingRight(const Rectf& avatarShape);
	void CheckDistanceAvatar(const Rectf& avatarShape);

	void KillSoldier(float elapsedSec);

};

