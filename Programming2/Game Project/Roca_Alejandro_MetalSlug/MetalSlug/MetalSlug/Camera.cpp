#include "pch.h"
#include "Camera.h"
#include <iostream>

Camera::Camera(float width, float height)
	:m_Width(width)
	, m_Height(height)
	, m_LevelBoundaries{ 0, 0, width, height }
{


}

// Change the camera position to the new position calculated by Clamp and Track
void Camera::Transform(const Rectf& target) const
{
	Point2f m_NewCameraPos;
	m_NewCameraPos = Track(target);

	Clamp(m_NewCameraPos);

	glTranslatef(-m_NewCameraPos.x, -m_NewCameraPos.y, 0.f);
}

// Correct camera pos so it doesn't leave the boundaries
void Camera::Clamp(Point2f& bottomLeftPos) const
{
	if (m_LevelBoundaries.left > bottomLeftPos.x)
	{
		bottomLeftPos.x = 0;
	}

	if ( ( m_LevelBoundaries.left + m_LevelBoundaries.width ) < ( bottomLeftPos.x + m_Width ))
	{
		bottomLeftPos.x = m_LevelBoundaries.width - m_Width;
	}


	if ( (m_LevelBoundaries.bottom + m_LevelBoundaries.height ) < ( bottomLeftPos.y + m_Height ))
	{
		bottomLeftPos.y = m_LevelBoundaries.height - m_Height;
	}



	if ( m_LevelBoundaries.bottom > bottomLeftPos.y )
	{
		bottomLeftPos.y = m_LevelBoundaries.bottom;
		
	}

}

// Keep track of the pos of the Avatar
// Camera is center in X pos but not in Y in order to not exit the boundaries of the level
Point2f Camera::Track(const Rectf target) const
{
	Point2f newPos{};

	newPos.x = (target.left + target.width / 2) - (m_Width / 2);
	newPos.y = (target.bottom + target.height / 2) - (m_Height / 4.5f);

	return newPos;
}


void Camera::SetLevelBoundaries(const Rectf& levelBoundaries)
{
	m_LevelBoundaries = levelBoundaries;
}
