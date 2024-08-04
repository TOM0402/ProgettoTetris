#include "Tetramino.hpp"
#include "../Screen/ScreenG.hpp"
#include "../Collisioni/Collisioni.hpp"
#include <ncurses.h>
using namespace std;

Tetramino::Tetramino(Screen screen) {
    posY=1;
    posX=(screen.getWide()/2)-2;
}

int Tetramino::getPosX(){
    return posX;
}

void Tetramino::setPosX(int x){
    posX=x;
}

int Tetramino::getPosY(){
    return posY;
}

void Tetramino::setPosY(int y){
    posY=y;
}

// Disegna i Tetrimini
void Tetramino::drawTetramino(WINDOW* screen){
    mvwprintw(screen,getPosY(),getPosX(),"XXXX");
}
void Tetramino::spawnTetramino(WINDOW* screen){
    
    mvwprintw(screen,getPosY(),getPosX(),"XXXX");
}
void Tetramino::moveTetramino(Tetramino * tetramino, int x, int y, Collisioni c) {
    int ch;
    while ((ch = getch()) != 'q') {
        //mvprintw(y, x, " "); // Cancella il carattere precedente


        // Calcola la nuova posizione
        int newX = tetramino->posX + x;
        int newY = tetramino->posY + y;
        // Verifica se il movimento è valido
        if (newX < 0 || newX + 5 > GRID_WIDE - 1 || newY < 0 || newY + 1 > GRID_HIGH - 1) {
            // Il movimento è fuori dai limiti della griglia, quindi non lo eseguiamo
            return;
        }
        switch (ch) {
            case KEY_DOWN:
                if (c.checkDown(newY, newX)) {
                    c.setMatrix(posY, posX, false);
                    c.setMatrix(posY, posX + 1, false);
                    c.setMatrix(posY, posX + 2, false);
                    c.setMatrix(posY, posX + 3, false);
                    tetramino->posX = newX;
                    tetramino->posY = newY;
                    c.setMatrix(newY, newX, true);
                    c.setMatrix(newY, newX + 1, true);
                    c.setMatrix(newY, newX + 2, true);
                    c.setMatrix(newY, newX + 3, true);
                }
                break;
            case KEY_LEFT:
                if (c.checkLeft(newY, newY)) {
                    c.setMatrix(posY, posX + 3, false);
                    tetramino->posX = newX;
                    tetramino->posY = newY;
                    c.setMatrix(newY, newX, true);
                }
                break;
            case KEY_RIGHT:
                if (c.checkLeft(newY, newY)) {
                    c.setMatrix(posY, posX, false);
                    tetramino->posX = newX;
                    tetramino->posY = newY;
                    c.setMatrix(newY, newX + 3, true);
                }
                break;
            default:
                break;
        }
    }
}

