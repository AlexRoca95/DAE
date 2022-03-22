#pragma once
#include "utils.h"


class Texture;
class SVGParser;
class Platform;
class Level
{
public:

	Level();
	~Level();
	void DrawBackground() const;
	void DrawForeground() const;
	void HandleCollision(Rectf& actorShape, Vector2f& velocity) const;
	bool IsOnGround(const Rectf& actorShape, const Vector2f& velocity) const;
	Rectf GetBoundaries();
	bool HasReachedEnd(const Rectf& actorShape) const;

private:

	SVGParser* m_pLevelSVG;	
	Platform* m_pPlatform;
	std::vector <std::vector<Point2f>> m_Vertices;
	const Texture* m_pBackgroundTexture;
	const Texture* m_pForegroundTexture;
	const Texture* m_EndSignTexture;
	Rectf m_EndSignShape;
	Point2f m_FenceBottomLeft;
	Rectf m_Boundaries;
	
};

