//
// Created by angelo on 7/16/24.
//

#include "../HandlerLeaderboard/HandlerLeaderboard.hpp"
#include "Leaderboard.hpp"

Leaderboard::Leaderboard(int h, int w):Screen(h,w){}

void Leaderboard::printLead() {
    HandlerLeaderboard lead("classifica.txt");
    int lclass=lead.getCurrentPlayer();
    Player player[lclass];
    lead.getLeaderboard(player);

    wattron(screen, COLOR_PAIR(2));
    mvwprintw(screen,0,2,"Back(Enter)");
    wattron(screen, A_BOLD | A_UNDERLINE);
    mvwprintw(screen,2,(wide-11)/2,"LEADERBOARD");
    wattroff(screen,A_BOLD | A_UNDERLINE);
    wattroff(screen, COLOR_PAIR(2));

    wattron(screen, COLOR_PAIR(5));
    mvwprintw(screen,4,3,"#  NAME\t\tPOINTS\tDATE");
    for (int i = 0; i < lclass; i++) {
        mvwprintw(screen,i*2+6,3,"%d",i+1);
        wprintw(screen,". ");
        wprintw(screen,player[i].getName());
        if(strlen(player[i].getName())<3) {
            wprintw(screen,"\t\t\t");
        }
        else {
            wprintw(screen,"\t\t");
        }
        wprintw(screen,"%d",player[i].getPoints());
        wprintw(screen,"\t");
        wprintw(screen,player[i].getDatePoints());
    }
    wattroff(screen,COLOR_PAIR(5));
    refresh();
    wrefresh(screen);
}