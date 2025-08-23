#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H

#include "../../Structs/Move.h"
#include <vector>
#include "../Board/Board.h"
#include "../../Enums/PieceType.h"

class MoveGenerator {
    private:        

        std::vector<bitboard> RookMoves[64];
        std::vector<bitboard> BishopMoves[64];
        
        bitboard RookMasks[64];
        bitboard BishopMasks[64];

        bitboard GetRookMoves(int sq, bitboard occupancy);
        bitboard GetBishopMoves(int sq, bitboard occupancy);




        bitboard KnightMoves[64];

        bitboard KingMoves[64];

        bitboard PawnMoves[2][64];
        bitboard PawnCaptures[2][64];

        void InitSliderMoveTables();
        void InitSliderPieceMasks();
        void InitKnightArrays();
        void InitKingArrays();
        void InitPawnArrays();


    public:
        MoveGenerator();
        void FillPieceMoveArrays(const Board& board, bool sideToMove, const PieceType piece, std::vector<Move> &silentMoves, std::vector<Move> &captures);
        std::vector<Move> GenerateCastlingMoves(const Board& board, bool sideToMove);
};


#endif