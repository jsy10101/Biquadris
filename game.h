#ifndef __GAME_H__
#define __GAME_H__

#include <string>
#include <memory>
#include "board.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "levZer.h"

class Game {
    int level;
    int id;
    Board b;
    std::string file;
    std::unique_ptr<Block> currBlock;
    std::unique_ptr<Block> nextBlock;
    std::unique_ptr<Level> levelPtr;
    int score = 0;          // Remove later
    public: 
        Game(std::string file, int level);
        Board& getBoardObject();
        int getLevel() const;
        int getScore() const;
        Block* getNextBlock();
        void setLevel(std::unique_ptr<Level>& levelPtr);
        void genBlock(std::unique_ptr<Block>& blockPtr, bool isNext); 
};

#endif