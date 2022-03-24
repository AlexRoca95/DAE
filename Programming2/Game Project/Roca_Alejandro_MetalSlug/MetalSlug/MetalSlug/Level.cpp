#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include "SVGParser.h"



Level::Level()
	:m_pLevelTexture{ new Texture("resources/sprites/level/mission1_level.png")}
	, m_Scale{ 2.7f }
	, m_SrcRect{ 0.f, m_pLevelTexture->GetHeight(), m_pLevelTexture->GetWidth(), m_pLevelTexture->GetHeight()}
	, m_DstRect{0.f, 0.f, m_pLevelTexture->GetWidth() * m_Scale, m_pLevelTexture->GetHeight() * m_Scale}
	, m_Boundaries{0.f, 0.f, m_pLevelTexture->GetWidth() * m_Scale,  m_pLevelTexture->GetHeight() * m_Scale }
	, m_Vertices{}
	, m_pLevelSVG{}
{
	//m_pLevelSVG->GetVerticesFromSvgFile("resources/sprites/Level/mission1_svg.svg", m_Vertices);
}


Level::~Level()
{
	delete m_pLevelTexture;
}



void Level::Draw() const
{

	m_pLevelTexture->Draw(m_DstRect, m_SrcRect);

}



Rectf Level::GetBoundaries() const
{
	return m_Boundaries;
}