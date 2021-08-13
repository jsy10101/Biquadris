#include "level.h"

Level::Level(int currLevel) : 
    currLevel{currLevel}
    {}

Level::~Level() {}

int Level::getCurLevl() const {
    return currLevel;
}