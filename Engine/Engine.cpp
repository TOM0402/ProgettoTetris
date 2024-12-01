#include "Engine.hpp"
#include "iostream"
#include "ctime"
using namespace std;
Engine::Engine() {
    char filename[] = "classifica.txt";
    classificaHandler = new HandlerClassifica(filename);
    init();
}

void Engine::init() {
    srand(time(NULL));
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
    t->setX(GRID_WIDTH / 2 - 2); // Center the tetromino
    t->setY(1); // Start at the top
    t->setColor(index + 7); // Assign color based on tetromino index (1-7)
    return t;
}

void Engine::printBoard() {
    for (int i = 0; i < GRID_HEIGHT; ++i) {
        for (int j = 0; j < GRID_WIDTH; ++j) {
            if(board[i][j] != '.') {
                wattron(stdscr, COLOR_PAIR(board[i][j])); // Usa il colore salvato nella board
                mvwprintw(stdscr, i, 2*j+1, "XX");
                wattroff(stdscr, COLOR_PAIR(board[i][j]));
            } else {
                mvwprintw(stdscr, i, 2*j+1, "  ");
            }
        }
        wrefresh(stdscr);
    }
}



//AUMENTA IL PUNTEGGIO
int Engine::clearLines() {
    int linesCleared = 0;
    for (int y = GRID_HEIGHT - 1; y >= 0; --y) {
        bool lineaPiena = true;
        for (int x = 0; x < GRID_WIDTH; ++x) {
            if (board[y][x] == '.') {
                lineaPiena = false;
                break;
            }
        }
        if (lineaPiena) {
            linesCleared++; // Conta le linee pulite
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
    if (linesCleared > 0) {
        scoreManager.addLinesClearedPoints(linesCleared);
    }
    return linesCleared;
}

void Engine::updateSideBar() {
    if (sideBar != nullptr) {
        sideBar->printScores(scoreManager.getScore(), scoreManager.getLevel());
    }
    sideBar->borderscreen();
}

bool Engine::moving(int ch, int &punteggio, bool isAutomatic) {
    bool gameOver = false;
    switch (ch) {
        case 'q':
            gameOver = true;
            break;
        case 'a':
        case KEY_LEFT:
            currentTetramino->setX(currentTetramino->getX()-1);
            if (C->checkCollisioni(board, currentTetramino)) currentTetramino->setX(currentTetramino->getX()+1);
            break;
        case 'd':
        case KEY_RIGHT:
            currentTetramino->setX(currentTetramino->getX()+1);
            if (C->checkCollisioni(board, currentTetramino)) currentTetramino->setX(currentTetramino->getX()-1);
            break;
        case 's':
        case KEY_DOWN:
            currentTetramino->setY(currentTetramino->getY()+1);
            if (C->checkCollisioni(board, currentTetramino)) {
                currentTetramino->setY(currentTetramino->getY()-1);
                currentTetramino->placeTetramino(board, currentTetramino);

                clearLines();
                punteggio = scoreManager.getScore();
                updateSideBar();

                currentTetramino = nextTetramino;
                nextTetramino = createTetramino();

                if (C->checkCollisioni(board, currentTetramino)) {
                    gameOver = true;
                }
            } else if (!isAutomatic) {
                scoreManager.addSoftDropPoints(1);
                punteggio = scoreManager.getScore();
                updateSideBar();
            }
            break;
        case 'w':
        case KEY_UP:
            currentTetramino->rotateTetramino(currentTetramino);
            if (C->checkCollisioni(board, currentTetramino)) {
                currentTetramino->setX(currentTetramino->getX() + 1);
                if (C->checkCollisioni(board, currentTetramino)) {
                    currentTetramino->setX(currentTetramino->getX() - 2);
                    if (C->checkCollisioni(board, currentTetramino)) {
                        currentTetramino->setX(currentTetramino->getX() + 1);
                        currentTetramino->rotateTetramino(currentTetramino);
                        currentTetramino->rotateTetramino(currentTetramino);
                        currentTetramino->rotateTetramino(currentTetramino);
                    }
                }
            }
            break;
        case ' ': // Spazio per hard drop
            int cellsMoved = 0;
            while (!C->checkCollisioni(board, currentTetramino)) {
                currentTetramino->setY(currentTetramino->getY()+1);
                cellsMoved++;
            }
            currentTetramino->setY(currentTetramino->getY()-1);
            if (cellsMoved > 0) {
                scoreManager.addHardDropPoints(cellsMoved - 1); // -1 perché l'ultima mossa viene annullata
                punteggio = scoreManager.getScore();
                updateSideBar();
            }
            currentTetramino->placeTetramino(board, currentTetramino);
            clearLines(); // Questo aggiunge punti per le linee completate
            punteggio = scoreManager.getScore(); // Aggiorna il punteggio dopo il clearLines
            updateSideBar(); // Aggiorna la sidebar con il punteggio finale

            currentTetramino = nextTetramino;
            nextTetramino = createTetramino();
            if (C->checkCollisioni(board, currentTetramino)) {
                gameOver = true;
            }
            break;
    }

    return gameOver;
}

void Engine::play(Game playGrill, NextT next, SideBar& sidebar) {
    sideBar = &sidebar;
    int ch;
    mvwprintw(playGrill.getScreen(), playGrill.getWide()/2,3 ,"premi un tasto");
    wrefresh(playGrill.getScreen());
    wgetch(playGrill.getScreen());
    mvwprintw(playGrill.getScreen(), playGrill.getWide()/2,3 ,"                 ");
    wrefresh(playGrill.getScreen());

    gameWin = playGrill.getScreen();
    nextWin = next.getScreen();

    initBoard();
    scoreManager.resetScore();
    updateSideBar();

    currentTetramino = createTetramino();
    nextTetramino = createTetramino();
    C = new CollisioniNuovo;

    time_t tempo_ultima = time(0);
    int velocità_caduta = 100;
    int punteggio = 0;
    nodelay(stdscr, TRUE);
    bool gameRunning = true;
    int last_pos_x, last_pos_y;
    

    while (gameRunning) {
        last_pos_x = currentTetramino->getX();
        last_pos_y = currentTetramino->getY();
        ch = getch();
        if (ch != ERR) {
            gameRunning = !moving(ch, punteggio, false);
        }
        time_t tempo_corrente = time(0);
        if (difftime(tempo_corrente, tempo_ultima) >= (double)velocità_caduta / 100.0) {
            gameRunning = !moving(KEY_DOWN, punteggio, true);
            tempo_ultima = tempo_corrente;
        }
        if(last_pos_x != currentTetramino->getX() || last_pos_y != currentTetramino->getY()) {
            playGrill.borderscreen(playGrill.getScreen(), board, punteggio);
            next.drawNextTetramino(nextTetramino);
            next.borderscreen();
            wattron(gameWin, COLOR_PAIR(currentTetramino->getColor()));
            for (int y = 0; y < 4; ++y) {
                for (int x = 0; x < 4; ++x) {
                    if (currentTetramino->getShape(y,x) == 'X') {
                        int displayX = currentTetramino->getX() + x;
                        int displayY = currentTetramino->getY() + y;
                        if (displayY >= 0 && displayY < GRID_HEIGHT &&
                            displayX >= 0 && displayX < GRID_WIDTH) {
                            mvwprintw(gameWin, displayY, 2 * displayX + 1, "XX");
                        }
                    }
                }
            }
            wattroff(gameWin, COLOR_PAIR(currentTetramino->getColor()));
            wrefresh(gameWin);
        }
    }

    // Prima liberiamo la memoria
    delete C;
    delete currentTetramino;
    delete nextTetramino;

    // Poi gestiamo il game over
    nodelay(stdscr, FALSE); // Riattiva l'input bloccante
    
    // Creiamo un oggetto Giocatore con i dati attuali
    Giocatore g;
    g.setNome(sidebar.getPlayerName());
    g.setPunteggio(scoreManager.getScore());
    classificaHandler->aggiungi(g);

    GameOver gameover(20,40);
    gameover.printLogo();
    gameover.borderscreen();
    int choice = gameover.menu();
    
    clear();
    refresh();
    
    if (choice == 0) { // Quit
        endwin(); // Chiamiamo endwin() solo una volta prima di uscire
        exit(0);
    } else { // Home
        run();
    }
}

void Engine::startGame(char* playerName) {
    // Se classificaHandler non è stato ancora inizializzato
    if (classificaHandler == nullptr) {
        char filename[] = "classifica.txt";
        classificaHandler = new HandlerClassifica(filename);
    }
    
    SideBar sideGrill(22, 22, playerName);
    NextT next(22/2, 22);
    Game playGrill(22, 22);
    
    playGrill.borderscreen();
    sideGrill.borderscreen();
    sideGrill.printScores(0, 1);

    play(playGrill, next, sideGrill);
}

void Engine::showLeaderboard() {
    Leaderboard lead(27, 46);
    lead.borderscreen();
    lead.printLead();
    
    // Aspetta che l'utente prema ENTER per tornare al menu
    int ch;
    while ((ch = getch()) != '\n' && ch != KEY_ENTER) {
        // Continua ad aspettare finché non viene premuto ENTER
    }
    
    clear();
    run(); // Torna al menu principale
}

void Engine::run() {
    Home home(28, 62);
    home.printLogo();
    home.borderscreen();
    int choice = home.menu();

    clear();
    
    if (choice == 0) {
        Name insName(5, 34);
        insName.borderscreen();
        insName.insert();
        char* playerName = insName.getName();
        
        clear();
        startGame(playerName);
    }
    else {
        showLeaderboard();
    }
}



