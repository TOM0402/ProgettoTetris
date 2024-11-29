#ifndef HOME_HPP
#define HOME_HPP
#include "Screen.hpp"

class Home:public Screen {
protected:
    char* scelte[]; //PLAY, Leaderboard, Quit
public:
    Home(int h, int w);
    void printLogo();
    int menu();
};

#endif //HOME_HPP
