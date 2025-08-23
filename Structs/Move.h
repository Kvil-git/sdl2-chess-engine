#ifndef GUI_MOVE_H
#define GUI_MOVE_H


#include <stdint.h>
#include "../Enums/MoveFlag.h"
#include "../Enums/PieceType.h"


struct Move {
    uint8_t fromSquare : 4;
    uint8_t toSquare : 4;
    uint8_t moveFlag : 4;
    uint8_t pieceType : 4;

    Move(int fromSquare, int toSquare, MoveFlag moveFlag = MoveFlag::SilentMove, PieceType pieceType = PieceType::Pawn){
        this->fromSquare = fromSquare;
        this->toSquare = toSquare;
        this->moveFlag = static_cast<int>(moveFlag);
        this->pieceType = static_cast<int>(pieceType);
    };
};


#endif