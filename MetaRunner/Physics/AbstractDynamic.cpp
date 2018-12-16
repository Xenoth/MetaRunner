#include "AbstractDynamic.h"

AbstractDynamic::AbstractDynamic():
        Tile()
{

    this->forcesSum = Vector2f(0,0);
    this->acceleration = Vector2f(0,0);
    this->velocity = Vector2f(0,0);
    this->position = Vector2f(0,0);
    this->weight = 1;

    this->isSubjectToGravity = false;
}

AbstractDynamic::AbstractDynamic(Vector2ui8 size, Vector2f position, float weight, bool isSubjectToGravity):
        Tile(size)
{
    if(weight == 0)
        weight = 1;

    this->forcesSum = Vector2f(0,0);
    this->acceleration = Vector2f(0,0);
    this->velocity = Vector2f(0,0);
    this->position = position;
    this->weight = weight;
    this->isSubjectToGravity = isSubjectToGravity;
}

inline void AbstractDynamic::addForce(Vector2f force)
{
    this->forcesSum += force;
}

inline void AbstractDynamic::setFriction(float friction)
{
    this->friction = friction;
}

Vector2f AbstractDynamic::calculateFrictionForce()
{
    return Vector2f( -1 * (this->friction * 2 * (this->velocity.x * this->velocity.x)),
            -1 * (this->friction * 2 * (this->velocity.y * this->velocity.y)));
}

void AbstractDynamic::applyForces()
{
    this->forcesSum += calculateFrictionForce();
    this->acceleration.x = this->forcesSum.x / this->weight;
    this->acceleration.y = this->forcesSum.y / this->weight;

    this->forcesSum = Vector2f(0,0);
}

inline void AbstractDynamic::applyAcceleration()
{
    this->velocity += this->acceleration;
}

inline void AbstractDynamic::applyVelocity()
{
    this->position += this->velocity;
}

