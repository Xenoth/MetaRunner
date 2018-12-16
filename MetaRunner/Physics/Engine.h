#ifndef RUNNER_GAMEBUINO_ENGINE_H
#define RUNNER_GAMEBUINO_ENGINE_H


#include "../Core/Tile.h"
#include "AbstractScene.h"
#include "AbstractDynamic.h"
#include "AbstractStatic.h"

class Engine
{
public:
    Vector2f gravity;

    Engine();

    void init(const Vector2f& gravity);

    void updateScene(AbstractScene scene);

    static bool twoRectanglesCollides(const float& R1x1, const float& R1x2, const float& R1y1, const float& R1y2, const float& R2x1, const float& R2x2, const float& R2y1, const float& R2y2);

    static bool collides(const AbstractDynamic& object1, const AbstractDynamic& object2);
    static bool collides(const AbstractDynamic& object1, const AbstractStatic& object2);
    static bool collides(const AbstractStatic& object1, const AbstractDynamic& object2);
};


#endif
