#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "level.h"
using namespace std;

Level::Level(int current_level, string filename = ""): 
    this->current_level{current_level}, this->filename{filename}{
        //to make sure the file name is not empty
        if(filename != ""){
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
    ifstream file{filename};
    //reading the file till eof
    while(file>>temp){
        type.emplace_back(temp);
    }
}





