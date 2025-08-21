#include "../Enums/PieceType.h"

#ifndef FEN_FUNCTIONS_H
#define FEN_FUNCTIONS_H

ChessPiece PieceByFEN(char pieceFEN){
    switch(pieceFEN){
        case 'P': return ChessPiece::WhitePawn;
        case 'N': return ChessPiece::WhiteKnight;
        case 'B': return ChessPiece::WhiteBishop;
        case 'R': return ChessPiece::WhiteRook;
        case 'Q': return ChessPiece::WhiteQueen;
        case 'K': return ChessPiece::WhiteKing;

        case 'p': return ChessPiece::BlackPawn;
        case 'n': return ChessPiece::BlackKnight;
        case 'b': return ChessPiece::BlackBishop;
        case 'r': return ChessPiece::BlackRook;
        case 'q': return ChessPiece::BlackQueen;
        case 'k': return ChessPiece::BlackKing;
        
        default:  return ChessPiece::NONE;
    }
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