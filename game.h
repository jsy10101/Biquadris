#ifndef __GAME_H__
#define __GAME_H__

#include <string>
#include <memory>
#include <map>
#include "board.h"
#include "score.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "levZer.h"
#include "levOne.h"
#include "levTwo.h"
#include "levThree.h"
#include "levFour.h"

class Game {
    int level;
    int id;
    bool isGameFinished;
    Board b;
    std::string file;
    std::string noRandomFile;
    std::unique_ptr<Block> currBlock;
    std::unique_ptr<Block> nextBlock;
    std::unique_ptr<Level> levelPtr;
    std::unique_ptr<Score> score;
    std::map<int, int> blockMap;
    public: 
        Game(std::string file, int level);
        Board& getBoardObject();
        Score& getScoreObj();
        int getPlayerScore() const;
        int getHighScore() const;
        int getLevel() const;
        void setNoRandomFile(std::string noRandomFile);
        Block* getNextBlock();
        void setDefCellState();
        bool isShiftable(int y, int x);
        void shiftBlock(int y, int x, int nIterations);
        void setLevel(std::unique_ptr<Level>& levelPtr);
        void changePlayerLevel(int levCntr, int nIterations);
        void genBlock(std::unique_ptr<Block>& blockPtr, bool isNext);
        void dropBlock(int nIterations);
        void changeCurrBlock(std::string bType);
        void deleteRow(int bottomRow);
        void rotateBlock(int times);
};

#endif