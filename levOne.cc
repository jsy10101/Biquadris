#include "levOne.h"
#include <fstream>

LevOne::LevOne() : 
    Level{1, ""}
    {}

char LevOne::blockCreate() {    
    int prob = rand() % 12;
    char retval = ' ';
    switch(prob) {
        case 0: 
            retval = 'S';
            break;
        case 1:
            retval = 'Z';
            break;
        case 2:
        case 3:
            retval = 'I';
            break;
        case 4:
        case 5:
            retval = 'J';
            break;
        case 6:
        case 7:
            retval = 'L';
            break;
        case 8:
        case 9:
            retval = 'O';
            break;
        case 10:
        case 11:
            retval = 'T';
            break;
        default:
        // Would never get here
        // one of the cases above will always be true since (any number % 6) < 6
            break;
    }
    return retval;
}