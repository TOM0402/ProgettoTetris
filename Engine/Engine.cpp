#include "Engine.hpp"
#include "iostream"
using namespace std;
Engine::Engine() {
    init();
}

void Engine::init() {
    initscr(); // Inizializza la libreria curses
    noecho(); // Disabilita l'echo delle caratteri
    curs_set(0); // Nasconde il cursore
    keypad(stdscr, TRUE); // Abilita la lettura delle tasti speciali
    //timeout(100); // Imposta un timeout per la lettura delle tasti
    start_color();

    init_pair(1,COLOR_RED,COLOR_BLACK);
    init_pair(2,COLOR_BLUE,COLOR_BLACK);
    init_pair(3,COLOR_YELLOW,COLOR_BLACK);
    init_pair(4,COLOR_GREEN,COLOR_BLACK);
    init_pair(5,COLOR_CYAN,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);

    init_pair(7,COLOR_RED, COLOR_RED);
    init_pair(8,COLOR_GREEN, COLOR_GREEN);
    init_pair(9,COLOR_BLUE, COLOR_BLUE);
    init_pair(10,COLOR_YELLOW, COLOR_YELLOW);
    init_pair(11,COLOR_CYAN, COLOR_CYAN);
    init_pair(12,COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(13,COLOR_WHITE, COLOR_WHITE);
}
/*
bool Engine::setup() {
    Home home(32,62);
    home.printLogo();
    home.borderscreen();
    int a =home.menu();
    return a;
}*/

void Engine::initBoard() {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            board[y][x] = '.';
        }
    }
}

TetraminoNuovo* Engine::createTetramino() {
    TetraminoNuovo* t=new TetraminoNuovo();
    int index = rand() % 7;
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            t->setShape(y,x,t->getTetramini(index, y, x));
        }
    }
    t->setX(GRID_WIDTH / 2 -2); // Center the tetromino
    t->setY(1); // Start at the top
    t->setColor(index + 7); // Assign color based on tetromino index (1-7)
    return t;
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

                currentTetramino->placeTetramino(board, currentTetramino); //placeTetramino va implementato anche visualmente (credo)

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
            currentTetramino->rotateTetramino(currentTetramino);
            if (C->checkCollisioni(board, currentTetramino)) {
                currentTetramino->rotateTetramino(currentTetramino);
                currentTetramino->rotateTetramino(currentTetramino);
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

void Engine::play(Game playGrill, NextT next) {
    int ch;
    mvwprintw(playGrill.getScreen(), playGrill.getWide()/2,3 ,"premi un tasto");
    wrefresh(playGrill.getScreen());
    wgetch(playGrill.getScreen());
    mvwprintw(playGrill.getScreen(), playGrill.getWide()/2,3 ,"                 ");
    wrefresh(playGrill.getScreen());

    //Finestra per il gioco
    WINDOW *gameWin = playGrill.getScreen();

    char board[GRID_HEIGHT][GRID_WIDTH];
    initBoard();

    currentTetramino = createTetramino();
    nextTetramino = createTetramino(); // PROSSIMO TETRAMINO
    C= new CollisioniNuovo;
    GameOver gameover(20,40);
    int punteggio = 0;

    bool gameRunning = true;
    while (gameRunning) {
        playGrill.borderscreen(playGrill.getScreen(), board, punteggio); // Pass score to drawBoard
        next.drawNextTetramino(nextTetramino); // Draw the next tetromino

        wattron(gameWin, COLOR_PAIR(currentTetramino->getColor()));  // Apply the color for the current tetromino
        for (int y = 0; y < 4; ++y) {
            for (int x = 0; x < 4; ++x) {
                if (currentTetramino->getShape(y,x) == 'X') {
                    mvwprintw(gameWin, currentTetramino->getY() + y, 2 * (currentTetramino->getX() + x)-1, "XX");
                }
            }
        }
        wattroff(gameWin, COLOR_PAIR(currentTetramino->getColor()));  // Turn off the color
        wrefresh(gameWin);

        ch = getch();
        gameRunning = !moving(ch, punteggio);

    }

    gameover.printLogo();
    gameover.borderscreen();
    int s2 =gameover.menu();
}



/*Usare con:
 *
    bool gameRunning = true;
    while (gameRunning) {
        int ch = getch();
        gameRunning = !moving(ch, gameWin, nextWin, currentTetramino, nextTetramino, board, C, punteggio);
    }
*/