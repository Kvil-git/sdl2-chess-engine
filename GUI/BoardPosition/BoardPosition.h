#include <iostream>
#include <stdint.h>

struct BoardPosition{
    enum PieceTypes{
        WhitePawn = 1,
        WgiteKnight = 2,
        WhiteBishop = 3,
        WhiteRook = 4,
        WhiteQueen = 5,
        WhiteKing = 6,

        BlackPawn = 7,
        BlackKnight = 8,
        BlackBishop = 9,
        BlackRook = 10,
        BlackQueen = 11,
        BlackKing = 12
    };

    uint8_t Pieces[64];
};