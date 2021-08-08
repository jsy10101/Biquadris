#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "posn.h"
#include <vector>

class Block {
    char b_type;
    int block_counter;
    std::vector<Posn> block; 
    public:
        Block(char b_type, std::vector<Posn> block);
        char getType() const;
        std::vector<Posn>& getBlock();
        bool isRotatable(std::vector<std::vector<Posn>>& grid, int x);
        void shift(int x);
        void rotate_clock(int n);
        void rotate_anti(int n);
};

#endif