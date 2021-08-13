#include "lblock.h"

Lblock::Lblock(int id, int level) : 
    Block('L', id, std::vector<Posn>{{2, 2}, {3, 0}, {3, 1}, {3, 2}}, level)
    {}