#include "jblock.h"

Jblock::Jblock(int id) : 
    Block('J', id, std::vector<Posn>{{2, 0}, {3, 0}, {3, 1}, {3, 2}})
    {}
