#include "pch.h"
#include "Boss.h"
#include <iostream>



Boss::Boss(const Point2f& startPos, bool comingFromRight, SoundManager* sounds)
	:Enemy(GameObject::Type::boss, startPos, 1, Point2f{ },
		comingFromRight, Point2f{ 0.f, g_Gravity }, sounds)
{

	Initialize();
}


void Boss::Initialize()
{

	m_pBottomSprite = new Sprite("Resources/sprites/enemies/Boss/boss.png");
	//m_pBottomSprite->UpdateValues(24, 1, 24, 11.f, 66.f, 68.f, 93.f);   // Firing up
	//m_pBottomSprite->UpdateValues(9, 1, 9, 11.f, 66.f, 68.f, 178.f);   // Going back firing up
	//m_pBottomSprite->UpdateValues(28, 1, 28, 11.f, 120.f, 64.f, 321.f);   // Firing horiz (Top)
	m_pBottomSprite->UpdateValues(11, 1, 11, 10.f, 90.f, 70.f, 408.f);
	//m_pBottomSprite->UpdateValues(3, 1, 3, 20.f, 80.f, 70.f, 493.f);	// Charging fire
	
	m_pBottomSprite->SetLeftDstRect(m_StartPosition.x);
	m_pBottomSprite->SetBottomDstRect(m_StartPosition.y);
	m_pBottomSprite->UpdateLeftSrcRect();

	/*
	m_pTopSprite = new Sprite("Resources/sprites/enemies/Boss/projectiles.png");
	//m_pTopSprite->UpdateValues(3, 1, 3, 8.f, 10.f, 10.f, 20.f);     // Flying bullet
	//m_pTopSprite->UpdateValues(4, 1, 4, 10.f, 80.f, 26.f, 50.f);  // Ground bullet
	m_pTopSprite->SetLeftDstRect(m_StartPosition.x);
	m_pTopSprite->SetBottomDstRect(m_StartPosition.y);
	m_pTopSprite->UpdateLeftSrcRect();
	*/
	//m_pTopSprite = new Sprite("Resources/sprites/enemies/Boss/Cloth.png");
	//m_pTopSprite->UpdateValues(1, 1, 1, 10.f, 120.f, 93.f, 108.f);  // Cloth iddle
	//m_pTopSprite->UpdateValues(15, 1, 15, 7.f, 120.f, 103.f, 230.f);  // Cloth flying away
	//m_pTopSprite->SetLeftDstRect(m_StartPosition.x);
	//m_pTopSprite->SetBottomDstRect(m_StartPosition.y);
	//m_pTopSprite->UpdateLeftSrcRect();

}

Boss::~Boss()
{
	delete m_pBottomSprite;
	//delete m_pTopSprite;
}


 void Boss::Draw() const
{
	 m_pBottomSprite->Draw();
}


void Boss::Hit()
{


}

void Boss::CheckGameState()
{

}

void Boss::Update(float elapsedSec, Avatar* avatar, const Level* level)
{
	m_pBottomSprite->Update(elapsedSec, true);

	//std::cout << m_pBottomSprite->GetActFrame() << std::endl;
}


Point2f Boss::GetStartPos() const
{
	return m_StartPosition;
}
