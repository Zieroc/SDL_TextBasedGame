#ifndef SCENE_CHOICE_H
#define SCENE_CHOICE_H

#include "TextSprite.h"
#include "Vector2.h"

class SceneChoice
{
public:
	SceneChoice();
	~SceneChoice();
	static std::shared_ptr<SceneChoice> Create(int id, std::shared_ptr<TextSprite> text, int sceneTransition);
	void Draw(SDL_Renderer* renderer);
	int GetID();
	int GetSceneTransition();
	void SetPosition(Vector2 position);
private:
	int m_Id;
	int m_SceneTransition; //The scene to move to if this choice is selected
	std::shared_ptr<TextSprite> m_p_Text;
};

#endif