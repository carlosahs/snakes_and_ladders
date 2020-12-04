#ifndef TILE_H
#define TILE_H

// tiles must have an index between 1 and 30
const int MAX_TILE_INDEX { 30 };

class Tile {
    private:
        int index;
    public:
        Tile();
        Tile(int);

        virtual int effect();

        char get_label();

        int get_index();
};

#endif
