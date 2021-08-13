#ifndef __BOARD_H__
#define __BOARD_H__

#include "cell.h"
#include "block.h"
#include <vector>
#include <memory>

class Board {
    const int row;
    const int col;
    //int blockCounter;
    std::vector<std::vector<Cell>> board;
    public:
        Board();
        int getRow() const;
        int getCol() const;
        std::vector<std::vector<Cell>>& getBoard();
        void updateBoard(std::unique_ptr<Block>& blockPtr);
        friend std::ostream& operator<<(std::ostream& out, const Board& b);
};

#endif