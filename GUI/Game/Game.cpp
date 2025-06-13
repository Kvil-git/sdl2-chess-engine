#include "Game.h"

void Game::AskCurrentPlayerToMove(){
    return;
}


bool Game::IsGameOver(){
    return false;
}



Game::Game(bool playerColor){
    this->IsGameOnTime = false;
    this->ClockIncrement = 0;
    this->playerColor = playerColor;

}


Game::Game(std::string startingFEN, int clockTime, int clockIncrement, bool playerColor){
    this->IsGameOnTime = true;
    this->ClockIncrement = clockIncrement;
    this->ClockTime = clockTime;
    this->playerColor = playerColor;
    this->currentFEN = startingFEN;
}

Game::Game(int clockTime, int clockIncrement, bool playerColor){
    this->IsGameOnTime = true;
    this->ClockIncrement = clockIncrement;
    this->ClockTime = clockTime;
    this->playerColor = playerColor;
}


std::string Game::GetCurrentFEN(){
    return this->currentFEN;
}
