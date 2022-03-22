#pragma once
#include "Vector2f.h"

class Texture;
class Platform
{
public:

	Platform(const Point2f& bottomLeft);
	~Platform();
	void Draw() const;
	void HandleCollision(Rectf& actorShape, Vector2f& actorVelocity);
	bool IsOnGround(const Rectf& actorShape, const Vector2f& actorVelocity);


private:

	Rectf m_Shape;
	std::vector <Point2f> m_Vertices;
	Texture* m_pTexture;



};

