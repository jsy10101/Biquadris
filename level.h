#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Level{
protected:
    string file;
    int pos = 0;
    vector<char> type;
public:
    int current_level;
    virtual char blockCreate() = 0;
    virtual void updateCount(int c);
    virtual int getCount();
    Level(int current_level, string file = "");
    virtual ~Level();
    void read_file();
   
};


#endif