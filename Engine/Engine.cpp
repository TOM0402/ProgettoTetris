#include "Engine.hpp"
#include "ctime"
using namespace std;
Engine::Engine() {
    char filename[] = "classifica.txt";
    leaderboardHandler = new HandlerLeaderboard(filename);
    init();
}

void Engine::init() {
    srand(time(NULL));
    initscr(); // Initialize the ncurses library
    noecho(); // Disable character echoing
    curs_set(0); // Hides the cursor
    keypad(stdscr, TRUE); // Enable reading of special keys
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

void Engine::initBoard() {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            board[y][x] = '.';
        }
    }
}

Tetramino* Engine::createTetramino() {
    Tetramino* t=new Tetramino();
    int index = rand() % 7;
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            t->setShape(y,x,t->getTetramini(index, y, x));
        }
    }
    t->setX(GRID_WIDTH / 2 - 2);
    t->setY(1);
    t->setColor(index + 7);
    return t;
}


//Increas the score
int Engine::clearLines() {
    int linesCleared = 0;
    for (int y = GRID_HEIGHT - 1; y >= 0; --y) {
        bool full_line = true;
        for (int x = 0; x < GRID_WIDTH; ++x) {
            if (board[y][x] == '.') {
                full_line = false;
                break;
            }
        }
        if (full_line) {
            linesCleared++;
            // remove line
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

bool Engine::moving(int ch, int &score, bool isAutomatic) {
    bool gameOver = false;
    switch (ch) {
        case 'q':
            gameOver = true;
            break;
        case 'a':
        case KEY_LEFT:
            currentTetramino->setX(currentTetramino->getX()-1);
            if (currentTetramino->checkCollisioni(board, currentTetramino)) currentTetramino->setX(currentTetramino->getX()+1);
            break;
        case 'd':
        case KEY_RIGHT:
            currentTetramino->setX(currentTetramino->getX()+1);
            if (currentTetramino->checkCollisioni(board, currentTetramino)) currentTetramino->setX(currentTetramino->getX()-1);
            break;
        case 's':
        case KEY_DOWN:
            currentTetramino->setY(currentTetramino->getY()+1);
            if (currentTetramino->checkCollisioni(board, currentTetramino)) {
                currentTetramino->setY(currentTetramino->getY()-1);
                currentTetramino->placeTetramino(board, currentTetramino);

                clearLines();
                score = scoreManager.getScore();
                updateSideBar();

                currentTetramino = nextTetramino;
                nextTetramino = createTetramino();

                if (currentTetramino->checkCollisioni(board, currentTetramino)) {
                    gameOver = true;
                }
            } else if (!isAutomatic) {
                scoreManager.addSoftDropPoints(1);
                score = scoreManager.getScore();
                updateSideBar();
            }
            break;
        case 'w':
        case KEY_UP:
            currentTetramino->rotateTetramino(currentTetramino);
            if (currentTetramino->checkCollisioni(board, currentTetramino)) {
                currentTetramino->setX(currentTetramino->getX() + 1);
                if (currentTetramino->checkCollisioni(board, currentTetramino)) {
                    currentTetramino->setX(currentTetramino->getX() - 2);
                    if (currentTetramino->checkCollisioni(board, currentTetramino)) {
                        currentTetramino->setX(currentTetramino->getX() + 1);
                        currentTetramino->rotateTetramino(currentTetramino);
                        currentTetramino->rotateTetramino(currentTetramino);
                        currentTetramino->rotateTetramino(currentTetramino);
                    }
                }
            }
            break;
        case ' ': // space for hard drop
            int cellsMoved = 0;
            while (!currentTetramino->checkCollisioni(board, currentTetramino)) {
                currentTetramino->setY(currentTetramino->getY()+1);
                cellsMoved++;
            }
            currentTetramino->setY(currentTetramino->getY()-1);
            if (cellsMoved > 0) {
                scoreManager.addHardDropPoints(cellsMoved - 1); // -1 last move cancelled
                score = scoreManager.getScore();
                updateSideBar();
            }
            currentTetramino->placeTetramino(board, currentTetramino);
            clearLines(); // Adds points for completed lines
            score = scoreManager.getScore(); // Update score
            updateSideBar(); // Update the sidebar with the new score

            currentTetramino = nextTetramino;
            nextTetramino = createTetramino();
            if (currentTetramino->checkCollisioni(board, currentTetramino)) {
                gameOver = true;
            }
            break;
    }

    return gameOver;
}

void Engine::play(Screen playGrill, NextT next, SideBar& sidebar) {
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

    time_t last_time = time(0);
    int fall_speed = 100;
    int score = 0;
    nodelay(stdscr, TRUE);
    bool gameRunning = true;
    int last_pos_x, last_pos_y;


    while (gameRunning) {
        last_pos_x = currentTetramino->getX();
        last_pos_y = currentTetramino->getY();
        ch = getch();
        if (ch != ERR) {
            gameRunning = !moving(ch, score, false);
        }
        time_t current_time = time(0);
        if (difftime(current_time, last_time) >= (double)fall_speed / 100.0) {
            gameRunning = !moving(KEY_DOWN, score, true);
            last_time = current_time;
        }
        if(last_pos_x != currentTetramino->getX() || last_pos_y != currentTetramino->getY()) {
            playGrill.borderscreen(playGrill.getScreen(), board, score);
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

    // let's free our memory
    delete currentTetramino;
    delete nextTetramino;

    // manage the game over
    nodelay(stdscr, FALSE); // Re-enable blocking input
    
    //Player
    Player g;
    g.setName(sidebar.getPlayerName());
    g.setPoints(scoreManager.getScore());
    leaderboardHandler->add_player(g);

    GameOver gameover(20,40);
    gameover.printLogo();
    gameover.borderscreen();
    int choice = gameover.menu();
    
    clear();
    refresh();
    
    if (choice == 0) {
        endwin();
        exit(0);
    } else {
        run();
    }
}

void Engine::startGame(char* playerName) {
    // if leaderboardHandler is not initialized yet
    if (leaderboardHandler == nullptr) {
        char filename[] = "leaderboard.txt";
        leaderboardHandler = new HandlerLeaderboard(filename);
    }
    
    SideBar sideGrill(22, 22, playerName);
    NextT next(22/2, 22);
    Screen playGrill(22, 22);
    
    playGrill.borderscreen();
    sideGrill.borderscreen();
    sideGrill.printScores(0, 1);

    play(playGrill, next, sideGrill);
}

void Engine::showLeaderboard() {
    Leaderboard lead(27, 46);
    lead.borderscreen();
    lead.printLead();

    int ch;
    while ((ch = getch()) != '\n' && ch != KEY_ENTER) {
        // It waits till ch is ENTER
    }
    
    clear();
    run(); // Back to home menu
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



