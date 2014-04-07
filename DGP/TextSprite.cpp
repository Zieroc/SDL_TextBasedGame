#include "TextSprite.h"

TextSprite::TextSprite()
{
}

TextSprite::~TextSprite()
{
}

std::shared_ptr<TextSprite> TextSprite::Create(TTF_Font* font, const char* message, SDL_Renderer* renderer)
{
	std::shared_ptr<TextSprite> pRet(new TextSprite());

	SDL_Color colour;
	colour.a = 255;
	colour.r = 0;
	colour.g = 0;
	colour.b = 0;

	SDL_Surface* surf = TTF_RenderText_Blended_Wrapped(font, message, colour, 760);
	if (surf == NULL)
	{
		return NULL;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == NULL)
	{
	
	}

	SDL_FreeSurface(surf);

	pRet->m_p_Texture = CC_Texture::Create(texture);
	return pRet;
}

void TextSprite::Draw(SDL_Renderer* renderer)
{
	SDL_Rect destRect;
	destRect.x = m_Position.x;
	destRect.y = m_Position.y;
	destRect.w = m_p_Texture->GetWidth();
	destRect.h = m_p_Texture->GetHeight();
	SDL_RenderCopy(renderer, m_p_Texture->GetTexture(), NULL, &destRect);
}

void TextSprite::SetPosition(Vector2 position)
{
	m_Position = position;
}

std::shared_ptr<CC_Texture> TextSprite::GetTexture()
{
	return m_p_Texture;
}