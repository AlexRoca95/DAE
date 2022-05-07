#pragma once
#include "Enemy.h"

class Boss final : public Enemy
{
public:

	Boss(const Point2f& startPos, bool comingFromRight);
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

	virtual void Initialize() override;


};

