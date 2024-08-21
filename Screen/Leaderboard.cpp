//
// Created by angelo on 7/16/24.
//

#include "Leaderboard.hpp"

Leaderboard::Leaderboard(int h, int w):Screen(h,w){}

void Leaderboard::printLead() {
    HandlerClassifica lead("prova.txt");
    int lclass=lead.getCurrentPlayer();
    Giocatore player[lclass];
    lead.getClassifica(player);

    wattron(screen, COLOR_PAIR(5));
    wattron(screen,A_BOLD | A_UNDERLINE);
    mvwprintw(screen,2,(wide-11)/2,"LEADERBOARD");
    wattroff(screen,A_BOLD | A_UNDERLINE);
    mvwprintw(screen,4,3,"#  NAME\t\tPOINTS\tDATE");
    for (int i = 0; i < lclass; i++) {
        mvwprintw(screen,i*2+6,3,"%d",i+1);
        wprintw(screen,". ");
        wprintw(screen,player[i].getNome());
        if(strlen(player[i].getNome())<3) {
            wprintw(screen,"\t\t\t");
        }
        else {
            wprintw(screen,"\t\t");
        }
        wprintw(screen,"%d",player[i].getPunteggio());
        wprintw(screen,"\t");
        wprintw(screen,player[i].getDataPunteggio());
    }
    wattroff(screen,COLOR_PAIR(5));
    refresh();
    wrefresh(screen);
}