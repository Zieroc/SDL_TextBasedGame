#include "SoundManager.h"


SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

std::shared_ptr<SoundManager> SoundManager::Create(std::shared_ptr<ContentManager> contentMan)
{
	std::shared_ptr<SoundManager> pRet(new SoundManager);

	pRet->m_p_ContentManager = contentMan;

	return pRet;
}

void SoundManager::PlayMusic(string name)
{
	Mix_PlayMusic(m_p_ContentManager->GetMusic(name), -1);
}

void SoundManager::FadeInMusic(string name, int ms)
{
	Mix_FadeInMusic(m_p_ContentManager->GetMusic(name), -1, ms);
}

void SoundManager::FadeOutMusic(int ms)
{
	Mix_FadeOutMusic(ms);
}

void SoundManager::PlaySoundEffect(string name)
{
	Mix_PlayChannel(-1, m_p_ContentManager->GetSoundEffect(name), 0);
}

void SoundManager::PauseMusic()
{
	if(!Mix_PausedMusic())
	{
		Mix_PauseMusic();
	}
}

void SoundManager::ResumeMusic()
{
	if(Mix_PausedMusic())
	{
		Mix_ResumeMusic();
	}
}

void SoundManager::StopMusic()
{
	if(Mix_PlayingMusic())
	{
		Mix_HaltMusic();
	}
}