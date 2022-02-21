#include "pch.h"
#include "PowerUp.h"
#include "Texture.h"
#include "utils.h"
#include <iostream>


PowerUp::PowerUp(const Point2f& center, PowerUp::Type type)
	:m_RotSpeed(360.f),
	m_Type(type),
	m_Angle(0.f)
{
	m_pTexture = new Texture("resources/images/PowerUp.png");

	m_Shape.center.x = center.x;
	m_Shape.center.y = center.y;
	m_Shape.radius = m_pTexture->GetWidth()/2;

	// Rectangular clip
	m_TextClip.left = 0.0f;
	m_TextClip.width = m_pTexture->GetWidth();
	m_TextClip.height = m_pTexture->GetHeight() / 2;

	if (m_Type == Type::brown)
	{
		m_TextClip.bottom = m_pTexture->GetHeight();
	}
	else
	{
		// Green
		m_TextClip.bottom = m_pTexture->GetHeight() / 2;
		
	}

}

PowerUp::~PowerUp()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}


void PowerUp::Draw() const
{
	glPushMatrix();		// Put the matrix in the container (the entire scene that is being draw)

	// We want the texture to rotate on his own center
	// 1º First translate to the position of the texture (2D only 2 coord)
	glTranslatef(m_Shape.center.x, m_Shape.center.y, 0.f); 

	// 2º Rotate to a certain angle
	glRotatef(m_Angle, 0, 0, 1.f);  // Angle that we want to rotate
	// 3º Scale to desire size
	glScalef(2.f, 2.f, 1.f);		// We scale the texture so it gets the correct size (2x size)
	// Now we translate back to the original position.
	glTranslatef(-m_Shape.center.x, -m_Shape.center.y, 0); // Rotates his own center

	Rectf dstRect{ m_Shape.center.x - m_Shape.radius/2 , m_Shape.center.y - m_Shape.radius/2, 
		m_Shape.radius, m_Shape.radius };
	m_pTexture->Draw(dstRect, m_TextClip);

	glPopMatrix();  // Remove the matrix from the container (it resets everything)
	
}

void PowerUp::Update(float elapsedSec)
{
	// Updates the angle rotation using elapsedSec and the rotationspeed
	m_Angle += elapsedSec * m_RotSpeed;

}

bool PowerUp::IsOverlapping(const Rectf& rect) const
{
	bool overlap{};

	overlap = utils::IsOverlapping(rect, m_Shape);

	return overlap;
}