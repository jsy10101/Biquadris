#ifndef __LEVFOUR_H__
#define __LEVFOUR_H__

#include"level.h"
#include <string>

class LevFour : public Level{
    int counter = 0;
    public: 
        LevFour(std::string file = "");
        char blockCreate() override;
        void updateCount(int temp) override;
        int getCount() override;
};

#endif