// -- Smiley.cpp file --
#include "pch.h"
#include "Smiley.h"
#include "Texture.h"
#include "utils.h"
#include <iostream>

// Static Texture data
Texture* Smiley::m_pSmileyTexture{ nullptr };
int Smiley::m_InstanceCounter{ 0 };

// Constructor
// Initializes the object, among others:
//	- Initializes the data members, the velocity gets a random value within the inclusive range[60, 180] and [-180, -60]
//	- Creates a texture object to load the image, only if it hasn’t been created before( !)
//  - Adapts the instance counter
Smiley::Smiley( const Point2f& position )
	:m_Position(position),
	m_IsHighest(false),
	m_IsInSafeArea(true),
	m_IsSleeping(false)
{
	// Random velocity [180, 60] && [-180, -60]
	m_Velocity.x = float((rand() % 121) + 60);
	m_Velocity.y = float((rand() % 121) + 60);
	int randomSign = rand() % 2;

	if (randomSign == 1)
	{
		m_Velocity.x = -m_Velocity.x;
	}

	randomSign = rand() % 2;
	if (randomSign == 1)
	{
		m_Velocity.y = -m_Velocity.y;
	}

	if (m_InstanceCounter == 0)
	{
		m_pSmileyTexture = new Texture("resources/Smileys.png");
	}
	
	m_InstanceCounter++;

}

// Destructor
// Deletes the Texture object when this is the last Smiley that is being destroyed.
Smiley::~Smiley( )
{
	m_InstanceCounter--;

	if (m_InstanceCounter == 0)
	{
		delete m_pSmileyTexture;
		m_pSmileyTexture = nullptr;
	}
}

// Draw
// Draws a part of the image on the window, which part depends on the state of the smiley:
// - If the smiley is sleeping then the sleeping smiley is drawn.
// - If the smiley is at the highest position, then the happy smiley is drawn.
// - If the smiley is not in the safe area, the scary smiley is drawn.
// - If none of the above conditions is met, the neutral smiley should be drawn.
void Smiley::Draw( ) const
{

	Rectf destRect{ m_Position.x, m_Position.y, m_pSmileyTexture->GetWidth() / 4,  m_pSmileyTexture->GetHeight() };
	Rectf srcRect{ 0.f, m_pSmileyTexture->GetHeight(), m_pSmileyTexture->GetWidth() / 4,  m_pSmileyTexture->GetHeight() };


	if (m_IsSleeping)
	{
		// Sleeping
		srcRect.left = 150.f;
	}
	else
	{
		if (m_IsHighest)
		{
			// Higghest smiley
			srcRect.left = 0.f;
		}
		else
		{
			if (!m_IsInSafeArea)
			{
				// Not in the safe area
				srcRect.left = 100.f;
			}
			else
			{
				// Neutral face
				srcRect.left = 50.f;
			}
		}
	}
	

	m_pSmileyTexture->Draw(destRect, srcRect);

}



// Update
// - When the smiley is not sleeping, the new position - using the velocity and elapsed seconds - is calculated.
// - The velocity changes sign when at this new position the smiley is outside the bounding rectangle (boundingRect)
// - Checks whether at this new position, it is located in the safe area and updates m_IsInSafeArea accordingly.
void Smiley::Update( float elapsedSec, const Rectf& boundingRect, const Rectf& safeRect )
{
	if (!m_IsSleeping)
	{
		// Not sleeping. We update
		// Bouncing smiley
		// Check X position
		if (m_Position.x + m_pSmileyTexture->GetWidth() / 4 >= boundingRect.left + boundingRect.width
			|| m_Position.x <= boundingRect.left)
		{
			m_Velocity.x = (-1) * m_Velocity.x;
		}

		// Check Y pos
		if (m_Position.y + m_pSmileyTexture->GetHeight() >= boundingRect.bottom + boundingRect.height
			|| m_Position.y <= boundingRect.bottom)
		{
			m_Velocity.y = (-1) * m_Velocity.y;
		}

		// Check inside safe area
		m_IsInSafeArea = IsInSafeArea(safeRect);

		m_Position += m_Velocity * elapsedSec;
	}
	
	
}

// HitTest
// If the value of the parameter pos is within the boundaries of the smiley’s circle,
// then the sleeping state of the smiley changes.
void Smiley::HitTest( const Point2f& pos )
{
	if (pos.x >= m_Position.x && pos.x <= m_Position.x + m_pSmileyTexture->GetWidth()/4)
	{
		if (pos.y >= m_Position.y && pos.y <= m_Position.y + m_pSmileyTexture->GetHeight())
		{
			// Smiley hit

			if (m_IsSleeping)
			{
				// Already sleeping. Awake
				m_IsSleeping = false;
			}
			else
			{
				// Put it in sleeping mode
				m_IsSleeping = true;
			}
			// In case it was the highest smiley
			m_IsHighest = false;
		}
	}
}

// IsSleeping
// Getter of the m_IsSleeping data member
bool Smiley::IsSleeping( ) const
{
	return m_IsSleeping; 
}

// GetPosition
// Getter of the m_Position data member
Point2f Smiley::GetPosition( ) const
{
	return m_Position;
}

// SetHighest
// Setter of the m_IsHighest data member
void Smiley::SetHighest( bool isHighest )
{
	m_IsHighest = isHighest;

}

// IncreaseSpeed
// Changes the speed 5% up
void Smiley::IncreaseSpeed( )
{
	m_Velocity.x += (m_Velocity.x / 100) * 5;
	m_Velocity.y += (m_Velocity.y / 100) * 5;
}

// DecreaseSpeed
// Changes the speed 5% down
void Smiley::DecreaseSpeed( )
{
	m_Velocity.x += (-1) * (m_Velocity.x / 100) * 5;
	m_Velocity.y += (-1) * (m_Velocity.y / 100) * 5;
}

// IsInSafeArea
// Returns true when the smiley is completely inside the safe area as indicated by safeRect
bool Smiley::IsInSafeArea( const Rectf& safeRect ) const
{
	if (m_Position.x >= safeRect.left && m_Position.x + m_pSmileyTexture->GetWidth() / 4 <= safeRect.width + safeRect.left)
	{
		if (m_Position.y >= safeRect.bottom && m_Position.y + m_pSmileyTexture->GetHeight() <= safeRect.height + safeRect.bottom)
		{
			// Inside safe area
			return true;
		}
	}

	return false; 
}



