#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "Debug.h"
#include <SDL.h>
#include <memory>

class InputHandler
{
public:
	enum MouseButton {LeftButton = 1, MiddleButton, RightButton};
	InputHandler();
	~InputHandler();
	static std::shared_ptr<InputHandler> Create();
	void Update();
	bool MousePressed(MouseButton button);
	int GetMouseX();
	int GetMouseY();
private:
	int m_MouseX;
	int m_MouseY;
};

#endif