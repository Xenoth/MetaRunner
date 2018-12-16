#ifndef RUNNER_GAMEBUINO_ABSTRACTDYNAMIC_H
#define RUNNER_GAMEBUINO_ABSTRACTDYNAMIC_H

#include <ws2tcpip.h>
#include "../Core/Tile.h"
#include "DynamicEnum.h"

class AbstractDynamic: public Tile
{
public:
    DynamicEnum type;

    Vector2f forcesSum;
    Vector2f acceleration;
    Vector2f velocity;
    Vector2f position;
    float weight;
    float friction;

    bool isSubjectToGravity;

    AbstractDynamic();

    AbstractDynamic(Vector2ui8 size, Vector2f position, float weight, bool isSubjectToGravity);

    void addForce(Vector2f force);
    void setFriction(float friction);

    Vector2f calculateFrictionForce();

    void applyForces();
    void applyAcceleration();
    void applyVelocity();

    virtual void onInteract(AbstractDynamic* object) = 0;
};


#endif
