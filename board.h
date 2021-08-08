#ifndef __BOARD_H__
#define __BOARD_H__

#include "cell.h"
#include "block.h"
#include <vector>

class Board {
    const int row;
    const int col;
    int blockCounter;

    std::vector<std::vector<Cell>> board;
    
    public:
        Board();
        std::vector<std::vector<Cell>>& getBoard();
        bool addBlock(Block& block);
        friend std::ostream& operator<<(std::ostream& out, const Board& b);
};

#endif