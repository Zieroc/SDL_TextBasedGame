#ifndef TEXT_SPRITE_H
#define TEXT_SPRITE_H

#include "CC_Texture.h"
#include "Vector2.h"
#include <SDL_ttf.h>

class TextSprite
{
public:
	TextSprite();
	~TextSprite();
	static std::shared_ptr<TextSprite> Create(TTF_Font* font,  const char* message, SDL_Renderer* renderer);
	void Draw(SDL_Renderer* renderer);
	void SetPosition(Vector2 position);
	std::shared_ptr<CC_Texture> GetTexture();
private:
	std::shared_ptr<CC_Texture> m_p_Texture;
	Vector2 m_Position;
};

#endif