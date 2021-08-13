#include "iblock.h"

Iblock::Iblock(int id, int level) : 
    Block('I', id, std::vector<Posn>{{3, 0}, {3, 1}, {3, 2}, {3, 3}}, level)
    {}