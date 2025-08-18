#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H

#include "../../Structs/Move.h"
#include <vector>
#include "../Board/Board.h"
#include "../../Enums/PieceType.h"

class MoveGenerator {
    private:



    public:
        std::vector<Move> GenerateLegalMoves(const Board& board);

        std::vector<Move> GenerateCaptures(const Board& board);
        std::vector<Move> GenerateChecks(const Board& board, const PieceType piece);
        std::vector<Move> GeneratePieceMoves(const Board& board, const PieceType piece);
};


#endif