#ifndef STORY_SCENE_H
#define STORY_SCENE_H

#include <map>
#include "SceneChoice.h"

class StoryScene
{
public:
	StoryScene();
	~StoryScene();
	static std::shared_ptr<StoryScene> Create(int id, std::shared_ptr<TextSprite> descriptor, std::shared_ptr<CC_Texture> image);
	void AddChoices(std::shared_ptr<SceneChoice> choice);
	void Draw(SDL_Renderer* renderer);
	int GetID();
	std::shared_ptr<SceneChoice> GetChoice(int id);
	int GetNumChoices();
	void SetDescriptorPosition(Vector2 position);
	void SetImagePosition(Vector2 position);
private:
	int m_Id;
	int m_NumChoices;
	Vector2 m_ImagePosition;
	std::shared_ptr<TextSprite> m_p_Descriptor;
	std::map<int, std::shared_ptr<SceneChoice>> m_p_Choices;
	std::shared_ptr<CC_Texture> m_p_Image;
};

#endif