#ifndef __GAME_H__
#define __GAME_H__

#include <string>
#include "board.h"
#include "block.h"

class Game {
    int level;
    std::string file;
    Board& b;

};

#endif