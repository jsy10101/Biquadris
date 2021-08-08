#include "cell.h"

Cell::Cell() :
    cId{-1}, cType{'.'} 
    {}

int Cell::getCId() const {
    return cId;
}

char Cell::getCType() const {
    return cType;
}

void Cell::setCell(int id, char type) {
    cId = id;
    cType = type;
}

std::ostream& operator<<(std::ostream& out, const Cell& c) {
    out << c.cType;
    return out;
}