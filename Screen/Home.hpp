#ifndef HOME_HPP
#define HOME_HPP
#include "ScreenG.hpp"

class Home:public Screen {
protected:
    char* scelte[]; //PLAY, Leaderboard
public:
    Home(int h, int w);
    void printLogo();
    int menu();
};

#endif //HOME_HPP
