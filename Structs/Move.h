#include <stdint.h>

#ifndef GUI_MOVE_H
#define GUI_MOVE_H

struct Move {
    uint8_t fromSquare;
    uint8_t toSquare;

    Move(int fromSquare, int toSquare){
        this->fromSquare = fromSquare;
        this->toSquare = toSquare;
    };
};


#endif