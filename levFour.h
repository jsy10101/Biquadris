#ifndef __LEVFOUR_H__
#define __LEVFOUR_H__

#include "level.h"
#include <string>
#include <vector>

class LevFour : public Level {
    std::vector<char> blockTypeList;
    std::string file;
    int pos;
    public:
        LevFour(std::string file);
        char blockCreate() override;
};

#endif
