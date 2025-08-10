#include "Game.h"
#include "../../Enums/GameResults.h"
#include "../../Enums/PlayerColors.h"

void Game::AskCurrentPlayerToMove(){
    return;
}


bool Game::IsGameOver(){
    if(this->gameResult == GameResults::GameStillGoing) return false;
    return true;
}



Game::Game(PlayerColors playerColor){
    this->IsGameOnTime = false;
    this->ClockIncrement = 0;
    this->playerColor = playerColor;

}


Game::Game(std::string startingFEN, int clockTime, int clockIncrement, PlayerColors playerColor){
    this->IsGameOnTime = true;
    this->ClockIncrement = clockIncrement;
    this->ClockTime = clockTime;
    this->playerColor = playerColor;
    this->currentFEN = startingFEN;
}

Game::Game(int clockTime, int clockIncrement, PlayerColors playerColor){
    this->IsGameOnTime = true;
    this->ClockIncrement = clockIncrement;
    this->ClockTime = clockTime;
    this->playerColor = playerColor;
}


std::string Game::GetCurrentFEN(){
    return this->currentFEN;
}

