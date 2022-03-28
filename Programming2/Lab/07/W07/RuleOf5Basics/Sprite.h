#pragma once
#include <string>

class Texture;

class Sprite final
{
public:
	Sprite( const std::string& filename, int nrCols = 1, int nrRows = 1, float frameSec = 0 );
	Sprite(const Sprite& spr1);
	Sprite(Sprite&& spr1);
	~Sprite( );
	Sprite& operator=(const Sprite& spr1);
	Sprite& operator= (Sprite&& spr1);
	void Update( float elapsedSec );
	void Draw( const Point2f& pos, float scale = 1.0f );

	float GetFrameWidth( );
	float GetFrameHeight( );

private:
	std::string m_Path;
	Texture *m_pTexture;
	int m_Cols;
	int m_Rows;
	float m_FrameSec;
	float m_AccuSec;
	int   m_ActFrame;

};


