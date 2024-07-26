#ifndef SCREENG_HPP
#define SCREENG_HPP
#include <ncurses.h>
#include "../Classifica/classifica.hpp"

const int N=11;

class Screen {
protected:
    WINDOW* screen;
    int high;
    int wide;

public:
    Screen(int h, int w);
    void borderscreen();
    WINDOW* getScreen();
    int getHigh();
    int getWide();
};


#endif //SCREENG_HPP