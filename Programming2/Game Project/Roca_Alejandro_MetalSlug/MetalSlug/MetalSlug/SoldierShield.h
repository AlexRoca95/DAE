#pragma once
#include "Enemy.h"

class Shield;
class SoldierShield final : public Enemy
{
public:

	SoldierShield(const Point2f& startPos, bool comingFromRight);
	~SoldierShield();
	SoldierShield(const SoldierShield & soldierShield) = delete;
	SoldierShield(SoldierShield && soldierShield) = delete;
	SoldierShield& operator=(const SoldierShield & soldierShield) = delete;
	SoldierShield& operator=(SoldierShield && soldierShield) = delete;


	virtual void Draw() const override;
	virtual void Hit() override;
	virtual void CheckGameState() override;

	virtual void Update(float elapsedSec, Avatar* avatar, const Level* level) override;


private:

	void Initialize();
	void InitShield();
	void KillSoldier(float elapsedSec);
	void CheckPreviousAction();
	
	void DoRunningState( float elapsedSec, const Rectf& avatarShape);
	void DoAttackState( float elapsedSec, const Rectf& avatarShape);
	void CheckFacingRight(const Rectf& avatarShape);
	void CheckDistanceAvatar(const Rectf& avatarShape);

	void Move(float elapsedSec);
	void UpdateFrames(float elapsedSec);

	bool m_IsShieldOn;			// Soldier has the shield or not
	bool m_IsFacingRight;		   // Is soldier loocking to the right or not
	bool m_IsAttackStarted;
	bool m_IsAttackFinished;

	Shield* m_pShield;			// Flying shield

	const float m_RunSpeed;

	// Time soldier body remains in ground
	const float m_MaxTimeDeath;
	float m_SecondsDeath;

	// Time soldier waits until attack again
	const float m_MaxTimeWait;
	float m_SecondsWaiting;

	const float m_AttackDist;




};

