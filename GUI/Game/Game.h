#include <stack>
#include <string>
#include "../Move/Move.h"

class Game {
    private:
        std::stack<Move> MoveList;
        std::string startingFEN;

        bool sideToMove;
        bool sideOfThePlayer;

        int ClockTime;
        int ClockIncrement;

        bool IsGameOnTime;




    public:
        int GameResult;

        void MakeMove(Move);
        void UndoLastMove();
        bool IsGameOver();

        void AskCurrentPlayerToMove();
        
        std::string GetGamePGN();
        std::string GetCurrentPosition();
};


