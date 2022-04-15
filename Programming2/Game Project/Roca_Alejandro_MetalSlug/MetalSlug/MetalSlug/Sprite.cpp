#include "pch.h"
#include "Sprite.h"

#include "Texture.h"
#include <iostream>

Sprite::Sprite( const std::string& path, int cols, int rows, float frameSec, float scale )
	: m_Path{ path }
	, m_Cols( cols )
	, m_Rows( rows )
	, m_FrameSec( frameSec )
	, m_AccuSec{ }
	, m_ActFrame{ }
	, m_pTexture{ new Texture( m_Path ) }
	, m_SrcRect{ }
	, m_DstRect{ }
	, m_Width{ }
	, m_Height{ } 
	, m_Scale{ scale }
	, m_IsFinish{ false }
	, m_Frames{ }
	, m_SpriteSheetTop{ }
{
	
}


Sprite::Sprite(const Sprite& spr1)
	: m_Cols(spr1.m_Cols)
	, m_Rows(spr1.m_Rows)
	, m_FrameSec(spr1.m_FrameSec)
	, m_AccuSec{ spr1.m_AccuSec}
	, m_ActFrame{spr1.m_ActFrame}
	, m_Path{spr1.m_Path}
	, m_pTexture{new Texture(spr1.m_Path)}  // Not copy the sprite, only the path
	, m_SrcRect{ spr1.m_SrcRect }
	, m_DstRect{ spr1.m_DstRect }
	, m_Width{ spr1.m_Width }
	, m_Height{ spr1.m_Height }
	, m_Scale{ spr1.m_Scale }
	, m_IsFinish{ spr1.m_IsFinish }
	, m_Frames{ spr1.m_Frames }
	, m_SpriteSheetTop{ spr1.m_SpriteSheetTop }
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
		m_Width = spr1.m_Width;
		m_Height = spr1.m_Height;
		m_Scale = spr1.m_Scale;
		m_IsFinish = spr1.m_IsFinish;
		m_Frames = spr1.m_Frames;
		m_SpriteSheetTop = spr1.m_SpriteSheetTop;

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
	, m_Width{ spr1.m_Width }
	, m_Height{ spr1.m_Height }
	, m_Scale{ spr1.m_Scale }
	, m_IsFinish{ spr1.m_IsFinish }
	, m_Frames{ spr1.m_Frames }
	, m_SpriteSheetTop{ spr1.m_SpriteSheetTop }

{
	spr1.m_Cols = 0;
	spr1.m_Rows = 0;
	spr1.m_FrameSec = 0.f;
	spr1.m_AccuSec = 0.f;
	spr1.m_ActFrame = 0;
	spr1.m_DstRect = Rectf{};
	spr1.m_SrcRect = Rectf{};
	spr1.m_Width = 0.f;
	spr1.m_Height = 0.f;
	spr1.m_Scale = 0.f;
	spr1.m_IsFinish = false;
	spr1.m_Frames = 0;
	spr1.m_SpriteSheetTop = 0.f;

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
		m_Width = spr1.m_Width;
		m_Height = spr1.m_Height;
		m_Scale = spr1.m_Scale;
		m_IsFinish = spr1.m_IsFinish;
		m_Frames = spr1.m_Frames;
		m_SpriteSheetTop = spr1.m_SpriteSheetTop;

		m_pTexture = new Texture(spr1.m_Path);

		spr1.m_Cols = 0;
		spr1.m_Rows = 0;
		spr1.m_FrameSec = 0.f;
		spr1.m_AccuSec = 0.f;
		spr1.m_ActFrame = 0;
		spr1.m_DstRect = Rectf{};
		spr1.m_SrcRect = Rectf{};
		spr1.m_Path = "";
		spr1.m_Width = 0.f;
		spr1.m_Height = 0.f;
		spr1.m_Scale = 0.f;
		spr1.m_IsFinish = false;
		spr1.m_Frames = 0;
		spr1.m_SpriteSheetTop = 0.f;

		delete spr1.m_pTexture;
		spr1.m_pTexture = nullptr;
	}

	return *this;
}

Sprite::~Sprite( )
{
	delete m_pTexture;
}

