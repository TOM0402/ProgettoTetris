#ifndef SIDEBAR_HPP
#define SIDEBAR_HPP
#include "ScreenG.hpp"

class SideBar:public Screen {
protected:
    char* username;
public:
    SideBar(int h, int w, char* username);
    void printScores();
};

#endif //SIDEBAR_HPP
