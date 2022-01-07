#include "pch.h"
#include "Fraction.h"


Fraction::Fraction(int numerator, int denominator)
	:m_Numerator(numerator), m_Denominator(denominator)
{



}


// Draw the fraction starting at pos and the number of cells indicated by m_Denominator
// the colored cells by m_Numerator and the size of the cells by size
void Fraction::Draw(const Point2f& pos, float size)
{
	float xPos = pos.x;

	for (int i{}; i < m_Denominator; i++)
	{
		utils::SetColor(1.f, 1.f, 1.f);
		utils::DrawRect(xPos, pos.y, size, size);

		if (i < m_Numerator)
		{
			utils::SetColor(0.20f, 0.59f, 1.f);
			utils::FillRect(xPos, pos.y, size, size);
		}

		xPos += size;
	}

}


// Returns the value of the fraction
float Fraction::GetValue()
{
	return float(m_Numerator) / float(m_Denominator);
}