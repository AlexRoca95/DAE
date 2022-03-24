#pragma once
#include <vector>

class SVGParser;
class Texture;
class Level final
{
public:

	Level();
	~Level();
	Level(const Level& level) = delete;
	Level& operator=(const Level& level) = delete;

	void Draw() const;

	
	Rectf GetBoundaries() const;

private:

	const Texture* m_pLevelTexture;
	const float m_Scale;
	Rectf m_SrcRect;
	Rectf m_DstRect;
	const Rectf m_Boundaries;
	std::vector <std::vector<Point2f>> m_Vertices;
	SVGParser* m_pLevelSVG;
	

};

