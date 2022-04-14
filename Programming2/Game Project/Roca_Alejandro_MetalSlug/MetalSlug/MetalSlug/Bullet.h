#include "projectile.h"

class Avatar;
#pragma once
class Bullet final : public Projectile
{

public:

	Bullet( const Point2f& startPos);
	Bullet(const Bullet& bullet) = delete;
	Bullet(Bullet&& bullet) = delete;
	Bullet& operator=(const Bullet& bullet) = delete;
	Bullet& operator=(Bullet&& bullet) = delete;
	~Bullet( );

	virtual void CheckGameState() override;

	void Update(float elapsedSec, const Avatar* avatar);
	


private:

	bool m_IsMovingUp;

	void Initialize();
	void SetStartPos(const Avatar* avatar);

	virtual void Move(float elapsedSec) override;
};

