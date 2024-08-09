#ifndef PROGETTOTETRIS_RANDOM_HPP
#define PROGETTOTETRIS_RANDOM_HPP

class Random{
public:
    Random();
    bool pezzo();
};

#endif //PROGETTOTETRIS_RANDOM_HPP



/*
 int ch;
        Random r;
        CollisioniLungo cl=CollisioniLungo();
        CollisioniQuadrato cq=CollisioniQuadrato();
        TetraminoQuadrato *TQ= new TetraminoQuadrato(playGrill);
        TetraminoLungo *TL= new TetraminoLungo(playGrill);
        playGrill.borderscreen();
        mvwprintw(playGrill.getScreen(), 1, 1, " ciao ");
        //TL->moveTetraminoL(TL, cl, ch, playGrill.getScreen());
        while ((ch = getch()) != 'q') {
            mvwprintw(playGrill.getScreen(), 1, 1, " entro nel while ");
                if (r.pezzo()) {
                        TL->drawTetraminoL(playGrill.getScreen(), cl);
                    while(cl.checkDownL(TL->getPosY() + 1, TL->getPosX())) {
                        TL->moveTetraminoL(TL, cl, ch, playGrill.getScreen());
                        //printBoolMatrix(stdscr, cq.occupiedMatrix);
                        if (!cl.checkDownL(TL->getPosY() + 1,TL->getPosX())) {//QUANDO ARRIVO IN FONDO SPAWN NUOVO TETRAMINO
                            cl.setMatrix(TL->getPosY(), TL->getPosX(), true);
                            cl.setMatrix(TL->getPosY(), TL->getPosX() + 1, true);
                            cl.setMatrix(TL->getPosY(), TL->getPosX() + 2, true);
                            cl.setMatrix(TL->getPosY(), TL->getPosX() + 3, true);
                            printBoolMatrix(stdscr, cl.occupiedMatrix);
                            /*TL = new TetraminoLungo(playGrill);
                            TL->spawnTetraminoL(playGrill, cl);
                            //printBoolMatrix(stdscr, cq.occupiedMatrix);*//*
                        }
                    }

                } else {
                    TQ->drawTetraminoQ(playGrill.getScreen(), cq);
                    while(cq.checkDownQ(TQ->getPosY() + 1,TQ->getPosX())) {
                        TQ->moveTetraminoQ(TQ, cq, ch, playGrill.getScreen());

                        //printBoolMatrix(stdscr, cq.occupiedMatrix);
                        if (!cq.checkDownQ(TQ->getPosY() + 1,TQ->getPosX())) {//QUANDO ARRIVO IN FONDO SPAWN NUOVO TETRAMINO
                            cq.setMatrix(TQ->getPosY(), TQ->getPosX(), true);
                            cq.setMatrix(TQ->getPosY(), TQ->getPosX() + 1, true);
                            cq.setMatrix(TQ->getPosY() + 1, TQ->getPosX(), true);
                            cq.setMatrix(TQ->getPosY() + 1, TQ->getPosX() + 1, true);
                            //printBoolMatrix(stdscr, cq.occupiedMatrix);
                            /*TQ = new TetraminoQuadrato(playGrill);
                            TL = new TetraminoLungo(playGrill);
                            //TQ->spawnTetraminoQ(playGrill, cq);
                            TL->spawnTetraminoL(playGrill, cl);
                            //printBoolMatrix(stdscr, cq.occupiedMatrix);*//*
                        }
                    }
                }
            playGrill.borderscreen();
        }
 */
