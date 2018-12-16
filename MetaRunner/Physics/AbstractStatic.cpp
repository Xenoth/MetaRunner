#include "AbstractStatic.h"

AbstractStatic::AbstractStatic():
        Tile()
{
    this->position = Vector2ui8(0,0);
}

AbstractStatic::AbstractStatic(Vector2ui8 size, Vector2ui8 position):
        Tile(size)
{
    this->position = position;
}
