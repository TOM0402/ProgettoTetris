#include "fileManagement/file.hpp"
//#include "Classifica/classifica.hpp"
#include "Screen/ScreenG.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <vector>
#include "Collisioni/Collisioni.hpp"
#include "Screen/Home.hpp"
#include "Screen/Game.hpp"
#include "Screen/Leaderboard.hpp"
#include "Screen/Name.hpp"
#include "Tetramino/TetraminoQuadrato.hpp"

using namespace std;

void printBoolMatrix(WINDOW* win, const bool matrix[22][22]) {
    for (int i = 0; i < 22; ++i) {
        for (int j = 0; j < 22; ++j) {
            mvwaddch(win, i, j * 2, (matrix[i][j] ? '1' : '0'));
        }
    }
    wrefresh(win); // Aggiorna la finestra per visualizzare il contenuto
}

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

    init_pair(1,COLOR_RED,COLOR_BLACK);
    init_pair(2,COLOR_BLUE,COLOR_BLACK);
    init_pair(3,COLOR_YELLOW,COLOR_BLACK);
    init_pair(4,COLOR_GREEN,COLOR_BLACK);
    init_pair(5,COLOR_CYAN,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);

}

void stampa_gioca(Giocatore g[], int n){
    for (int i = 0; i < n; i++) {
        cout<<g[i].getNome()<<" punteggio: "<<g[i].getPunteggio()<<", data "<<g[i].getDataPunteggio()<<endl;
    }
}

int main() {

    init();

    Home home(32,62);
    home.printLogo();
    home.borderscreen();
    int s=home.menu();

    clear();
    if (s==0) {
        Name insName(5,34);
        insName.borderscreen();
        insName.insert();

        clear();
        Game playGrill(GRID_HIGH,GRID_WIDE);
        int ch;
        Collisioni c=Collisioni();
        TetraminoQuadrato *T1 = new TetraminoQuadrato(playGrill);
        T1->drawTetramino(playGrill.getScreen(), c);
        printBoolMatrix(stdscr, c.occupiedMatrix);
        playGrill.borderscreen();

        while ((ch = getch()) != 'q') {
            T1->moveTetramino(T1, c, ch, playGrill.getScreen());
            printBoolMatrix(stdscr, c.occupiedMatrix);
            if(T1->getPosY()==GRID_HIGH-2){     //QUANDO ARRIVO IN FONDO SPAWN NUOVO TETRAMINO
                T1 = new TetraminoQuadrato(playGrill);
                T1->spawnTetramino(playGrill, c);
                printBoolMatrix(stdscr, c.occupiedMatrix);
            }
            printBoolMatrix(stdscr, c.occupiedMatrix);
            wrefresh(playGrill.getScreen());

        }


    }
    else { // CLASSIFICA
        Leaderboard lead(27,46);
        lead.borderscreen();
        lead.printLead();
    }

    getch();
    endwin();

    return 0;
}


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

//printw("ciao","stronzo");
