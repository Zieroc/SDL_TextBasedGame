#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <vector>
#include "ChoiceButton.h"
#include "StoryManager.h"

class UIManager
{
public:
	UIManager();
	~UIManager();
	static std::shared_ptr<UIManager> Create(std::vector<std::shared_ptr<ChoiceButton>> buttons, std::shared_ptr<InputHandler> input, std::shared_ptr<StoryManager> story);
	void Draw(SDL_Renderer* renderer);
	void HandleInput();
private:
	std::shared_ptr<InputHandler> m_p_InputRef;
	std::shared_ptr<StoryManager> m_p_Story;
	std::vector<std::shared_ptr<ChoiceButton>> m_p_Buttons;
};

#endif