#ifndef _USER_CONTROLLER_H_
#define _USER_CONTROLLER_H_

#include <Gamebuino-Meta.h>
//#include "GameController.h"

class GameController;

class UserController {
  
  private:
    GameController* gameController;

  public:
    UserController(GameController *gameController);
  
    void loop();
  
};

#endif
