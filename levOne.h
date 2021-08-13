#ifndef __LEVONE_H__
#define __LEVONE_H__

#include "level.h"

class LevOne : public Level {
    public:
        LevOne();
        char blockCreate() override;
};

#endif
