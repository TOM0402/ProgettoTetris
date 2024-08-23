#include "Engine.hpp"
#include <vector>
Engine::Engine() {
    init();
}

void printBoolMatrix(WINDOW* win, const bool matrix[22][22]) {
    for (int i = 0; i < 22; ++i) {
        for (int j = 0; j < 22; ++j) {
            mvwaddch(win, i, j * 2, (matrix[i][j] ? '1' : '0'));
        }
    }
    wrefresh(win); // Aggiorna la finestra per visualizzare il contenuto
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
    init_pair(8,COLOR_GREEN, COLOR_GREEN);
}

bool Engine::setup() {
    Home home(32,62);
    home.printLogo();
    home.borderscreen();
    int a =home.menu();
    return a;
}

int Engine::generateRandom() {
    srand(time(0));
    return rand() % 2;
}

void Engine::play(Game playGrill) {
    int ch;
    mvwprintw(playGrill.getScreen(), playGrill.getWide()/2,3 ,"premi un tasto");
    wrefresh(playGrill.getScreen());
    wgetch(playGrill.getScreen());
    mvwprintw(playGrill.getScreen(), playGrill.getWide()/2,3 ,"              ");
    wrefresh(playGrill.getScreen());

    while ((ch = getch()) != 'q') {
        moving(playGrill, ch);
        playGrill.borderscreen();
    }
}
int Engine::moving(Game playGrill, int ch) {
    if(generateRandom()==1) {
        bool stop=false;
        tl = new TetraminoLungo();
        tl->spawnTetramino(playGrill);
        wrefresh(playGrill.getScreen());
        while (!stop ) {
            ch = getch();
            tl->moveTetramino(tl, cl, ch, playGrill.getScreen());
            if (cl.checkDownL(tl->getPosY() + 1, tl->getPosX(), tl->getOrientamento())) {     //QUANDO ARRIVO IN FONDO SPAWN NUOVO TETRAMINO
                stop = true;
                //printBoolMatrix(stdscr, cl.occupiedMatrix);
            }
            //printBoolMatrix(stdscr, cl.occupiedMatrix);
            wrefresh(playGrill.getScreen());
        }

        return tl->getPosX();
    }else{
        bool stop=false;
        tq = new TetraminoQuadrato();
        tq->spawnTetramino(playGrill);
        while (!stop) {
            ch=getch();
            tq->moveTetramino(tq, cq, ch, playGrill.getScreen());
            if (cq.checkDownQ(tq->getPosY() + 1, tq->getPosX())) {     //QUANDO ARRIVO IN FONDO SPAWN NUOVO TETRAMINO
                printBoolMatrix(stdscr, cl.occupiedMatrix);
                stop=true;
            }
            printBoolMatrix(stdscr, cl.occupiedMatrix);
            wrefresh(playGrill.getScreen());
        }
        return tq->getPosY();
    }

}