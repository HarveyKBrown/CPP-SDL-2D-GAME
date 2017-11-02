#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Game.h"
#include <map>
#include <functional>

class EventManager
{
  private:
    //Action name to registered functions map
    static std::map<char*, void*> actionMap;

  public:
    static void registerAction(char* actionName, std::function<void*> const& f);
    //controller will resolve actionNames from keys using a master key list
    static void handleEvents();

};

#endif
