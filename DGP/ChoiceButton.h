#ifndef CHOICE_BUTTON__H
#define CHOICE_BUTTON__H

#include "CC_Texture.h"
#include "InputHandler.h"
#include "Vector2.h"

class ChoiceButton
{
public:
	ChoiceButton();
	~ChoiceButton();
	static std::shared_ptr<ChoiceButton> Create(std::shared_ptr<CC_Texture> texture, std::shared_ptr<CC_Texture> hoverTexture, Vector2 position, int choice);
	void Draw(SDL_Renderer* renderer, Vector2 mousePos);
	int HandleInput(std::shared_ptr<InputHandler> input); //Returns either the choice if the button is clicked or a 0 if none is selected
private:
	std::shared_ptr<CC_Texture> m_p_Texture;
	std::shared_ptr<CC_Texture> m_p_HoverTexture;
	Vector2 m_Position;
	SDL_Rect m_Bounds;
	bool m_Clicked;
	int m_Choice; //The choice this button represents
};

#endif