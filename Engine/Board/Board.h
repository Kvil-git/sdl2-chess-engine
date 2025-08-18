#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>
#include "Move.h"

typedef uint64_t bitboard;
struct Board {
    bitboard PiecePositions[2][6]; //indexed with player count and piecetype
    bitboard emptyBitboard = 0;
    bitboard occupiedBitboard = 18446744073709551615;
    
    bool sideToMove = 1;
    uint8_t castlingRights = 0b11110000; //first two bits are white castling rights, the next two bits are black castling rights
    uint8_t enPassantSquare = 0;

    int halfMoveClock = 0; 

    void ApplyMove(const Move move);
    Board BoardAfterMoveApplication(const Move move);
};




#endif