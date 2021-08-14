#include "levZer.h"
#include <fstream>

LevZer::LevZer(std::string file) :
    Level{0, file}
    {}

char LevZer::blockCreate() {
    pos = (pos >= blockTypeList.size()) ? 0 : pos;
    ++pos;
    return blockTypeList[pos - 1];
}