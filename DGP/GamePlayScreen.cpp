#include "GameplayScreen.h"
#include <iostream>
#include "ScreenManager.h"
#include <string>
#include "StoryDAO.h"
#include "UIDAO.h"

GameplayScreen::GameplayScreen()
{
}

GameplayScreen::~GameplayScreen()
{
	TTF_CloseFont(m_p_Font);
}

std::shared_ptr<GameplayScreen> GameplayScreen::Create()
{
	std::shared_ptr<GameplayScreen> pRet(new GameplayScreen());

	pRet->m_Covered = false;
	pRet->m_p_StoryManager = StoryManager::Create();

	return pRet;
}

void GameplayScreen::Initialize(ScreenManager* manager)
{
	m_p_Manager = manager;
}

void GameplayScreen::LoadContent(std::shared_ptr<ContentManager> conMan)
{
	conMan->LoadTexture("Screen.png");
	m_p_Background = conMan->GetTexture("Screen.png");
	m_p_Font = TTF_OpenFont("data/Files/SourceSansPro-Semibold.ttf", 26);
	StoryDAO storyDAO(m_p_Font, m_p_Manager->GetRenderer(), conMan);
	std::vector<std::shared_ptr<StoryScene>> storyScenes = storyDAO.Read("data/Files/Story.xml");

	for(int i = 0; i < storyScenes.size(); i++)
	{
		m_p_StoryManager->AddScene(storyScenes[i]);
	}

	UIDAO uiDAO(m_p_StoryManager, conMan);
	std::vector<std::shared_ptr<ChoiceButton>> buttons = uiDAO.Read("data/Files/UI.xml");

	m_p_UIManager = UIManager::Create(buttons, m_p_Manager->GetInputHandler(), m_p_StoryManager);
}

void GameplayScreen::UnloadContent()
{
}

void GameplayScreen::Update(Uint32 timeElapsed)
{
}

void GameplayScreen::Draw(SDL_Renderer* renderer)
{
	SDL_Rect destRect;
	destRect.x = 0;
	destRect.y = 0;
	destRect.w = m_p_Background->GetWidth();
	destRect.h = m_p_Background->GetHeight();
	SDL_RenderCopy(renderer, m_p_Background->GetTexture(), NULL, &destRect);
	m_p_StoryManager->Draw(renderer);
	m_p_UIManager->Draw(renderer);
}

void GameplayScreen::HandleInput(std::shared_ptr<InputHandler> input)
{
	 m_p_UIManager->HandleInput();
}

void GameplayScreen::HandleEvents(SDL_Event sdlEvent)
{
	m_p_StoryManager->HandleEvents(sdlEvent);
}