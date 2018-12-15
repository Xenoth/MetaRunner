#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include <Gamebuino-Meta.h>

#include "AbstractDynamic.h"

class Physics {
  public:

    static bool collides(AbstractDynamic object1, AbstractDynamic object2)
    {
      return twoRectanglesCollides(object1.positionX, object1.positionX + object1.width, object1.positionY, object1.positionY + object1.height,
                                    object2.positionX, object2.positionX + object2.width, object2.positionY, object2.positionY + object2.height);
    }

    static bool collides(AbstractDynamic object1, AbstractStatic object2)
    {
      bool res =  twoRectanglesCollides(object1.positionX, object1.positionX + object1.width, object1.positionY, object1.positionY + object1.height,
                                    object2.positionX, object2.positionX + object2.width, object2.positionY, object2.positionY + object2.height);

      if(res)
      {
        gb.sound.playCancel();
      }
      return twoRectanglesCollides(object1.positionX, object1.positionX + object1.width, object1.positionY, object1.positionY + object1.height,
                                    object2.positionX, object2.positionX + object2.width, object2.positionY, object2.positionY + object2.height);
    }

   static bool twoRectanglesCollides(float R1x1, float R1x2, float R1y1, float R1y2, float R2x1, float R2x2, float R2y1, float R2y2)
   {
       bool noColision =  R1x1 > R2x2 ||
                         R2x1 > R1x2 ||
                         R1y1 > R2y2 ||
                         R2y1 > R1y2;

      
      return (!noColision);
   }

   static void applyForce(AbstractDynamic *object, float accelerationX, float accelerationY)
   {
      object->velocityX += accelerationX;
      object->velocityY += accelerationY;
   }

   static void moveObject(AbstractDynamic *object)
   {
      object->positionX += object->velocityX;
      object->positionY += object->velocityY;
   }
};

#endif
