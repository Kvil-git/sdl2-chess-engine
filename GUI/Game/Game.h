#include <stack>
#include <string>
#include "../Move/Move.h"

class Game {
    private:
        enum GameResults{
            GameStillGoing = -1,
            WhiteWin = 1,
            BlackWin = 0,
            Draw = 2
        };

        std::stack<Move> MoveList;
        std::string startingFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

        bool sideToMove;
        bool sideOfThePlayer;

        int ClockTime;
        int ClockIncrement;

        bool IsGameOnTime;

        int gameResult = GameStillGoing;

    public:
        enum PlayerColors{
            White = 1,
            Black = 0,
        };
        
        Game(std::string startingFEN, int clockTime, int clockIncrement, bool playerColor);
        Game(int clockTime, int clockIncrement, bool playerColor);
        Game(bool playerColor);

        int GameResult;

        void MakeMove(Move);
        void UndoLastMove();
        bool IsGameOver();

        void AskCurrentPlayerToMove();
        
        std::string GetGamePGN();
        std::string GetCurrentPosition();
};


