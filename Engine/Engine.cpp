#include "Engine.hpp"
#include "../Collisioni/CollisioniNuovo.hpp"
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
//----------------------------------------------------------------------------------------------
/*
TetraminoNuovo createTetramino() {
    TetraminoNuovo t;
    int index = rand() % 7;
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 5; ++x) {
            t.setShape(y,x,t.getTetramini(index, y, x));
        }
    }
    t.setX(GRID_WIDTH / 2 - 2); // Center the tetromino
    t.setY(0); // Start at the top
    t.setColor(index + 1); // Assign color based on tetromino index (1-7)
    return t;
}

void drawNextTetramino(WINDOW *win, TetraminoNuovo* t) {
    werase(win);
    attron(COLOR_PAIR(t->getColor()));  // Use the color assigned to the tetromino
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t->getShape(x,y) == 'X') {
                mvwprintw(win, y, 2 * x, "XX");
            }
        }
    }
    attroff(COLOR_PAIR(t->getColor()));  // Turn off the color attribute
    wrefresh(win);
}

void rotateTetramino(TetraminoNuovo* t) {
    char temp[4][5]; //matrice temporanea per salvare il tetramino ruotato
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            temp[x][3 - y] = t->getShape(y,x); // Rotate the tetromino
        }
    }
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 5; ++x) {
            t->setShape(y,x, temp[y][x]);
        }
    }
}

void placeTetramino(char board[GRID_HEIGHT][GRID_WIDTH], TetraminoNuovo* t) {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t->getShape(y,x) == 'X') {
                board[t->getY() + y][t->getX()+ x] = 'X';
            }
        }
    }
}

//AUMENTA IL PUNTEGGIO
int clearLines(char board[GRID_HEIGHT][GRID_WIDTH]) {
    int punteggio = 0;
    for (int y = GRID_HEIGHT - 1; y >= 0; --y) {
        bool lineaPiena = true;
        for (int x = 0; x < GRID_WIDTH; ++x) {
            if (board[y][x] == '.') {
                lineaPiena = false;
                break;
            }
        }
        if (lineaPiena) {
            punteggio++; // Incrementa il punteggio
            // CANCELLA LA LINEA
            for (int i = y; i > 0; --i) {
                for (int x = 0; x < GRID_WIDTH; ++x) {
                    board[i][x] = board[i - 1][x];
                }
            }
            for (int x = 0; x < GRID_WIDTH; ++x) {
                board[0][x] = '.';
            }
            ++y; // Check the same line again after shifting down
        }
    }
    return punteggio; // Return the total score for cleared lines
}


void moving(int ch, WINDOW* gameWin, WINDOW* nextWin, TetraminoNuovo* currentTetramino, TetraminoNuovo* nextTetramino, char board[GRID_HEIGHT][GRID_WIDTH], CollisioniNuovo* C, int punteggio){
    switch (ch) {
        case 'q':
            delwin(gameWin);
            delwin(nextWin);
            endwin();
            return 0; // Exit on 'q' key
        case 'a': // Move left
        case KEY_LEFT:
            currentTetramino->setX(currentTetramino->getX()-1);
            if (C->checkCollisioni(board, currentTetramino)) currentTetramino->setX(currentTetramino->getX()+1);
            break;
        case 'd': // Move right
        case KEY_RIGHT:
            currentTetramino->setX(currentTetramino->getX()+1);
            if (C->checkCollisioni(board, currentTetramino)) currentTetramino->setX(currentTetramino->getX()-1);
            break;
        case 's': // Move down
        case KEY_DOWN:
            currentTetramino->setY(currentTetramino->getY()+1);
            if (C->checkCollisioni(board, currentTetramino)) {
                currentTetramino->setY(currentTetramino->getY()-1);
                placeTetramino(board, currentTetramino);
                punteggio += clearLines(board); // Aumenta il punteggio ed elimina le righe
                currentTetramino = nextTetramino; // Il prossimo tetramino, diventa il corrente
                nextTetramino = createTetramino(); // Genero il prossimo tetramino
                if (C->checkCollisioni(board, currentTetramino)) {
                    // Game over
                    delwin(gameWin);
                    delwin(nextWin);
                    endwin();
                    return 0;
                }
            }
            break;
        case 'w': // Rotate
        case KEY_UP:
            rotateTetromino(currentTetramino);
            if (C->checkCollisioni(board, currentTetramino)) {
                // If collision occurs, revert the rotation
                rotateTetramino(currentTetramino); // Rotate back
                rotateTetramino(currentTetramino); // Rotate back again (180 degrees)
            }
            break;
    }
}*/