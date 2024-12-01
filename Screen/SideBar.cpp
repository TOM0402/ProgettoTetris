#include "SideBar.hpp"

SideBar::SideBar(int h, int w, char* usName):Screen(h,w) {
    int yMax,xMax;
    high=h;
    wide=w;
    getmaxyx(stdscr,yMax,xMax);
    int startY=(yMax/2)-high/2;
    int startX=(xMax/2)-wide/2 + wide + 2;
    screen=newwin(high,wide, startY,startX);
    username=usName;
}

char* SideBar::getPlayerName() {
    return this->username;
}

void SideBar::printScores(int score, int level) {
    int i=2;
    wattron(screen, COLOR_PAIR(2));
    wattron(screen,A_BOLD);
    mvwprintw(screen,i,3,"Player:");
    mvwprintw(screen,i+3,3,"Level:");
    mvwprintw(screen,i+6,3,"Score:");
    wattroff(screen,A_BOLD);

    mvwprintw(screen,i+1,3, username);
    mvwprintw(screen,i+4,3,"%d", level);
    mvwprintw(screen,i+7,3,"%d", score);
    wattroff(screen, COLOR_PAIR(2));
    refresh();
    wrefresh(screen);
}
