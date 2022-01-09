#pragma once

class Sprite
{

private:
	utils::Texture m_Texture;
	int m_Cols;				// Number of cols 
	int m_Rows;				// Number of rows
	float m_FrameSec;		// FrameRate 
	float m_AccuSec;		// Accumulated time
	int m_ActFrame;			// Actual frame that we are
	float m_Scale;			// Scale of the sprite
public:
	Sprite(const std::string& filename, int nrCols, int nrRows, float frameSec, float scale);
	~Sprite();
	void Update(float elapsedSec);
	void Draw(const Point2f& pos);
	float GetFrameWidth();
	float GetFrameHeight();
	float GetScale();
};

