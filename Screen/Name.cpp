#include "Name.hpp"

Name::Name(int h, int w):Screen(h,w){}

void Name::insert() {
    echo();
    curs_set(1);


    wattron(screen,COLOR_PAIR(2));
    mvwprintw(screen,0,2,"Enter your Name:");
    wattroff(screen,COLOR_PAIR(2));

    wmove(screen,2,3);

    wgetnstr(screen,name,10);


    wrefresh(screen);
    refresh();
    noecho();
    curs_set(0);
}

char* Name::getName() {
    char* nameast;
    strcpy(nameast,name);
    return nameast;
}