#ifndef LADDER_TILE_H
#define LADDER_TILE_H

#include "Tile.h"

class LadderTile : public Tile {
    private:
        int reward;
    public:
        LadderTile();
        LadderTile(int, int);

        int effect();
};

#endif
