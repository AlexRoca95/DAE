#include "pch.h"
#include "SoundManager.h"
#include "SoundStream.h"
#include "SoundEffect.h"



SoundManager::SoundManager()
	: m_Sounds{}
	, m_Effects{}
	, m_IsSoundOn { true }
{

}

SoundManager::~SoundManager()
{
	for (std::pair<std::string, SoundStream*> sound : m_Sounds)
	{
		delete sound.second;
		
	}
	
	for (std::pair<std::string, SoundEffect*> effect : m_Effects)
	{
		delete effect.second;

	}

}


SoundStream* SoundManager::GetSound(const std::string& filename)
{
	if (m_Sounds.find(filename) == m_Sounds.end())
	{
		// It didn't find the sound
		SoundStream* pSound{ new SoundStream(filename) };   // Create it

		m_Sounds[filename] = pSound;			   // Add it to the container

		return pSound;
	}
	else
	{
		return m_Sounds[filename];
	}
}

SoundEffect* SoundManager::GetEffect(const std::string& filename)
{
	if (m_Effects.find(filename) == m_Effects.end())
	{
		SoundEffect* pEffect{ new SoundEffect(filename) };   

		m_Effects[filename] = pEffect;			  

		return pEffect;
	}
	else
	{
		return m_Effects[filename];
	}

}

// Play the sound effect as many times as indicated and only if the sound is on
void SoundManager::PlaySoundEffect(const SoundEffect* soundEffect, const int times)
{
	if (m_IsSoundOn)
	{
		soundEffect->Play(times);
	}
}

void SoundManager::PlaySong(const SoundStream* song, const bool repeat)
{
	if (m_IsSoundOn)
	{
		song->Play(repeat);
	}
}


// Decrement / Increment soundtrack volume according with the value
void SoundManager::ChangeSoundtrackVolume(const int value)
{
	for (std::pair<std::string, SoundStream*> sound : m_Sounds)
	{
		sound.second->SetVolume(sound.second->GetVolume() + value);
	}
}

void SoundManager::ChangeEffectVolume(const int value)
{
	for (std::pair<std::string, SoundEffect*> effect : m_Effects)
	{
		effect.second->SetVolume(effect.second->GetVolume() - value);
	}
}


void SoundManager::turnOnOffSound()
{
	
	if (m_IsSoundOn)
	{
		// Turn off sound

		for (std::pair<std::string, SoundStream*> sound : m_Sounds)
		{
			sound.second->Pause();
		}

		for (std::pair<std::string, SoundEffect*> effect : m_Effects)
		{
			effect.second->StopAll();
		}

		m_IsSoundOn = false;
	}
	else
	{
		// turn on sound
		for (std::pair<std::string, SoundStream*> sound : m_Sounds)
		{
			sound.second->Resume();
		}

		for (std::pair<std::string, SoundEffect*> effect : m_Effects)
		{
			effect.second->ResumeAll();
		}

		m_IsSoundOn = true;
	}
	
}

bool SoundManager::GetSoundActivated()
{
	return m_IsSoundOn;
}

// Randomly chooses the death sound for the enemies
std::string SoundManager::GetDeathSound()
{
	int deathEffect = rand() % 3;

	std::string filename{};


	switch (deathEffect)
	{
	case 0:
		filename = "Resources/Sounds/Soldierdies1.wav";
		break;

	case 1:
		filename = "Resources/Sounds/Soldierdies2.wav";
		break;

	case 2:
		filename = "Resources/Sounds/Soldierdies3.mp3";
		break;
	}

	return filename;
}