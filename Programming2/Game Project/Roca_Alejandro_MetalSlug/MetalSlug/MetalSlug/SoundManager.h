#pragma once
#include <unordered_map>

class SoundStream;
class SoundEffect;
class SoundManager
{

public:

	SoundManager();
	~SoundManager();
	SoundManager(const SoundManager& soundManager) = delete;
	SoundManager(SoundManager&& soundManager) = delete;
	SoundManager& operator=(const SoundManager& soundManager) = delete;
	SoundManager& operator=(SoundManager&& oundManager) = delete;



	SoundStream* GetSound(const std::string& filename);
	SoundEffect* GetEffect(const std::string& filename);

	void turnOffSound();

private:

	std::unordered_map < std::string, SoundStream* > m_Sounds;
	std::unordered_map < std::string, SoundEffect* > m_Effects;

	bool m_IsSoundOn;
};

