#include "pch.h"
#include "Light.h"


Light::Light(const Rectf& rect, const Color4f& color)
	:m_Rect(rect), m_Color(color), m_IsOn(false)
{

}

void Light::Draw()
{
	if (m_IsOn)
	{
		// Colored square
		utils::SetColor(m_Color);
	}
	else
	{
		// grey 
		utils::SetColor(0.45f, 0.45f, 0.45f);
	}

	// Draw rectangle
	utils::FillRect(m_Rect);

	// White borders
	utils::SetColor(1.0f, 1.0f, 1.0f);
	utils::DrawRect(m_Rect);


}

bool Light::IsHit(const Point2f& pos)
{
	bool changed{};
	if (pos.x > m_Rect.left && pos.x < m_Rect.left + m_Rect.width)
	{
		// X within the rect boundaries
		if (pos.y > m_Rect.bottom && pos.y < m_Rect.bottom + m_Rect.height)
		{
			// Change light according to its previous state
			if (m_IsOn)
			{
				m_IsOn = false;
			}
			else
			{
				m_IsOn = true;
			}

			changed = true;
		}
	}

	return changed;

}


bool Light::IsOn()
{
	return m_IsOn;
}


