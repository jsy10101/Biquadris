#ifndef __LEVTHREE_H__
#define __LEVTHREE_H__

#include "level.h"
#include <string>
#include <vector>

class LevThree : public Level {
    std::vector<char> blockTypeList;
    std::string file;
    int pos;
    public:
        LevThree(std::string file);
        char blockCreate() override;
};

#endif
