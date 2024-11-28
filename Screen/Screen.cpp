#include "Screen.hpp"
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

void Screen::borderscreen(WINDOW* screen, char board[GRID_HEIGHT][GRID_WIDTH], int score) {
    box(screen, 0, 0);
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            if (board[y][x] != '.') {
                wattron(screen, COLOR_PAIR(board[y][x]));
                mvwprintw(screen, y+1, 2*x+1, "XX");
                wattroff(screen, COLOR_PAIR(board[y][x]));
            } else {
                mvwprintw(screen, y+1, 2*x+1, "  ");
            }
        }
    }
     // Disegna il punteggio (aggiustata la posizione per il bordo)
    mvwprintw(screen, 0, GRID_WIDTH * 2 + 3, "Score: %d", score);

    // Disegna il bordo dopo aver disegnato il tabellone
    wattron(screen, COLOR_PAIR(2));
    wattron(screen, A_ALTCHARSET);
    wborder(screen, 'x', 'x', 'q', 'q', 'l', 'k', 'm', 'j');
    wattroff(screen, COLOR_PAIR(2));
    wattroff(screen, A_ALTCHARSET);

    wrefresh(screen);
}

WINDOW* Screen::getScreen() {
    return screen;
}

int Screen::getHigh() {
    return high;
}

int Screen::getWide() {
    return wide;
}


