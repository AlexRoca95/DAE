#include "pch.h"
#include "Pause.h"
#include "Sprite.h"
#include "utils.h"
#include <iostream>


Pause::Pause(const Point2f& windowSize, SoundManager* soundManager)
	: m_pBackgroundMenu { }
	, m_pMainPauseTexts { }
	, m_ClosePauseMenu { false }
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
	m_pBackgroundMenu = new Sprite("Resources/sprites/HUD/Pause/pauseMenu.png");
	m_pBackgroundMenu->UpdateValues(1, 1, 1, 1.f, m_pBackgroundMenu->GetTexture()->GetWidth(), m_pBackgroundMenu->GetTexture()->GetHeight(), m_pBackgroundMenu->GetTexture()->GetHeight());
	m_pBackgroundMenu->SetLeftDstRect(( windowSize.x / 2.f ) - (m_pBackgroundMenu->GetFrameWidth() * g_Scale) / 2.f  );
	m_pBackgroundMenu->SetBottomDstRect(( windowSize.y / 2.f ) - ( m_pBackgroundMenu->GetFrameHeight() * g_Scale ) / 2.f  );

	// CONTINUE TEXT 
	Sprite* pContinue{ new Sprite("Resources/sprites/HUD/Pause/continue.png") };
	pContinue->UpdateValues(1, 1, 1, 1.f, pContinue->GetTexture()->GetWidth(), pContinue->GetTexture()->GetHeight(), pContinue->GetTexture()->GetHeight());
	pContinue->SetLeftDstRect((windowSize.x / 2.f) - (pContinue->GetFrameWidth() * g_Scale) / 2.f);
	pContinue->SetBottomDstRect((windowSize.y / 2.f) + (pContinue->GetFrameHeight() * g_Scale));

	// CONTINUE TEXT (Colored)
	Sprite* pContinueColored{ new Sprite("Resources/sprites/HUD/Pause/continueColor.png") };
	pContinueColored->UpdateValues(1, 1, 1, 1.f, pContinueColored->GetTexture()->GetWidth(), pContinueColored->GetTexture()->GetHeight(), pContinueColored->GetTexture()->GetHeight());
	pContinueColored->SetLeftDstRect(pContinue->GetDstRect().left);
	pContinueColored->SetBottomDstRect(pContinue->GetDstRect().bottom);

	// First sprite will be without color and second one with color
	m_pMainPauseTexts.push_back( std::make_pair(pContinue, pContinueColored ) );

	const float textSpacing{ 10.f };

	// SETTINGS TEXT
	Sprite* pSettings{ new Sprite("Resources/sprites/HUD/Pause/settings.png") };
	pSettings->UpdateValues(1, 1, 1, 1.f, pSettings->GetTexture()->GetWidth(), pSettings->GetTexture()->GetHeight(), pSettings->GetTexture()->GetHeight());
	pSettings->SetLeftDstRect(pContinue->GetDstRect().left);
	pSettings->SetBottomDstRect(pContinueColored->GetDstRect().bottom - (pSettings->GetFrameHeight() * g_Scale) - textSpacing);

	// SETTINGS TEXT (COLORED)
	Sprite* pSettingsColored{ new Sprite("Resources/sprites/HUD/Pause/settingsColor.png") };
	pSettingsColored->UpdateValues(1, 1, 1, 1.f, pSettingsColored->GetTexture()->GetWidth(), pSettingsColored->GetTexture()->GetHeight(), pSettingsColored->GetTexture()->GetHeight());
	pSettingsColored->SetLeftDstRect(pContinue->GetDstRect().left);
	pSettingsColored->SetBottomDstRect(pSettings->GetDstRect().bottom);

	m_pMainPauseTexts.push_back( std::make_pair(pSettings, pSettingsColored) );

	// CONTROLS TEXT
	Sprite* pControls{ new Sprite("Resources/sprites/HUD/Pause/controls.png") };
	pControls->UpdateValues(1, 1, 1, 1.f, pControls->GetTexture()->GetWidth(), pControls->GetTexture()->GetHeight(), pControls->GetTexture()->GetHeight());
	pControls->SetLeftDstRect(pContinue->GetDstRect().left);
	pControls->SetBottomDstRect(pSettings->GetDstRect().bottom - (pControls->GetFrameHeight() * g_Scale) - textSpacing);

	// CONTROLS TEXT (COLORED)
	Sprite* pControlsColored{ new Sprite("Resources/sprites/HUD/Pause/controlsColor.png") };
	pControlsColored->UpdateValues(1, 1, 1, 1.f, pControlsColored->GetTexture()->GetWidth(), pControlsColored->GetTexture()->GetHeight(), pControlsColored->GetTexture()->GetHeight());
	pControlsColored->SetLeftDstRect(pContinue->GetDstRect().left);
	pControlsColored->SetBottomDstRect(pControls->GetDstRect().bottom);

	m_pMainPauseTexts.push_back(std::make_pair(pControls, pControlsColored));

	// QUIT TEXT
	Sprite* pQuit{ new Sprite("Resources/sprites/HUD/Pause/quit.png") };
	pQuit->UpdateValues(1, 1, 1, 1.f, pQuit->GetTexture()->GetWidth(), pQuit->GetTexture()->GetHeight(), pQuit->GetTexture()->GetHeight());
	pQuit->SetLeftDstRect(pContinue->GetDstRect().left);
	pQuit->SetBottomDstRect(pControls->GetDstRect().bottom - (pQuit->GetFrameHeight() * g_Scale) - textSpacing);

	// QUIT TEXT (COLORED)
	Sprite* pQuitColored{ new Sprite("Resources/sprites/HUD/Pause/quitColor.png") };
	pQuitColored->UpdateValues(1, 1, 1, 1.f, pQuitColored->GetTexture()->GetWidth(), pQuitColored->GetTexture()->GetHeight(), pQuitColored->GetTexture()->GetHeight());
	pQuitColored->SetLeftDstRect(pContinue->GetDstRect().left);
	pQuitColored->SetBottomDstRect(pQuit->GetDstRect().bottom);

	m_pMainPauseTexts.push_back(std::make_pair(pQuit, pQuitColored));

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

// Check wich selection the player chooses. It returns true if the player wants to close the game
void Pause::SelectOption(Point2f& mousePos, bool& closeGame, bool& closePauseMenu)
{
	for (int i{ 0 }; i < m_pMainPauseTexts.size(); i++)
	{
		if (utils::IsPointInRect(mousePos, m_pMainPauseTexts.at(i).first->GetDstRect()))
		{
			switch (i)
			{
				case 0:
					// Continue playing (Close pause Menu)
					closePauseMenu = true;
					break;
				case 1:
					// Settings

					break;
				case 2:
					// Show Controls
					break;
				case 3:
					// Close Game
					closeGame = true;
					break;
			}

		}
	}
}