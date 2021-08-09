#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "levTwo.h"

using namespace std;

LevTwo::LevTwo(): Level(2) {}

char LevTwo::blockCreate() {
    int prob = rand() % 7;
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
        default:
        //one of the cases above will always be true since (any number % 6) < 6
    }
    return retval;
}
