#include "sblock.h"

Sblock::Sblock(int id, int level) : 
    Block('S', id, std::vector<Posn>{{2, 1}, {2, 2}, {3, 0}, {3, 1}}, level)
    {}