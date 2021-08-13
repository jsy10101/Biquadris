#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <string>
#include <vector>

class Level {
    int currLevel;
    std::string file;
    public:
        Level(int currLevel, std::string file);
        static int pos;
        std::vector<char> blockTypeList;
        int getCurLevl() const;
        virtual char blockCreate() = 0;
        virtual ~Level();
};


#endif