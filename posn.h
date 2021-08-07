#ifndef _POSN_H_
#define _POSN_H_
#include <iostream>

class Posn {
    int x = 0;
    int y = 0;
    public:
        Posn(int sx, int sy);
        void setPosn(int sx, int sy);
        int getX() const;
        int getY() const;
};

std::ostream& operator<<(std::ostream& out, const Posn& p);
bool operator==(const Posn& p1, const Posn& p2);

#endif