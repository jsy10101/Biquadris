#include "level.h"
#include <fstream>
#include <iostream>

Level::Level(int currLevel, std::string file) : 
    currLevel{currLevel}, pos{0} {
        while(true) {
            if(file != "") {
                std::ifstream infile{file};
                if( file != "" && !infile.fail() ) {
                    this->file = file;
                    char blockType{' '};
                    while(true) {
                        if(infile >> blockType) {
                            blockTypeList.emplace_back(blockType);
                        } else {
                            break;
                        }
                    }
                    break;
                } else {
                    std::cout << "Wrong file name, enter a valid file: ";
                    std::cin >> file;  
                }
            } else {
                break;
            }
        }
    }

Level::~Level() {}

int Level::getCurLevl() const {
    return currLevel;
}