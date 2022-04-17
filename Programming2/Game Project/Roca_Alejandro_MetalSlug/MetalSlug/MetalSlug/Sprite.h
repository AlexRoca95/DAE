#pragma once
#include <string>

class Texture;

class Sprite final
{
public:

	Sprite( const std::string& filename, int nrCols = 1, int nrRows = 1, float frameSec = 0, float scale = g_Scale );
	Sprite(const Sprite& spr1);
	Sprite(Sprite&& spr1);
	~Sprite( );
	Sprite& operator=(const Sprite& spr1);
	Sprite& operator= (Sprite&& spr1);

	void Update( float elapsedSec, const bool repeat );
	void Draw( ) const;

	void UpdateLeftSrcRect( );
	void UpdateBottomSrcRect( );
	void UpdateValues(const int cols, const int rows, const int frames, const float frameSec,
		const float width, const float height, const float spriteSheetTop, const float scale = 2.7f);

	void FlipSprite() const;
	void RotateSprite(float angle) const;
	void ResetActFrame();
	void ResetSprite();

	// Getters
	float GetFrameWidth( ) const;
	float GetFrameHeight( ) const;
	Rectf GetSrcRect( ) const;
	Rectf& GetDstRect( );
	Rectf GetHitBox() const;
	int GetActFrame( ) const;
	int GetTotalFrames() const;
	Texture* GetTexture( ) const;
	bool GetAnimationFinish( ) const;


	// Setters
	void SetDstRect(const float x, const float y, const float width, const float height);
	void SetDstRect(const float width, const float height);
	void SetLeftDstRect(const float left);
	void SetBottomDstRect(const float bottom);
	void SetSrcRect(const float y, const float width, const float height);
	void SetSrcRect(const float y);
	void ResetAnimationFinish(const bool reset);
	void SetActFrame(int frame);


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
	bool m_IsFinish;		// Animation finished or not
	
};


