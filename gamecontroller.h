#ifndef __GAMECONTROLLER_H__
#define __GAMECONTROLLER_H__

#include <string>
#include "game.h"
#include "view.h"

class GameController {
    Game player1;
    Game player2;
    View v;
    public:
        GameController(int lvl, std::string iF1, std::string iF2);
        void startGame();
};

#endif