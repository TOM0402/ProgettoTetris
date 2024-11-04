#include "Engine.hpp"
#include "../Collisioni/CollisioniNuovo.hpp"
#include "../Tetramino/TetraminoNuovo.hpp"
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
    init_pair(8,COLOR_GREEN, COLOR_GREEN);
}

bool Engine::setup() {
    Home home(32,62);
    home.printLogo();
    home.borderscreen();
    int a =home.menu();
    return a;
}

void Engine::initBoard() {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            board[y][x] = '.';
        }
    }
}


/*

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

}*/
//----------------------------------------------------------------------------------------------

TetraminoNuovo* Engine::createTetramino() {
    TetraminoNuovo* t;
    int index = rand() % 7;
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 5; ++x) {
            t->setShape(y,x,t->getTetramini(index, y, x));
        }
    }
    t->setX(GRID_WIDTH / 2 - 2); // Center the tetromino
    t->setY(0); // Start at the top
    t->setColor(index + 1); // Assign color based on tetromino index (1-7)
    return t;
}

void Engine::drawNextTetramino( TetraminoNuovo* t) {
    werase(nextWin);
    attron(COLOR_PAIR(t->getColor()));  // Use the color assigned to the tetromino
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t->getShape(x,y) == 'X') {
                mvwprintw(nextWin, y, 2 * x, "XX");
            }
        }
    }
    attroff(COLOR_PAIR(t->getColor()));  // Turn off the color attribute
    wrefresh(nextWin);
}

void Engine::rotateTetramino() {
    char temp[4][5]; //matrice temporanea per salvare il tetramino ruotato
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            temp[x][3 - y] = currentTetramino->getShape(y,x); // Rotate the tetromino
        }
    }
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 5; ++x) {
            currentTetramino->setShape(y,x, temp[y][x]);
        }
    }
}

void Engine::placeTetramino() {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (currentTetramino->getShape(y,x) == 'X') {
                board[currentTetramino->getY() + y][currentTetramino->getX()+ x] = 'X';
            }
        }
    }
}

//AUMENTA IL PUNTEGGIO
int Engine::clearLines() {
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


bool Engine::moving(int ch, int &punteggio){
    bool gameOver = false; // Variabile flag per indicare la fine del gioco

    switch (ch) {
        case 'q':
            gameOver = true; // Imposta il flag a true per indicare che il gioco è finito
            break;
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
                placeTetramino();
                punteggio += clearLines();
                currentTetramino = nextTetramino;
                nextTetramino = createTetramino();
                if (C->checkCollisioni(board, currentTetramino)) {
                    gameOver = true; // Game over
                }
            }
            break;
        case 'w': // Rotate
        case KEY_UP:
            rotateTetramino();
            if (C->checkCollisioni(board, currentTetramino)) {
                rotateTetramino();
                rotateTetramino();
            }
            break;
    }

    if (gameOver) {
        delwin(gameWin);
        delwin(nextWin);
        endwin();
    }
    return gameOver; // Restituisce true se il gioco è finito, false altrimenti
}

void Engine::play(Game playGrill) {
    int ch;
    mvwprintw(playGrill.getScreen(), playGrill.getWide()/2,3 ,"premi un tasto");
    wrefresh(playGrill.getScreen());
    wgetch(playGrill.getScreen());
    mvwprintw(playGrill.getScreen(), playGrill.getWide()/2,3 ,"              ");
    wrefresh(playGrill.getScreen());

    //Finestra per il gioco
    WINDOW *gameWin = newwin(GRID_HEIGHT, GRID_WIDTH * 2 + 10, 0, 0);
    WINDOW *nextWin = newwin(4, 8, 0, GRID_WIDTH * 2 + 2); // Finestra per il prossimo tetramino

    char board[GRID_HEIGHT][GRID_WIDTH];
    initBoard();

    TetraminoNuovo* currentTetramino = createTetramino();
    TetraminoNuovo* nextTetramino = createTetramino(); // PROSSIMO TETRAMINO
    CollisioniNuovo* C;
    int punteggio = 0;

    bool gameRunning = true;
    while (gameRunning) {
        playGrill.borderscreen(gameWin, board, punteggio); // Pass score to drawBoard
        drawNextTetramino(nextTetramino); // Draw the next tetromino
        ch = getch();
        gameRunning = !moving(ch, punteggio);
    }
}

/*Usare con:
 *
    bool gameRunning = true;
    while (gameRunning) {
        int ch = getch();
        gameRunning = !moving(ch, gameWin, nextWin, currentTetramino, nextTetramino, board, C, punteggio);
    }
*/