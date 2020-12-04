#include <iostream>
#include <stdexcept>

#include "Game.h"
#include "LadderTile.h"
#include "SnakeTile.h"

Game::Game() {
    type = 'A';
    turns = 100;
    snakes = 5;
    ladders = 6;

    fill_tiles(false);

    dice = Dice(6);

    players[0] = Player();
    players[1] = Player();
}

Game::Game(
    char _type, int _turns, int _snakes,
    int _ladders, Dice _dice, Player _players[2]
) {
    if (_dice.get_faces() > 10) 
        throw std::invalid_argument("The game does not accept a dice with more than 10 faces");

    if (!(_type == 'A' || _type == 'M')) 
        throw std::invalid_argument("Game type not supported");

    if (_snakes == _ladders) 
        throw std::invalid_argument("The game does not allow the same number of snakes and ladders"); 

    if (_snakes == 30)
        throw std::logic_error("The last tile cannot be a snake tile, it creates and impossible game");

    type = _type;
    turns = _turns;
    snakes = _snakes;
    ladders = _ladders;

    fill_tiles(true);

    dice = _dice;

    players[0] = _players[0];
    players[1] = _players[1];
}

void Game::fill_tiles(bool use_randomized) {
    for (int i { 1 }; i <= MAX_TILE_INDEX; i++) {
        if (i % snakes == 0) {
            use_randomized 
                ? tiles.push_back(new SnakeTile(i, dice.throw_dice())) 
                : tiles.push_back(new SnakeTile(i, 5));
        } else if (i % ladders == 0) {
            use_randomized 
                ? tiles.push_back(new LadderTile(i, dice.throw_dice())) 
                : tiles.push_back(new LadderTile(i, 5));
        } else { 
            tiles.push_back(new Tile(i));
        }
    }
}

void Game::start() {
    int turn { 1 };

    if (type == 'A') std::cout << "Game is set in automatic mode\n";
    else std::cout << "Game is set in manual mode\n";

    while (turns-- > 0) {
        std::cout << "==================\n";
        std::cout << "Current turn is: " << turn << "\n";

        int player_on_game { turn % 2 };

        if (type == 'M') {
            std::cout << players[player_on_game].get_name() 
                << " (Player "
                << player_on_game + 1 
                << ") please throw the dice\n";

            std::cout << "Type 't' to throw the dice\n";

            std::string player_input { "" };

            while (std::cin >> player_input) {
                if (player_input == "t") break;

                std::cout << "You did not throw the dice >:O\n";
            }
        }

        int dice_throw = dice.throw_dice();

        if (type == 'M') 
            std::cout << "Dice throw is " << dice_throw << "\n";

        players[player_on_game] += dice_throw;
        
        int tile_index { players[player_on_game].get_tile_index() };
        
        players[player_on_game] += tiles.at(tile_index - 1)->effect();

        if (players[player_on_game].won()) {
            std::cout << players[player_on_game].get_name() 
                << " (Player "
                << player_on_game + 1 
                << ") wins the game\n";

            break;
        }

        std::cout << player_on_game + 1 << " " << turn 
            << " " << tiles.at(tile_index - 1)->get_index()
            << " " << dice_throw
            << " " << tiles.at(tile_index - 1)->get_label()
            << " " << players[player_on_game].get_tile_index() << "\n";
        
        turn++;
    }

    if (!(players[0].won() || players[1].won()))
        std::cout << "Game ran out of turns\n";
}
