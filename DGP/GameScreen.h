#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include "Debug.h"
#include "ContentManager.h"
#include <SDL.h>
#include "InputHandler.h"

class ScreenManager; //Forward declaration

class GameScreen
{
public:
	GameScreen();
	virtual ~GameScreen();
	virtual void Initialize(ScreenManager* manager) = 0;
	virtual void LoadContent(std::shared_ptr<ContentManager> conMan) = 0;
	virtual void UnloadContent() = 0;
	virtual void Update(Uint32 timeElapsed) = 0;
	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual void HandleInput(std::shared_ptr<InputHandler> input) = 0;
	virtual void HandleEvents(SDL_Event sdlEvent) = 0;
	bool IsCovered();
	void SetCovered(bool covered);
protected:
	ScreenManager* m_p_Manager; //A reference to the screen manager that controls this screen
	bool m_Covered; //Is this screen covered by another one
};

#endif