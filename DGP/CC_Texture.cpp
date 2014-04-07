#include "CC_Texture.h"
#include <iostream>

CC_Texture::CC_Texture()
{
}

CC_Texture::~CC_Texture()
{
	DEBUG_MSG("DESTROYED");
	SDL_DestroyTexture(m_p_Texture);
}

std::shared_ptr<CC_Texture> CC_Texture::Create(SDL_Renderer* renderer, const char* filepath)
{
	std::shared_ptr<CC_Texture> pRet(new CC_Texture());

	pRet->m_p_Texture = IMG_LoadTexture(renderer, filepath);

	if(pRet->m_p_Texture == 0)
	{
		DEBUG_MSG("ERROR LOADING TEXTURE:");
		DEBUG_MSG(filepath);
	}

	SDL_QueryTexture(pRet->m_p_Texture, NULL, NULL, &(pRet->m_Width), &(pRet->m_Height));

	return pRet;
}

std::shared_ptr<CC_Texture> CC_Texture::Create(SDL_Texture* texture)
{
	std::shared_ptr<CC_Texture> pRet(new CC_Texture());

	pRet->m_p_Texture = texture;

	if(pRet->m_p_Texture == 0)
	{
		DEBUG_MSG("ERROR LOADING TEXTURE:");
	}

	SDL_QueryTexture(pRet->m_p_Texture, NULL, NULL, &(pRet->m_Width), &(pRet->m_Height));

	return pRet;
}


int CC_Texture::GetWidth()
{
	return m_Width; 
}

int CC_Texture::GetHeight()
{
	return m_Height;
}

SDL_Texture* CC_Texture::GetTexture()
{
	return m_p_Texture;
}
