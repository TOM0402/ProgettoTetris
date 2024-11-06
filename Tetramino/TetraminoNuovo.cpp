//
// Created by kali on 10/28/24.
//

#include "TetraminoNuovo.hpp"
TetraminoNuovo::TetraminoNuovo() {

}
char TetraminoNuovo::getTetramini(int x, int y, int z) {
    return tetramini[x][y][z];
}
char TetraminoNuovo::getShape(int x, int y) {
    return shape[y][x];
}

void TetraminoNuovo::setShape(int x, int y, char a){
    shape[y][x]=a;
}

int TetraminoNuovo::getX() {
    return x;
}

int TetraminoNuovo::getY() {
    return y;
}

void TetraminoNuovo::setX(int a) {
    x=a;
}

void TetraminoNuovo::setY(int a) {
    y=a;
}

int TetraminoNuovo::getColor() {
    return color;
}

void TetraminoNuovo::setColor(int a) {
    color=a;
}

void TetraminoNuovo::rotateTetramino(TetraminoNuovo* currentTetramino) {
    char temp[4][4]; // Dimensione corretta per forma 4x4
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

void TetraminoNuovo::placeTetramino(char board[GRID_HEIGHT][GRID_WIDTH], TetraminoNuovo* t) {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t->shape[y][x] == 'X') {
                int boardX = t->x + x;
                int boardY = t->y + y;
                if (boardX >= 0 && boardX <= GRID_WIDTH && boardY >= 0 && boardY <= GRID_HEIGHT+2) {
                    board[boardY][boardX] = 'X';
                } else {
                    // Gestisci condizione fuori dai limiti (es. game over)
                }
            }
        }
    }
}