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

}

void Sprite::Update(float elapsedSec)
{

}

void Sprite::Draw(const Point2f& pos)
{

}


float Sprite::GetFrameHeight()
{
	return m_Texture.height;
}

float Sprite::GetFrameWidth()
{
	return m_Texture.width;
}