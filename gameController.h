#ifndef __GAMECONTROLLER_H__
#define __GAMECONTROLLER_H__

#include <string>
#include "game.h"
#include "view.h"

class GameController {
    Game player1;
    Game player2;
    Game *currPlayer;
    int currPlayerId;
    bool isSwitchOff;
    void switchPlayer();
    View v;
    public:
        GameController(int lvl, std::string iF1, std::string iF2);
        void startGame();
        void restartGame();
        void exitGame();
};

#endif