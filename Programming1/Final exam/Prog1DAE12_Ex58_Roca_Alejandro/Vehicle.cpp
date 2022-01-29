#include "pch.h"
#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(int id)
	:m_IsActive(false),
	m_Position(0.f,0.f),
	m_MaxSpeed(200),
	m_MinSpeed(20)
{
	bool load{};

	// Try to load the texture of the car
	std::string path = "Resources/car-truck" + std::to_string(id) +".bmp";
	load = TextureFromFile(path, m_Texture);
	if (!load)
		std::cout << "Error at loading texture " << path << std::endl;

	
	RandomSpeed();
}


// Reset X position from the vehicle to a random pos ( -300, 0 ) 
// and change speed to random (minSpeed, maxSpeed) 
void Vehicle::Reset()
{
	// Take into account the size of the vehicle
	int finalValue = 301 - int(m_Texture.width);
	m_Position.x = float(rand() % finalValue - 300);

	RandomSpeed();
	m_IsActive = true;		// Vehicle activated

}

Vehicle::~Vehicle()
{
	DeleteTexture(m_Texture);
}

// Move vehicle to the right when it is activated.
void Vehicle::Update(float elapsedSec, float windowWidth)
{
	// Only if the vehicle is active
	if (m_IsActive)
	{
		// Move acordding to its speed 
		m_Position.x += m_Speed * elapsedSec;

		if (m_Position.x > windowWidth)
		{
			// Vehicle left the window
			// Reset position to left of the window
			m_Position.x = 0 - m_Texture.width; 
		}

	}
}

void Vehicle::Draw()
{
	DrawTexture(m_Texture, m_Position);
}

// Return true if vehicle intersects with the pos passed by argument
// False otherwise
bool Vehicle::IsIntersecting(const Point2f& pt)
{
	if (pt.x > m_Position.x && pt.x < m_Position.x + m_Texture.width)
	{
		if (pt.y > m_Position.y && pt.y < m_Position.y + m_Texture.height)
		{
			return true;
		}
	}

	return false;
}

void Vehicle::SetActive(bool isActive)
{
	m_IsActive = isActive;
}

void Vehicle::SetYPos(float posY)
{
	m_Position.y = posY;
}

// Change the speed of the vehicle to a random value between minSpeed and maxSpeed
void Vehicle::RandomSpeed()
{
	m_Speed = float(rand() % (m_MaxSpeed - m_MinSpeed + 1) + m_MinSpeed);
}
