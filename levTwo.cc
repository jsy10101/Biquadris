#include "levTwo.h"
#include <fstream>

LevTwo::LevTwo() :
    Level{2, ""}
    {}

char LevTwo::blockCreate() {
    int prob = rand() % 7;
    char retval = ' ';
    switch(prob) {
        case 0: 
            retval = 'S';
            break;
        case 1:
            retval = 'Z';
            break;
        case 2:
            retval = 'I';
            break;
        case 3:
            retval = 'J';
            break;
        case 4:
            retval = 'L';
            break;
        case 5:
            retval = 'O';
            break;
        case 6:
            retval = 'T';
            break;
        default:
        // Would never get here
        // one of the cases above will always be true since (any number % 7) < 7
            break;
    }
    return retval;
}