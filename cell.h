#ifndef __CELL_H__
#define __CELL_H__

#include <iostream>

class Cell {
    int cId;
    char cType;
    public:
       Cell();
       void setCell(int id, char type);
       int getCId() const;
       char getCType() const; 
       friend std::ostream& operator<<(std::ostream& out, const Cell& c);
};

#endif