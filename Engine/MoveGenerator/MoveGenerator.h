#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H

#include "../../Structs/Move.h"
#include <vector>
#include "../Board/Board.h"
#include "../../Enums/PieceType.h"

class MoveGenerator {
    private:        

        static std::vector<bitboard> RookMoves[64];
        static std::vector<bitboard> BishopMoves[64];
        
        static bitboard RookMasks[64];
        static bitboard BishopMasks[64];

        bitboard GetRookMoves(int sq, bitboard occupancy);
        bitboard GetBishopMoves(int sq, bitboard occupancy);

        static bitboard KnightMoves[64];

        static bitboard KingMoves[64];

        static bitboard PawnMoves[2][64];
        static bitboard PawnCaptures[2][64];

        static bool initialized;





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