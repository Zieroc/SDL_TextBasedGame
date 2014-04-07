#include "SceneChoice.h"

SceneChoice::SceneChoice()
{
}

SceneChoice::~SceneChoice()
{
}

std::shared_ptr<SceneChoice> SceneChoice::Create(int id, std::shared_ptr<TextSprite> text, int sceneTransition)
{
	std::shared_ptr<SceneChoice> pRet(new SceneChoice());
	pRet->m_p_Text = text;
	pRet->m_SceneTransition = sceneTransition;
	pRet->m_Id = id;

	return pRet;
}

void SceneChoice::Draw(SDL_Renderer* renderer)
{
	m_p_Text->Draw(renderer);
}

int SceneChoice::GetID()
{
	return m_Id;
}

int SceneChoice::GetSceneTransition()
{
	return m_SceneTransition;
}

void SceneChoice::SetPosition(Vector2 position)
{
	m_p_Text->SetPosition(position);
}