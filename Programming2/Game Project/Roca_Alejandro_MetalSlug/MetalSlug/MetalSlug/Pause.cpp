#include "pch.h"
#include "Pause.h"
#include "Sprite.h"
#include "utils.h"


Pause::Pause(const Point2f& windowSize, SoundManager* soundManager)
	: m_pBackgroundMenu { }
	, m_pMainPauseTexts { }
{
	Initialize(windowSize);
}


Pause::~Pause()
{
	delete m_pBackgroundMenu;

	for (std::pair<Sprite*, Sprite*> spr : m_pMainPauseTexts)
	{
		delete spr.first;
		delete spr.second;
	}

}


void Pause::Initialize(const Point2f& windowSize)
{
	// Background for the Pause Menu
	m_pBackgroundMenu = new Sprite("Resources/sprites/HUD/pauseMenu.png");
	m_pBackgroundMenu->UpdateValues(1, 1, 1, 1.f, m_pBackgroundMenu->GetTexture()->GetWidth(), m_pBackgroundMenu->GetTexture()->GetHeight(), m_pBackgroundMenu->GetTexture()->GetHeight());
	m_pBackgroundMenu->SetLeftDstRect(( windowSize.x / 2.f ) - (m_pBackgroundMenu->GetFrameWidth() * g_Scale) / 2.f  );
	m_pBackgroundMenu->SetBottomDstRect(( windowSize.y / 2.f ) - ( m_pBackgroundMenu->GetFrameHeight() * g_Scale ) / 2.f  );


	// CONTINUE TEXT 
	Sprite* pContinue{ new Sprite("Resources/sprites/HUD/continue.png") };
	pContinue->UpdateValues(1, 1, 1, 1.f, pContinue->GetTexture()->GetWidth(), pContinue->GetTexture()->GetHeight(), pContinue->GetTexture()->GetHeight());
	pContinue->SetLeftDstRect((windowSize.x / 2.f) - (pContinue->GetFrameWidth() * g_Scale) / 2.f);
	pContinue->SetBottomDstRect((windowSize.y / 2.f) + (pContinue->GetFrameHeight() * g_Scale));

	// CONTINUE TEXT (Colored)
	Sprite* pContinueColored{ new Sprite("Resources/sprites/HUD/continueColor.png") };
	pContinueColored->UpdateValues(1, 1, 1, 1.f, pContinueColored->GetTexture()->GetWidth(), pContinueColored->GetTexture()->GetHeight(), pContinueColored->GetTexture()->GetHeight());
	pContinueColored->SetLeftDstRect((windowSize.x / 2.f) - (pContinueColored->GetFrameWidth() * g_Scale) / 2.f);
	pContinueColored->SetBottomDstRect((windowSize.y / 2.f) + (pContinueColored->GetFrameHeight() * g_Scale));

	pContinueColored->SetActive(false);			// Desactivated at start

	// First sprite will be without color and second one with color
	m_pMainPauseTexts.push_back( std::make_pair(pContinue, pContinueColored ));


}

void Pause::Draw() const
{
	m_pBackgroundMenu->Draw();

	for (int i{ 0 }; i < m_pMainPauseTexts.size(); i++)
	{
		// Only those that are activated will be drawn
		m_pMainPauseTexts.at(i).first->Draw();				// Better at than [] to access elements
		m_pMainPauseTexts.at(i).second->Draw();
	}
}

void Pause::Update(float elapsedSec, Point2f& mousePos)
{
	
	for (int i{ 0 }; i < m_pMainPauseTexts.size(); i++)
	{
		if (utils::IsPointInRect(mousePos, m_pMainPauseTexts.at(i).first->GetDstRect()))
		{
			// Draw colored text when mouse on it
			m_pMainPauseTexts.at(i).first->SetActive(false);
			m_pMainPauseTexts.at(i).second->SetActive(true);
		}
		else
		{
			// Draw text without color
			m_pMainPauseTexts.at(i).first->SetActive(true);
			m_pMainPauseTexts.at(i).second->SetActive(false);
		}
	}


}