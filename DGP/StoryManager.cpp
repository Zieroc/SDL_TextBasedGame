#include "StoryManager.h"

StoryManager::StoryManager()
{
}

StoryManager::~StoryManager()
{
}

std::shared_ptr<StoryManager> StoryManager::Create()
{
	std::shared_ptr<StoryManager> pRet(new StoryManager());
	pRet->m_CurrentSceneID = 0;

	return pRet;
}

void StoryManager::AddScene(std::shared_ptr<StoryScene> scene)
{
	m_p_Scenes[scene->GetID()] = scene;
}

void StoryManager::Draw(SDL_Renderer* renderer)
{
	m_p_Scenes[m_CurrentSceneID]->Draw(renderer);
	
}

void StoryManager::HandleEvents(SDL_Event sdlEvent)
{
	switch(sdlEvent.type)
	{
	case SDL_KEYDOWN:
		if(isdigit(SDL_GetKeyName(sdlEvent.key.keysym.sym)[0]))
		{
			int choice = atoi(SDL_GetKeyName(sdlEvent.key.keysym.sym));
			if(choice <= m_p_Scenes[m_CurrentSceneID]->GetNumChoices())
			{
				m_CurrentSceneID = (m_p_Scenes[m_CurrentSceneID]->GetChoice(choice)->GetSceneTransition());
			}
		}
		break;
	}
}

void StoryManager::SetPositions(Vector2 scenePos, Vector2 imagePos, Vector2 choicePos, int choicePosInc)
{
	for(int i = 0; i < m_p_Scenes.size(); i++)
	{
		m_p_Scenes[i]->SetImagePosition(imagePos);
		m_p_Scenes[i]->SetDescriptorPosition(scenePos);

		for(int j = 0; j < m_p_Scenes[i]->GetNumChoices(); j++)
		{
			m_p_Scenes[i]->GetChoice(j + 1)->SetPosition(Vector2(choicePos.x, choicePos.y + (j * choicePosInc)));
		}
	}
}

std::shared_ptr<StoryScene> StoryManager::GetCurrentScene()
{
	return m_p_Scenes[m_CurrentSceneID];
}

void StoryManager::SwitchSceneByChoice(int choice)
{
	m_CurrentSceneID = (m_p_Scenes[m_CurrentSceneID]->GetChoice(choice)->GetSceneTransition());
}