#pragma once
// Abstract class from which all objects from the game will inherit

class GameObject
{
public:
	GameObject(int id);
	virtual ~GameObject();
	virtual void Draw() const = 0;
	virtual void Update(float elapsedSeconds) = 0;
	virtual void InitDestRect() = 0;
	virtual void InitSrcRect() = 0;

	// For sprites with two parts
	virtual void InitDestRectTop() = 0;
	virtual void InitSrcRectTop() = 0;


protected:
	int m_Id;

	// Sprite related 
	Rectf m_SrcRect;
	Rectf m_DestRect;
	int m_Cols;
	float m_Width;
	float m_Height;
	float m_SpriteSheetLeft;
	float m_SpriteSheetTop;
	float m_SpriteSheetWidth;
	float m_SpriteSheetHeight;
	int m_Frames;
	float m_FrameTime;
	int m_CurrentFrame;
	float m_AccumTime;

	// For sprites with two parts (Top Part)
	Rectf m_SrcRectTop;
	Rectf m_DestRectTop;
	int m_ColsTop;
	float m_WidthTop;
	float m_HeightTop;
	float m_SpriteSheetTop2;
	int m_FramesTop;
	int m_CurrentFrameTop;
	float m_FrameTimeTop;
	float m_AccumTimeTop;
};

