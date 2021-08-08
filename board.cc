#include "board.h"

<<<<<<< HEAD
Board::Board() :
=======
Board::Board() : 
>>>>>>> d06818604b3e8a7d8d853f5c01a4066a9675acc7
    row{18}, col{11}, blockCounter{0} {
    for(int i = 0; i < row; ++i) {
        std::vector<Cell> boardRow;
        for(int j = 0; j < col; ++j) {
<<<<<<< HEAD
            Cell c;
            boardRow.emplace_back(c);
=======
            boardRow.emplace_back(Cell());
>>>>>>> d06818604b3e8a7d8d853f5c01a4066a9675acc7
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
<<<<<<< HEAD
                out << b.board.at(i).at(j);
=======
                out << *(b.board.at(i).at(j));
>>>>>>> d06818604b3e8a7d8d853f5c01a4066a9675acc7
            }
        out << std::endl;
    } 
    out << "grid completed \n\n";
    return out;
}