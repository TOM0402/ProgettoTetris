#include "ScreenG.hpp"
#include "../Tetramino/Tetramino.hpp"
#include <ncurses.h>
using namespace std;

//const int N=11;

Screen::Screen(int h, int w) {
    int yMax,xMax;
    high=h;
    wide=w;
    getmaxyx(stdscr,yMax,xMax);
    int startY=(yMax/2)-high/2;
    int startX=(xMax/2)-wide/2;
    screen=newwin(high,wide, startY,startX);

    //borderscreen();
}

void Screen::borderscreen(){

    wattron(screen,COLOR_PAIR(2));
    wattron(screen,A_ALTCHARSET);

    //box(griglia, 0,0);
    //wborder(screen, 'Y', 'Y', 'R', 'R', 'C', 'B', 'D', 'A'); // Windows
    wborder(screen, 'x', 'x', 'q', 'q', 'l', 'k', 'm', 'j'); // Linux

    wattroff(screen,COLOR_PAIR(2));
    wattroff(screen,A_ALTCHARSET);

    refresh();
    wrefresh(screen);
}

WINDOW* Screen::getScreen() {
    return screen;
}