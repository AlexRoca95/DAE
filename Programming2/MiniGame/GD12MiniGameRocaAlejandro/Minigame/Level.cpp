#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include <iostream>


Level::Level()
	: m_FenceBottomLeft(Point2f{200, 190}),
	m_pBackgroundTexture(new Texture("resources/images/background.png")),
	m_pForegroundTexture(new Texture("resources/images/Fence.png"))
{

	m_Vertices.push_back(Point2f{ 0, 0 });
	m_Vertices.push_back(Point2f{ 0, 190 });
	m_Vertices.push_back(Point2f{ 340, 190 });
	m_Vertices.push_back(Point2f{ 408, 124 });
	m_Vertices.push_back(Point2f{ 560, 124 });
	m_Vertices.push_back(Point2f{ 660, 224 });
	m_Vertices.push_back(Point2f{ 846, 224 });
	m_Vertices.push_back(Point2f{ 846, 0 });
	m_Vertices.push_back(Point2f{ 0, 0 });
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

void Level::HandleCollision(Rectf& actorShape, Vector2f& velocity)
{	
	// The ray
	Point2f ray{ actorShape.left + actorShape.width / 2, actorShape.bottom + actorShape.height };
	Point2f rayBottom{ actorShape.left + actorShape.width / 2, actorShape.bottom };

	// The raycast
	utils::HitInfo hitInfo{}; // Will hold info about the intersection point
	if (utils::Raycast(m_Vertices, ray, rayBottom, hitInfo))
	{
		if (actorShape.bottom <= hitInfo.intersectPoint.y)
		{
			// Collision with the ground
			actorShape.bottom = hitInfo.intersectPoint.y;
			velocity.y = 0.f;
		}
	}
}

bool Level::IsOnGround(const Rectf& actorShape)
{
	// The ray
	Point2f ray{ actorShape.left + actorShape.width / 2, actorShape.bottom + actorShape.height };
	Point2f rayBottom{ actorShape.left + actorShape.width / 2, actorShape.bottom - 1 };

	// The raycast
	utils::HitInfo hitInfo{}; // Will hold info about the intersection point
	if (utils::Raycast(m_Vertices, ray, rayBottom, hitInfo))
	{
		if (actorShape.bottom <= hitInfo.intersectPoint.y)
		{
			return true;
		}
	}
	
	return false;
}