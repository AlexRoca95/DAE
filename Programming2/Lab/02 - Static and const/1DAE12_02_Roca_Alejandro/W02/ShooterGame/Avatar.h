#pragma once

class Enemy;
class Bullet;

class Avatar
{
public:
	Avatar();
	~Avatar();
	Avatar(const Point2f& center, float width, float height);
	void Update(float elapsedSec, Enemy* pEnemies, int numEnemies);
	void Draw() const;
	void SetCenter(const Point2f& center);
	void SetDimensions(float width, float height);
	void SetBoundaries(const Rectf& boundaries);

private:
	Point2f m_Center;
	float m_Width;
	float m_Height;
	float m_Speed;
	Rectf m_Boundaries;
	Bullet* m_pBullet;
	void Clamp();
	void HandleMoveKeysState(float elapsedSec);
};

