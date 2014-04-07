#ifndef UIDAO_H
#define UIDAO_H

#include <vector>
#include "ContentManager.h"
#include "StoryManager.h"
#include "ChoiceButton.h"
#include "tinyxml2.h"

class IUIDAO
{
public:
	virtual ~IUIDAO(){};

	//read
	virtual std::vector<std::shared_ptr<ChoiceButton>> Read(const char* file) = 0;
};


//xml implementation
class UIDAO : public IUIDAO
{
public:
	UIDAO(std::shared_ptr<StoryManager> story, std::shared_ptr<ContentManager> content);
	virtual ~UIDAO(){};

	//read
	std::vector<std::shared_ptr<ChoiceButton>> Read(const char* file);
private:
	//Story & Content Manager References for loading the text sprites
	std::shared_ptr<StoryManager> m_p_Story;
	std::shared_ptr<ContentManager> m_p_Content;
};

#endif