#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"

class Lblock : public Block {
    public:
        Lblock(int id, int level);
};

#endif