void Sprite::Update( float elapsedSec, const bool repeat )
{
	m_AccuSec += elapsedSec;
	
	if ( m_AccuSec > m_FrameSec )
	{
		++m_ActFrame;

		// Loop Animations
		if ( m_ActFrame >= ( m_Cols * m_Rows ) && repeat )
		{
			m_ActFrame = 0;
			
		}
		else
		{
			// No Loop Animations
			if (m_ActFrame >= (m_Cols * m_Rows ) && !repeat)
			{
				m_ActFrame = m_Cols - 1;
				m_IsFinish = true;	// Animation finished

			}
		}

		// Change the left and bottom pos of spritesheet according with active frame
		UpdateLeftSrcRect();  
		UpdateBottomSrcRect();

		// Only keep the remaining time
		m_AccuSec -= m_FrameSec;
	}
}

// Update all the values for the sprite. 
void Sprite::UpdateValues(const int cols, const int rows, const int frames, const float frameSec, const float width,
	const float height, const float spriteSheetTop, const float scale)
{

	m_Frames = frames;
	m_Cols = cols;
	m_Rows = rows;
	m_FrameSec = 1 / frameSec;
	m_Width = width;
	m_Height = height;
	m_SpriteSheetTop = spriteSheetTop;
	m_Scale = scale;

	SetDstRect(m_Width, m_Height);						// Update size of m_DstRect
	SetSrcRect(m_SpriteSheetTop, m_Width, m_Height);	// Update the y, widht and height of m_SrcRect

}

void Sprite::Draw( ) const
{
	m_pTexture->Draw(m_DstRect, m_SrcRect);
}

// Flip the sprite to the oposite side using OpenGL
void Sprite::FlipSprite() const
{
	glTranslatef( m_DstRect.left + m_Width, m_DstRect.bottom + m_Height, 0.f );

	glScalef(-1, 1, 1.f);

	glTranslatef(-(m_DstRect.left + m_Width ), -( m_DstRect.bottom + m_Height ), 0.f );
}

void Sprite::ResetActFrame( )
{
	m_ActFrame = 0;
}

float Sprite::GetFrameWidth( ) const
{
	return m_Width;
}

float Sprite::GetFrameHeight( ) const
{
	return m_Height;
}

int Sprite::GetActFrame( ) const
{

	return m_ActFrame;

}
Rectf Sprite::GetSrcRect( ) const
{
	return m_SrcRect;
}
Rectf& Sprite::GetDstRect( ) 
{
	return m_DstRect;
}

Texture* Sprite::GetTexture( ) const
{
	return m_pTexture;
}

bool Sprite::GetAnimationFinish( ) const
{
	return m_IsFinish;
}

void Sprite::SetDstRect( const float x, const float y, const float width, const float height )
{

	m_DstRect.left = x;
	m_DstRect.bottom = y;
	m_DstRect.width = width * m_Scale;
	m_DstRect.height = height * m_Scale;

}

void Sprite::SetDstRect( const float width, const float height )
{
	m_DstRect.width = width * m_Scale;  
	m_DstRect.height = height * m_Scale;
}

void Sprite::SetLeftDstRect( const float left )
{
	m_DstRect.left = left;
}

void Sprite::SetBottomDstRect( const float bottom )
{
	m_DstRect.bottom = bottom;
}

void Sprite::SetSrcRect( const float y, const float width, const float height )
{
	m_SrcRect.width = width;
	m_SrcRect.height = height;
	m_SrcRect.bottom = y * (m_ActFrame / m_Cols + 1);
	
}

void Sprite::SetSrcRect(const float y)
{
	m_SrcRect.bottom = y * (m_ActFrame / m_Cols + 1);

}



// Set the correct left sprite pos of the spritesheet 
void Sprite::UpdateLeftSrcRect( )
{
	m_SrcRect.left = m_Width * (m_ActFrame % m_Cols);
}


void Sprite::UpdateBottomSrcRect( )
{
	m_SrcRect.bottom = m_SpriteSheetTop * (m_ActFrame / m_Cols + 1);
}


void Sprite::ResetAnimationFinish( bool reset )
{
	m_IsFinish = reset;
}