#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "levThree.h"



LevThree::LevThree(std::string file): Level(3, file) {}

char LevThree::blockCreate(){
    if(file != ""){
        pos = (type.size() == pos)? 0 : pos;
        char retval = type[pos];
        pos++;
        return retval;
    }
    int prob = rand() % 9 ;
    char retval = 'A';
    if(prob == 0){
        retval = 'I';
    }
    else if(prob == 1){
        retval = 'L';
    }
    else if (prob == 2 || prob == 3){
        retval = 'S';
    }
    else if (prob == 4){
        retval = 'J';
    }
    else if (prob == 5){
        retval = 'O';
    }
    else if (prob == 6){
        retval = 'T';
    }
    else if (prob == 7 || prob == 8){
        retval == 'Z';
    }
    return retval;
}