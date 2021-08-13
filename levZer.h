#ifndef __LEVZER_H__
#define __LEVZER_H__

#include "level.h"
#include <string>

class LevZer : public Level {
    public:
        LevZer(std::string file);
        char blockCreate() override;
};

#endif
