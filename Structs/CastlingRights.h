#ifndef CASTLING_RIGHTS_H
#define CASTLING_RIGHTS_H

#include <stdint.h>
#include <array>



struct CastlingRights {
    uint16_t WhiteShortCastling : 1 = 1;
    uint16_t WhiteLongCastling : 1 = 1;
    uint16_t BlackShortCastling : 1 = 1;
    uint16_t BlackLongCastling : 1 = 1;
};







#endif