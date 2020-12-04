#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Dice.h"
#include "Player.h"
#include "Tile.h"

class Game {
    private:
        char type;
        int turns;
        int snakes;
        int ladders;
        std::vector<Tile*> tiles;
        Dice dice;
        Player players[2];

        void fill_tiles(bool);
    public:
        Game();
        Game(
            char, int, int, int,
            Dice, Player[2]
        );
        
        void start();
};

#endif
