#ifndef DICE_H
#define DICE_H

class Dice {
    private:
        int faces;
    public:
        Dice();
        Dice(int);

        int throw_dice();
        int get_faces();
};

#endif
