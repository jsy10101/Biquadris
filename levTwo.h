#ifndef __LEVTWO_H__
#define __LEVTWO_H__

#include"level.h"

using namespace std;

class LevTwo : public Level{
    public: 
        LevTwo();
        char blockCreate() override;
};

#endif