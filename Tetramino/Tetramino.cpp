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

int Tetramino::getPosY(){
    return posY;
}

// Disegna i Tetrimini
void Tetramino::drawTetramino(WINDOW* screen, Collisioni c){

    mvwprintw(screen,getPosY(),getPosX(),"XXXX");
    for(int i=0; i<4;i++){
        c.setMatrix(posX+i, 1, true);
    }
}
void Tetramino::spawnTetramino(Screen screen, Collisioni c){
    mvwprintw(screen.getScreen(),1,(screen.getWide()/2)-2,"XXXX");
    for(int i=0; i<4;i++){
        c.setMatrix(posX+i, 1, true);
    }
}

void Tetramino::clearTetramino(WINDOW* screen) {
    mvwprintw(screen, getPosY(), getPosX(), "    ");
}

void Tetramino::moveTetramino(Tetramino * tetramino, Collisioni c, int ch, WINDOW* screen) {

        int newX;
        int newY;

        switch (ch) {

            case KEY_DOWN:
                newX = tetramino->posX;
                newY = tetramino->posY + 1;
                if (newY<GRID_HIGH-1 && c.checkDown(newY, newX)) {
                    for (int i = 0; i < 4; i++) {
                        c.setMatrix(posX+i, posY, false);
                    }

                    clearTetramino(screen);

                    for (int i = 0; i < 4; i++) {
                        c.setMatrix(posX+i, posY+1, true);
                    }
                    posY++;
                }
                break;

            case KEY_LEFT:
                newX = tetramino->posX -1;
                newY = tetramino->posY ;

                if (newX>0 && c.checkLeft(newY, newX)) {

                    c.setMatrix(posX+3, posY, false);

                    clearTetramino(screen);

                    c.setMatrix(posX-1, posY, true);
                    posX--;
                }
                break;

            case KEY_RIGHT:
                newX = tetramino->posX +1;
                newY = tetramino->posY ;

                if (newX+3<GRID_WIDE-1 && c.checkRight(newY, newX)) {

                    c.setMatrix(posX, posY, false);

                    clearTetramino(screen);

                    c.setMatrix(posX+4, posY, true);

                    posX++;
                }
                break;

            default:
                break;
        }
    tetramino->drawTetramino(screen, c); // Disegna il tetramino nella nuova posizione
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

