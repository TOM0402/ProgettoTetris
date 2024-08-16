#include "Name.hpp"

Name::Name(int h, int w):Screen(h,w) {}

void Name::insert() {
    echo();
    curs_set(1);

    wattron(screen,COLOR_PAIR(2));
    mvwprintw(screen,0,2,"Inserisci il tuo Nome:");
    wattroff(screen,COLOR_PAIR(2));

    wmove(screen,2,3);

    wgetnstr(screen,name,N-1);

    // Stampa il nome inserito nella finestra principale
    //mvprintw(high - 2, 0, "Nome inserito: %s", name);

    wrefresh(screen);
    refresh();
    noecho();
    curs_set(0);
}

char* Name::getName() {
    return name;
}
