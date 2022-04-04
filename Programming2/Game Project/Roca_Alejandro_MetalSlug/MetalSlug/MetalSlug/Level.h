#pragma once
#include "utils.h"

class SVGParser;
class Texture;
class Level final
{
public:

	Level();
	~Level();
	Level(const Level& level) = delete;
	Level(Level&& level) = delete;
	Level& operator=(const Level& level) = delete;
	Level& operator=(Level&& level) = delete;


	void DrawBackground() const;
	void DrawForeground() const;

	void TransformSVGVertices();
	void HandleCollision(Rectf& actorShape, Vector2f& velocity) const;
	bool IsOnGround(const Rectf& actorShape, const Vector2f& velocity) const;
	
	Rectf GetBoundaries() const;

private:

	const Texture* m_pLevelTexture;
	const Texture* m_pLevelLakeTexture;
	const float m_Scale;
	const Rectf m_Boundaries;
	std::vector <std::vector<Point2f>> m_Vertices;
	std::vector<Point2f> m_TransformedVertices;
	SVGParser* m_pLevelSVG;
	

};

