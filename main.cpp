#include "fileManagement/file.hpp"
#include <ncurses.h>
//#include <stdlib.h>
#include <vector>
#include "Collisioni/Collisioni.hpp"
#include "Collisioni/CollisioniLungo.hpp"
#include "Collisioni/CollisioniQuadrato.hpp"
#include "Screen/Home.hpp"
#include "Screen/Game.hpp"
#include "Screen/Leaderboard.hpp"
#include "Screen/Name.hpp"
#include "Tetramino/TetraminoQuadrato.hpp"
#include "Screen/SideBar.hpp"
#include "Engine/Engine.hpp"

using namespace std;

void printBoolMatrix(WINDOW* win, const bool matrix[22][22]) {
    for (int i = 0; i < 22; ++i) {
        for (int j = 0; j < 22; ++j) {
            mvwaddch(win, i, j * 2, (matrix[i][j] ? '1' : '0'));
        }
    }
    wrefresh(win); // Aggiorna la finestra per visualizzare il contenuto
}


int main() {

    Engine engine();

    /*
    Home home(32,62);
    home.printLogo();
    home.borderscreen();
    int s=home.menu();
    */

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
            //pezzo=r.pezzo();
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
                        cq.setMatrix(T->getPosY(), T->getPosX() + 2, true);
                        cq.setMatrix(T->getPosY(), T->getPosX() + 3, true);
                        cq.setMatrix(T->getPosY() + 1, T->getPosX(), true);
                        cq.setMatrix(T->getPosY() + 1, T->getPosX() + 1, true);
                        cq.setMatrix(T->getPosY() + 1, T->getPosX() + 2, true);
                        cq.setMatrix(T->getPosY() + 1, T->getPosX() + 3, true);
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