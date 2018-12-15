#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <Gamebuino-Meta.h>

#include "AbstractDynamic.h"

class Player: public AbstractDynamic {
  public:

    static const uint8_t STATE_JUMPING = 1;
    static const uint8_t STATE_FALLING = 2;
    static const uint8_t STATE_CROUCHING = 4;
    static const uint8_t STATE_RUNNING = 8;

    uint8_t state;

    const float initialJumpYVelocity = -7.5;
    const float playerForcingFallingAcceleration = 2.0;

    Player(const uint8_t state, float positionX, float positionY, uint8_t width, uint8_t height)
      :AbstractDynamic(positionX, positionY, width, height)
    {
      this->state = state;
    }

    void onInteract()
    {
      return;
    }

    void run()
    {
      if(state == STATE_CROUCHING)
      {
        state = STATE_RUNNING;
        this->positionY -= 8;
        this->height = 16;
        this->width = 8;
      }
    }

    void crouch()
    {
      if(state == STATE_JUMPING || state == STATE_FALLING)
      {
        state = STATE_FALLING;
        this->velocityY += playerForcingFallingAcceleration;       
      }

      else if(state == STATE_RUNNING)
      {
        state = STATE_CROUCHING;
        this->positionY += 8;
        this->height = 8;
        this->width = 16;
      }
    }

    void jump()
    {
        if(state == STATE_RUNNING)
        {
          state = STATE_JUMPING;
          velocityY = initialJumpYVelocity;
          gb.sound.playOK();
        }
    }
};

#endif


