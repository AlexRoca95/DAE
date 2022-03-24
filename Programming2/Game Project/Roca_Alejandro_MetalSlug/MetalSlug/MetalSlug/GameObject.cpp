#include "pch.h"
#include "GameObject.h"


GameObject::GameObject(int id)
	:m_Id{ id }
	, m_SrcRect{}
	, m_DestRect{}
	, m_Cols{}
	, m_Width{}
	, m_Height{}
	, m_SpriteSheetLeft{}
	, m_SpriteSheetTop{}
	, m_Frames{}
	, m_FrameTime{}
	, m_CurrentFrame{}
	, m_AccumTime{}
	, m_SpriteSheetWidth{}
	, m_SpriteSheetHeight{}

	// For sprites with two parts
	, m_SrcRectTop{}
	, m_DestRectTop{}
	, m_ColsTop{}
	, m_WidthTop{}
	, m_HeightTop{}
	, m_SpriteSheetTop2{}
	, m_FramesTop{}
	, m_CurrentFrameTop{}
	, m_FrameTimeTop{}
	, m_AccumTimeTop{}
{
	
}


