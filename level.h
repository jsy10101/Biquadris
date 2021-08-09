#ifndef __LEVEL_H__
#define __LEVEL_H__

class Level {
    int currLevel;
    public:
        Level(int currLevel);
        int getCurLevl() const;
        virtual char blockCreate() = 0;
        virtual ~Level();
};


#endif