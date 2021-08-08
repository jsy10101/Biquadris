#include "board.h"

Board::Board() : 
    row{18}, col{11} {
    for(int i = 0; i < row; ++i) {
        std::vector<Cell> board_row;
        for(int j = 0; j < col; ++j) {
            board_row.emplace_back(Cell());
        }
        board.emplace_back(board_row);
    }
}

std::vector<std::vector<Cell>>& Board::getBoard() {
    return board;
}

std::ostream& operator<<(std::ostream& out, const Board& b) {
    for(int i = 0; i < b.row; ++i) {
        for(int j = 0; j < b.col; ++j) {
        //     bool found = false;
        //     for(int k = 0; k < b.getBlock().size(); ++k) {
        //         if(b.getBlock().at(k) == grid[i].at(j)) {
        //             found = true;
        //             break;
        //         }
        //     }
        //     if(found) {
        //         std::cout << std::setw(4) << b.getType() << std::setw(3) << " ";
        //     } else {
        //         std::cout << grid[i].at(j) <<  " ";
        //     }
        // }
        // std::cout << std::endl;
                std::cout << b.board.at(i).at(j);
            }
        std::cout << std::endl;
    } 
    std::cout << "grid completed \n\n";
}