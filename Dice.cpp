#include <random>
#include <stdexcept>

#include "Dice.h"

Dice::Dice() {
    faces = 6;
}

Dice::Dice(int _faces) {
    if (faces <= 4) 
        throw std::invalid_argument("Dice cannot have less than 4 faces");

    faces = _faces;
}

int Dice::throw_dice() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, faces);

    return dist(gen);
}

int Dice::get_faces() {
    return faces;
}
