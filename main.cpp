#include "fileManagement/file.hpp"
//#include "Classifica/classifica.hpp"
#include "Screen/ScreenG.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <vector>
#include "Collisioni/Collisioni.hpp"
#include "Collisioni/CollisioniLungo.hpp"
#include "Collisioni/CollisioniQuadrato.hpp"
#include "Screen/Home.hpp"
#include "Screen/Game.hpp"
#include "Screen/Leaderboard.hpp"
#include "Screen/Name.hpp"
#include "Tetramino/TetraminoQuadrato.hpp"
#include "Random/Random.hpp"
#include "Screen/SideBar.hpp"


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

    init_pair(7,COLOR_RED, COLOR_RED);
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
        SideBar sideGrill(GRID_HIGH, GRID_WIDE);
        sideGrill.printScores();
        sideGrill.borderscreen();

        Game playGrill(GRID_HIGH,GRID_WIDE);

        int ch;
        Random r;
        CollisioniLungo cl=CollisioniLungo();
        CollisioniQuadrato cq=CollisioniQuadrato();
        Tetramino *T=NULL;
        /*TetraminoQuadrato *TQ= new TetraminoQuadrato(playGrill);
        TetraminoLungo *TL= new TetraminoLungo(playGrill);*/
        //mvwprintw(playGrill.getScreen(), 10, 1, " premi un tasto ");
        playGrill.borderscreen();

        bool pezzo;

        while ((ch = getch()) != 'q') {
            mvwprintw(playGrill.getScreen(), 10, 1, "                ");
            pezzo=r.pezzo();
            mvwprintw(stdscr, 60, 1, " prima ");
                if (pezzo) {
                    mvwprintw(stdscr, 61, 1, " dopo ");
                    T=new TetraminoLungo(playGrill);
                    mvwprintw(stdscr, 49, 1, " if vero ");
                    mvwprintw(stdscr, 50, 1, to_string(T->getPosY()).c_str());
                    T->spawnTetramino(playGrill, cl);
                    bool down=cl.checkDownL(T->getPosY() + 1, T->getPosX());
                    while(down) {
                        mvwprintw(stdscr, 55, 1, " sotto è libero");
                        T->moveTetramino(T, cl, ch, playGrill.getScreen());
                        down=cl.checkDownL(T->getPosY() + 1, T->getPosX());

                    }
                        cl.setMatrix(T->getPosY(), T->getPosX(), true);
                        cl.setMatrix(T->getPosY(), T->getPosX() + 1, true);
                        cl.setMatrix(T->getPosY(), T->getPosX() + 2, true);
                        cl.setMatrix(T->getPosY(), T->getPosX() + 3, true);

                    printBoolMatrix(stdscr, cl.occupiedMatrix);
                    playGrill.borderscreen();
                } else {
                    T=new TetraminoQuadrato(playGrill);
                    mvwprintw(stdscr, 49, 1, " if falso ");
                    mvwprintw(stdscr, 50, 1, to_string(T->getPosY()).c_str());
                    T->spawnTetramino(playGrill, cq);
                    bool down=cq.checkDownQ(T->getPosY() + 2,T->getPosX());
                    while(down){
                        mvwprintw(stdscr, 55, 1, " sotto è libero");
                        T->moveTetramino(T, cq, ch, playGrill.getScreen());
                        down=cq.checkDownQ(T->getPosY() + 2,T->getPosX());
                    }
                        cq.setMatrix(T->getPosY(), T->getPosX(), true);
                        cq.setMatrix(T->getPosY(), T->getPosX() + 1, true);
                        cq.setMatrix(T->getPosY() + 1, T->getPosX(), true);
                        cq.setMatrix(T->getPosY() + 1, T->getPosX() + 1, true);
                    }

                    printBoolMatrix(stdscr, cl.occupiedMatrix);
                }
            playGrill.borderscreen();

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
