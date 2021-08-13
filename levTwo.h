#ifndef __LEVTWO_H__
#define __LEVTWO_H__

#include "level.h"
#include <string>
#include <vector>

class LevTwo : public Level {
    std::vector<char> blockTypeList;
    std::string file;
    int pos;
    public:
        LevTwo(std::string file);
        char blockCreate() override;
};

#endif
