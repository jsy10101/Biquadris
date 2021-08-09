#include "gameController.h"
#include <memory>

GameController::GameController(int lvl, std::string iF1, std::string iF2) : 
    player1{Game(iF1, lvl)}, player2{Game(iF2, lvl)}, v{View()}
    {}

void GameController::startGame() {
    v.textDisplay(player1, player2);
}