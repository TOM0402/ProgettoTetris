#include "GestionePezzi.hpp"
#include "Tetramino.hpp"
#include "TetraminoLungo.hpp"
#include "TetraminoQuadrato.hpp"
#include "../Screen/Game.hpp"

TetraminoQuadrato *tq;
TetraminoLungo *tl;
CollisioniLungo cl = CollisioniLungo();
CollisioniQuadrato cq = CollisioniQuadrato();
int ch;

int GestionePezzi::generateRandom() {
    srand(time(0));
    return rand() % 2;
}





void GestionePezzi::game(Game playGrill) {
    while ((ch = getch()) != 'q') {
        moving(playGrill);
    }
}
int GestionePezzi::moving(Game playGrill) {
    if(generateRandom()==1) {
        bool stop=false;
        while (!stop) {
            ch = getch();
            tl = new TetraminoLungo();
            tl->spawnTetramino(playGrill, cl);
            tl->moveTetramino(tl, cl, ch, playGrill.getScreen());
            if (!cl.checkDownL(tl->getPosY() + 1, tl->getPosX())) {     //QUANDO ARRIVO IN FONDO SPAWN NUOVO TETRAMINO
                stop = true;
                //printBoolMatrix(stdscr, cl.occupiedMatrix);
            }
            //printBoolMatrix(stdscr, cl.occupiedMatrix);
            wrefresh(playGrill.getScreen());
        }

            return tl->getPosX();
    }else{
        bool stop=false;
        while (!stop) {
            ch=getch();
            tq = new TetraminoQuadrato();
            tq->spawnTetramino(playGrill, cq);
            tq->moveTetramino(tq, cq, ch, playGrill.getScreen());
            if (cq.checkDownQ(tq->getPosY() + 1, tq->getPosX())) {     //QUANDO ARRIVO IN FONDO SPAWN NUOVO TETRAMINO
                //printBoolMatrix(stdscr, cl.occupiedMatrix);
                stop=true;
            }
            //printBoolMatrix(stdscr, cl.occupiedMatrix);
            wrefresh(playGrill.getScreen());
        }
        return tq->getPosY();
    }

}

    srand(time(0));
    for (int i = 0; i < 5; i++) {
        if(rand()%2==0) {
            //Lungo
            Tetramino t;
            t = new TetraminoQuadrato();

            TetraminoLungo tmp = new TetraminoLungo();
            append(tmp);

        }else{
            //quadrato
            append(new TetraminoQuadrato());
        }
    }

}

p_list GestionePezzi::append(Tetramino t) {
    if(pezzi==NULL){
        //TODO assegnare correttamente valore al nuovo tetramino
        pezzi->next=NULL;
    }else {
        p_list p = pezzi;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new list;
        p = p->next;
        p->t() = t;
        p->next = NULL;
    }
    return pezzi;

}

p_list GestionePezzi::remove() {
    if (this->pezzi != nullptr) {
        p_list temp = pezzi;
        pezzi = pezzi->next;
        delete temp;
    }
}

/*
mvwprintw(playGrill.getScreen(), 10, 1, "                ");
            //pezzo=r.pezzo();
            mvwprintw(stdscr, 60, 1, " prima ");
                if (pezzo) { // Lungo
                mvwprintw(stdscr, 61, 1, " dopo ");
                        T=new TetraminoLungo(playGrill);
                        mvwprintw(stdscr, 49, 1, " if vero ");
                        mvwprintw(stdscr, 50, 1, to_string(T->getPosY()).c_str());
                        T->spawnTetramino(playGrill, cl);
                    bool down= true;
                    T->moveTetramino(T, cl, ch, playGrill.getScreen());
                    while(down){
                        mvwprintw(stdscr, 55, 1, " sotto è libero");
                        if(getch() == 'codifica della fraccia giù')

                        down=cl.checkDownL(T->getPosY() + 1, T->getPosX());
                    }
                            cl.setMatrix(T->getPosY(), T->getPosX(), true);
                            cl.setMatrix(T->getPosY(), T->getPosX() + 1, true);
                            cl.setMatrix(T->getPosY(), T->getPosX() + 2, true);
                            cl.setMatrix(T->getPosY(), T->getPosX() + 3, true);

                        printBoolMatrix(stdscr, cl.occupiedMatrix);
                        playGrill.borderscreen();

                    }
                } else { // Quadrato
                    T=new TetraminoQuadrato(playGrill);
                    mvwprintw(stdscr, 49, 1, " if falso ");
                    mvwprintw(stdscr, 50, 1, to_string(T->getPosY()).c_str());
                    T->spawnTetramino(playGrill, cq);
                    bool down=cq.checkDownQ(T->getPosY() + 2,T->getPosX());
                    if(down){
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
*/
/*while ((ch = getch()) != 'q') {
            T1->moveTetramino(T1, c, ch, playGrill.getScreen());
            printBoolMatrix(stdscr, c.occupiedMatrix);
            if(T1->getPosY()==GRID_HIGH-2){     //QUANDO ARRIVO IN FONDO SPAWN NUOVO TETRAMINO
                T1 = new TetraminoQuadrato(playGrill);
                T1->spawnTetramino(playGrill, c);
                printBoolMatrix(stdscr, c.occupiedMatrix);
            }
            printBoolMatrix(stdscr, c.occupiedMatrix);
            wrefresh(playGrill.getScreen());

        }*/