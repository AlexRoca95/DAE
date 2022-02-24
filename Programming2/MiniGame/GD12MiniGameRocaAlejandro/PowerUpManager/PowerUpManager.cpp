#include "pch.h"
#include "PowerUpManager.h"


PowerUpManager::PowerUpManager()
{

}

PowerUpManager::~PowerUpManager()
{
	for (int i{ 0 }; i < m_pItems.size(); i++)
	{
		delete m_pItems[i];
		m_pItems[i] = nullptr;
	}

}

PowerUp* PowerUpManager::AddItem(const Point2f& center, PowerUp::Type type)
{
	PowerUp* pw1 = new PowerUp(center, type);

	m_pItems.push_back(pw1);

	return pw1;
}

void PowerUpManager::Update(float elapsedSec)
{
	for (int i{ 0 }; i < m_pItems.size(); i++)
	{
		m_pItems[i]->Update(elapsedSec);
	}
}

void PowerUpManager::Draw() const
{
	for (int i{ 0 }; i < m_pItems.size(); i++)
	{
		m_pItems[i]->Draw();
	}
}

size_t PowerUpManager::Size() const
{
	return m_pItems.size();
}

bool PowerUpManager::HitItem(const Rectf& rect)
{
	bool removed{ false };
	
	for (int i{ 0 }; i < m_pItems.size() && !removed; i++)
	{

		removed = m_pItems[i]->IsOverlapping(rect);

		if (removed)
		{
			PowerUp* pw1 = m_pItems[i];
			m_pItems[i] = m_pItems[m_pItems.size()-1];
			m_pItems[m_pItems.size() - 1] = pw1;

			m_pItems.pop_back();

			// Delete the copy object
			delete pw1;
			pw1 = nullptr;
		}

	}

	return removed;
}