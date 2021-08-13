#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <string>
#include <vector>

class Level {
    int currLevel;
    std::string file;
    public:
        static int pos;
        std::vector<char> blockTypeList;
        Level(int currLevel, std::string file);
        int getCurLevl() const;
        virtual char blockCreate() = 0;
        virtual ~Level();
};


#endif