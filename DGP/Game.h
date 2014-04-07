#ifndef GAME_H
#define GAME_H
#include "Debug.h"
#include "ContentManager.h"
#include "ScreenManager.h"
#include "GamePlayScreen.h"
#include <SDL.h>

class Game
{
public:
	Game();
	~Game();
	static std::shared_ptr<Game> Create();
	bool Initialize(const char* title, int x, int y, int width, int height, int flags);
	void Update();
	void Draw();
	void HandleEvents();
	bool IsRunning();
	void CleanUp();
	Uint32 GetTimeElapsed(); //Get the time elapsed since the last frame
private:
	bool m_Running;
	SDL_Window* m_p_Window;
	SDL_Renderer * m_p_Renderer;
	std::shared_ptr<ScreenManager> m_p_ScreenManager;
	std::shared_ptr<ContentManager> m_p_ContentManager;
	Uint32 m_LastTime; //The time of the last frame
};

#endif