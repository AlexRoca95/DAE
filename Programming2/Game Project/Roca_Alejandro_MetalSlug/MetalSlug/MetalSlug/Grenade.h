#pragma once
#include "Projectile.h"

class Soldier;
class Grenade final : public Projectile
{

public:

	Grenade();
	Grenade(const Grenade& grenade) = delete;
	Grenade(Grenade&& grenade) = delete;
	Grenade& operator=(const Grenade& grenade) = delete;
	Grenade& operator=(Grenade&& grenade) = delete;
	~Grenade();

	virtual void CheckGameState() override;
	virtual void Draw() const;

	void Update(float elapsedSec, const Soldier* soldier);


private:

	float m_Angle{ };

	void Initialize();
	void SetStartPos(const Soldier* soldier);

	virtual void Move(float elapsedSec) override;
	

};

