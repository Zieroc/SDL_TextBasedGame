#include "StoryDAO.h"

StoryDAO::StoryDAO(TTF_Font* font, SDL_Renderer* renderer, std::shared_ptr<ContentManager> content)
{
	m_p_Font = font;
	m_p_Renderer = renderer;
	m_p_Content = content;
}

//create
void StoryDAO::Create(const char* file)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLNode* node = doc.NewElement("Story");
	doc.InsertEndChild(node);
	doc.SaveFile(file);
}

//read
std::vector<std::shared_ptr<StoryScene>> StoryDAO::Read(const char* file)
{
	std::vector<std::shared_ptr<StoryScene>> storyScenes;

	tinyxml2::XMLDocument doc;
	//doc.LoadFile(file);

	if(doc.LoadFile(file) ==  tinyxml2::XML_SUCCESS)
	{
		//doc.Parse(XMLDOC);

		//get the first story element
		tinyxml2::XMLElement* root = doc.FirstChildElement();
		for(tinyxml2::XMLElement* child = root->FirstChildElement(); child != NULL; child =  child->NextSiblingElement())
		{
			int id = atoi(child->FirstChildElement()->GetText());
			const char* image = child->FirstChildElement("Image")->GetText();
			m_p_Content->LoadTexture(image);
			std::shared_ptr<StoryScene> storyScene = StoryScene::Create(id, TextSprite::Create(m_p_Font, child->FirstChildElement("SceneText")->GetText(), m_p_Renderer), m_p_Content->GetTexture(image));

			for(tinyxml2::XMLElement* sceneChoiceElement = child->FirstChildElement("SceneChoice"); sceneChoiceElement != NULL; sceneChoiceElement = sceneChoiceElement->NextSiblingElement())
			{
				id = atoi(sceneChoiceElement->FirstChildElement()->GetText());
				int transition = atoi(sceneChoiceElement->FirstChildElement("Transition")->GetText());
				std::shared_ptr<SceneChoice> choice = SceneChoice::Create(id, TextSprite::Create(m_p_Font, sceneChoiceElement->FirstChildElement("ChoiceText")->GetText(), m_p_Renderer), transition);
				storyScene->AddChoices(choice);
			}

			storyScenes.push_back(storyScene);
		}
	}

	return storyScenes;
}