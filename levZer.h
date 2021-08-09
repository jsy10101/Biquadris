#ifndef __LEVZER_H__
#define __LEVZER_H__

#include "level.h"
#include <string>
#include <vector>

class LevZer : public Level {
    std::vector<char> blockTypeList;
    std::string file;
    int pos;
    public:
        LevZer(std::string file);
        char blockCreate() override;
};

#endif
