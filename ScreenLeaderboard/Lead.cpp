#include "Lead.hpp"
#include <ncurses.h>

using namespace std;

Lead::Lead() {
    Giocatore tmp[N];
        HandlerClassifica hc("LEAD");
        hc.getClassifica(tmp);
    for (int i=0; i<N; i++) {
        strcpy(leadList[i].nome, tmp[i].getNome());
        leadList[i].points=tmp[i].getPunteggio();
        strcpy(leadList[i].data, tmp[i].getDataPunteggio());
    }
}

void Lead::initgrill(WINDOW* griglia,int h, int w) {
    int yMax,xMax;
    getmaxyx(stdscr,yMax,xMax);
    int startY=(yMax/2)-h/2;
    int startX=(xMax/2)-w/2;
    griglia=newwin(h,w, startY,startX);

    init_pair(1,COLOR_BLUE,COLOR_BLACK);

    wattron(griglia,COLOR_PAIR(1));
    wattron(griglia,A_ALTCHARSET);

    //box(griglia, 0,0);
    wborder(griglia, 'Y', 'Y', 'R', 'R', 'C', 'B', 'D', 'A');

    wattroff(griglia,COLOR_PAIR(1));
    wattroff(griglia,A_ALTCHARSET);

    refresh();
    wrefresh(griglia);
}

void Lead::printLead() {
    clear();
    initgrill(this->leadscr,20,20);
}

WINDOW* Lead::getLeadscr() {
    return this->leadscr;
}