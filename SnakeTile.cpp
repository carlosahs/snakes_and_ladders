#include "SnakeTile.h"

SnakeTile::SnakeTile() {
    penalty = 3;
}

SnakeTile::SnakeTile(int _index, int _penalty) : Tile(_index) {
    penalty = _penalty;
}

int SnakeTile::effect() {
    return -penalty;
}
