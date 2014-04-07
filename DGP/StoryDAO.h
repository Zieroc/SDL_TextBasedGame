#ifndef STORYDAO_H
#define STORYDAO_H

#include <vector>
#include "ContentManager.h"
#include "StoryScene.h"
#include "tinyxml2.h"

class IStoryDAO
{
public:
	virtual ~IStoryDAO(){};

	//create
	virtual void Create(const char* file) = 0;

	//read
	virtual std::vector<std::shared_ptr<StoryScene>> Read(const char* file) = 0;
};


//xml implementation
class StoryDAO : public IStoryDAO
{
public:
	StoryDAO(TTF_Font* font, SDL_Renderer* renderer, std::shared_ptr<ContentManager> content);
	virtual ~StoryDAO(){};

	//create
	void Create(const char* file);

	//read
	std::vector<std::shared_ptr<StoryScene>> Read(const char* file);
private:
	//Font & Renderer References for loading the text sprites
	TTF_Font* m_p_Font;
	SDL_Renderer* m_p_Renderer;
	std::shared_ptr<ContentManager> m_p_Content;
};

#endif