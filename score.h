#ifndef __SCORE_H__
#define __SCORE_H__

class Score {
    int currScore;
    static int highScore;
    public:
        Score();
        int getCurrScore() const;
        static int getHighScore();
        void resetCurrScore();
        void calcBlockScore(int genLevel);
        void calcRowScore(int currLevel, int nRows);
};

#endif