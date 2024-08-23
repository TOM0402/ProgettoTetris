#include "Engine.hpp"

Engine::Engine() {
    init();
}

void Engine::init() {
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

bool Engine::setup() {
    Home home(32,62);
    home.printLogo();
    home.borderscreen();
    return home.menu();
}

int Engine::generateRandom() {
    srand(time(0));
    return rand() % 2;
}

void Engine::play(Game playGrill) {
    int ch;
    while ((ch = getch()) != 'q') {
        moving(playGrill, ch);
        playGrill.borderscreen();
    }
}
int Engine::moving(Game playGrill, int ch) {
    if(generateRandom()==1) {
        bool stop=false;
        while (!stop) {
            ch = getch();
            tl = new TetraminoLungo();
            tl->spawnTetramino(playGrill);
            tl->moveTetramino(tl, cl, ch, playGrill.getScreen());
            if (!cl.checkDownL(tl->getPosY() + 1, tl->getPosX(), tl->getOrientamento())) {     //QUANDO ARRIVO IN FONDO SPAWN NUOVO TETRAMINO
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
            tq->spawnTetramino(playGrill);
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