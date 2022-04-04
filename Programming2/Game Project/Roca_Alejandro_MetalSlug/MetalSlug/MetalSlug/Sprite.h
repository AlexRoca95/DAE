#pragma once
#include <string>

class Texture;

class Sprite final
{
public:
	Sprite( const std::string& filename, int nrCols = 1, int nrRows = 1, float frameSec = 0, float scale = 2.7f );
	Sprite(const Sprite& spr1);
	Sprite(Sprite&& spr1);
	~Sprite( );
	Sprite& operator=(const Sprite& spr1);
	Sprite& operator= (Sprite&& spr1);
	void Update( float elapsedSec, bool repeat );
	void Draw() const;

	void UpdateLeftSrcRect();
	void ResetActFrame();

	// Getters
	float GetFrameWidth( );
	float GetFrameHeight( );
	Rectf GetSrcRect();
	Rectf& GetDstRect();
	int GetActFrame();

	// Setters
	void SetDstRect(float x, float y, float width, float height);
	void SetDstRect(float width, float height);
	void SetLeftDstRect(float left);
	void SetBottomDstRect(float bottom);
	void SetSrcRect(float y, float width, float height);

	
	
	void UpdateValues(int cols, int rows, int frames, float frameSec, float width, float height, float spriteSheetTop);

private:
	std::string m_Path;
	Texture *m_pTexture;
	Rectf m_SrcRect;
	Rectf m_DstRect;
	int m_Cols;
	int m_Rows;
	int m_ActFrame;
	int m_Frames;
	float m_FrameSec;
	float m_AccuSec; 
	float m_SpriteSheetTop;
	float m_Width;
	float m_Height;
	float m_Scale;
	
};


