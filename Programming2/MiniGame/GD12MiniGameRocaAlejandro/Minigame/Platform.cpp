#include "pch.h"
#include "Texture.h"
#include "utils.h"
#include "Platform.h"



Platform::Platform(const Point2f& bottomLeft)
	:m_pTexture{ new Texture{"resources/images/Platform.png"} }
{
	m_Shape.left = bottomLeft.x;
	m_Shape.bottom = bottomLeft.y;
	m_Shape.width = m_pTexture->GetWidth();
	m_Shape.height = m_pTexture->GetHeight();

	m_Vertices.push_back(Point2f{ m_Shape.left, m_Shape.bottom + m_Shape.height });
	m_Vertices.push_back(Point2f{ m_Shape.left + m_Shape.width, m_Shape.bottom + m_Shape.height });
}

Platform::~Platform()
{

	delete m_pTexture;
}


void Platform::Draw() const
{

	m_pTexture->Draw(m_Shape);

}

void Platform::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity)
{
	if (actorVelocity.y < 0.f)
	{
		// The ray
		Point2f ray{ actorShape.left + actorShape.width / 2, actorShape.bottom + actorShape.height };
		Point2f rayBottom{ actorShape.left + actorShape.width / 2, actorShape.bottom };

		utils::DrawLine(ray, rayBottom);

		// The raycast
		utils::HitInfo hitInfo{}; // Will hold info about the intersection point
		if (utils::Raycast(m_Vertices, ray, rayBottom, hitInfo))
		{

			if (rayBottom.y <= hitInfo.intersectPoint.y)
			{
				// Collision with the ground
				actorShape.bottom = hitInfo.intersectPoint.y;
				actorVelocity.y = 0.f;
			}
		}
	}

}

bool Platform::IsOnGround(const Rectf& actorShape, const Vector2f& actorVelocity)
{

	if (actorVelocity.y < 0.f)
	{
		// Actor Going down

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

	}


	return false;

}