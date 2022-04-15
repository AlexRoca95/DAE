#pragma once
#include "Enemy.h"

class Soldier final : public Enemy
{

public:

	Soldier(const Point2f& startPos);
	virtual ~Soldier();
	Soldier(const Soldier& soldier) = delete;
	Soldier(Soldier&& soldier) = delete;
	Soldier& operator=(const Soldier& soldier) = delete;
	Soldier& operator=(Soldier&& soldier) = delete;


	virtual void Draw() const override;
	virtual void Hit() override;
	virtual void CheckGameState() override;

	virtual void Update(float elapsedSec, Avatar* avatar, const Level* level) override;


private:

	const float m_RunSpeed;
	const float m_RunAwayDist;
	const float m_ThrowGrenadeDist;
	bool m_FacingRight;


	const float m_MaxTimeRunAway;
	float m_Seconds;

	void Initialize();
	void Move(float elapsedSec);
	void DoWalkingState(float elapsedSec, Avatar* avatar);
	void DoAttackState(float elapsedSec, Avatar* avatar);
	void DoRunAwayState(float elapsedSec, Avatar* avatar);
	void Falling(float elapsedSec, const Level* level);

	void UpdateFrames(float elapsedSec);
	void CheckPreviousAction();

	void CheckFacingRight(Avatar* avatar);

};

