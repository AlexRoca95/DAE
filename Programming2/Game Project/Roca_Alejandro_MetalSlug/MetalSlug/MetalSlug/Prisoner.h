#pragma once
#include "Enemy.h"

class Prisoner final : public Enemy
{

public:
	Prisoner(const Point2f& startPos);
	virtual ~Prisoner();
	Prisoner(const Prisoner& prisioner) = delete;
	Prisoner(Prisoner&& prisioner) = delete;
	Prisoner& operator=(const Prisoner& prisioner) = delete;
	Prisoner& operator=(Prisoner&& prisioner) = delete;

	virtual void Draw() const override;
	virtual void Hit() override;
	virtual void CheckGameState() override;

	virtual void Update(float elapsedSec, Avatar* avatar, const Level* level) override;

	void CheckAvatarRelease(const Rectf& avatarShape);


	bool GetDropItem() const;

	void ItemDropped();

private:

	// Time waiting after giving object
	const float m_MaxTimeWait;
	float m_SecondsWait;

	bool m_IsReleased;
	bool m_DropItem;
	bool m_IsItemDropped;

	void Initialize();

	void ReleasePrisoner(float elapsedSec);
	void GiveObject(float elapsedSec);

};

