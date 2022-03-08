#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include "SVGParser.h"
#include "Camera.h"
#include <iostream>


Level::Level()
	: m_FenceBottomLeft(Point2f{200, 190}),
	m_pBackgroundTexture(new Texture("resources/images/background.png")),
	m_pForegroundTexture(new Texture("resources/images/Fence.png")),
	m_pLevelSVG{},
	m_Vertices{},
	m_Boundaries{0, 0, m_pBackgroundTexture->GetWidth(),m_pBackgroundTexture->GetHeight() }
{
	m_pLevelSVG->GetVerticesFromSvgFile("resources/images/level.svg", m_Vertices);
	
}


Level::~Level()
{
	delete m_pBackgroundTexture;
	delete m_pForegroundTexture;
}


void Level::DrawBackground() const
{
	m_pBackgroundTexture->Draw();
}

void Level::DrawForeground() const
{
	m_pForegroundTexture->Draw(m_FenceBottomLeft);

}

void Level::HandleCollision(Rectf& actorShape, Vector2f& velocity) const
{	
	// The ray
	Point2f ray{ actorShape.left + actorShape.width / 2, actorShape.bottom + actorShape.height };
	Point2f rayBottom{ actorShape.left + actorShape.width / 2, actorShape.bottom+1 };
	
	utils::DrawLine(ray, rayBottom);

	// The raycast
	utils::HitInfo hitInfo{}; // Will hold info about the intersection point
	if (utils::Raycast(m_Vertices[0], ray, rayBottom, hitInfo))
	{
		
		if (rayBottom.y <= hitInfo.intersectPoint.y)
		{
			// Collision with the ground
			actorShape.bottom = hitInfo.intersectPoint.y;
			velocity.y = 0.f;
		}
	}
}

bool Level::IsOnGround(const Rectf& actorShape) const
{
	// The ray
	Point2f ray{ actorShape.left + actorShape.width / 2, actorShape.bottom + actorShape.height };
	Point2f rayBottom{ actorShape.left + actorShape.width / 2, actorShape.bottom - 1 };

	
	// The raycast
	utils::HitInfo hitInfo{}; // Will hold info about the intersection point
	if (utils::Raycast(m_Vertices[0], ray, rayBottom, hitInfo))
	{
		if (actorShape.bottom  <= hitInfo.intersectPoint.y)
		{
			return true;
		}
	}
	
	return false;
}

Rectf Level::GetBoundaries()
{
	return m_Boundaries;
}