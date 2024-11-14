#include "NextT.hpp"

NextT::NextT(int h, int w):Screen(h,w) {
    int yMax,xMax;
    high=h;
    wide=w;
    getmaxyx(stdscr,yMax,xMax);
    int startY=(yMax/2)-high ;
    int startX=(xMax/2)-wide/2 - wide - 2;
    screen=newwin(high,wide, startY,startX);
}

void NextT::drawNextTetramino(TetraminoNuovo *t) {
    werase(screen);
    wattron(screen, COLOR_PAIR(t->getColor()));
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t->getShape(y,x) == 'X') {
                mvwprintw(screen, y+4, (2*x)+7, "XX");
            }
        }
    }
    wattroff(screen, COLOR_PAIR(t->getColor()));
    wrefresh(screen);
}
