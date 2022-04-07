#pragma once
#include "utils.h"

class SVGParser;
class Texture;
class Sprite;
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
	void Update(float elapsedSec, const Rectf& ActorShape);

	void TransformSVGVertices();
	void InitSprites();

	// Collisions with the Level
	void HandleCollision(Rectf& actorShape, Vector2f& velocity) const;
	bool IsOnGround(const Rectf& actorShape, const Vector2f& velocity) const;

	
	Rectf GetBoundaries() const;

private:

	// Level sprites
	Sprite* m_pLevelLakeTexture;
	Sprite* m_pLevelTexture;
	
	// Sprites and drawing
	const float m_Scale;				// Scale for the vertices
	const int m_NumberOfPaths;			// Total number of paths from the SVG File
	const int m_Rows;

	// Boundaries of the level
	Rectf m_Boundaries;
	float m_UpperBoundary;					// Upper limit for the level
	float m_BottomBoundary;
	const float m_UpperBoundaryValue;
	const float m_XPosChangeBoundaries;    // Position from where boundaries will change

	std::vector <std::vector<Point2f>> m_Vertices;
	std::vector<std::vector<Point2f>> m_TransformedVertices;
	SVGParser* m_pLevelSVG;

	// Collisions with the Level
	void HorizCollision(Rectf& actorShape, Vector2f& velocity) const;
	void VerticalCollision(Rectf& actorShape, Vector2f& velocity) const;

	void UpdateLevelBoundaries();

};

