#ifndef __LEVONE_H__
#define __LEVONE_H__

#include "level.h"
#include <string>
#include <vector>

class LevOne : public Level {
    std::vector<char> blockTypeList;
    std::string file;
    int pos;
    public:
        LevOne(std::string file);
        char blockCreate() override;
};

#endif
