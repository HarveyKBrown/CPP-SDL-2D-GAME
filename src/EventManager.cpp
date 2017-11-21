#include "EventManager.h"

/* EventCode -> EventLambda */
std::map<int, std::function<void()>> eventMap;

void EventManager::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	/* Quit Event */
	case SDL_QUIT:
		eventMap[quit]();
		break;

	/* If keys */
	default:
		break;
	}
}

void EventManager::registerEvent(int eventCode, std::function<void()> f)
{
	eventMap[eventCode] = f;
}
