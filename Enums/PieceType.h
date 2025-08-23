#ifndef ENUMS_PIECETYPE
#define ENUMS_PIECETYPE

#include <iostream>

enum class ChessPiece {
    WhitePawn = 0,
    WhiteKnight = 1,
    WhiteBishop = 2,
    WhiteRook = 3,
    WhiteQueen = 4,
    WhiteKing = 5,

    BlackPawn = 6,
    BlackKnight = 7,
    BlackBishop = 8,
    BlackRook = 9,
    BlackQueen = 10,
    BlackKing = 11,
    NONE = 12,  
};

enum class PieceType {
    Pawn = 0,
    Knight = 1,
    Bishop = 2,
    Rook = 3,
    Queen = 4,
    King = 5
};



inline std::ostream& operator<<(std::ostream& out, const ChessPiece piece) {
    switch(piece) {
        case ChessPiece::WhitePawn:   out << "WhitePawn"; break;
        case ChessPiece::WhiteKnight: out << "WhiteKnight"; break;
        case ChessPiece::WhiteBishop: out << "WhiteBishop"; break;
        case ChessPiece::WhiteRook:   out << "WhiteRook"; break;
        case ChessPiece::WhiteQueen:  out << "WhiteQueen"; break;
        case ChessPiece::WhiteKing:   out << "WhiteKing"; break;
        case ChessPiece::BlackPawn:   out << "BlackPawn"; break;
        case ChessPiece::BlackKnight: out << "BlackKnight"; break;
        case ChessPiece::BlackBishop: out << "BlackBishop"; break;
        case ChessPiece::BlackRook:   out << "BlackRook"; break;
        case ChessPiece::BlackQueen:  out << "BlackQueen"; break;
        case ChessPiece::BlackKing:   out << "BlackKing"; break;
        case ChessPiece::NONE:        out << "NONE"; break;
    }
    return out;
}

inline std::ostream& operator<<(std::ostream& out, const PieceType type) {
    switch(type) {
        case PieceType::Pawn:   out << "Pawn"; break;
        case PieceType::Knight: out << "Knight"; break;
        case PieceType::Bishop: out << "Bishop"; break;
        case PieceType::Rook:   out << "Rook"; break;
        case PieceType::Queen:  out << "Queen"; break;
        case PieceType::King:   out << "King"; break;
    }
    return out;
}



#endif