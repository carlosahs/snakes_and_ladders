#include "LadderTile.h"

LadderTile::LadderTile() {
    reward = 3;
}

LadderTile::LadderTile(int _index, int _reward) : Tile(_index) {
    reward = _reward;
}

int LadderTile::effect() {
    return reward;
}
