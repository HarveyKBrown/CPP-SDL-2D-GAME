#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Game.h"
#include <map>
#include <functional>

class EventManager
{
	private:

	public:
		enum Code { quit, jump, up, down, left, right };

		static void registerEvent(int eventCode, std::function<void()> f);

		//controller will resolve actionNames from keys using a master key list
		static void handleEvents();

};

#endif
