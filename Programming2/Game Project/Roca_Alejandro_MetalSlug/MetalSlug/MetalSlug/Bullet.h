#include "GameObject.h"

class Avatar;
#pragma once
class Bullet final : public GameObject
{

public:

	Bullet( const Point2f& startPos);
	Bullet(const Bullet& bullet) = delete;
	Bullet(Bullet&& bullet) = delete;
	Bullet& operator=(const Bullet& bullet) = delete;
	Bullet& operator=(Bullet&& bullet) = delete;
	~Bullet( );


	virtual void Draw() const override;
	virtual void Update(float elapsedSeconds, const Level* level);
	virtual bool GetIsActive() const;
	virtual void SetIsActive(bool active);

	void Update(float elapsedSec, const Avatar* avatar);

	
	void DesactivateBullet();
	void CheckHitLevel();
	void Hit();

	Rectf GetShape() const;

private:

	Sprite* m_pCollisionSprite;


	Point2f m_Position;
	bool m_IsInitialized;
	bool m_IsMovingUp;
	bool m_IsHit;

	const float m_MaxSeconds;     // Time the bullet is active if it doesn't collide 
	float m_Seconds;			  // Current Seconds
	const float m_Speed;
	Point2f m_Velocity;
	


	void Initialize();
	void SetStartPos(const Avatar* avatar);
	void Move(float elapsedSec);



};

