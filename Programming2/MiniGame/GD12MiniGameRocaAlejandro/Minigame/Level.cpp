#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include "SVGParser.h"
#include "Camera.h"
#include "Platform.h"
#include <iostream>


Level::Level()
	: m_FenceBottomLeft(Point2f{ 200, 190 }),
	m_pBackgroundTexture(new Texture("resources/images/background.png")),
	m_pForegroundTexture(new Texture("resources/images/Fence.png")),
	m_EndSignTexture(new Texture("resources/images/EndSign.png")),
	m_pLevelSVG{},
	m_Vertices{},
	m_Boundaries{ 0, 0, m_pBackgroundTexture->GetWidth(),m_pBackgroundTexture->GetHeight() },
	m_pPlatform{ new Platform{Point2f{220, 350}} }
{
	m_pLevelSVG->GetVerticesFromSvgFile("resources/images/level.svg", m_Vertices);
	m_EndSignShape.left = 730.f;
	m_EndSignShape.bottom = 224.f;
	m_EndSignShape.width = m_EndSignTexture->GetWidth();
	m_EndSignShape.height = m_EndSignTexture->GetHeight();

}


Level::~Level()
{
	delete m_pBackgroundTexture;
	delete m_pForegroundTexture;
	delete m_pPlatform;
	delete m_EndSignTexture;
}


void Level::DrawBackground() const
{
	m_pBackgroundTexture->Draw();
	m_pPlatform->Draw();
}

void Level::DrawForeground() const
{
	m_pForegroundTexture->Draw(m_FenceBottomLeft);
	m_EndSignTexture->Draw(m_EndSignShape);

}

void Level::HandleCollision(Rectf& actorShape, Vector2f& velocity) const
{	
	// Platform collision
	m_pPlatform->HandleCollision(actorShape, velocity);

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

bool Level::IsOnGround(const Rectf& actorShape, const Vector2f& velocity) const
{
	bool onGround = false;

	onGround = m_pPlatform->IsOnGround(actorShape, velocity);

	if (!onGround)
	{
		// The ray
		Point2f ray{ actorShape.left + actorShape.width / 2, actorShape.bottom + actorShape.height };
		Point2f rayBottom{ actorShape.left + actorShape.width / 2, actorShape.bottom - 1 };

		// The raycast
		utils::HitInfo hitInfo{}; // Will hold info about the intersection point
		if (utils::Raycast(m_Vertices[0], ray, rayBottom, hitInfo))
		{
			if (actorShape.bottom <= hitInfo.intersectPoint.y)
			{
				onGround = true;
			}
		}
	}
	
	return onGround;
}

Rectf Level::GetBoundaries()
{
	return m_Boundaries;
}


bool Level::HasReachedEnd(const Rectf& actorShape) const
{

	if (actorShape.left + actorShape.width > m_EndSignShape.left)
	{
		return true;
	}

	return false;
}