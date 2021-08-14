#include "gameController.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

GameController::GameController(int lvl, std::string iF1, std::string iF2) : 
    player1{Game(iF1, lvl)}, player2{Game(iF2, lvl)}, 
    currPlayer{nullptr}, currPlayerId{1}, isSwitchOff{false}, v{View()}
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
    bool isSequenceFile = false;
    std::istringstream iStrStream;
    std::string cmd;
    std::string partCmd; 
    std::ifstream sequenceFile;

    while( true ) {
        v.textDisplay(player1, player2);

        std::cout << std::endl;
        if(currPlayerId == 2) {
            std::cout << std::setw(27) << " "; 
        }
        std::cout << "Enter command: ";
        
        if( isSequenceFile == false ) {
            if( !( std::cin >> cmd ) ) {
                break;
            }
        } else {
            // use the ifstream file which we initialised when sequence cmd was invoked
            if( !( sequenceFile >> cmd ) ) {
                isSequenceFile = !isSequenceFile;
                // if entire sequence file has been processed, return to default behaviour
                if( !( std::cin >> cmd ) ) {
                    break;
                }
            }
            
        }
        // Always empty stringstream first
        iStrStream.clear();
        iStrStream.str(cmd);
        // if user enters cmdCounter (int), then mutate the default val
        if( !(iStrStream >> cmdCounter) ) {
            cmdCounter = 1;
            iStrStream.clear();
        }
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
            // clockwise
            std::cout << cmd << std::endl;
            currPlayer->rotateBlock(cmdCounter);

        } else if( partCmd.substr(0, 2) == "co" || partCmd == "cc" ) {
            // counter clockwise
            std::cout << cmd << std::endl;
            currPlayer->rotateBlock(-1 * cmdCounter);

        } else if( partCmd.substr(0, 2) == "dr" ) {
            // drop
            std::cout << cmd << std::endl;
            currPlayer->dropBlock(cmdCounter);
            if( currPlayer->getIsGameFinished() ) {
                if(currPlayerId == 2) {
                    std::cout << std::setw(27) << " ";    
                }
                std::cout << "Player " << currPlayerId << " game finished" << std::endl;
                if(currPlayerId == 2) {
                    std::cout << std::setw(27) << " ";    
                }
                std::cout << "Input 'r' to restart" << std::endl;
                if(currPlayerId == 2) {
                    std::cout << std::setw(27) << " ";    
                }
                std::cout << "Input 'e' to end game" << std::endl;
                if(currPlayerId == 2) {
                    std::cout << std::setw(27) << " ";    
                }
                std::cin >> cmd;
                std::cout << std::endl;
                if( cmd == "r" ) {
                    restartGame();
                } else if( cmd == "e" ) {
                    if(player1.getIsGameFinished() && player2.getIsGameFinished()) {
                        break;
                    }
                    exitGame(); 
                }
            }
            if( !isSwitchOff ) {
                switchPlayer();
            }

        } else if( partCmd.substr(0, 6) == "levelu" ) {
            // level up
            std::cout << cmd << std::endl;
            currPlayer->changePlayerLevel(1, cmdCounter);

        } else if( partCmd.substr(0, 6) == "leveld" ) {
            // level down
            std::cout << cmd << std::endl;
            currPlayer->changePlayerLevel(-1, cmdCounter);

        } else if( partCmd.substr(0, 2) == "ri" ) {
            // right
            std::cout << cmd << std::endl;
            currPlayer->shiftBlock(0, 1, cmdCounter);

        } else if( partCmd.substr(0, 2) == "do" ) {
            // down
            std::cout << cmd << std::endl;
            currPlayer->shiftBlock(1, 0, cmdCounter);

        } else if( partCmd.substr(0, 3) == "lef" ) {
            // left
            std::cout << cmd << std::endl;
            currPlayer->shiftBlock(0, -1, cmdCounter);

        } else if( partCmd.substr(0, 1) == "n" ) {
            // no random file
            std::cout << cmd << std::endl;
            std::string file;
            std::cin >> file;
            currPlayer->setNoRandomFile(file);

        } else if( partCmd.substr(0, 2) == "ra" ) {
            // random
            std::cout << cmd << std::endl;
            currPlayer->setNoRandomFile("");

        } else if( partCmd.substr(0, 1) == "s") {
            // sequence file
            std::cout << cmd << std::endl;
            std::string seqFile = "";
            std::cin >> seqFile;
            isSequenceFile = true;
            sequenceFile = std::ifstream{seqFile};

        } else if( partCmd.substr(0, 2) == "re" ) {
            // restart game
            std::cout << cmd << std::endl;
            restartGame();

        } else if( partCmd.substr(0, 2) == "ex" ) {
            // exit game
            std::cout << cmd << std::endl;
            if(player1.getIsGameFinished() && player2.getIsGameFinished()) {
                break;
            }
            exitGame(); 

        }  else {
            std::cout << "Wrong command" << std::endl;
        }
    }
}

void GameController::restartGame() {
    currPlayer->reset();
}

void GameController::exitGame() {
    switchPlayer();
    isSwitchOff = true;
}