#include "cell.h"

Cell::Cell() :
    cId{-1}, cLevelGen{-1}, cType{'.'}   
    {}

int Cell::getCId() const {
    return cId;
}

char Cell::getCType() const {
    return cType;
}

int Cell::getCLevel() const {
    return cLevelGen;
}

void Cell::setCell(int id, int level, char type) {
    cId = id;
    cLevelGen = level;
    cType = type;
}

void Cell::setDefault() {
    cId = -1;
    cLevelGen = -1;
    cType = '.';
}

std::ostream& operator<<(std::ostream& out, const Cell& c) {
    out << c.cType << " ";
    return out;
}