#include "pch.h"
#include "Pause.h"
#include "Sprite.h"
#include "utils.h"


Pause::Pause(const Point2f& windowSize, SoundManager* soundManager)
	: m_pMainPauseBackground { }
	, m_pControlsBackground{ }
	, m_pSettingsBackground{ }
	, m_pBackTexts{ }
	, m_pMainPauseTexts { }
	, m_ClosePauseMenu { false }
	, m_PauseState { PauseState::mainPause }
	
	
{
	Initialize(windowSize);
}


Pause::~Pause()
{
	delete m_pMainPauseBackground;
	delete m_pControlsBackground;
	delete m_pSettingsBackground;

	delete m_pBackTexts.first;
	delete m_pBackTexts.second;

	for (std::pair<Sprite*, Sprite*> spr : m_pMainPauseTexts)
	{
		delete spr.first;
		delete spr.second;
	}

}


void Pause::Initialize(const Point2f& windowSize)
{
	// BACKGROUNDS SPRITES
	// Background for the Pause Menu
	m_pMainPauseBackground = new Sprite("Resources/sprites/HUD/Pause/pauseMenu.png");
	m_pMainPauseBackground->UpdateValues(1, 1, 1, 1.f, m_pMainPauseBackground->GetTexture()->GetWidth(), m_pMainPauseBackground->GetTexture()->GetHeight(), m_pMainPauseBackground->GetTexture()->GetHeight());
	m_pMainPauseBackground->SetLeftDstRect(( windowSize.x / 2.f ) - (m_pMainPauseBackground->GetFrameWidth() * g_Scale) / 2.f  );
	m_pMainPauseBackground->SetBottomDstRect(( windowSize.y / 2.f ) - ( m_pMainPauseBackground->GetFrameHeight() * g_Scale ) / 2.f  );

	m_pControlsBackground = new Sprite("Resources/sprites/HUD/Pause/keyInfo.png");
	m_pControlsBackground->UpdateValues(1, 1, 1, 1.f, m_pControlsBackground->GetTexture()->GetWidth(), m_pControlsBackground->GetTexture()->GetHeight(), m_pControlsBackground->GetTexture()->GetHeight());
	m_pControlsBackground->SetLeftDstRect((windowSize.x / 2.f) - (m_pControlsBackground->GetFrameWidth() * g_Scale) / 2.f);
	m_pControlsBackground->SetBottomDstRect((windowSize.y / 2.f) - (m_pControlsBackground->GetFrameHeight() * g_Scale) / 2.f);

	m_pSettingsBackground = new Sprite("Resources/sprites/HUD/Pause/settingsMenu.png");
	m_pSettingsBackground->UpdateValues(1, 1, 1, 1.f, m_pSettingsBackground->GetTexture()->GetWidth(), m_pSettingsBackground->GetTexture()->GetHeight(), m_pSettingsBackground->GetTexture()->GetHeight());
	m_pSettingsBackground->SetLeftDstRect((windowSize.x / 2.f) - (m_pSettingsBackground->GetFrameWidth() * g_Scale) / 2.f);
	m_pSettingsBackground->SetBottomDstRect((windowSize.y / 2.f) - (m_pSettingsBackground->GetFrameHeight() * g_Scale) / 2.f);


	// TEXTS
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

	// BACK TEXT
	m_pBackTexts.first = new Sprite("Resources/sprites/HUD/pause/back.png");
	m_pBackTexts.first->UpdateValues(1, 1, 1, 1.f, m_pBackTexts.first->GetTexture()->GetWidth(), m_pBackTexts.first->GetTexture()->GetHeight(), m_pBackTexts.first->GetTexture()->GetHeight());
	m_pBackTexts.first->SetLeftDstRect((windowSize.x / 2.f) - (m_pBackTexts.first->GetFrameWidth() * g_Scale) / 2.f);
	m_pBackTexts.first->SetBottomDstRect(m_pControlsBackground->GetDstRect().bottom + ( m_pBackTexts.first->GetFrameHeight() ) );
	
	// BACK TEXT (Colored)
	m_pBackTexts.second = new Sprite("Resources/sprites/HUD/pause/backColor.png");
	m_pBackTexts.second->UpdateValues(1, 1, 1, 1.f, m_pBackTexts.second->GetTexture()->GetWidth(), m_pBackTexts.second->GetTexture()->GetHeight(), m_pBackTexts.second->GetTexture()->GetHeight());
	m_pBackTexts.second->SetLeftDstRect(m_pBackTexts.first->GetDstRect().left);
	m_pBackTexts.second->SetBottomDstRect(m_pBackTexts.first->GetDstRect().bottom);


}

