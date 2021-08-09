#include "block.h"

Block::Block(char bType, int id, std::vector<Posn> block) :
    bType{bType}, bId{id}, block{block}
    {}

char Block::getType() const {
    return bType;
}

int Block::getBId() const {
    return bId;
}

std::vector<Posn>& Block::getBlock() {
    return block;
}

//bool Block::isRotatable(std::vector<std::vector<Posn>>& grid, int x) {
//}

// I block
// {{3, 0}, {3, 1}, {3, 2}, {3, 3}}
// clockwise rotation
// {{3, 0}, {2, 0}, {1, 0}, {0, 0}}

// J block
// {{2, 0}, {3, 0}, {3, 1}, {3, 2}}
// clockwise rotation
// {{3, 0}, {2, 0}, {1, 0}, {0, 0}}


// Algorithm for checking rotation
// x:
//      pos -> clockwise
//      neg -> counter clockwise

// if x > 0
//      if block.right + 
// if block.left < grid.left
//      return false
// if block.right > grid.right
//      return false