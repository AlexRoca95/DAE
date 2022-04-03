#include "pch.h"
#include "Sprite.h"

#include "Texture.h"

Sprite::Sprite( const std::string& path, int cols, int rows, float frameSec, float scale )
	: m_Path{path}
	, m_Cols( cols )
	, m_Rows( rows )
	, m_FrameSec( frameSec )
	, m_AccuSec{}
	, m_ActFrame{}
	, m_pTexture{ new Texture( m_Path ) }
	, m_SrcRect{}
	, m_DstRect{}
	, m_Width{}
	, m_Height{} 
	, m_Scale{ scale }
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
	, m_SrcRect{}
	, m_DstRect{}
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
		m_SrcRect = spr1.m_SrcRect;
		m_DstRect = spr1.m_DstRect;

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
	, m_SrcRect{}
	, m_DstRect{}

{
	spr1.m_Cols = 0;
	spr1.m_Rows = 0;
	spr1.m_FrameSec = 0.f;
	spr1.m_AccuSec = 0.f;
	spr1.m_ActFrame = 0;
	spr1.m_DstRect = Rectf{};
	spr1.m_SrcRect = Rectf{};
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
		m_SrcRect = spr1.m_SrcRect;
		m_DstRect = spr1.m_DstRect;
		m_pTexture = new Texture(spr1.m_Path);

		spr1.m_Cols = 0;
		spr1.m_Rows = 0;
		spr1.m_FrameSec = 0.f;
		spr1.m_AccuSec = 0.f;
		spr1.m_ActFrame = 0;
		spr1.m_DstRect = Rectf{};
		spr1.m_SrcRect = Rectf{};
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
		// Change the left pos of spritesheet according with active frame
		UpdateLeftSrcRect();  

		// Only keep the remaining time
		m_AccuSec -= m_FrameSec;
	}
}

// Update all the values for the sprite. 
void Sprite::UpdateValues(int cols, int rows, int frames, float frameSec, float width, float height, float spriteSheetTop)
{

	m_Frames = frames;
	m_Cols = cols;
	m_Rows = rows;
	m_FrameSec = 1 / frameSec;
	m_Width = width;
	m_Height = height;
	m_SpriteSheetTop = spriteSheetTop;

	SetDstRect(m_Width, m_Height);						// Update size of m_DstRect
	SetSrcRect(m_SpriteSheetTop, m_Width, m_Height);	// Update the y, widht and height of m_SrcRect

}

void Sprite::Draw( /*const Point2f& pos, float scale*/) const
{
	m_pTexture->Draw(m_DstRect, m_SrcRect);
}

void Sprite::ResetActFrame()
{
	m_ActFrame = 0;
}

float Sprite::GetFrameWidth( )
{
	//return m_pTexture->GetWidth( ) / m_Cols;

	return m_Width;
}

float Sprite::GetFrameHeight( )
{
	//return m_pTexture->GetHeight( ) / m_Rows;
	return m_Height;
}

Rectf Sprite::GetSrcRect()
{
	return m_SrcRect;
}
Rectf& Sprite::GetDstRect()
{
	return m_DstRect;
}


void Sprite::SetDstRect(float x, float y, float width, float height)
{

	m_DstRect.left = x;
	m_DstRect.bottom = y;
	m_DstRect.width = width;
	m_DstRect.height = height;

}

void Sprite::SetDstRect(float width, float height)
{
	m_DstRect.width = width * m_Scale;  // Apply the scale of the sprite we want
	m_DstRect.height = height * m_Scale;
}

void Sprite::SetLeftDstRect(float left)
{
	m_DstRect.left = left;
}

void Sprite::SetBottomDstRect(float bottom)
{
	m_DstRect.bottom = bottom;
}

void Sprite::SetSrcRect(float y, float width, float height)
{
	m_SrcRect.bottom = m_SpriteSheetTop;
	m_SrcRect.width = m_Width;
	m_SrcRect.height = m_Height;
	
}

// Set the correct left sprite pos  of the spritesheet 
void Sprite::UpdateLeftSrcRect()
{
	m_SrcRect.left = m_Width * m_ActFrame;
}