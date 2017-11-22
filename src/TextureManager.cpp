#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* FILENAME, SDL_Renderer* r)
{
    SDL_Surface* s = IMG_Load( FILENAME );

    SDL_Texture* texture;
    texture = SDL_CreateTextureFromSurface( r, s );

    SDL_FreeSurface( s );
    s = NULL;

    return texture;
}
