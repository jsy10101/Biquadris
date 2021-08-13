#include "levThree.h"
#include <fstream>

LevThree::LevThree(std::string file) :
    Level{0}, pos{0} {
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

char LevThree::blockCreate() {
    pos = (pos == blockTypeList.size()) ? 0 : pos;
    ++pos;
    return blockTypeList[pos - 1];
}