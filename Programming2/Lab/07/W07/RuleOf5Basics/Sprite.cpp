#include "pch.h"
#include "Sprite.h"

#include "Texture.h"

Sprite::Sprite( const std::string& path, int cols, int rows, float frameSec )
	: m_Path{path}
	, m_Cols( cols )
	, m_Rows( rows )
	, m_FrameSec( frameSec )
	, m_AccuSec{}
	, m_ActFrame{}
	, m_pTexture{ new Texture( m_Path ) }
{
	//m_pTexture = new Texture( path );
}


Sprite::Sprite(const Sprite& spr1)
	: m_Cols(spr1.m_Cols)
	, m_Rows(spr1.m_Rows)
	, m_FrameSec(spr1.m_FrameSec)
	, m_AccuSec{ spr1.m_AccuSec}
	, m_ActFrame{spr1.m_ActFrame}
	, m_Path{spr1.m_Path}
	, m_pTexture{new Texture(spr1.m_Path)}  // Not copy the sprite, only the path
{

}

Sprite& Sprite::operator=(const Sprite& spr1)
{
	if (this != &spr1)
	{
		m_Cols = spr1.m_Cols;
		m_Rows = spr1.m_Rows;
		m_FrameSec = spr1.m_FrameSec;
		m_AccuSec = spr1.m_AccuSec;
		m_ActFrame = spr1.m_ActFrame;
		m_Path = spr1.m_Path;
		
		delete m_pTexture;

		m_pTexture = new Texture(spr1.m_Path);


	}

	return *this;
}

Sprite::Sprite(Sprite&& spr1)
	: m_Path{spr1.m_Path}
	,m_Cols(spr1.m_Cols)
	, m_Rows(spr1.m_Rows)
	, m_FrameSec(spr1.m_FrameSec)
	, m_AccuSec{ spr1.m_AccuSec }
	, m_ActFrame{ spr1.m_ActFrame }
	, m_pTexture{ new Texture(spr1.m_Path) }  // Not copy the sprite, only the path
{
	spr1.m_Cols = 0;
	spr1.m_Rows = 0;
	spr1.m_FrameSec = 0.f;
	spr1.m_AccuSec = 0.f;
	spr1.m_ActFrame = 0;
	delete spr1.m_pTexture;
	spr1.m_pTexture = nullptr;

}

Sprite& Sprite::operator= (Sprite&& spr1)
{
	if (this != &spr1)
	{
		delete m_pTexture;
		
		m_Cols = spr1.m_Cols;
		m_Rows = spr1.m_Rows;
		m_FrameSec = spr1.m_FrameSec;
		m_AccuSec = spr1.m_AccuSec;
		m_ActFrame = spr1.m_ActFrame;
		m_Path = spr1.m_Path;
		m_pTexture = new Texture(spr1.m_Path);

		spr1.m_Cols = 0;
		spr1.m_Rows = 0;
		spr1.m_FrameSec = 0.f;
		spr1.m_AccuSec = 0.f;
		spr1.m_ActFrame = 0;
		spr1.m_Path = "";
		delete spr1.m_pTexture;
		spr1.m_pTexture = nullptr;
	}

	return *this;
}

Sprite::~Sprite( )
{
	delete m_pTexture;
}

void Sprite::Update( float elapsedSec )
{
	m_AccuSec += elapsedSec;

	if ( m_AccuSec > m_FrameSec )
	{
		// Go to next frame
		++m_ActFrame;
		if ( m_ActFrame >= m_Cols * m_Rows )
		{
			m_ActFrame = 0;
		}

		// Only keep the remaining time
		m_AccuSec -= m_FrameSec;
	}
}

void Sprite::Draw( const Point2f& pos, float scale )
{
	// frame dimensions
	const float frameWidth{  m_pTexture->GetWidth() / m_Cols };
	const float frameHeight{  m_pTexture->GetHeight() / m_Rows };
	int row = m_ActFrame / m_Cols;
	int col = m_ActFrame % m_Cols;

	Rectf srcRect;
	srcRect.height = frameHeight;
	srcRect.width = frameWidth;
	srcRect.left = m_ActFrame % m_Cols * srcRect.width;
	srcRect.bottom = m_ActFrame / m_Cols * srcRect.height + srcRect.height;
	Rectf destRect{ pos.x, pos.y,srcRect.width * scale,srcRect.height * scale };
	m_pTexture->Draw( destRect, srcRect );
}

float Sprite::GetFrameWidth( )
{
	return m_pTexture->GetWidth( ) / m_Cols;
}

float Sprite::GetFrameHeight( )
{
	return m_pTexture->GetHeight( ) / m_Rows;
}

