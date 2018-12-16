//
// Created by Xenoth on 16/12/2018.
//

#include "Tile.h"

Tile::Tile()
{
    this-> size = Vector2ui8(0,0);
}

Tile::Tile(Vector2ui8 size)
{
    this->size = size;
}