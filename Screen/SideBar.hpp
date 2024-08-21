#ifndef SIDEBAR_HPP
#define SIDEBAR_HPP
#include "ScreenG.hpp"

class SideBar:public Screen {
protected:
public:
    SideBar(int h, int w);
    void printScores();
};

#endif //SIDEBAR_HPP
