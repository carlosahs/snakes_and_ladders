#include <iostream>
#include <stdexcept>

#include "Tile.h"
#include "LadderTile.h"
#include "SnakeTile.h"
#include "Player.h"
#include "Game.h"

int main() {
    try {
        Player players[2];

        std::string p1_name { "" };
        std::string p2_name { "" };

        std::cout << "Type name of player 1\n";
        std::cin >> p1_name;

        std::cout << "Type name of player 2\n";
        std::cin >> p2_name;

        players[0] = Player(p1_name);
        players[1] = Player(p2_name);

        char game_type { ' ' };

        std::cout << "What game type do you prefer? (A / M)\n";
        std::cin >> game_type;

        int turns { 0 };

        std::cout << "How many turns in the game?\n";
        std::cin >> turns;

        int snakes { 0 };

        std::cout << "How many snakes?\n";
        std::cin >> snakes;

        int ladders { 0 };

        std::cout << "How many ladders?\n";
        std::cin >> ladders;

        int dice_faces { 0 };

        std::cout << "How many faces in the dice?\n";
        std::cin >> dice_faces;

        Game game(
            game_type, turns, snakes, 
            ladders, Dice(dice_faces), players
        );

        game.start();
    } catch (std::logic_error &e) {
        std::cerr << e.what() << "\n";
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << "\n";
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
