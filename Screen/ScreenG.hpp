#ifndef SCREENG_HPP
#define SCREENG_HPP
#include <ncurses.h>
#include "../Classifica/classifica.hpp"


class Screen {
private:
    WINDOW* screen;
public:
    Screen(int h, int w);
    void borderscreen();
    void printTop();
};

#endif //SCREENG_HPP