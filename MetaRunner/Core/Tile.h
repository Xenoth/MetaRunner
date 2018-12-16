#ifndef RUNNER_GAMEBUINO_TILE_H
#define RUNNER_GAMEBUINO_TILE_H


#include "Vector2.hpp"

class Tile
{
public:
    Vector2ui8 size;

    Tile();

    explicit Tile(Vector2ui8 size);
};


#endif
