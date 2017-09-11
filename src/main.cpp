#include "Game.h"

Game* game = NULL;

int main( int argc, char* args[] )
{

	game = new Game();
	game->init("SDL Engine", 720, 480, false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}
