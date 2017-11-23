#include "Game.h"
#include "EventManager.h"

Game* game = NULL;

int main( int argc, char* args[] )
{

	game = new Game();
	game->init("SDL Engine", 500, 500, false);

	while (game->running())
	{
		EventManager::handleEvents();
		game->calculateDelta();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}
