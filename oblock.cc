#include "oblock.h"

Oblock::Oblock(int id) : 
    Block('O', id, std::vector<Posn>{{2, 0}, {2, 1}, {3, 0}, {3, 1}})
    {}