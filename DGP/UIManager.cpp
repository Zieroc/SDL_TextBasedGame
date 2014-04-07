#include "UIManager.h"

UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}

std::shared_ptr<UIManager> UIManager::Create(std::vector<std::shared_ptr<ChoiceButton>> buttons, std::shared_ptr<InputHandler> input, std::shared_ptr<StoryManager> story)
{
	std::shared_ptr<UIManager> pRet(new UIManager());
	pRet->m_p_Buttons = buttons;
	pRet->m_p_InputRef = input;
	pRet->m_p_Story = story;

	return pRet;
}

void UIManager::Draw(SDL_Renderer* renderer)
{
	for(int i = 0; i < m_p_Story->GetCurrentScene()->GetNumChoices(); i++)
	{
		m_p_Buttons[i]->Draw(renderer, Vector2(m_p_InputRef->GetMouseX(), m_p_InputRef->GetMouseY()));
	}
}


void UIManager::HandleInput()
{
	for(int i = 0; i < m_p_Story->GetCurrentScene()->GetNumChoices(); i++)
	{
		int option = m_p_Buttons[i]->HandleInput(m_p_InputRef);

		if(option != 0)
		{
			m_p_Story->SwitchSceneByChoice(option);
		}
	}
}