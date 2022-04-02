#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include "SVGParser.h"
#include "Matrix2x3.h"



Level::Level()
	:m_pLevelTexture{ new Texture("resources/sprites/level/mission1_level.png")}
	, m_Scale{ 2.7f }
	, m_Boundaries{0.f, 0.f, m_pLevelTexture->GetWidth() * m_Scale,  m_pLevelTexture->GetHeight() * m_Scale }
	, m_Vertices{}
	, m_pLevelSVG{}
{
	m_pLevelSVG->GetVerticesFromSvgFile("resources/sprites/Level/level.svg", m_Vertices);
	TransformSVGVertices();
}


Level::~Level()
{
	delete m_pLevelTexture;
}

// Scale the vertices from the SVG file so it matches with the map size
void Level::TransformSVGVertices()
{
	Matrix2x3 matScale; // Scale matrix
	Matrix2x3 matWorld;  // Resulting matrix

	matScale.SetAsScale(m_Scale);
	
	// TRS Transformation
	matWorld = matScale;

	m_TransformedVertices = matWorld.Transform(m_Vertices[17]);  // Apply transformation
}

void Level::DrawBackground() const
{

}

void Level::DrawForeground() const
{
	glPushMatrix();

	glScalef(m_Scale, m_Scale, 1.f);    // Scale all the map to the correct size
	m_pLevelTexture->Draw();
	
	glPopMatrix();

	//utils::DrawPolygon(m_Vertices[17]);

	//utils::DrawPolygon(m_TransformedVertices);
}


void Level::HandleCollision(Rectf& actorShape, Vector2f& velocity) const
{
	// The ray
	Point2f ray{ actorShape.left + actorShape.width / 2, actorShape.bottom + actorShape.height };
	Point2f rayBottom{ actorShape.left + actorShape.width / 2, actorShape.bottom + 1 };

	utils::DrawLine(ray, rayBottom);

	
	// The raycast
	utils::HitInfo hitInfo{}; // Info about the intersection point
	if (utils::Raycast(m_TransformedVertices, ray, rayBottom, hitInfo))
	{

		if (rayBottom.y <= hitInfo.intersectPoint.y)
		{
			// Collision with the ground
			actorShape.bottom = hitInfo.intersectPoint.y;
			velocity.y = 0.f;
		}
	}

}

// Check if the avatar hits the ground
bool Level::IsOnGround(const Rectf& actorShape, const Vector2f& velocity) const
{
	bool onGround = false;

	// The ray
	Point2f ray{ actorShape.left + actorShape.width / 2, actorShape.bottom + actorShape.height };
	Point2f rayBottom{ actorShape.left + actorShape.width / 2, actorShape.bottom - 1 };

	// The raycast
	utils::HitInfo hitInfo{}; // Will hold info about the intersection point
	if (utils::Raycast(m_TransformedVertices, ray, rayBottom, hitInfo))
	{
		if (actorShape.bottom <= hitInfo.intersectPoint.y)
		{
			onGround = true;
		}
	}
	

	return onGround;
}

Rectf Level::GetBoundaries() const
{
	return m_Boundaries;
}