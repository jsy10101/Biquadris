#include "board.h"

Board::Board() :
    row{18}, col{11}, blockCounter{0} {
    for(int i = 0; i < row; ++i) {
        std::vector<Cell> boardRow;
        for(int j = 0; j < col; ++j) {
            Cell c;
            boardRow.emplace_back(c);
        }
        board.emplace_back(boardRow);
    }
}

std::vector<std::vector<Cell>>& Board::getBoard() {
    return board;
}

bool Board::addBlock(Block &block){
    return true;
}

std::ostream& operator<<(std::ostream& out, const Board& b) {
    for(int i = 0; i < b.row; ++i) {
        for(int j = 0; j < b.col; ++j) {
                out << b.board.at(i).at(j);
            }
        out << std::endl;
    } 
    out << "grid completed \n\n";
    return out;
}