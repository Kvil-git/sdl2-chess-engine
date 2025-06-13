#include <stack>
#include <string>
#include "../Move/Move.h"

class Game {
    private:
        std::stack<Move> MoveList;
        std::string currentFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

        bool sideToMove;
        bool playerColor;

        int ClockTime;
        int ClockIncrement;

        bool IsGameOnTime;

        void UpdateCurrentFEN();
        
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
        
        enum GameResults{
            GameStillGoing = -1,
            WhiteWin = 1,
            BlackWin = 0,
            Draw = 2
        };
        
        int gameResult = GameStillGoing;

        bool IsGameOver();
        void AskCurrentPlayerToMove();
        
        std::string GetGamePGN();
        std::string GetCurrentPosition();
        std::string GetCurrentFEN();
};


