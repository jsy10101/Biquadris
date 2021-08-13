#ifndef __LEVTWO_H__
#define __LEVTWO_H__

#include "level.h"

class LevTwo : public Level {
    public:
        LevTwo();
        char blockCreate() override;
};

#endif
