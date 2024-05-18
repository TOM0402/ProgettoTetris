#include "ScreenG.hpp"
#include <ncurses.h>
using namespace std;

const int N=10;

Screen::Screen(int h, int w) {
    int yMax,xMax;
    getmaxyx(stdscr,yMax,xMax);
    int startY=(yMax/2)-h/2;
    int startX=(xMax/2)-w/2;
    screen=newwin(h,w, startY,startX);
}

void Screen::borderscreen(){
    init_pair(1,COLOR_BLUE,COLOR_BLACK);

    wattron(screen,COLOR_PAIR(1));
    wattron(screen,A_ALTCHARSET);

    //box(griglia, 0,0);
    wborder(screen, 'Y', 'Y', 'R', 'R', 'C', 'B', 'D', 'A');

    wattroff(screen,COLOR_PAIR(1));
    wattroff(screen,A_ALTCHARSET);

    refresh();
    wrefresh(screen);
}

void Screen::printTop() {
    HandlerClassifica lead("prova.txt");
    Giocatore player[N];
    lead.getClassifica(player);
    wattron(screen,COLOR_PAIR(1));
    int lclass=lead.getCurrentPlayer();
    mvwprintw(screen,2,3,"NAME\t\tPOINTS\tDATE");
    for (int i = 0; i < lclass; i++) {
        mvwprintw(screen,i*2+4,3,player[i].getNome());
        wprintw(screen,"\t");
        wprintw(screen,"%d",player[i].getPunteggio());
        wprintw(screen,"\t");
        wprintw(screen,player[i].getDataPunteggio());
    }
    wattroff(screen,COLOR_PAIR(1));
    refresh();
    wrefresh(screen);
}
