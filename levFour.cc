#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "levFour.h"

LevFour::LevFour(string file): Level(4, file) {}

void LevFour::updateCount(int temp) {
    counter = temp;
}

int LevFour::getCount() {
    return counter;
}

char LevFour::blockCreate() {
    counter += 1;
    if(file != ""){
        pos = (type.size() == pos)? 0 : pos;
        char retval = type[pos];
        pos++;
        return retval;
    }
    int prob = rand() % 9;
    char retval = 'A';
    switch(prob) {
        case 0: 
            retval = 'S';
            break;
        case 1:
            retval = 'T';
            break;
        case 2:
            retval = 'O';
            break;
        case 3:
            retval = 'I';
            break;
        case 4:
            retval = 'L';
            break;
        case 5:
            retval = 'J';
            break;
        case 6:
            retval = 'Z';
            break;
        case 7:
            retval = 'Z';
            break;
        case 8:
            retval = 'S';
            break;
        default:
        //one of the cases above will always be true since (any number % 9) < 9
        break;
    }
    return retval;
}