#include "ChoiceButton.h"

ChoiceButton::ChoiceButton()
{
}

ChoiceButton::~ChoiceButton()
{
}

std::shared_ptr<ChoiceButton> ChoiceButton::Create(std::shared_ptr<CC_Texture> texture, std::shared_ptr<CC_Texture> hoverTexture, Vector2 position, int choice)
{
	std::shared_ptr<ChoiceButton> pRet(new ChoiceButton());
	pRet->m_p_Texture = texture;
	pRet->m_p_HoverTexture = hoverTexture;
	pRet->m_Position = position;
	pRet->m_Choice = choice;

	pRet->m_Bounds.x = position.x;
	pRet->m_Bounds.y = position.y;
	pRet->m_Bounds.w = texture->GetWidth();
	pRet->m_Bounds.h = texture->GetHeight();

	pRet->m_Clicked = false;

	return pRet;
}

void ChoiceButton::Draw(SDL_Renderer* renderer, Vector2 mousePos)
{
	SDL_Rect mouse;
	mouse.x = mousePos.x;
	mouse.y = mousePos.y;
	mouse.w = 8;
	mouse.h = 8;

	if(SDL_HasIntersection(&mouse, &m_Bounds))
	{
		SDL_RenderCopy(renderer, m_p_HoverTexture->GetTexture(), NULL, &m_Bounds);
	}
	else
	{
		SDL_RenderCopy(renderer, m_p_Texture->GetTexture(), NULL, &m_Bounds);
	}
}

int ChoiceButton::HandleInput(std::shared_ptr<InputHandler> input)
{
	if(input->MousePressed(input->LeftButton))
	{
		if(!m_Clicked)
		{
			SDL_Rect mouse;
			mouse.x = input->GetMouseX();
			mouse.y = input->GetMouseY();
			mouse.w = 8;
			mouse.h = 8;
			
			m_Clicked = true;

			if(SDL_HasIntersection(&mouse, &m_Bounds))
			{
				return m_Choice;
			}
			else 
			{
				return 0;
			}
		}
	}
	else
	{
		m_Clicked = false;
	}

	return 0;
}