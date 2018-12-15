#include "UserController.h"
#include "GameController.h"

UserController::UserController(GameController* gameController) : gameController(gameController) {
  this->gameController = gameController; 
}

void UserController::loop() {
  if(gb.buttons.repeat(BUTTON_UP, 1))
    gameController->onButtonUpRepeat();
  if(gb.buttons.repeat(BUTTON_DOWN, 1))
    gameController->onButtonDownRepeat();
  if(gb.buttons.released(BUTTON_DOWN))
    gameController->onButtonDownReleased();
  if(gb.buttons.pressed(BUTTON_MENU))
    gameController->begin();
}
