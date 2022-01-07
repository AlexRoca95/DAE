#include "pch.h"   // Utils functions, Color4f and Point2f
#include "BouncingCircle.h"


// Constructor
BouncingCircle::BouncingCircle(float windowWidth, float windowHeight)
	:m_WindowWidth{windowWidth}, m_WindowHeight{windowHeight},
	m_CircleColor{ Color4f{ rand() % 256 / 255.0f,rand() % 256 / 255.0f,rand() % 256 / 255.0f,1 } },
	m_CirclePosition{ Point2f{ 200 , 200} },
	m_CircleRadius { 50 }
{
	// Inside because if not it wouldnt initialize correctly due to the list order in the header
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
}

void BouncingCircle::CheckCollisionCircle()
{
	
	if (m_CirclePosition.x - m_CircleRadius <= 0 && m_CircleSpeedX < 0) m_CircleSpeedX *= -1;

	if (m_CirclePosition.x + m_CircleRadius >= m_WindowWidth && m_CircleSpeedX > 0) m_CircleSpeedX *= -1;

	if (m_CirclePosition.y - m_CircleRadius <= 0 && m_CircleSpeedY < 0) m_CircleSpeedY *= -1;

	if (m_CirclePosition.y + m_CircleRadius >= m_WindowHeight && m_CircleSpeedY > 0) m_CircleSpeedY *= -1;
	

}