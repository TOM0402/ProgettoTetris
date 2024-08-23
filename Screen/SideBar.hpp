#ifndef SIDEBAR_HPP
#define SIDEBAR_HPP
#include "Screen.hpp"

class SideBar:public Screen {
protected:
    char* username;
public:
    SideBar(int h, int w, char* usName);
    void printScores();
};


#endif //SIDEBAR_HPP
