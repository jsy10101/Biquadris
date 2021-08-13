#include "zblock.h"

Zblock::Zblock(int id, int level) : 
    Block('Z', id, std::vector<Posn>{{2, 0}, {2, 1}, {3, 1}, {3, 2}}, level)
    {}