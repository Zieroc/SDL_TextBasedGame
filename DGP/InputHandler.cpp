#include "InputHandler.h"
#include <iostream>

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

std::shared_ptr<InputHandler> InputHandler::Create()
{
	std::shared_ptr<InputHandler> pRet(new InputHandler);
	SDL_GetMouseState(&(pRet->m_MouseX), &(pRet->m_MouseY));
	return pRet;
}

void InputHandler::Update()
{
	SDL_PumpEvents();
	SDL_GetMouseState(&m_MouseX, &m_MouseY);
}

bool InputHandler::MousePressed(MouseButton button)
{
	SDL_PumpEvents();
	return(SDL_GetMouseState(&m_MouseX, &m_MouseY) & SDL_BUTTON(button));
}

int InputHandler::GetMouseX()
{
	return m_MouseX;
}

int InputHandler::GetMouseY()
{
	return m_MouseY;
}