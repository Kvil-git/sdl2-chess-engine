#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>
#include "Move.h"

typedef uint64_t bitboard;
struct Board {
    bitboard PiecePositions[2][6]; //indexed with player color and piecetype

    bitboard AllPiecesOfOneColor[2];
    bitboard AllPieces;

    bool sideToMove = 1;
    bool castlingRights[2][2] = { {0} };
    uint8_t enPassantSquare = 0;

    int halfMoveClock = 0; 

    void ApplyMove(const Move move);
    Board BoardAfterMoveApplication(const Move move);
};




#endif