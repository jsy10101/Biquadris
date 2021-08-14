#include "board.h"
#include <iomanip>

Board::Board() :
    row{18}, col{11}/*, blockCounter{0}*/ {
    for(int i = 0; i < row; ++i) {
        std::vector<Cell> boardRow;
        for(int j = 0; j < col; ++j) {
            Cell c;
            boardRow.emplace_back(c);
        }
        board.emplace_back(boardRow);
    }
}

int Board::getRow() const {
    return row;
}

int Board::getCol() const {
    return col;
}

std::vector<std::vector<Cell>>& Board::getBoard() {
    return board;
}

void Board::updateBoard(std::unique_ptr<Block>& blockPtr) {
    for(int i = 0; i < blockPtr->getBlock().size(); ++i) {
        if(board.at(blockPtr->getBlock().at(i).getY())
                .at(blockPtr->getBlock().at(i).getX())
                .getCType() == '.') {
           board.at(blockPtr->getBlock().at(i).getY())
                .at(blockPtr->getBlock().at(i).getX())
                .setCell( blockPtr->getBId(), 
                          blockPtr->getBLevel(),
                          blockPtr->getBType() ); 
        }
    }
}

void Board::resetBoard() {
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            board.at(i).at(j).setDefault();
        }
    }
}

// Delete later, no longer needed
std::ostream& operator<<(std::ostream& out, const Board& b) {
    for(int i = 0; i < b.row; ++i) {
        for(int j = 0; j < b.col; ++j) {
            out << b.board.at(i).at(j);
        }
    } 
    return out;
}