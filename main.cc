#include <iostream>
#include <vector>
#include <iomanip>
#include "posn.h"
#include <string>

int main(int args, char *argv[]) {

    
    int start_level = 0;
    bool graphic_switch = true;
    string inputfile1 = "sequence1.txt";
    string inputfile1 = "sequence2.txt";
    for(int i = 1; i < args; i++){
        string input = argv[i];
        if(input == "-text"){
            //since in this mode we donot need the graphics
            graphic_switch = false;
        }
        if(input == "-seed"){
            //we will use unsigned int since the random number generated should be greater than 0
            unsigned int seed_val;
            i++;
            string temp = argv[i];
            istringstream ss1{temp};
            ss1>>seed_val;
            srand(seed_val);
        }
        if(input == "-scriptfile1"){
            i++;
            string file_name = argv[i];
            inputfile1 = file_name;
        }
        if(input == "-scriptfile2"){
            i++;
            string file_name = argv[i];
            inputfile2 = file_name;
        }
        if(input == "-startlevel"){
            ++i;
            string level_input = argv[i];
            istringstream ss1{level_input};
            ss1>>start_level;
        }
    }

    std::vector<std::vector<Posn>> grid;
    for(int i = 0; i < 18; ++i) {
        std::vector<Posn> row;
        for(int j = 0; j < 11; ++j) {
            row.emplace_back(Posn(i, j));
        }
        grid.emplace_back(row);
    }

    std::vector<Posn> iblock{{0, 0}, {0, 1}, {0, 2}, {0, 3}};
    std::vector<Posn> jblock{{0, 0}, {1, 0}, {1, 1}, {1, 2}};
    std::vector<Posn> lblock{{0, 2}, {1, 0}, {1, 1}, {1, 2}};
    std::vector<Posn> sblock{{0, 1}, {0, 2}, {1, 0}, {1, 1}};
    std::vector<Posn> zblock{{0, 0}, {0, 1}, {1, 1}, {1, 2}};
    std::vector<Posn> tblock{{0, 0}, {0, 1}, {0, 2}, {1, 1}};

    for(int i = 0; i < 18; ++i) {
        for(int j = 0; j < 11; ++j) {
            bool found = false;
            for(int k = 0; k < iblock.size(); ++k) {
                if(iblock.at(k) == grid[i].at(j)) {
                    found = true;
                    break;
                }
            }
            if(found) {
                std::cout << std::setw(4) << "I" << std::setw(3) << " ";
            } else {
                std::cout << grid[i].at(j) <<  " ";
            }
        }
        std::cout << std::endl;
    } 
    std::cout << "grid completed \n\n";
    return 0;
}