#include "EventManager.h"

void EventManager::handleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type)
  {
    case SDL_QUIT:
    /*swap this to a registered action in the map, main game controller will register quit */
      //isRunning = false;
      break;

    /* If keys */
    default:
      break;
  }
}

void EventManager::registerAction(char* actionName, void (*f) (void))
{
  actionMap[actionName] = f;
}
