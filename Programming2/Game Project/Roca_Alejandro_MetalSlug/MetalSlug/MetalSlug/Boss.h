#pragma once
#include "Enemy.h"

class Boss final : public Enemy
{
public:

	enum class State {

		sleeping,
		starting,
		firingUp,
		waiting,
		chargingShot,
		firingBot

	};


	Boss(const Point2f& startPos, bool comingFromRight, SoundManager* sounds);
	~Boss();
	Boss(const Boss& soldier) = delete;
	Boss(Boss&& soldier) = delete;
	Boss& operator=(const Boss& soldier) = delete;
	Boss& operator=(Boss&& soldier) = delete;


	virtual void Draw() const override;
	virtual void Hit() override;
	virtual void CheckGameState() override;

	virtual void Update(float elapsedSec, Avatar* avatar, const Level* level) override;

	Point2f GetStartPos() const;

private:

	State m_FightState;
	State m_PreviousState;

	float m_Seconds;
	int m_NrOfShots;
	int m_NrOfChargings;

	virtual void Initialize() override;

	
	void StartFight(float elapsedSec);
	void FiringUp(float elapsedSec);
	void FiringBot(float elapsedSec);
	void ChargingShot(float elapsedSec);
	void Waiting(float elapsedSec);

};

