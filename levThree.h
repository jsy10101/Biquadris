#ifndef __LEVTHREE_H__
#define __LEVTHREE_H__

#include "level.h"
#include <string>

class LevThree : public Level {
    std::string file;
    public:
        LevThree(std::string file);
        char blockCreate() override;
};

#endif
