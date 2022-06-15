#pragma once
#include "Enemy.h"

class BossBullet;
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

	BossBullet* m_pWaterBullet2;
	std::vector <BossBullet*> m_pAirBullets2;

	Sprite* m_pWaterBullet;
	std::vector <std::pair<Sprite*, bool>> m_pAirBullets;  // Sprite and boolean to know if fired or not
	std::vector <float> m_AirSeconds;

	State m_FightState;
	State m_PreviousState;

	float m_Seconds;
	int m_NrOfShots;
	int m_NrOfChargings;

	const Point2f m_BulletBotPos;
	const Point2f m_BulletAirPos;
	const Point2f m_BulletAirSpeed;
	const float m_WaterBulletSpeed;
	const float m_CloathSpeed;

	bool m_FireBottom;

	virtual void Initialize() override;

	
	void StartFight(float elapsedSec);
	void FiringUp(float elapsedSec);
	void FiringBot(float elapsedSec);
	void ChargingShot(float elapsedSec);
	void Waiting(float elapsedSec);

};

