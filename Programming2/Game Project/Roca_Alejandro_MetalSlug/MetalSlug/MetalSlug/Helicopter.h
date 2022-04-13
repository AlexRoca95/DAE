#pragma once
#include "Enemy.h"
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

	virtual void Update(float elapsedSec);

private:

	void Initialize();

};

