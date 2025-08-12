#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

typedef uint64_t bitboard;
struct Board {
    bitboard PiecePositions[12];
    bitboard emptyBitboard = 0;
    bitboard occupiedBitboard = 18446744073709551615;

};




#endif