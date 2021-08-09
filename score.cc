#include "view.h"
#include <sstream>
#include "score.h"
#include <iomanip>

Score::Score(int level,View * ptr, int h, int v) : current_score{0} , high_score{0}, level{level}, view{ptr}, h_shift{h}, v_shift{v} {}

int Score::update_score(int temp){
    current_score += temp; 
}

void Score::eliminate_row (int n_rows){
    current_score += (n_rows + level) * (n_rows + level);
    high_score = (current_score > high_score)? current_score : high_score;

}

int Score::get_highscore(){
    return high_score;
}

void Score::eliminate_block(int temp){
    current_score = current_score + (temp + 1) * (temp + 1);
    high_score = (current_score > high_score)? current_score : high_score;
}

void reset_score(){
    current_score = 0;
}

void Score::update_level(int new_level){
    level = new_level;
}