#include "pch.h"
#include "BouncingCircle.h"
#include "utils.h"
#include <iostream>

BouncingCircle::BouncingCircle(const Rectf& boundingRect)
	: BouncingCircle{ boundingRect, 50, Point2f{100,100} }  // We call the second constr from the 1º one
	
{	 

}

BouncingCircle::BouncingCircle(const Rectf& boundingRect, float radius, const Point2f& position)
	: m_BoundingRect{boundingRect}
	, m_CirclePosition{ position }
	, m_CircleRadius{ radius }
	, m_CircleColor{ Color4f{ rand() % 256 / 255.0f,rand() % 256 / 255.0f,rand() % 256 / 255.0f,1 } }
	, m_MaxSpeed{ 500 }, m_MinSpeed{ 250 }	
{

	// Circle speed relies on the max speed, but circle speed is initializing before the max one 
	// so it doesnt get a good value (this is because it depends on the order of declaration in the .h file)

	m_CircleSpeedX = rand() % (int(m_MaxSpeed - m_MinSpeed) + 1) - m_MinSpeed;
	m_CircleSpeedY = rand() % (int(m_MaxSpeed - m_MinSpeed) + 1) - m_MinSpeed;
}
void BouncingCircle::DrawCircle()
{
	utils::SetColor(m_CircleColor);
	utils::FillEllipse(m_CirclePosition, m_CircleRadius, m_CircleRadius);
}

void BouncingCircle::UpdateCircle(float elapsedSec)
{
	m_CirclePosition.x += m_CircleSpeedX * elapsedSec;
	m_CirclePosition.y += m_CircleSpeedY * elapsedSec;
	CheckCollisionCircle();
}

void BouncingCircle::CheckCollisionCircle()
{
	// Check left edge
	if (m_CirclePosition.x - m_CircleRadius <= m_BoundingRect.left && m_CircleSpeedX < 0) m_CircleSpeedX *= -1;

	// Check right edge
	if (m_CirclePosition.x + m_CircleRadius >= m_BoundingRect.left + m_BoundingRect.width && m_CircleSpeedX > 0) m_CircleSpeedX *= -1;

	// Bottom edge
	if (m_CirclePosition.y - m_CircleRadius <= m_BoundingRect.bottom && m_CircleSpeedY < 0) m_CircleSpeedY *= -1;
	
	// Top edge
	if (m_CirclePosition.y + m_CircleRadius >= m_BoundingRect.bottom + m_BoundingRect.height && m_CircleSpeedY > 0) m_CircleSpeedY *= -1;
}


BouncingCircle::~BouncingCircle()
{
	std::cout << "Destructor of the BouncingCircle is being executed" << std::endl;

}

bool BouncingCircle::IsHit(const Point2f& pos)
{

	float dX{ pos.x - m_CirclePosition.x };
	float dY{ pos.y - m_CirclePosition.y };

	if (dX * dX + dY * dY < m_CircleRadius * m_CircleRadius)
	{
		// Circle hitted
		return true;
	}

	return false;
}