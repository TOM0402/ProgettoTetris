#ifndef SIDEBAR_HPP
#define SIDEBAR_HPP
#include "Screen.hpp"

class SideBar:public Screen {
protected:
    char* username;
public:
    SideBar(int h, int w, char* usName);
    char* getPlayerName();
    void printScores(int score, int level);
};


#endif //SIDEBAR_HPP
