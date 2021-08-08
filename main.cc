#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main(int args, char *argv[]) {
    int start_level = 0;
    bool graphic_switch = true;
    std::string inputfile1 = "sequence1.txt";
    std::string inputfile2 = "sequence2.txt";
    for(int i = 1; i < args; i++){
        std::string input{argv[i]};
        if(input == "-text"){
            //since in this mode we donot need the graphics
            graphic_switch = false;
        } else if(input == "-seed"){
            //we will use unsigned int since the random number generated should be greater than 0
            int seed_val = 0;
            i++;
            std::string temp{argv[i]};
            std::istringstream ss1{temp};
            ss1 >> seed_val;
            srand(seed_val);
        } else if(input == "-scriptfile1"){
            i++;
            std::string file_name{argv[i]};
            inputfile1 = file_name;
        } else if(input == "-scriptfile2"){
            i++;
            std::string file_name{argv[i]};
            inputfile2 = file_name;
        } else if(input == "-startlevel"){
            ++i;
            std::string level_input{argv[i]};
            std::istringstream ss1{level_input};
            ss1 >> start_level;
        }
    }
    return 0;
}