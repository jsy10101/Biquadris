#include "levFour.h"
#include <fstream>

LevFour::LevFour(std::string file) :
    Level{4, file}, file{file}
    {}

char LevFour::blockCreate() {
    if(file == "") {
        int prob = rand() % 9;
        char retval = ' ';
        switch(prob) {
            case 0: 
            case 1:
                retval = 'S';
                break;
            case 2:
            case 3:
                retval = 'Z';
                break;
            case 4:
                retval = 'I';
                break;
            case 5:
                retval = 'J';
                break;
            case 6:
                retval = 'L';
                break;
            case 7:
                retval = 'O';
                break;
            case 8:
                retval = 'T';
                break;
            default:
            // Would never get here
            // one of the cases above will always be true since (any number % 9) < 9
                break;
        }
        return retval;
    } else {
        pos = (pos >= blockTypeList.size()) ? 0 : pos;
        ++pos;
        return blockTypeList[pos - 1];
    }
}