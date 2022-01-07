#include "pch.h"
#include "Box.h"
#include "BouncingCircle.h"


Box::Box(const Rectf& boundingBox)
	:m_BoundingBox(boundingBox)
{
	for (int i{}; i < m_NumberOfCircles; i++)
	{
		m_pManyCircles[i] = new BouncingCircle{ m_BoundingBox, rand() % 20 + 10.f, Point2f{m_BoundingBox.left + m_BoundingBox.width / 2, m_BoundingBox.bottom + m_BoundingBox.height / 2 } };
	}
}

Box::~Box()
{
	for (int i{}; i < m_NumberOfCircles; i++)
	{
		delete m_pManyCircles[i];
		m_pManyCircles[i] = nullptr;
	}
}


void Box::Update(float elapsedSec)
{
	for (int i{}; i < m_NumberOfCircles; i++)
	{
		m_pManyCircles[i]->UpdateCircle(elapsedSec);
	}
}


void Box::Draw()
{
	utils::SetColor(0.f, 0.f, 0.f);
	utils::DrawRect(m_BoundingBox);
	for (int i{}; i < m_NumberOfCircles; i++)
	{
		m_pManyCircles[i]->DrawCircle();
	}

}
