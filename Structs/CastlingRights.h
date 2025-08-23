#ifndef CASTLING_RIGHTS_H
#define CASTLING_RIGHTS_H

#include <stdint.h>
#include <array>



struct CastlingRights {
    bool WhiteShortCastling : 1;
    bool WhiteLongCastling : 1;
    bool BlackShortCastling : 1;
    bool BlackLongCastling : 1;
    CastlingRights(){
        WhiteLongCastling = 1;
        WhiteShortCastling = 1;
        BlackLongCastling = 1;
        BlackShortCastling = 1;
    }
};







#endif