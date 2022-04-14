#pragma once
#include "Enemy.h"

class Bomb;
class Avatar;
class Helicopter final : public Enemy
{

public:

	

	Helicopter(const Point2f& startPos);
	virtual ~Helicopter();
	Helicopter(const Helicopter & helicopter) = delete;
	Helicopter(Helicopter && helicopter) = delete;
	Helicopter& operator=(const Helicopter & helicopter) = delete;
	Helicopter& operator=(Helicopter && helicopter) = delete;


	virtual void Draw() const override;
	virtual void Hit() override;
	virtual void CheckGameState() override;

	virtual void Update(float elapsedSec, Avatar* avatar, const std::vector<Point2f>& vertices);


private:

	const float m_MaxHeight;						// Maximum height at which the helicopter flies
	const float m_MaxTimerBombs;					// Time between throwing 3 bombs
	bool m_IsThrowingBombs;							// Throwing bombs or not
	bool m_NewBombs;								// New round of bombs needs to be throw or not
	float m_TimerBombs;								// Time needed to start throwing the next 3 bombs
	std::vector <Bomb*> m_pBombs;					
	const float m_TimeThrowBomb;					// Time needed to throw the next bomb 
	float m_Seconds;
	int m_ExplosionCounter;


	// PRIVATE methods
	void Initialize();
	void DestroyHelicopter(float elapsedSec);
	void ThrowBombs(float elapsedSec, const Rectf& actorShape);
	void Move(float elapsedSec, const Avatar* avatar);
	void ColocateInPos(float elapsedSec);
	void CheckTimerBombs(float elapsedSec);
	void CheckBombCollision(Avatar* avatar, const std::vector<Point2f>& vertices);


};

