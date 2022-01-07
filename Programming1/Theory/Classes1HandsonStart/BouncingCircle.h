#pragma once


class BouncingCircle {

public:
	BouncingCircle(float m_WindowWidth, float m_WindowHeigth);
	void DrawCircle();
	void UpdateCircle(float elapsedSec);
	void CheckCollisionCircle();

private:  // The order of this matter when you initialize the members with the member list at the constructor
	Color4f m_CircleColor{};
	Point2f m_CirclePosition{};
	float m_CircleSpeedX{};
	float m_CircleSpeedY{};
	float m_CircleRadius{};
	const float m_MaxSpeed{ 500 }, m_MinSpeed{ 250 };
	const float m_WindowWidth, m_WindowHeight;
};