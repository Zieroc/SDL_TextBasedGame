#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H
#include "GameScreen.h"
#include "InputHandler.h"
#include <SDL_ttf.h>
#include "StoryManager.h"
#include "UIManager.h"

class GameplayScreen : public GameScreen
{
public:
	GameplayScreen();
	~GameplayScreen();
	static  std::shared_ptr<GameplayScreen> Create();
	void Initialize(ScreenManager* manager);
	void LoadContent(std::shared_ptr<ContentManager> conMan);
	void UnloadContent();
	void Update(Uint32 timeElapsed);
	void Draw(SDL_Renderer* renderer);
	void HandleInput(std::shared_ptr<InputHandler> input);
	void HandleEvents(SDL_Event sdlEvent);
private:
	TTF_Font* m_p_Font;
	std::shared_ptr<StoryManager> m_p_StoryManager;
	std::shared_ptr<UIManager> m_p_UIManager;
	std::shared_ptr<CC_Texture> m_p_Background;
};

#endif