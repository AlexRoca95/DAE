#pragma once

class Sprite
{
private:
	Texture m_Texture;
	int m_Cols;
	int m_Rows;
	float m_FrameSec;
	float m_AccuSec;
	float m_ActFrame;
	float m_Scale;


public:
	Sprite(const std::string& Filename, int nrCols, int nrRows, float frameSec, float scale);
	~Sprite();
	void Update(float elapsedSec);
	void Draw(const Point2f& pos);
	float GetFrameWidth();
	float GetFrameHeight();


};

