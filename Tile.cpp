#include <stdexcept>

#include "Tile.h"

Tile::Tile() {
    index = 1;
}

Tile::Tile(int _index) {
    if (_index < 1 || _index > 30)
        throw std::out_of_range("Tiles can only have an index between 1 and 30");
    index = _index;
}

int Tile::effect() {
    return 0;
}

char Tile::get_label() {
    int i { effect() };

    if (i == 0) return 'N';
    else if (i > 0) return 'L';
    else return 'S';
}

int Tile::get_index() {
    return index;
}
