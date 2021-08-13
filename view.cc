#include "view.h"
#include "game.h"
#include <iostream>
#include <iomanip>

View::View() :
    row{18}, col{11}
    {}

void View::textDisplay(Game& player1, Game& player2) {
    std::cout << "L e v e l:" << std::setw(7) << player1.getLevel() << std::setw(20)
        << "L e v e l:" << std::setw(7) << player2.getLevel() << std::endl;

    std::cout << "S c o r e:" << std::setw(7) << player1.getPlayerScore() << std::setw(20)
        << "S c o r e:" << std::setw(7) << player2.getPlayerScore() << std::endl;

    for(int i = 0; i < 11; ++i) {
        std::cout << "- ";
    }
    std::cout << std::setw(5) << " ";
    for(int i = 0; i < 11; ++i) {
        std::cout << "- ";
    }
    std::cout << std::endl;

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            std::cout << player1.getBoardObject().getBoard().at(i).at(j);
        }
        std::cout << std::setw(5) << " ";
        for(int j = 0; j < col; ++j) {
            std::cout << player2.getBoardObject().getBoard().at(i).at(j);
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < 11; ++i) {
        std::cout << "- ";
    }
    std::cout << std::setw(5) << " ";
    for(int i = 0; i < 11; ++i) {
        std::cout << "- ";
    }
    std::cout << std::endl;

    std::cout << "N e x t:" << std::setw(19) << " "
        << "N e x t:" << std::endl;
    int k1 = 0;
    int k2 = 0;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < player1.getNextBlock()->getBlock().size(); ++j) {
            if( k1 < player1.getNextBlock()->getBlock().size() && 
                player1.getNextBlock()->getBlock().at(k1) == Posn{i + 2, j} ) {
                std::cout << player1.getNextBlock()->getBType() << " ";
                ++k1;
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::setw(19) << " ";
        for(int j = 0; j < player2.getNextBlock()->getBlock().size(); ++j) {
            if( k2 < player2.getNextBlock()->getBlock().size() && 
                player2.getNextBlock()->getBlock().at(k2) == Posn{i + 2, j} ) {
                std::cout << player2.getNextBlock()->getBType() << " ";
                ++k2;
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}