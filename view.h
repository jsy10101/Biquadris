#ifndef __VIEW_H__
#define __VIEW_H__

class Game;
class View {
    const int row;
    const int col;
    public:
        View();      
        void textDisplay(Game& player1, Game& player2);
};

#endif