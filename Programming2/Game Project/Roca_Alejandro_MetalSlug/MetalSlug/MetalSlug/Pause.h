#pragma once
#include <vector>

class SoundManager;
class Sprite;
class Pause
{
public:


	
	Pause(const Point2f& windowSize, SoundManager* soundManager);
	~Pause();
	Pause(const Pause& pause) = delete;
	Pause(Pause&& pause) = delete;
	Pause& operator=(const Pause& pause) = delete;
	Pause& operator=(Pause&& pause) = delete;


	void Draw() const;
	void Update(float elapsedSec, const Point2f& mousePos);

	void SelectOption(const Point2f& mousePos, bool& closeGame, bool& closePauseMenu);



private:
	
	enum class PauseState{

		mainPause,
		settings,
		controls

	};

	PauseState m_PauseState;
	Sprite* m_pMainPauseBackground;
	Sprite* m_pControlsBackground;
	Sprite* m_pSettingsBackground;
	std::pair <Sprite*, Sprite*> m_pBackTexts;
	std::vector< std::pair<Sprite*, Sprite*> > m_pMainPauseTexts;	// It will contain the text with and without color		

	bool m_ClosePauseMenu;
	
	
	void Initialize(const Point2f& windowSize);
	void HighlightText(const Point2f& mousePos, std::pair<Sprite*, Sprite*>& texts);

};

