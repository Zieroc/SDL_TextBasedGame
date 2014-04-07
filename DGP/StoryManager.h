#ifndef STORY_MANAGER_H
#define STORY_MANAGER_H

#include "StoryScene.h"
#include <ctype.h>

class StoryManager
{
public:
	StoryManager();
	~StoryManager();
	static std::shared_ptr<StoryManager> Create();
	void AddScene(std::shared_ptr<StoryScene> scene);
	void Draw(SDL_Renderer* renderer);
	void HandleEvents(SDL_Event sdlEvent);
	void SetPositions(Vector2 scenePos, Vector2 imagePos, Vector2 choicePos, int choicePosInc);
	std::shared_ptr<StoryScene> GetCurrentScene();
	void SwitchSceneByChoice(int scene);
private:
	std::map<int, std::shared_ptr<StoryScene>> m_p_Scenes;
	int m_CurrentSceneID; //ID of the current scene
};

#endif