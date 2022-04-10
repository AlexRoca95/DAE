#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include "SVGParser.h"
#include "Matrix2x3.h"
#include "Sprite.h"
#include <iostream>



Level::Level()
	:m_pLevelTexture{ new Sprite("Resources/sprites/level/levelLeft.png") }
	, m_pLevelLakeTexture{ new Sprite("Resources/sprites/level/levelRight.png")}
	, m_Vertices{}
	, m_pLevelSVG{}
	, m_Scale{2.7f}
	, m_NumberOfPaths{18}
	, m_TransformedVertices{}
	, m_Rows{ 8 }
	, m_UpperBoundary{}
	, m_UpperBoundaryValue{ 130.f }
	, m_BottomBoundary{}
	, m_Boundaries{}
	, m_XPosChangeBoundaries{3340.f * m_Scale}

{

	m_Boundaries.left = 0.f;
	m_Boundaries.width = m_pLevelTexture->GetTexture()->GetWidth() * m_Scale;
	UpdateLevelBoundaries();
	m_pLevelSVG->GetVerticesFromSvgFile("resources/sprites/Level/level.svg", m_Vertices);
	TransformSVGVertices();


	InitSprites();
}


Level::~Level()
{
	delete m_pLevelTexture;
	delete m_pLevelLakeTexture;

}

// Scale the vertices from the SVG file so it matches with the map size
void Level::TransformSVGVertices()
{
	Matrix2x3 matScale; // Scale matrix
	Matrix2x3 matWorld;  // Resulting matrix

	matScale.SetAsScale(m_Scale);
	
	// TRS Transformation
	matWorld = matScale;

	for (int i{ 0 }; i < m_NumberOfPaths; i++)
	{
		m_TransformedVertices.push_back(matWorld.Transform(m_Vertices[i])); // Apply transformation to vertices
	}

	
}

void Level::DrawBackground() const
{
	m_pLevelTexture->Draw();
	//utils::DrawPolygon(m_Vertices[17]);

	//utils::DrawPolygon(m_TransformedVertices[17]);
}

void Level::DrawForeground() const
{
	m_pLevelLakeTexture->Draw();
}

void Level::Update(float elapsedSec, const Rectf& ActorShape)
{
	
	if (ActorShape.left + ActorShape.width >= m_XPosChangeBoundaries)
	{
		m_UpperBoundary = 0.f;
	}
	else
	{
		m_UpperBoundary = m_UpperBoundaryValue;
	}



	// Update height and bottom boundaries
	UpdateLevelBoundaries();

	// Update the sprites
	m_pLevelTexture->Update(elapsedSec, true);
	m_pLevelLakeTexture->Update(elapsedSec, true);

	//std::cout << m_pLevelTexture->GetActFrame() << std::endl;

}

void Level::HandleCollision(Rectf& actorShape, Vector2f& velocity) const
{
	VerticalCollision(actorShape, velocity);
	HorizCollision(actorShape, velocity);  
}


void Level::VerticalCollision(Rectf& actorShape, Vector2f& velocity) const
{
	// Ray from the middle of the sprite to the bottom
	Point2f ray{ actorShape.left + actorShape.width / 2, actorShape.bottom + actorShape.height/2 };
	Point2f rayBottom{ actorShape.left + actorShape.width / 2, actorShape.bottom + 1 };

	utils::HitInfo hitInfo{}; // Info about the intersection point
	for (int i{ 0 }; i < m_NumberOfPaths; i++)
	{
		if (utils::Raycast(m_TransformedVertices[i], ray, rayBottom, hitInfo))
		{
			if (velocity.y <= 0.f)  // Only check if Avatar is going down
			{
				if (rayBottom.y <= hitInfo.intersectPoint.y)
				{
					// Collision with the ground
					actorShape.bottom = hitInfo.intersectPoint.y;
					velocity.y = 0.f;

					break; // If collision == true ,no need to check the others
				}
			}
		}
	}

}

void Level::HorizCollision(Rectf& actorShape, Vector2f& velocity) const
{
	// Check Collision to the left
	Point2f ray{ actorShape.left + actorShape.width/2, actorShape.bottom + actorShape.height / 2 };
	Point2f rayEnd{ actorShape.left , actorShape.bottom + actorShape.height / 2 };

	utils::HitInfo hitInfo{};

	if (utils::Raycast(m_TransformedVertices[17], ray, rayEnd, hitInfo))
	{
		if (rayEnd.x <= hitInfo.intersectPoint.x)
		{
			actorShape.left = hitInfo.intersectPoint.x;
			velocity.x = 0.f;
	
		}
	}

}

// Check if the avatar hits the ground
bool Level::IsOnGround(const Rectf& actorShape, const Vector2f& velocity) const
{
	bool onGround = false;

	// The ray
	Point2f ray{ actorShape.left + actorShape.width / 2, actorShape.bottom + actorShape.height/2 };
	Point2f rayBottom{ actorShape.left + actorShape.width / 2, actorShape.bottom - 1 };

	// The raycast
	utils::HitInfo hitInfo{}; // Will hold info about the intersection point

	for (int i{ 0 }; i < m_NumberOfPaths; i++)
	{
		if (utils::Raycast(m_TransformedVertices[i], ray, rayBottom, hitInfo))
		{
			if (velocity.y <= 0.f)
			{
				if (actorShape.bottom <= hitInfo.intersectPoint.y)
				{
					onGround = true;
					break;  
				}
			}
		}
	}
	

	return onGround;
}

void Level::InitSprites()
{
	// Mid Sprite Level Background
	m_pLevelTexture->UpdateValues(1, m_Rows, m_Rows, 15.f, 4152.f, 352.f, 352.f);
	m_pLevelTexture->SetLeftDstRect(0);
	m_pLevelTexture->SetBottomDstRect(0);
	m_pLevelTexture->UpdateLeftSrcRect();

	// Front Sprite Level 
	m_pLevelLakeTexture->UpdateValues(1, m_Rows, m_Rows, 20.f, 4152.f, 352.f, 352.f);
	m_pLevelLakeTexture->SetLeftDstRect(0);
	m_pLevelLakeTexture->SetBottomDstRect(0);
	m_pLevelLakeTexture->UpdateLeftSrcRect();

}

// Update bottom and height of the level boundaries
void Level::UpdateLevelBoundaries()
{
	m_Boundaries.bottom = m_BottomBoundary;
	m_Boundaries.height = ((m_pLevelTexture->GetTexture()->GetHeight() / m_Rows) - m_UpperBoundary)* m_Scale;

}

Rectf Level::GetBoundaries() const
{
	return m_Boundaries;
}