#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Level{
    string filename;
    int pos = 0;
    vector<char> type;
public:
    int current_level;
    virtual char block_create() = 0;
    Level(int current_level, string filename = "");
    virtual ~Level();
    void read_file();

};


#endif