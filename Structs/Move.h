#include <stdint.h>

#ifndef GUI_MOVE_H
#define GUI_MOVE_H


struct Move {
    uint8_t fromSquare;
    uint8_t toSquare;

    uint8_t moveFlag;

    Move(int fromSquare, int toSquare, uint8_t moveFlag = 0){
        this->fromSquare = fromSquare;
        this->toSquare = toSquare;
        this->moveFlag = moveFlag;
    };
};


#endif