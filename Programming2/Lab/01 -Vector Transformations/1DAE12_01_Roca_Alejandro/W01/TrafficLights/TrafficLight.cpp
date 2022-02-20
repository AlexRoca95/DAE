#include "pch.h"
#include "TrafficLight.h"
#include "utils.h"
#include <iostream>


TrafficLight::TrafficLight(const Point2f& pos)
	:m_State(State::off),
	m_Width(80.f),
	m_Height(200.f),
	m_RadiusCircle(m_Width / 3),
	m_AccumulatedSec(0.f),
	m_Position(pos),
	m_ColorLight(Color4f{ 0.8f, 0.8f, 0.8f, 1.f })
{
	m_Lights[1] = Circlef{ Point2f{ m_Position.x + (m_Width / 2) ,m_Position.y + (m_Height / 2) }, m_RadiusCircle };
	m_Lights[0] = Circlef{ m_Lights[1].center.x, m_Position.y + m_Height - m_RadiusCircle - 10.f , m_RadiusCircle };
	m_Lights[2] = Circlef{ m_Lights[1].center.x, m_Position.y + m_RadiusCircle + 10.f , m_RadiusCircle };

}


void TrafficLight::DoHitTest(const Point2f& point)
{
	bool isPoint{};
	int light{ -1 };

	if (m_State == TrafficLight::State::off)
	{
		// Traffic light disabled. Check if one the lights was clicked
		for (int i{0}; i < m_NrLights && !isPoint; i++)
		{
			isPoint = utils::IsPointInCircle(point, m_Lights[i]);
			if (isPoint)
			{
				// Light clicked. Save wich light was it
				light = i;
			}
		}

		switch (light)
		{
		case 0:  // Top
			m_State = TrafficLight::State::red;
			m_AccumulatedSec = 0.f;
			break;
		case 1: // Middle
			m_State = TrafficLight::State::orange;
			m_AccumulatedSec = 0.f;
			break;
		case 2: // Bottom
			m_State = TrafficLight::State::green;
			m_AccumulatedSec = 0.f;
			break;
		}
	}
	
	if (m_State != TrafficLight::State::off)
	{
		// Traffic light is ON

		// Check if we are not clicking any circle
		for (int i{ 0 }; i < m_NrLights && !isPoint; i++)
		{
			isPoint = utils::IsPointInCircle(point, m_Lights[i]);
		}

		if (!isPoint)
		{	
			// No light was clicked
			// Check if armature was clicked
			isPoint = utils::IsPointInRect(point, Rectf{ m_Position.x,m_Position.y,
				m_Width, m_Height });
			if (isPoint)
			{
				// Disable traffic light
				m_State = TrafficLight::State::off;
			}
		}

	}
		
}
void TrafficLight::Update(float elapsedSec)
{
	m_AccumulatedSec += elapsedSec;

	switch (m_State)
	{
	case TrafficLight::State::red:
		if (m_AccumulatedSec >= 4.f)
		{
			m_AccumulatedSec = 0.f;
			m_State = TrafficLight::State::green;
		}
		break;
	case TrafficLight::State::orange:
		if (m_AccumulatedSec >= 1.f)
		{
			m_AccumulatedSec = 0.f;
			m_State = TrafficLight::State::red;
		}
		break;
	case TrafficLight::State::green:
		if (m_AccumulatedSec >= 4.f)
		{
			m_AccumulatedSec = 0.f;
			m_State = TrafficLight::State::orange;
		}
		break;
	}


}
void TrafficLight::Draw() const
{
	// Armature
	utils::SetColor(Color4f(0.f, 0.f, 0.f, 1.f));
	utils::FillRect(m_Position, m_Width, m_Height);
	
	utils::SetColor(Color4f{ 0.6f, 0.6f, 0.6f, 1.0f });  // Grey color

	// Draw all the lights
	for (int i{ 0 }; i < m_NrLights; i++)
	{
		utils::FillEllipse(m_Lights[i].center, m_Lights[i].radius, m_Lights[i].radius);
	}


	switch (m_State)  // Check color to draw in the traffic light
	{
	case State::red:
		utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.0f });
		utils::FillEllipse(m_Lights[0].center, m_Lights[0].radius, m_Lights[0].radius);
		break;

	case State::orange:
		utils::SetColor(Color4f{ 1.f, 0.50f, 0.f, 1.0f });
		utils::FillEllipse(m_Lights[1].center, m_Lights[0].radius, m_Lights[0].radius);
		break;

	case State::green:
		utils::SetColor(Color4f{ 0.f, 1.f, 0.f, 1.0f });
		utils::FillEllipse(m_Lights[2].center, m_Lights[2].radius, m_Lights[2].radius);
		break;

	};

}

float TrafficLight::getWidth() const
{
	return m_Width;
}
float TrafficLight::getHeight() const
{
	return m_Height;
}



