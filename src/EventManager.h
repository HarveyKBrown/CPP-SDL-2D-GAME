#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Game.h"

class EventManager
{
private:
//Action name to registered functions map
//
public:
static void registerAction(char* actionName, void (*f) (void));
//controller will resolve actionNames from keys using a master key list

//Main event handler function
static void handleEvents();

};

#endif
