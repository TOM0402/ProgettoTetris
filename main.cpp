#include "fileManagement/file.hpp"
//#include "Classifica/classifica.hpp"
#include "Screen/ScreenG.hpp"
#include <ncurses.h>
#include <stdlib.h>


using namespace std;

void init() {
    initscr(); // Inizializza la libreria curses
    noecho(); // Disabilita l'echo delle caratteri
    curs_set(0); // Nasconde il cursore
    keypad(stdscr, TRUE); // Abilita la lettura delle tasti speciali
    //timeout(100); // Imposta un timeout per la lettura delle tasti
    if(!has_colors())
        printw("NO COLORS");
    else
        start_color();
}

void stampa_gioca(Giocatore g[], int n){
    for (int i = 0; i < n; i++) {
        cout<<g[i].getNome()<<" punteggio: "<<g[i].getPunteggio()<<", data "<<g[i].getDataPunteggio()<<endl;
    }
}

/*
void initgrill(WINDOW* griglia,int h, int w) {
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
*/

int main() {
    //init();
    /*
    File * f = new File("prova.txt");
    Giocatore giocatori [3];
    //la write funziona
    //Giocatore g("Andrea",15,"11/06/2024");
    //f->write(g);
    f->read(giocatori);
    for (int i = 0; i < 3; i++) {
        cout << "Nome: " << giocatori[i].getNome() << endl;
        cout << "Punteggio: " << giocatori[i].getPunteggio() << endl;
        cout << "Data Punteggio: " << giocatori[i].getDataPunteggio() << endl;
        cout << "------------------------" << endl;
        cout << "------------------------" << endl;
    }


    for(int i = 0; i<ngiocatori;i++){
        cout<<cla.giocatori[i].getNome()<<" "<<cla.giocatori[i].getPunteggio()<<" "<<cla.giocatori[i].getDataPunteggio()<<endl;
    }


*/

    //init();
    // TODO
    /* da
    cout<<"Test classe gestione classifica"<<endl;
     HandlerClassifica c ("prova.txt");
    */ //a
    /*Giocatore gio[c.getCurrentPlayer()];
    c.getClassifica(gio);
    stampa_gioca(gio, c.getCurrentPlayer());
    */
    /* da
    Giocatore gio[c.getCurrentPlayer()];
    c.getClassifica(gio);
    stampa_gioca(gio, c.getCurrentPlayer());
    */ //a

     /* c.getClassifica(gio);
     stampa_gioca(gio, c.getCurrentPlayer());
     cout<<"Test"<<endl;
     c.aggiungi(Giocatore("ale3",102,"11/06/2023"));
    Giocatore gio2[c.getCurrentPlayer()];
    c.getClassifica(gio2);
    stampa_gioca(gio2, c.getCurrentPlayer());

    c->aggiungi(Giocatore("ale1",2000,"10/09/2024"));
    c->aggiungi(Giocatore("ale2",2,"10/09/2024"));
    c->aggiungi(Giocatore("ale3",10,"10/09/2024"));
    c->aggiungi(Giocatore("ale4",30,"10/09/2024"));

    c->aggiungi(Giocatore("ale5",120,"10/09/2024"));
    Giocatore gio2[c->getCurrentPlayer()];
    c->getClassifica(gio2);
    cout<<"Stampa con aggiunta"<<endl;
    stampa_gioca(gio2, c->getCurrentPlayer());
*/
    init();
    //printw("ciao","stronzo");
    Screen lead(25,37);
    lead.borderscreen();
    lead.printTop();

    getch();
    endwin();


    return 0;
}