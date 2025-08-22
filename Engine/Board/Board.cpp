#ifndef BOARD_CPP
#define BOARD_CPP



#include "Board.h"

void Board::ApplyMove(const Move move){
    int fromSquare = move.fromSquare;
    int toSquare = move.toSquare;
    MoveFlag flag = static_cast<MoveFlag>(move.moveFlag);

    bitboard fromSquareMask = ~((1ULL) << fromSquare);
    bitboard toSquareBit = 1ULL << toSquare;

    this->AllPieces &= fromSquareMask;
    for(int playerColor = 0; playerColor < 2; playerColor++){
        this->AllPiecesOfOneColor[playerColor] &= fromSquareMask;
        this->PiecePositions[playerColor][move.pieceType] &= fromSquareMask;
    }

    switch(flag){
        case MoveFlag::SilentMove:
            
            break;
    }
}

Board Board::BoardAfterMoveApplication(const Move move){

}





#endif