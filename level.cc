#include "level.h"
#include <fstream>

Level::Level(int currLevel, std::string file) : 
    currLevel{currLevel}, file{file} {
        std::ifstream infile{file};
        char blockType{' '};
        while(true) {
            if(infile >> blockType) {
                blockTypeList.emplace_back(blockType);
            } else {
                break;
            }
        }
    }

int Level::pos = 0;

Level::~Level() {}

int Level::getCurLevl() const {
    return currLevel;
}