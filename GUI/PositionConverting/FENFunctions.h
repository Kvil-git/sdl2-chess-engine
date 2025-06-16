#include "../Enums/PieceTypes.h"
#ifndef FEN_FUNCTIONS_H
#define FEN_FUNCTIONS_H

int PieceIdByFEN(char pieceFEN){
    switch(pieceFEN){
        case 'P': return WhitePawn;
        case 'N': return WhiteKnight;
        case 'B': return WhiteBishop;
        case 'R': return WhiteRook;
        case 'Q': return WhiteQueen;
        case 'K': return WhiteKing;

        case 'p': return BlackPawn;
        case 'n': return BlackKnight;
        case 'b': return BlackBishop;
        case 'r': return BlackRook;
        case 'q': return BlackQueen;
        case 'k': return BlackKing;
    }
    return -1;
}

inline char FENCharByPieceId(int pieceId){
    char fenCharsByPieceId[12] = {
        'P', 'N', 'B', 'R', 'Q', 'K',
        'p', 'n', 'b', 'r', 'q', 'k',
    };

    if(pieceId >= 0 and pieceId <= 11) return fenCharsByPieceId[pieceId];
    return 'Z';
}

bool IsCharacterADigit(char characterToTest){
    if(characterToTest >= int('0') and characterToTest <= int('9')) return true;
    return false;
}

int CharacterToDigit(char characterToConvert){
    return (int(characterToConvert) - int('0'));
}

int DigitToCharacter(int digitToConvert){
    if(digitToConvert < 0) return 'Z';
    if(digitToConvert > 9) return 'Z';
    return char(int('0') + digitToConvert);
}

#endif