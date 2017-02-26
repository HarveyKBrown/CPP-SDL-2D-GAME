#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
void quit();
void input();

SDL_Surface* screenSurface = NULL;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int main( int argc, char* args[] )
{

	float x = 10;
	float y = 10;

	if ( !init() ) 
	{
		printf("Could not initialize SDL2\n");
	}
	else
	{	
		bool quit_flag = false;
		SDL_Event e;

		while ( !quit_flag ) 
		{
			while ( SDL_PollEvent( &e ) != 0 )
			{
				if ( e.type == SDL_QUIT )
				{
					quit_flag = true;
				}
			}

			/* Handle Keyboard Input */
			const Uint8* keyStates = SDL_GetKeyboardState( NULL );
			if ( keyStates[ SDL_SCANCODE_UP ] ) 
				{ y-=0.01; }
			if ( keyStates[ SDL_SCANCODE_DOWN ] ) 
				{ y+=0.01; }
			if ( keyStates[ SDL_SCANCODE_LEFT ] ) 
				{ x-=0.01; }
			if ( keyStates[ SDL_SCANCODE_RIGHT ] ) 
				{ x+=0.01; }
			


			SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
			SDL_RenderClear( renderer );

			SDL_Rect fillRect = { x, y, 10, 10 };
			SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0x00 );
			SDL_RenderFillRect( renderer, &fillRect );

			SDL_RenderPresent( renderer );
		}
	}

	quit();
	return 0;
}


/* initialize SDL */
bool init()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}

	//Create window
	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( window == NULL )
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}

	//Create renderer for window
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if( renderer == NULL )
	{
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

	screenSurface = SDL_GetWindowSurface( window );

	return true;
}

/* Exit SDL, freeing resorces */
void quit()
{
	SDL_FreeSurface( screenSurface );
	screenSurface = NULL;

	SDL_DestroyWindow( window );
	window = NULL;

	SDL_Quit();
}


