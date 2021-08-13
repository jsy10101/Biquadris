#ifndef __LEVFOUR_H__
#define __LEVFOUR_H__

#include "level.h"
#include <string>

class LevFour : public Level {
    std::string file;
    public:
        LevFour(std::string file);
        char blockCreate() override;
};

#endif
