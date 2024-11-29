#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

const int BOARD_WIDTH = 10;  // Doubled width for larger board
const int BOARD_HEIGHT = 20;

// Define tetromino shapes
char tetrominoes[7][4][5] = {
    {"....", "XXXX", "....", "...."},
    {".X..", ".X..", ".XX.", "...."},
    {"..X.", "..X.", ".XX.", "...."},
    {"....", ".XX.", ".XX.", "...."},
    {".XX.", "XX..", "....", "...."},
    {"XX..", ".XX.", "....", "...."},
    {"..X.", ".XXX", "....", "...."}
};

// Tetromino structure
struct Tetromino {
    char shape[4][5];
    int x, y;
    int color;  // Add color for each tetromino
};

// Function to initialize ncurses screen
void init() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand(time(0));
    start_color();  // Start ncurses color functionality

    // Define color pairs (pair numbers must be unique)
    init_pair(1, COLOR_CYAN, COLOR_CYAN);   // Color for I piece
    init_pair(2, COLOR_YELLOW, COLOR_YELLOW); // Color for O piece
    init_pair(3, COLOR_MAGENTA, COLOR_MAGENTA); // Color for T piece
    init_pair(4, COLOR_GREEN, COLOR_GREEN);  // Color for S piece
    init_pair(5, COLOR_RED, COLOR_RED);    // Color for Z piece
    init_pair(6, COLOR_BLUE, COLOR_BLUE);   // Color for J piece
    init_pair(7, COLOR_WHITE, COLOR_WHITE);  // Color for L piece
}
//-------------------------------------------------------------------------------------------------------
// Function to draw the board with doubled width and color
void drawBoard(WINDOW *win, char board[BOARD_HEIGHT][BOARD_WIDTH], int score) {
    werase(win);
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            // Each block is drawn twice horizontally to double the width
            if (board[y][x] == 'X') {
                mvwprintw(win, y, 2 * x, "XX");
            } else {
                mvwprintw(win, y, 2 * x, "  "); // Draw empty spaces
            }
        }
    }
    mvwprintw(win, 0, BOARD_WIDTH * 2 + 2, "Score: %d", score); // Display the score
    wrefresh(win);
}
//--------------------------------------------------------------------------------------------------------
// Function to draw the next tetromino with doubled width and color
void drawNextTetromino(WINDOW *win, Tetromino &t) {
    werase(win);
    attron(COLOR_PAIR(t.color));  // Use the color assigned to the tetromino
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t.shape[y][x] == 'X') {
                mvwprintw(win, y, 2 * x, "XX");
            }
        }
    }
    attroff(COLOR_PAIR(t.color));  // Turn off the color attribute
    wrefresh(win);
}

// Initialize the game board
void initBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            board[y][x] = '.';
        }
    }
}

// Function to create a new tetromino with a random shape and color
Tetromino createTetromino() {
    Tetromino t;
    int index = rand() % 7;
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 5; ++x) {
            t.shape[y][x] = tetrominoes[index][y][x];
        }
    }
    t.x = BOARD_WIDTH / 2 - 2; // Center the tetromino
    t.y = 0; // Start at the top
    t.color = index + 1; // Assign color based on tetromino index (1-7)
    return t;
}

// Function to check for collisions
bool checkCollision(char board[BOARD_HEIGHT][BOARD_WIDTH], Tetromino &t) {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t.shape[y][x] == 'X') {
                int boardX = t.x + x;
                int boardY = t.y + y;
                if (boardX < 0 || boardX >= BOARD_WIDTH || boardY >= BOARD_HEIGHT ||
                    (boardY >= 0 && board[boardY][boardX] == 'X')) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Function to rotate tetromino
void rotateTetromino(Tetromino &t) {
    char temp[4][5]; // Temporary array to hold the rotated shape
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            temp[x][3 - y] = t.shape[y][x]; // Rotate the tetromino
        }
    }
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 5; ++x) {
            t.shape[y][x] = temp[y][x];
        }
    }
}

// Function to place the tetromino on the board
void placeTetromino(char board[BOARD_HEIGHT][BOARD_WIDTH], Tetromino &t) {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t.shape[y][x] == 'X') {
                board[t.y + y][t.x + x] = 'X';
            }
        }
    }
}

// Function to clear completed lines and return score
int clearLines(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    int score = 0;
    for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
        bool fullLine = true;
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            if (board[y][x] == '.') {
                fullLine = false;
                break;
            }
        }
        if (fullLine) {
            score++; // Increment score for each cleared line
            // Clear the line
            for (int i = y; i > 0; --i) {
                for (int x = 0; x < BOARD_WIDTH; ++x) {
                    board[i][x] = board[i - 1][x];
                }
            }
            for (int x = 0; x < BOARD_WIDTH; ++x) {
                board[0][x] = '.';
            }
            ++y; // Check the same line again after shifting down
        }
    }
    return score; // Return the total score for cleared lines
}

int main() {
    init();

    //Finestra per il gioco
    WINDOW *gameWin = newwin(BOARD_HEIGHT, BOARD_WIDTH * 2 + 10, 0, 0);
    WINDOW *nextWin = newwin(4, 8, 0, BOARD_WIDTH * 2 + 2); // Finestra per il prossimo tetramino (doubled)

    char board[BOARD_HEIGHT][BOARD_WIDTH];
    initBoard(board);

    Tetromino currentTetromino = createTetromino();
    Tetromino nextTetromino = createTetromino(); // Initialize the next tetromino

    int score = 0; // Initialize score

    while (true) {
        drawBoard(gameWin, board, score); // Pass score to drawBoard
        drawNextTetromino(nextWin, nextTetromino); // Draw the next tetromino

        // Draw the current tetromino with doubled width and color
        wattron(gameWin, COLOR_PAIR(currentTetromino.color));  // Apply the color for the current tetromino
        for (int y = 0; y < 4; ++y) {
            for (int x = 0; x < 4; ++x) {
                if (currentTetromino.shape[y][x] == 'X') {
                    mvwprintw(gameWin, currentTetromino.y + y, 2 * (currentTetromino.x + x), "XX");
                }
            }
        }
        wattroff(gameWin, COLOR_PAIR(currentTetromino.color));  // Turn off the color
        wrefresh(gameWin);

        int ch = getch(); // Wait for user input

        switch (ch) {
            case 'q':
                delwin(gameWin);
                delwin(nextWin);
                endwin();
                return 0; // Exit on 'q' key
            case 'a': // Move left
            case KEY_LEFT:
                currentTetromino.x--;
                if (checkCollision(board, currentTetromino)) currentTetromino.x++;
                break;
            case 'd': // Move right
            case KEY_RIGHT:
                currentTetromino.x++;
                if (checkCollision(board, currentTetromino)) currentTetromino.x--;
                break;
            case 's': // Move down
            case KEY_DOWN:
                currentTetromino.y++;
                if (checkCollision(board, currentTetromino)) {
                    currentTetromino.y--;
                    placeTetromino(board, currentTetromino);
                    score += clearLines(board); // Update score with cleared lines
                    currentTetromino = nextTetromino; // Set the next tetromino as current
                    nextTetromino = createTetromino(); // Generate a new next tetromino
                    if (checkCollision(board, currentTetromino)) {
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
                rotateTetromino(currentTetromino);
                if (checkCollision(board, currentTetromino)) {
                    // If collision occurs, revert the rotation
                    rotateTetromino(currentTetromino); // Rotate back
                    rotateTetromino(currentTetromino); // Rotate back again (180 degrees)
                }
                break;
        }
    }

    delwin(gameWin);
    delwin(nextWin);
    endwin();
    return 0;
}