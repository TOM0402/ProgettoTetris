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
/*
void NextT::drawNextTetromino(TetraminoNuovo &t) {
    werase(screen);
    attron(COLOR_PAIR(t.color));
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t.shape[y][x] == 'X') {
                mvwprintw(screen, y, 2 * x, "XX");
            }
        }
    }
    attroff(COLOR_PAIR(t.color));
    wrefresh(screen);
}
*/