#include "UIDAO.h"

UIDAO::UIDAO(std::shared_ptr<StoryManager> story, std::shared_ptr<ContentManager> content)
{
	m_p_Story = story;
	m_p_Content = content;
}

std::vector<std::shared_ptr<ChoiceButton>>UIDAO::Read(const char* file)
{
	std::vector<std::shared_ptr<ChoiceButton>> buttons;

	tinyxml2::XMLDocument doc;
	//doc.LoadFile(file);

	if(doc.LoadFile(file) ==  tinyxml2::XML_SUCCESS)
	{
		//doc.Parse(XMLDOC);

		//get the first story element
		tinyxml2::XMLElement* root = doc.FirstChildElement();
		
		Vector2 storyScenePos;
		Vector2 storyImagePos;
		Vector2 storyChoicePos;
		int storyChoicePosInc;

		storyScenePos.x = atoi(root->FirstChildElement()->GetText());
		storyScenePos.y = atoi(root->FirstChildElement("SSY")->GetText());
		storyImagePos.x = atoi(root->FirstChildElement("SIX")->GetText());
		storyImagePos.y = atoi(root->FirstChildElement("SIY")->GetText());
		storyChoicePos.x = atoi(root->FirstChildElement("SCX")->GetText());
		storyChoicePos.y = atoi(root->FirstChildElement("SCY")->GetText());
		storyChoicePosInc = atoi(root->FirstChildElement("SCI")->GetText());

		
		m_p_Story->SetPositions(storyScenePos, storyImagePos, storyChoicePos, storyChoicePosInc);

		for(tinyxml2::XMLElement* child = root->FirstChildElement("Button"); child != NULL; child =  child->NextSiblingElement())
		{
			Vector2 position;
			position.x = atoi(child->FirstChildElement()->GetText());
			position.y = atoi(child->FirstChildElement("Y")->GetText());
			const char* image = child->FirstChildElement("Image")->GetText();
			m_p_Content->LoadTexture(image);
			const char* imageH = child->FirstChildElement("Hover")->GetText();
			m_p_Content->LoadTexture(imageH);
			int choice = atoi(child->FirstChildElement("Choice")->GetText());
			std::shared_ptr<ChoiceButton> button = ChoiceButton::Create(m_p_Content->GetTexture(image), m_p_Content->GetTexture(imageH), position, choice);
			buttons.push_back(button);
		}
	}

	return buttons;
}