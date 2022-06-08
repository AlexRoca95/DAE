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
	void Update(float elapsedSec, Point2f& mousePos);



private:
	
	enum class PauseState{

		mainPause,
		settings,
		controls
	};


	// Sprites
	Sprite* m_pBackgroundMenu;

	
	std::vector< std::pair<Sprite*, Sprite*> > m_pMainPauseTexts;	// It will contain the text with and without color		
	

	void Initialize(const Point2f& windowSize);
};

