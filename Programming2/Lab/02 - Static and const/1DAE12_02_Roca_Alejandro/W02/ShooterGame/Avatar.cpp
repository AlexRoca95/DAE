#include "pch.h"
#include "Avatar.h"
#include "utils.h"
#include "Enemy.h"
#include "Bullet.h"

Avatar::Avatar()
{

}

Avatar::Avatar(const Point2f& center, float width, float height)
	:m_Center(center),
	m_Width(width),
	m_Height(height),
	m_Speed(200.f)
{
	m_pBullet = new Bullet(width / 2, height);
}

Avatar::~Avatar()
{
	delete m_pBullet;
	m_pBullet = nullptr;
}

void Avatar::Update(float elapsedSec, Enemy* pEnemies, int numEnemies)
{

	HandleMoveKeysState(elapsedSec);

	m_pBullet->Update(elapsedSec, pEnemies, numEnemies);


}
void Avatar::Draw() const
{
	utils::SetColor(Color4f{1.f, 1.f, 0.f, 1.f});
	utils::DrawRect(m_Center.x - m_Width, m_Center.y - m_Height, m_Width, m_Height);

	m_pBullet->Draw();
}
void Avatar::SetCenter(const Point2f& center)
{
	m_Center = center;
}
void Avatar::SetDimensions(float width, float height)
{
	m_Width = width;
	m_Height = height;
}
void Avatar::SetBoundaries(const Rectf& boundaries)
{
	m_Boundaries = boundaries;
}

void Avatar::Clamp()
{

}
void Avatar::HandleMoveKeysState(float elapsedSec)
{
	float newPos{};
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		newPos = m_Center.x +( m_Speed * elapsedSec);
		if (newPos < m_Boundaries.width)
		{
			m_Center.x = newPos;
		}
		
	}
	if ( pStates[SDL_SCANCODE_LEFT])
	{
		newPos = m_Center.x - (m_Speed * elapsedSec);
		if (newPos - m_Width > m_Boundaries.left)
		{
			m_Center.x = newPos;
		}
	}

	if (pStates[SDL_SCANCODE_UP])
	{
		m_pBullet->SetBondaries(m_Boundaries);
		m_pBullet->Shoot(m_Center, Vector2f{ 10.f, 250.f });
	}
}
