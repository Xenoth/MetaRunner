#include <Gamebuino-Meta.h>
#include "GameController.h"

GameController *gameController;

void setup() {
  gb.begin();

  gb.lights.clear();
  gb.titleScreen();

  gb.pickRandomSeed();

  gameController = new GameController();
  gameController->begin();
}

void loop() {
  while(!gb.update());

  gameController->loop();
  
}
