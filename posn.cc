#include "posn.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Posn::Posn(int sy, int sx) : y{sy}, x{sx} {}

int Posn::getX() const {
    return x;
}

int Posn::getY() const {
    return y;
}

std::ostream& operator<<(std::ostream& out, const Posn& p) {
    out << std::setw(6);
    std::ostringstream os;
    os << "(" << p.getY() << "," << p.getX() << ")";  
    out << std::setw(6) << os.str();
    return out;
}

bool operator==(const Posn& p1, const Posn& p2) {
    return p1.getX() == p2.getX() && p1.getY() == p2.getY();
}