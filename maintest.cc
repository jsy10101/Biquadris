#include <iostream>
#include <vector>
#include <iomanip>
#include "posn.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "board.h"

//template <typename T>
// void display(std::vector<std::vector<Posn>>& grid, T b) {
//     for(int i = 0; i < 18; ++i) {
//         for(int j = 0; j < 11; ++j) {
//             bool found = false;
//             for(int k = 0; k < b.getBlock().size(); ++k) {
//                 if(b.getBlock().at(k) == grid[i].at(j)) {
//                     found = true;
//                     break;
//                 }
//             }
//             if(found) {
//                 std::cout << std::setw(4) << b.getType() << std::setw(3) << " ";
//             } else {
//                 std::cout << grid[i].at(j) <<  " ";
//             }
//         }
//         std::cout << std::endl;
//     } 
//     std::cout << "grid completed \n\n";
    
// }

int main() {
<<<<<<< HEAD
    // std::vector<std::vector<Posn>> grid;
    // for(int i = 0; i < 18; ++i) {
    //     std::vector<Posn> row;
    //     for(int j = 0; j < 11; ++j) {
    //         row.emplace_back(i, j);
    //     }
    //     grid.emplace_back(row);
    // }
    
    // Iblock iblock;
    // Jblock jblock;
    // Lblock lblock;
    // Oblock oblock;
    // Sblock sblock;
    // Tblock tblock;
    // Zblock zblock;
=======
    std::vector<std::vector<Posn>> grid;
    for(int i = 0; i < 18; ++i) {
        std::vector<Posn> row;
        for(int j = 0; j < 11; ++j) {
            row.emplace_back(i, j);
        }
        grid.emplace_back(row);
    }
    
    Iblock iblock;
    Jblock jblock;
    Lblock lblock;
    Oblock oblock;
    Sblock sblock;
    Tblock tblock;
    Zblock zblock;
>>>>>>> d06818604b3e8a7d8d853f5c01a4066a9675acc7

    // display(grid, iblock);
    // display(grid, jblock);
    // display(grid, lblock);
    // display(grid, oblock);
    // display(grid, sblock);
    // display(grid, tblock);
    // display(grid, zblock);
    
    // std::cout << std::endl;

    Board b;
    std::cout << b;
<<<<<<< HEAD
   //std::cout << c.getCId() << std::endl;
   //std::cout << c.getCType() << std::endl;
=======
>>>>>>> d06818604b3e8a7d8d853f5c01a4066a9675acc7
    return 0;
}