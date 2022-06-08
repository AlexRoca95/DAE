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

	void turnOnOffSound();
	void PlaySoundEffect(const SoundEffect* soundEffect, int times);
	void PlaySong(const SoundStream* song, bool repeat);

	void ChangeSoundtrackVolume(int value);
	void ChangeEffectVolume(int value);

	bool GetSoundActivated();
	

private:

	std::unordered_map < std::string, SoundStream* > m_Sounds;
	std::unordered_map < std::string, SoundEffect* > m_Effects;

	bool m_IsSoundOn;


	// Sounds

	
};

