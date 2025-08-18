#include <stack>
#include <string>
#include "../../Structs/Move.h"
#include "../../Enums/GameResult.h"
#include "../../Enums/PlayerColor.h"

#ifndef GUI_GAME_H
#define GUI_GAME_H


class Game {
    private:
        std::stack<Move> MoveList;
        std::string currentFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

        bool sideToMove = PlayerColor::White;
        const PlayerColor playerColor = PlayerColor::White;

        int ClockTime;
        int ClockIncrement;

        bool IsGameOnTime;

        void UpdateCurrentFEN();
        

        
    public:
        GameStatus gameStatus = GameStatus::GameStillGoing;
        
        Game(std::string startingFEN, int clockTime, int clockIncrement, const PlayerColor playerColor) : playerColor(playerColor) {};
        Game(int clockTime, int clockIncrement, const PlayerColor playerColor) : playerColor(playerColor) {};
        Game(const PlayerColor playerColor) : playerColor(playerColor) {};
        Game() = default;

        void MakeMove(Move);
        void UndoLastMove();

        bool IsGameOver();
        void AskCurrentPlayerToMove();
        
        std::string GetGamePGN();
        std::string GetCurrentPosition();
        std::string GetCurrentFEN();
};



#endif