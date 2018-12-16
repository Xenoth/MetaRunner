#include "Engine.h"

Engine::Engine()
{
    this->gravity = Vector2f(0,0);
}

void Engine::init(const Vector2f& gravity)
{
    this->gravity = gravity;
}

void Engine::updateScene(AbstractScene scene)
{
    AbstractDynamic* currentDynamic
    for(uint8_t i = 0; i < scene.numberDynamicObjects; i++)
    {
        currentDynamic = scene.dynamicObjects[i];

        if(currentDynamic->isSubjectToGravity)
            currentDynamic->addForce(gravity);

        currentDynamic->applyForces();
        currentDynamic->applyAcceleration();
        currentDynamic->applyVelocity();

        for(uint8_t j = 0; i < scene.numberDynamicObjects; j++)
        {
            if(j == i)
                continue;
            if(collides(*currentDynamic, *scene.dynamicObjects[j]))
                scene.dynamicObjects[j]->onInteract(currentDynamic);
        }

        for(uint8_t j = 0; i < scene.numberStaticObjects; j++)
        {
            if(collides(*currentDynamic, *scene.staticsObject[j]))
                scene.staticsObject[j]->onInteract(currentDynamic);
        }
    }
}

static bool Engine::twoRectanglesCollides(const float& R1x1, const float& R1x2, const float& R1y1, const float& R1y2, const float& R2x1, const float& R2x2, const float& R2y1, const float& R2y2)
{
    bool noCollision = R1x1 > R2x2 ||
                       R2x1 > R1x2 ||
                       R1y1 > R2y2 ||
                       R2y1 > R1y2;


    return (!noCollision);
}

inline static bool Engine::collides(const AbstractDynamic& object1, const AbstractDynamic& object2)
{
    return twoRectanglesCollides(object1.position.x, object1.position.x + object1.size.x, object1.position.y, object1.position.y + object1.size.y,
                                 object2.position.x, object2.position.x + object2.size.x, object2.position.y, object2.position.y + object2.size.y);
}


inline static bool Engine::collides(const AbstractDynamic& object1, const AbstractStatic& object2)
{
    return twoRectanglesCollides(object1.position.x, object1.position.x + object1.size.x, object1.position.y, object1.position.y + object1.size.y,
                                 object2.position.x, object2.position.x + object2.size.x, object2.position.y, object2.position.y + object2.size.y);
}

inline static bool Engine::collides(const AbstractStatic& object1, const AbstractDynamic& object2)
{
    collides(object2, object1);
}

