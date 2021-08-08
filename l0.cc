#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "l0.h"

using namespace std;

l0::l0(string filename): Level(0,filename) {}

char l0::block_create(){
    pos = (pos == type.size()) ? 0 : type.size();
    char retval = type[pos];
    ++pos;
    return retval;
}