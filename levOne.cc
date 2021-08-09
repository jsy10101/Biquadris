#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "levOne.h"

using namespace std;

LevOne::LevOne() : Level(1) {}

char LevOne::blockCreate(){
    int prob = rand() % 6;
    char retval = 'A';
    switch(prob) {
        case 0: 
            retval = (rand() % 2 == 0)? 'Z' : 'S';
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
        default:
        //one of the cases above will always be true since (any number % 6) < 6
            break;
    }
    return retval;
}

