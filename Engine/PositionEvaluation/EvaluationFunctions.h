#ifndef POSITION_EVAL_FUNCTIONS
#define POSITION_EVAL_FUNCTIONS


#include <vector>
#include <bitset>
#include <iostream>

#include "../../Enums/PlayerColors.h"
#include "../Board/Board.h"
#include "../../Enums/PieceType.h"


int MaterialCount(const Board& board, const bool playerColor){
    const float PieceCosts[6] = {
        [BoardArrayPieceIndex::Pawn] = 1.0f,
        [BoardArrayPieceIndex::Knight] = 3.0f,
        [BoardArrayPieceIndex::Bishop] = 3.0f,
        [BoardArrayPieceIndex::Rook] = 4.9f,
        [BoardArrayPieceIndex::Queen] = 8.0f,
        [BoardArrayPieceIndex::King] = 200.0f
    };
    int totalMaterial = 0;
    for(int pieceType = 0; pieceType < 6; pieceType++){
        totalMaterial += std::bitset<64>(board.PiecePositions[playerColor][pieceType]).count();
    }
    return totalMaterial;
}

int PieceActivityBonuses(const Board& board, const bool playerColor){
    return 0;
}

int EvaluatePosition(const Board& board) {
    int playerEvaluations[2] = {0};
    for(int playerColor=0; playerColor<2; playerColor++){
        playerEvaluations[playerColor] += MaterialCount(board, playerColor);
        playerEvaluations[playerColor] += PieceActivityBonuses(board, playerColor);
    }

    return playerEvaluations[PlayerColor::White] - playerEvaluations[PlayerColor::Black];
}



#endif