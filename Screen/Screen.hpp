#ifndef SCREENG_HPP
#define SCREENG_HPP
#include <ncurses.h>
#include "../Classifica/classifica.hpp"
#include "../Collisioni/CollisioniNuovo.hpp"

const int N=11;

class Screen {
protected:
    WINDOW* screen;
    int high;
    int wide;

public:
    Screen(int h, int w);
    void borderscreen();
    void borderscreen(WINDOW* screen, char board[GRID_HEIGHT][GRID_WIDTH], int score);
    WINDOW* getScreen();
    int getHigh();
    int getWide();
};


#endif //SCREENG_HPP