#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "posn.h"
#include <vector>

class Block {
    char bType;
    int bId;
    std::vector<Posn> block; 
    int bLevelGen;
    public:
        Block(char bType, int bId, std::vector<Posn> block, int level);
        char getBType() const;
        int getBId() const;
        int getBLevel() const;
        std::vector<Posn>& getBlock();
        void updateBlock(int y, int x);
        void rotateBlock(int times);
};

#endif