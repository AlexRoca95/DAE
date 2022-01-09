#include "pch.h"
#include "Sprite.h"
#include <iostream>

Sprite::Sprite(const std::string& filename, int nrCols, int nrRows, float frameSec, float scale)
	:m_Cols(nrCols),
	m_Rows(nrRows),
	m_FrameSec(frameSec),
	m_AccuSec(0.f),
	m_ActFrame(0),
	m_Scale(scale)
{
	// Try to load the sprite
	bool load = TextureFromFile(filename, m_Texture);

	if (!load)
		std::cout << "Fail loading sprite " << filename << std::endl;

}

Sprite::~Sprite()
{
	// Free the texture
	utils::DeleteTexture(m_Texture);
}

// Check if the Accumulated time has passed the framerate of the sprite
// If true --> ++ m_Actframe
void Sprite::Update(float elapsedSec)
{
	m_AccuSec += elapsedSec;		// Check how many sec have passed

	if (m_AccuSec > m_FrameSec)
	{
		// Determine the next frame (start 0 - ends at frames - 1)
		++m_ActFrame %= (m_Cols * m_Rows);
		m_AccuSec -= m_FrameSec;

	}


}

// Draw part of the texture as indicated by m_ActFrame at the pos. 
// Scale the sprite with m_Scale
void Sprite::Draw(const Point2f& pos)
{
	Rectf srcRect{};	// Rectangle where we will draw our sprite

	srcRect.width = GetFrameWidth();
	srcRect.height = GetFrameHeight();

	// Left frames will go from 0 to m_Cols - 1
	srcRect.left = srcRect.width * (m_ActFrame % m_Cols);
	// Y of the sprites start on the top (not the bottom)
	srcRect.bottom = srcRect.height * (m_ActFrame / m_Cols + 1);

	// Where we want to draw it
	Rectf destRect{};  // Place where we want to draw the sprite
	destRect.left = pos.x;
	destRect.bottom = pos.y;
	destRect.width = srcRect.width * m_Scale;
	destRect.height = srcRect.height * m_Scale;

	utils::DrawTexture(m_Texture, destRect, srcRect);

}


float Sprite::GetFrameHeight()
{
	return m_Texture.height / m_Rows;
}

float Sprite::GetFrameWidth()
{
	return m_Texture.width / m_Cols;
}

float Sprite::GetScale()
{
	return m_Scale;
}