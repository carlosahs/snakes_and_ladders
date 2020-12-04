#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Tile.h"

class Player {
    private:
        std::string name;
        bool winner;
        int tile_index;
    public:
        Player();
        Player(std::string);

        int get_tile_index();

        std::string get_name();

        bool won();

        Player& operator+=(int);
};

#endif
