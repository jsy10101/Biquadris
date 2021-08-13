#include "jblock.h"

Jblock::Jblock(int id, int level) : 
    Block('J', id, std::vector<Posn>{{2, 0}, {3, 0}, {3, 1}, {3, 2}}, level)
    {}
