#pragma once
#include "utils.h"

class Texture;

class Level
{
public:

	Level();
	~Level();
	void DrawBackground() const;
	void DrawForeground() const;
	void HandleCollision(Rectf& actorShape, Vector2f& velocity) const;
	bool IsOnGround(const Rectf& actorShape) const;

private:

	std::vector <Point2f> m_Vertices;
	Texture* m_pBackgroundTexture;
	Texture* m_pForegroundTexture;
	Point2f m_FenceBottomLeft;

};

