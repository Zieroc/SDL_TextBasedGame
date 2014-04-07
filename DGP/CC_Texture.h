#ifndef CC_TEXTURE_H
#define CC_TEXTURE_H
#include "Debug.h"
#include <SDL.h>
#include <SDL_image.h>
#include <memory>

class CC_Texture
{
public:
	CC_Texture();
	~CC_Texture();
	static std::shared_ptr<CC_Texture> Create(SDL_Renderer* renderer, const char* filepath);
	static std::shared_ptr<CC_Texture> Create(SDL_Texture* texture);
	int GetWidth();
	int GetHeight();
	SDL_Texture* GetTexture();
private:
	SDL_Texture* m_p_Texture;
	int m_Width;
	int m_Height;
};

#endif
