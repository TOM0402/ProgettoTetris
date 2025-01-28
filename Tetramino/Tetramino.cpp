#include "Tetramino.hpp"

Tetramino::Tetramino() {

}
char Tetramino::getTetramini(int x, int y, int z) {
    return tetramini[x][y][z];
}
char Tetramino::getShape(int y, int x) {
    return shape[y][x];
}

void Tetramino::setShape(int y, int x, char a){
    shape[y][x]=a;
}

int Tetramino::getX() {
    return x;
}

int Tetramino::getY() {
    return y;
}

void Tetramino::setX(int a) {
    x=a;
}

void Tetramino::setY(int a) {
    y=a;
}

int Tetramino::getColor() {
    return color;
}

void Tetramino::setColor(int a) {
    color=a;
}

void Tetramino::rotateTetramino(Tetramino* currentTetramino) {
    char temp[4][4];
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            temp[x][3 - y] = currentTetramino->getShape(y, x);
        }
    }
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            currentTetramino->setShape(y, x, temp[y][x]);
        }
    }
}

void Tetramino::placeTetramino(char board[GRID_HEIGHT][GRID_WIDTH], Tetramino* t) {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t->getShape(y,x) == 'X') {
                int boardX = t->getX() + x;
                int boardY = t->getY() + y;
                if (boardX >= 0 && boardX < GRID_WIDTH &&
                    boardY >= 0 && boardY < GRID_HEIGHT) {
                    board[boardY][boardX] = t->getColor();
                }
            }
        }
    }
}

bool Tetramino::checkCollisioni(char board[GRID_HEIGHT][GRID_WIDTH], Tetramino *t) {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t->getShape(y, x) == 'X') {
                int boardX = t->getX() + x;
                int boardY = t->getY() + y;



                if (boardX < 0 || boardX >= GRID_WIDTH || boardY < 0 || boardY >= GRID_HEIGHT-2) {
                    return true; // Collisione con i bordi
                }

                // Controllo collisione con altri blocchi
                if (boardY >= 0 && board[boardY][boardX] != '.') {
                    return true;
                }
            }
        }
    }
    return false;
}
