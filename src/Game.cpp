#include "Game.h"
#include <stdio.h>
#include "TextureManager.h"
#include "EventManager.h"

SDL_Texture* playerTexture;

Game::Game()
{}
Game::~Game()
{}

/* initialize SDL */
bool Game::init(const char* title, int width, int height, bool fullscreen)
{
	isRunning = true;

	/* Set fullscreen flag */
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_BORDERLESS;
	}

	/* Initialize SDL */
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
		return false;
	}

	/* Create window */
	window = SDL_CreateWindow( title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags );
	if( window == NULL )
	{
		std::cout << "Window could not be created! SDL_Error: %s\n" << SDL_GetError() << std::endl;
		return false;
	}

	/* Create renderer for window */
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if( renderer == NULL )
	{
		std::cout <<  "Renderer could not be created! SDL Error: %s\n" << SDL_GetError() << std::endl;
		return false;
	}

	/* Register the window quit control function */ 
	EventManager::registerEvent(EventManager::quit, [&] () { isRunning = false; });

	/* Set initial deltatime variable */
	NOW = SDL_GetPerformanceCounter();

	SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );

	playerTexture = TextureManager::loadTexture("assets/bee.png", renderer);

	return true;
}

void Game::calculateDelta()
{
	/* DeltaTime */
	LAST = NOW;
	NOW = SDL_GetPerformanceCounter();
	deltaTime = (double)(((NOW - LAST) * 1000)) / SDL_GetPerformanceFrequency();
	printf("DeltaTime: %f\n", deltaTime);
}

void Game::update()
{

}

void Game::render()
{
	/* Draw a bee, because why not */
	SDL_RenderClear( renderer );
	SDL_RenderCopy( renderer, playerTexture, NULL, NULL );
	SDL_RenderPresent( renderer );
}

void Game::clean()
{
	SDL_DestroyWindow( window );
	window = NULL;

	SDL_DestroyRenderer( renderer );
	renderer = NULL;

	SDL_Quit();
}
