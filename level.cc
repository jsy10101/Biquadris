#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "level.h"
using namespace std;

Level::Level(int current_level, string file = ""): 
    this->current_level{current_level}, this->file{file}{
        //to make sure the file name is not empty
        if(file != ""){
            read_file();
        }
        else{
            cerr<<"error";
            return;
        }
    }

void Level::read_file(){
    char temp;
    //open file in input mode
    ifstream file{file};
    //reading the file till eof
    while(file>>temp){
        type.emplace_back(temp);
    }
}





