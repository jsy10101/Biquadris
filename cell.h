#ifndef __CELL_H__
#define __CELL_H__

#include <iostream>

class Cell {
    int cId;
    int cLevelGen;
    char cType;
    public:
       Cell();
       int getCId() const;
       char getCType() const; 
       int getCLevel() const;
       void setCell(int id, int level, char type);
       void setDefault();
       friend std::ostream& operator<<(std::ostream& out, const Cell& c);
};

#endif