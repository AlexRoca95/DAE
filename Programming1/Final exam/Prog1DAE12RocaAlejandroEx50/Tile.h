#pragma once


class Tile 
{
public:
	Tile(const Rectf& dstRect, const std::string& textPath, int nrAnimals );
	~Tile();
	void Draw();
	void CheckActivation(const Point2f& pos);
	bool CheckHit(const Point2f& pos);
	int GetCurrentAnimal();
	void Deactivate();
	//void Randomize( );

private: 
	Rectf m_DestRect;			// Position where we will draw the tile
	Rectf m_SrcRect;			// Part of the texture that we want to draw
	Rectf m_LefHitRegion;
	Rectf m_RightHitRegion;
	int m_TotalAnimals;
	int m_CurrentAnimal;		// Current animal being draw
	utils::Texture m_Tile;
	bool m_Activated;			// Tile activated or not

};
