#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.h"

class TextureManager
{
	public:
		static SDL_Texture* loadTexture ( const char* FILENAME, SDL_Renderer* r );
};

#endif
