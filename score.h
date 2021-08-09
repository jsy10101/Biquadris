#ifndef __SCORE_H__
#define __SCORE_H__

#ifndef __SCORE_H__
#define __SCORE_H__

#include <iostream>

class View;

class Score{
    int curr_level;
    int high_score;
    int current_score;
    View * view = nullptr;
    int h_shift;
    int v_shift;

public:

    explicit Score(int level, View*, int, int);
    void eliminate_row(int);
    void eliminate_block(int);
    void update_level(int);
    void reset_score();
    int get_score();
    int get_highscore();
    void update_score(int);
};

#endif

#endif