/*
void Tetramino::moveTetramino(Tetramino* tetrimino, int dx, int dy, char a){
    // Calcola la nuova posizione
    int newX = tetrimino->posX + dx;
    int newY = tetrimino->posY + dy;

    // Verifica se il movimento è valido
    if (newX < 0 || newX + 5 > GRID_WIDTH -1 || newY < 0 || newY + 1 > GRID_HEIGHT - 1) {
        // Il movimento è fuori dai limiti della griglia, quindi non lo eseguiamo
        return;
    }
    switch(a){
        case 'd':
            if(!occupiedMatrix[newX+4][newY]) {
                occupiedMatrix[newX-dx][newY-dy] = false;
                tetrimino->posX = newX;
                tetrimino->posY = newY;
                occupiedMatrix[newX+4][newY] = true;
            }
            break;

        case 'a':
            if(!occupiedMatrix[newX-1][newY]) {
                occupiedMatrix[newX-dx+3][newY-dy] = false;
                tetrimino->posX = newX;
                tetrimino->posY = newY;
                occupiedMatrix[newX-1][newY] = true;
            }
            break;

        case 's':
            if(!occupiedMatrix[newX][newY] && !occupiedMatrix[newX+1][newY] && !occupiedMatrix[newX+2][newY] && !occupiedMatrix[newX+3][newY]) {
                occupiedMatrix[newX-dx][newY-dy] = false;
                occupiedMatrix[newX-dx+1][newY-dy] = false;
                occupiedMatrix[newX-dx+2][newY-dy] = false;
                occupiedMatrix[newX-dx+3][newY-dy] = false;
                tetrimino->posX = newX;
                tetrimino->posY = newY;
                occupiedMatrix[newX][newY] = true;
                occupiedMatrix[newX+1][newY] = true;
                occupiedMatrix[newX+2][newY] = true;
                occupiedMatrix[newX+3][newY] = true;
            }
            break;
    }

}
/*
    // Funzione per spostare un Tetrimino
    void moveTetriminoDx(Tetrimino* tetrimino, int dx, int dy) {
        // Calcola la nuova posizione
        int newX = tetrimino->posX + dx;
        int newY = tetrimino->posY + dy;

        // Verifica se il movimento è valido
        if (newX < 0 || newX + 5 > GRID_WIDTH -1 || newY < 0 || newY + 1 > GRID_HEIGHT - 1) {
            // Il movimento è fuori dai limiti della griglia, quindi non lo eseguiamo
            return;
        }

        // Se il movimento a destra è valido, aggiorna la posizione del Tetrimino
        if(!occupiedMatrix[newX+4][newY]) {
            occupiedMatrix[newX-dx][newY-dy] = false;
            tetrimino->posX = newX;
            tetrimino->posY = newY;
            occupiedMatrix[newX+4][newY] = true;
        }

    }

    void moveTetriminoSx(Tetrimino* tetrimino, int dx, int dy) {
        // Calcola la nuova posizione
        int newX = tetrimino->posX + dx;
        int newY = tetrimino->posY + dy;

        // Verifica se il movimento è valido
        if (newX < 0 || newX + 5 > GRID_WIDTH -1 || newY < 0 || newY + 1 > GRID_HEIGHT - 1) {
            // Il movimento è fuori dai limiti della griglia, quindi non lo eseguiamo
            return;
        }

        // Se il movimento a destra è valido, aggiorna la posizione del Tetrimino
        if(!occupiedMatrix[newX-1][newY]) {
            occupiedMatrix[newX-dx+3][newY-dy] = false;
            tetrimino->posX = newX;
            tetrimino->posY = newY;
            occupiedMatrix[newX-1][newY] = true;
        }

    }

    void moveTetriminoDown(Tetrimino* tetrimino, int dx, int dy) {
        // Calcola la nuova posizione
        int newX = tetrimino->posX + dx;
        int newY = tetrimino->posY + dy;

        // Verifica se il movimento è valido
        if (newX < 0 || newX + 5 > GRID_WIDTH -1 || newY < 0 || newY + 1 > GRID_HEIGHT - 1) {
            // Il movimento è fuori dai limiti della griglia, quindi non lo eseguiamo
            return;
        }

        // Se il movimento a destra è valido, aggiorna la posizione del Tetrimino
        if(!occupiedMatrix[newX][newY] && !occupiedMatrix[newX+1][newY] && !occupiedMatrix[newX+2][newY] && !occupiedMatrix[newX+3][newY]) {
            occupiedMatrix[newX-dx][newY-dy] = false;
            occupiedMatrix[newX-dx+1][newY-dy] = false;
            occupiedMatrix[newX-dx+2][newY-dy] = false;
            occupiedMatrix[newX-dx+3][newY-dy] = false;
            tetrimino->posX = newX;
            tetrimino->posY = newY;
            occupiedMatrix[newX][newY] = true;
            occupiedMatrix[newX+1][newY] = true;
            occupiedMatrix[newX+2][newY] = true;
            occupiedMatrix[newX+3][newY] = true;
        }

    }

};*/

