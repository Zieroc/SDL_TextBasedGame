#include "StoryScene.h"

StoryScene::StoryScene()
{
}

StoryScene::~StoryScene()
{
}

std::shared_ptr<StoryScene> StoryScene::Create(int id, std::shared_ptr<TextSprite> descriptor, std::shared_ptr<CC_Texture> image)
{
	std::shared_ptr<StoryScene> pRet(new StoryScene());
	pRet->m_p_Descriptor = descriptor;
	pRet->m_Id = id;
	pRet->m_NumChoices = 0;
	pRet->m_p_Image = image;

	return pRet;
}

int StoryScene::GetID()
{
	return m_Id;
}

void StoryScene::Draw(SDL_Renderer* renderer)
{
	for(std::map<int, std::shared_ptr<SceneChoice>>::const_iterator iter = m_p_Choices.begin(); iter != m_p_Choices.end(); ++iter)
	{
		iter->second->Draw(renderer);
	}

	m_p_Descriptor->Draw(renderer);

	SDL_Rect destRect;
	destRect.x = m_ImagePosition.x;
	destRect.y = m_ImagePosition.y;
	destRect.w = m_p_Image->GetWidth();
	destRect.h = m_p_Image->GetHeight();
	SDL_RenderCopy(renderer, m_p_Image->GetTexture(), NULL, &destRect);
}

void StoryScene::AddChoices(std::shared_ptr<SceneChoice> choice)
{
	m_NumChoices++;
	m_p_Choices[choice->GetID()] = choice;
}

std::shared_ptr<SceneChoice> StoryScene::GetChoice(int id)
{
	return m_p_Choices[id];
}

int StoryScene::GetNumChoices()
{
	return m_NumChoices;
}

void StoryScene::SetDescriptorPosition(Vector2 position)
{
	m_p_Descriptor->SetPosition(position);
}

void StoryScene::SetImagePosition(Vector2 position)
{
	m_ImagePosition = position;
}