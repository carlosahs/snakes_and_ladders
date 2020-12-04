#ifndef SNAKE_TILE_H
#define SNAKE_TILE_H

#include "Tile.h"

class SnakeTile : public Tile {
    private:
        int penalty;
    public:
        SnakeTile();
        SnakeTile(int, int);

        int effect();
};

#endif
