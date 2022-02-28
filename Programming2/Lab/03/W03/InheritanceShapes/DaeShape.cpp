#include "pch.h"
#include "DaeShape.h"
#include "utils.h"



DaeShape::DaeShape(const Point2f& center, float width, float height, const Color4f& color)
	: m_Center(center),
	m_Color(color),
	m_Width(width),
	m_Height(height)
{

}

void DaeShape::Draw() const
{
	utils::SetColor(m_Color);

}

void DaeShape::Translate(const Vector2f& tr)
{
	m_Center += tr;
}

