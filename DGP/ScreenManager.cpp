#include "ScreenManager.h"
#include <iostream>


ScreenManager::ScreenManager()
{
}

ScreenManager::~ScreenManager()
{
	while(!m_p_Screens.empty())
	{
		//Unload any content held by that screen
		m_p_Screens.front()->UnloadContent();
		m_p_Screens.pop_front();
	}
}

std::shared_ptr<ScreenManager> ScreenManager::Create(SDL_Renderer* renderer, std::shared_ptr<ContentManager> conMan)
{
	std::shared_ptr<ScreenManager> pRet(new ScreenManager());
	pRet->m_p_Renderer = renderer;
	pRet->m_p_ContentManager = conMan;
	pRet->m_p_InputHandler = InputHandler::Create();

	return pRet;
}

void ScreenManager::Initialize()
{
}

void ScreenManager::LoadContent()
{
	m_p_Screens.front()->LoadContent(m_p_ContentManager);
}

void ScreenManager::UnloadContent()
{
	m_p_Screens.front()->UnloadContent();
}

void ScreenManager::Update(Uint32 timeElapsed)
{
	//m_p_InputHandler->Update(); //Update the input

	m_p_UpdateScreens.clear();

	for(auto iter = m_p_Screens.begin(); iter != m_p_Screens.end(); ++iter)
	{
		if(iter != m_p_Screens.end())
		{
			m_p_UpdateScreens.push_front(*iter);
		}
	}

    while (!m_p_UpdateScreens.empty())
    {
        //Get the screen and the remove it from the update list
        std::shared_ptr<GameScreen> screen = m_p_Screens.front();
        m_p_UpdateScreens.pop_front();

        // Update the screen.
        screen->Update(timeElapsed);
	}

	m_p_Screens.front()->HandleInput(m_p_InputHandler);
}

void ScreenManager::HandleEvents(SDL_Event sdlEvent)
{
	//Front screen will always be the active one
	m_p_Screens.front()->HandleEvents(sdlEvent);
}

void ScreenManager::Draw()
{
	for(forward_list<std::shared_ptr<GameScreen>>::const_iterator iter = m_p_Screens.begin(); iter != m_p_Screens.end(); ++iter)
	{
		if(!(*iter)->IsCovered())
		{
			(*iter)->Draw(m_p_Renderer);
		}
	}
}

void ScreenManager::AddScreen(std::shared_ptr<GameScreen> screen, bool removePrevious)
{
	if(removePrevious)
	{
		RemoveScreen();
	}
	else
	{
		if(!m_p_Screens.empty())
		{
			m_p_Screens.front()->SetCovered(true);
		}
	}

	screen->Initialize(this);
	screen->LoadContent(m_p_ContentManager);
	m_p_Screens.push_front(screen);
}

void ScreenManager::AddPopup(std::shared_ptr<GameScreen> popup)
{
	popup->Initialize(this);
	popup->LoadContent(m_p_ContentManager);
	m_p_Screens.push_front(popup);
}

void ScreenManager::RemoveScreen()
{
	if(!m_p_Screens.empty())
	{
		m_p_Screens.front()->UnloadContent();
		m_p_Screens.pop_front();
		m_p_Screens.front()->SetCovered(false);
	}
}

SDL_Renderer* ScreenManager::GetRenderer()
{
	return m_p_Renderer;
}

std::shared_ptr<InputHandler> ScreenManager::GetInputHandler()
{
	return m_p_InputHandler;
}