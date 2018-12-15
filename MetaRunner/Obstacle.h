#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "AbstractStatic.h"

class Obstacle: public AbstractStatic {

  public:
    Obstacle(float positionX, float positionY, float width, float height) : AbstractStatic(positionX, positionY, width, height)
    {  }

  void onInteract()
  {
    return;
  }

  static float generateNextPositionXObstacle(float mostFarObstaclePositionX, float separationBetweenObstacles)
  {    
    return separationBetweenObstacles + (random(20) - 10) + mostFarObstaclePositionX ;
  }

};

#endif
