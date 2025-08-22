#ifndef GUI_MOVE_H
#define GUI_MOVE_H


#include <stdint.h>
#include "../Enums/MoveFlag.h"


struct Move {
    uint8_t fromSquare;
    uint8_t toSquare;

    uint8_t moveFlag;

    Move(int fromSquare, int toSquare, MoveFlag moveFlag = MoveFlag::SilentMove){
        this->fromSquare = fromSquare;
        this->toSquare = toSquare;
        this->moveFlag = static_cast<int>(moveFlag);
    };
};


#endif