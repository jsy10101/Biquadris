#include "lblock.h"

Lblock::Lblock(int id) : 
    Block('L', id, std::vector<Posn>{{2, 2}, {3, 0}, {3, 1}, {3, 2}})
    {}