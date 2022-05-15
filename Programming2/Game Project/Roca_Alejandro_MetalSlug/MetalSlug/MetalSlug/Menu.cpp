#include "pch.h"
#include "Menu.h"
#include "Sprite.h"


Menu::Menu(const Point2f& windowSize)
	: m_pStartScreen { }
	, m_pPushStart { }
	, m_StartPlaying { false }
	, m_StartLettersPos{ 270.f, 50.f }
	, m_DrawLetters { true }
	, m_FlickeringMaxTime{ 0.6f }
	, m_FlickeringSec { }
{
	Initialize();
}

Menu::~Menu()
{
	delete m_pStartScreen;
	delete m_pPushStart;
}

void Menu::Initialize()
{
	// Background Screen
	m_pStartScreen = new Sprite("Resources/sprites/HUD/startScreen.png");
	m_pStartScreen->UpdateValues(1, 1, 1, 1.f, m_pStartScreen->GetTexture()->GetWidth(), m_pStartScreen->GetTexture()->GetHeight(), m_pStartScreen->GetTexture()->GetHeight());
	m_pStartScreen->SetLeftDstRect(0.f);
	m_pStartScreen->SetBottomDstRect(0.f);

	// PUSH START letters
	m_pPushStart = new Sprite("Resources/sprites/HUD/PushStart2.png");
	m_pPushStart->UpdateValues(1, 1, 1, 1.f, m_pPushStart->GetTexture()->GetWidth(), m_pPushStart->GetTexture()->GetHeight(), m_pPushStart->GetTexture()->GetHeight(), 3.5f);
	m_pPushStart->SetLeftDstRect(m_StartLettersPos.x);
	m_pPushStart->SetBottomDstRect(m_StartLettersPos.y);
}

void Menu::Draw() const
{
	m_pStartScreen->Draw();

	if (m_DrawLetters)
	{
		m_pPushStart->Draw();
	}
	
}

void Menu::Update(float elapsedSec, Game::GameState& gameState)
{

	UpdateFlicker(elapsedSec);

	if (m_StartPlaying)
	{
		// Start playing the game
		gameState = Game::GameState::playing;
	}
}

// Flicker effect for the Start letters
void Menu::UpdateFlicker(float elapsedSec)
{
	if (m_FlickeringSec >= m_FlickeringMaxTime)
	{
		if (m_DrawLetters)
		{
			m_DrawLetters = false;
		}
		else
		{
			m_DrawLetters = true;
		}

		m_FlickeringSec = 0.f;
	}
	else
	{
		m_FlickeringSec += elapsedSec;
	}

}

void Menu::SetPlaying(bool start)
{
	m_StartPlaying = start;
}

bool Menu::GetStartPlaying() const
{
	return m_StartPlaying;
}