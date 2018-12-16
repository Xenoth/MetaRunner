#ifndef RUNNER_GAMEBUINO_ABSTRACTSTATIC_H
#define RUNNER_GAMEBUINO_ABSTRACTSTATIC_H


#include "../Core/Tile.h"
#include "AbstractDynamic.h"

class AbstractStatic: public Tile
{
public:

    Vector2ui8 position;

    AbstractStatic();

    AbstractStatic(Vector2ui8 size, Vector2ui8 position);

    virtual void onInteract(AbstractDynamic* object) = 0;
};


#endif
