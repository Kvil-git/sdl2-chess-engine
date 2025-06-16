#include <stack>
#include <string>
#include "../Move/Move.h"
#include "../Enums/GameResults.h"
#include "../Enums/PlayerColors.h"

#ifndef GUI_GAME_H
#define GUI_GAME_H


class Game {
    private:
        std::stack<Move> MoveList;
        std::string currentFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

        bool sideToMove;
        PlayerColors playerColor;

        int ClockTime;
        int ClockIncrement;

        bool IsGameOnTime;

        void UpdateCurrentFEN();
        

        
    public:
        GameResults gameResult = GameStillGoing;


        
        Game(std::string startingFEN, int clockTime, int clockIncrement, PlayerColors playerColor);
        Game(int clockTime, int clockIncrement, PlayerColors playerColor);
        Game(PlayerColors playerColor);

        void MakeMove(Move);
        void UndoLastMove();

        bool IsGameOver();
        void AskCurrentPlayerToMove();
        
        std::string GetGamePGN();
        std::string GetCurrentPosition();
        std::string GetCurrentFEN();
};



#endif