void Pause::Draw() const
{
	switch (m_PauseState)
	{
	case Pause::PauseState::mainPause:
		m_pMainPauseBackground->Draw();

		for (int i{ 0 }; i < m_pMainPauseTexts.size(); i++)
		{
			// Only those that are activated will be drawn
			m_pMainPauseTexts.at(i).first->Draw();				// Better at than [] to access elements
			m_pMainPauseTexts.at(i).second->Draw();
		}
		break;
	case Pause::PauseState::settings:
		m_pSettingsBackground->Draw();
		m_pBackTexts.first->Draw();
		m_pBackTexts.second->Draw();
		break;
	case Pause::PauseState::controls:
		m_pControlsBackground->Draw();
		m_pBackTexts.first->Draw();
		m_pBackTexts.second->Draw();
		break;
	}
	
}

void Pause::Update(float elapsedSec, const Point2f& mousePos)
{
	switch (m_PauseState)
	{
	case Pause::PauseState::mainPause:
		for (int i{ 0 }; i < m_pMainPauseTexts.size(); i++)
		{
			HighlightText(mousePos, m_pMainPauseTexts.at(i));
		}
		break;
	case Pause::PauseState::settings:
		m_pBackTexts.first->SetBottomDstRect(m_pSettingsBackground->GetDstRect().bottom + (m_pBackTexts.first->GetFrameHeight()));
		m_pBackTexts.second->SetBottomDstRect(m_pBackTexts.first->GetDstRect().bottom);
		HighlightText(mousePos, m_pBackTexts);
		break;
	case Pause::PauseState::controls:
		m_pBackTexts.first->SetBottomDstRect(m_pControlsBackground->GetDstRect().bottom + (m_pBackTexts.first->GetFrameHeight()));
		m_pBackTexts.second->SetBottomDstRect(m_pBackTexts.first->GetDstRect().bottom);
		HighlightText(mousePos, m_pBackTexts);
		break;

	}
	
}

// Check wich selection the player chooses. It returns true if the player wants to close the game
void Pause::SelectOption(const Point2f& mousePos, bool& closeGame, bool& closePauseMenu)
{
	switch (m_PauseState)
	{
	case Pause::PauseState::mainPause:
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
					m_PauseState = PauseState::settings;
					break;
				case 2:
					// Show Controls
					m_PauseState = PauseState::controls;
					break;
				case 3:
					// Close Game
					closeGame = true;
					break;
				}
			}
		}
		break;
	case Pause::PauseState::settings:
		if (utils::IsPointInRect(mousePos, m_pBackTexts.first->GetDstRect()))
		{
			// Go back
			m_PauseState = PauseState::mainPause;
		}
		break;
	case Pause::PauseState::controls:
		if ( utils::IsPointInRect(mousePos, m_pBackTexts.first->GetDstRect()) )
		{
			// Go back
			m_PauseState = PauseState::mainPause;
		}
		break;
	}
	
}

// Highlight the text when mouse over
void Pause::HighlightText(const Point2f& mousePos, std::pair<Sprite*, Sprite*>& texts)
{
	if (utils::IsPointInRect(mousePos, texts.first->GetDstRect()))
	{
		// Draw colored text when mouse on it
		texts.first->SetActive(false);
		texts.second->SetActive(true);
	}
	else
	{
		// Draw text without color
		texts.first->SetActive(true);
		texts.second->SetActive(false);
	}
}