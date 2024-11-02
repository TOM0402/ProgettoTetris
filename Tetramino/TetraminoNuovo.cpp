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
    return shape[x][y];
}

void TetraminoNuovo::setShape(int x, int y, char a){
    shape[x][y]=a;
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

void TetraminoNuovo::rotateTetramino(TetraminoNuovo* t) {
    char temp[4][5]; //matrice temporanea per salvare il tetramino ruotato
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            temp[x][3 - y] = t->shape[y][x]; // Rotate the tetromino
        }
    }
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 5; ++x) {
            t->shape[y][x] = temp[y][x];
        }
    }
}

void TetraminoNuovo::placeTetramino(char board[GRID_HEIGHT][GRID_WIDTH], TetraminoNuovo* t) {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (t->shape[y][x] == 'X') {
                board[t->y + y][t->x + x] = 'X';
            }
        }
    }
}