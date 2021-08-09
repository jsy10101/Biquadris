#include <string>
#include <sstream>
#include "gameController.h"

int main(int args, char *argv[]) {
    int startLevel = 0;
    bool graphicSwitch = true;
    std::string inputFile1 = "sequence1.txt";
    std::string inputFile2 = "sequence2.txt";
    for(int i = 1; i < args; i++){
        std::string cmd{argv[i]};
        if(cmd == "-text"){
            //since in this mode we donot need the graphics
            graphicSwitch = false;
        } else if(cmd == "-seed"){
            int seedVal = 0;
            ++i;
            std::string temp{argv[i]};
            std::istringstream ss1{temp};
            ss1 >> seedVal;
            srand(seedVal);
        } else if(cmd == "-scriptfile1"){
            i++;
            std::string file{argv[i]};
            inputFile1 = file;
        } else if(cmd == "-scriptfile2"){
            i++;
            std::string file{argv[i]};
            inputFile2 = file;
        } else if(cmd == "-startlevel"){
            ++i;
            std::string levelInput{argv[i]};
            std::istringstream ss1{levelInput};
            ss1 >> startLevel;
        }
    }
    GameController g{startLevel, inputFile1, inputFile2};
    g.startGame();
    return 0;
}