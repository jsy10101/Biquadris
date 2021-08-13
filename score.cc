#include "score.h"

Score::Score() : 
    currScore{0}
    {}

int Score::highScore = 0;

int Score::getCurrScore() const {
    return currScore;
}

void Score::calcBlockScore(int levelGen) {
    currScore += ( levelGen + 1 ) * ( levelGen + 1 );
    if( currScore > highScore ) {
        highScore = currScore;
    }
}

void Score::calcRowScore(int currLevel, int nRows) {
    currScore += ( currLevel + nRows ) * ( currLevel + nRows );
    if( currScore > highScore ) {
        highScore = currScore;
    }
}

void Score::resetCurrScore() {
    currScore = 0;
}

int Score::getHighScore() {
    return highScore;
}