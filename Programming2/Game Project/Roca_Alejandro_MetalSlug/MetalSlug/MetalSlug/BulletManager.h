#pragma once
#include <vector>

class Bullet;
class Avatar;
class Enemy;
class GameObject;
class BulletManager final
{
public:

	BulletManager();
	BulletManager(const BulletManager& bulletManager) = delete;
	BulletManager(BulletManager&& bulletManager) = delete;
	BulletManager& operator=(const BulletManager& bulletManager) = delete;
	BulletManager& operator=(BulletManager&& bulletManager) = delete;
	~BulletManager();

	void Update(float elapsedSec, const Avatar* avatar);
	void Draw() const;

	void AddBullet(Point2f& startPos);
	void ActivateBullet();

	void CheckHitLevel();
	void CheckHitGameObjects(std::vector<GameObject*> gameObjects);

	void SetVerticesLevel(std::vector<Point2f> vertices);


private:

	std::vector<Bullet*> m_pBullets;
	std::vector<Point2f> m_VerticesLevel;

	void RandomCollision(int& random);
	

};

