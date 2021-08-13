#include "gameController.h"
#include <iostream>
#include <iomanip>
#include <sstream>

#ifndef DEBUG
#define DEBUG 0
#endif

GameController::GameController(int lvl, std::string iF1, std::string iF2) : 
    player1{Game(iF1, lvl)}, player2{Game(iF2, lvl)}, 
    currPlayer{nullptr}, currPlayerId{1}, v{View()}
    {}

void GameController::switchPlayer() {
    if( currPlayerId == 1 ) {
        currPlayerId = 2;
        currPlayer = &player2;
    } else {
        currPlayerId = 1;
        currPlayer = &player1;
    }
}

void GameController::startGame() {
    currPlayer = &player1;
    int cmdCounter = 1; 
    std::istringstream iStrStream;
    std::string cmd;
    std::string partCmd; 

    while( true ) {
        v.textDisplay(player1, player2);
        std::cout << std::endl;
        if(currPlayerId == 2) {
            std::cout << std::setw(27) << " "; 
        }
        std::cout << "Enter command: ";
        std::cin >> cmd;
        if( std::cin.eof() ) {
            break;
        }
        // Always empty stringstream first
        iStrStream.clear();
        iStrStream.str(cmd);
        // if user enters cmdCounter (int), then mutate the default val
        if( !(iStrStream >> cmdCounter) ) {
            cmdCounter = 1;
            iStrStream.clear();
        }
        // to be deleted later
        if(currPlayerId == 2) {
            std::cout << std::setw(27) << " "; 
        }
        iStrStream >> partCmd;
        if( cmd == "I" || cmd == "J" || cmd == "L" ||
            cmd == "O" || cmd == "S" || cmd == "T" ||
            cmd == "Z" ) {
            std::cout << cmd << std::endl;
            currPlayer->changeCurrBlock(cmd);

        } else if( partCmd.substr(0, 2) == "cl" ) {
            std::cout << partCmd << std::endl;
            currPlayer->rotateBlock(cmdCounter);

        } else if( partCmd.substr(0, 2) == "co" || partCmd == "cc" ) {
            std::cout << partCmd << std::endl;
            currPlayer->rotateBlock(-1 * cmdCounter);

        } else if( partCmd.substr(0, 2) == "dr" ) {
            std::cout << partCmd << std::endl;
            currPlayer->dropBlock(cmdCounter);

            #if DEBUG == 0
            switchPlayer();
            #endif

        } else if( partCmd.substr(0, 6) == "levelu" ) {
            std::cout << partCmd << std::endl;

        } else if( partCmd.substr(0, 6) == "leveld" ) {
            std::cout << partCmd << std::endl;

        } else if( partCmd.substr(0, 2) == "ri" ) {
            std::cout << partCmd << std::endl;
            currPlayer->shiftBlock(0, 1, cmdCounter);

        } else if( partCmd.substr(0, 2) == "do" ) {
            std::cout << partCmd << std::endl;
            currPlayer->shiftBlock(1, 0, cmdCounter);

        } else if( partCmd.substr(0, 3) == "lef" ) {
            std::cout << partCmd << std::endl;
            currPlayer->shiftBlock(0, -1, cmdCounter);

        } else if( partCmd.substr(0, 1) == "n" ) {
            std::cout << partCmd << std::endl;

        } else if( partCmd.substr(0, 2) == "ra" ) {
            std::cout << partCmd << std::endl;

        } else if( partCmd.substr(0, 1) == "s") {
            std::cout << partCmd << std::endl;

        } else if( partCmd.substr(0, 2) == "re" ) {
            std::cout << partCmd << std::endl;

        } else {
            std::cout << "Wrong command" << std::endl;
        }
    }
}