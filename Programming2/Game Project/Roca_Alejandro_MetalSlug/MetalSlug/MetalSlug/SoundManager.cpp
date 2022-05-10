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


// Turn ON/Off the sound depending if it was on already or not
void SoundManager::turnOffSound()
{
	
	for (std::pair<std::string, SoundStream*> sound : m_Sounds)
	{
		if (m_IsSoundOn)
		{
			sound.second->Pause();
		}
		else
		{
			sound.second->Resume();
		}
	}

	for (std::pair<std::string, SoundEffect*> effect : m_Effects)
	{
		if (m_IsSoundOn)
		{
			effect.second->StopAll();
		}
		else
		{
			effect.second->ResumeAll();
		}
	}

	if (m_IsSoundOn)
	{
		m_IsSoundOn = false;
	}
	else
	{
		m_IsSoundOn = true;
	}
	
	
}