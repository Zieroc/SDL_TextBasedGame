#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include "GameScreen.h"
#include "Debug.h"
#include "ContentManager.h"
#include "InputHandler.h"
#include <forward_list>
#include <iostream>
#include <SDL.h>

using std::forward_list;

class ScreenManager
{
public:
	ScreenManager();
	~ScreenManager();
	static std::shared_ptr<ScreenManager> Create(SDL_Renderer* renderer, std::shared_ptr<ContentManager> conMan);
	void Initialize();
	void LoadContent();
	void UnloadContent();
	void Update(Uint32 timeElapsed);
	void HandleEvents(SDL_Event sdlEvent);
	void Draw();
	void AddScreen(std::shared_ptr<GameScreen> screen, bool removePrevious);
	void AddPopup(std::shared_ptr<GameScreen> popup);
	void RemoveScreen(); //Removes the last added screen
	SDL_Renderer* GetRenderer();
	std::shared_ptr<InputHandler> GetInputHandler();
private:
	forward_list<std::shared_ptr<GameScreen>> m_p_Screens;
	forward_list<std::shared_ptr<GameScreen>> m_p_UpdateScreens;
	std::shared_ptr<InputHandler> m_p_InputHandler;
	std::shared_ptr<ContentManager> m_p_ContentManager;
	SDL_Renderer* m_p_Renderer;
};

#endif

