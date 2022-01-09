#include "pch.h"		
#include "Tile.h"
#include <iostream>



Tile::Tile(const Rectf& dstRect, const std::string& textPath, int nrAnimals)
	:m_DestRect(dstRect), 
	m_TotalAnimals(nrAnimals),
	m_Activated(false)
{
	// Try to load the texture
	bool load = TextureFromFile(textPath, m_Tile);

	// Check if loaded
	if(!load)
		std::cout << "Error loading the texture " << textPath << std::endl;

	// Choose a random current animal
	Randomize();

	// Small hitting rectangles values
	m_LefHitRegion.bottom = dstRect.bottom;
	m_LefHitRegion.left = dstRect.left;
	m_LefHitRegion.width = m_LefHitRegion.height = dstRect.width / 4;

	
	m_RightHitRegion.width = m_RightHitRegion.height = dstRect.width / 4;
	m_RightHitRegion.bottom = dstRect.bottom;
	m_RightHitRegion.left = (dstRect.left + dstRect.width) - m_RightHitRegion.width;

}

Tile::~Tile()
{
	// Free resources
	DeleteTexture(m_Tile);
}

// Draw the current animal in the Rectangle area 
void Tile::Draw()
{
	// Size of the texture that we want to draw
	m_SrcRect.height = m_Tile.height;
	m_SrcRect.width = m_Tile.width / m_TotalAnimals;
	
	// Which part we want to draw
	m_SrcRect.bottom = m_SrcRect.height;
	m_SrcRect.left = m_SrcRect.width * (m_CurrentAnimal % m_TotalAnimals);


	utils::DrawTexture(m_Tile, m_DestRect, m_SrcRect);


	if (m_Activated)
	{
		// Tile activated. Draw a semi transparent greyish rectangle on top of the tile
		utils::SetColor(0.70f, 0.70f, 0.70f, 0.5);  // semi transparent greyish
		utils::FillRect(m_DestRect);


		// Two red rectangular hitregions
		utils::SetColor(1.f, 0.f, 0.f);			// Red color

		utils::DrawRect(m_LefHitRegion);
		utils::DrawRect(m_RightHitRegion);
		
	}
}

// Check if mouse is inside the rectangular area of the tile
void Tile::CheckActivation(const Point2f& pos)
{

	if (pos.x > m_DestRect.left && pos.x < m_DestRect.left + m_DestRect.width)
	{
		// Inside X
		if (pos.y > m_DestRect.bottom && pos.y < m_DestRect.bottom + m_DestRect.height)
		{
			// Inside rectangular size of the tile
			m_Activated = true;
		}
		else
		{
			m_Activated = false;
		}
	}
	else
	{
		m_Activated = false;
	}


}

// Check if we clicked inside the rectangular Hit region
bool Tile::CheckHit(const Point2f& pos)
{
	bool hit{};
	// Check left rectangle
	if (pos.x > m_LefHitRegion.left && pos.x < m_LefHitRegion.left + m_LefHitRegion.width)
	{
		// Inside X
		if (pos.y > m_LefHitRegion.bottom && pos.y < m_LefHitRegion.bottom + m_LefHitRegion.height)
		{
			// We hit the left rectangle
			if (m_CurrentAnimal == 0)
			{
				// We are in the first animal. Go to the end
				m_CurrentAnimal = m_TotalAnimals - 1;
			}
			else
			{
				m_CurrentAnimal--;
			}

			hit = true;
		}
	}

	// Check right rectangle
	if (pos.x > m_RightHitRegion.left && pos.x < m_RightHitRegion.left + m_RightHitRegion.width)
	{
		// Inside X
		if (pos.y > m_RightHitRegion.bottom && pos.y < m_RightHitRegion.bottom + m_RightHitRegion.height)
		{

			if (m_CurrentAnimal == m_TotalAnimals - 1)
			{
				// We are in the last animal. Reset to the first one
				m_CurrentAnimal = 0;
			}
			else
			{
				m_CurrentAnimal++;
			}

			hit = true;
		}
	}

	return hit;
}

// Get a random current animal
void Tile::Randomize()
{
	// Choose randomly the animal to draw
	m_CurrentAnimal = rand() % m_TotalAnimals;

}


int Tile::GetCurrentAnimal()
{
	return m_CurrentAnimal;
}

void Tile::Deactivate()
{
	m_Activated = false;
}