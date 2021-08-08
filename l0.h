#ifndef __L0_H__
#define __L0_H__

#include <iostream>

#include"level.h"

#include <vector>

#include <fstream>

using namespace std;


class l0 : public Level{
    public:
        l0(string filename);
        char block_create() override;
};

#endif
