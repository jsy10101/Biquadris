#include "tblock.h"

Tblock::Tblock(int id) : 
    Block('T', id, std::vector<Posn>{{2, 0}, {2, 1}, {2, 2}, {3, 1}})
    {}