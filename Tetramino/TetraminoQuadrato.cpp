#include "TetraminoQuadrato.hpp"
#include <ncurses.h>
using namespace std;
TetraminoQuadrato::TetraminoQuadrato(Screen screen): Tetramino(screen){};

void TetraminoQuadrato::drawTetramino(WINDOW* screen, Collisioni c){
    mvwprintw(screen,getPosY(),getPosX(),"XX");
    mvwprintw(screen,getPosY()+1,getPosX(),"XX");
    c.setMatrix(posX, posY, true);
    c.setMatrix(posX+1, posY, true);
    c.setMatrix(posX, posY+1, true);
    c.setMatrix(posX+1, posY+1, true);

}

void TetraminoQuadrato::spawnTetramino(Screen screen, Collisioni c){
    mvwprintw(screen.getScreen(),1,(screen.getWide()/2)-2,"XX");
    mvwprintw(screen.getScreen(),2,(screen.getWide()/2)-2,"XX");
    c.setMatrix((screen.getWide()/2)-2, 1, true);
    c.setMatrix((screen.getWide()/2)-1, 1, true);
    c.setMatrix((screen.getWide()/2)-2, 2, true);
    c.setMatrix((screen.getWide()/2)-1, 2, true);
}

void TetraminoQuadrato::clearTetramino(WINDOW* screen) {
    mvwprintw(screen, getPosY(), getPosX(), "  ");
    mvwprintw(screen, getPosY()+1, getPosX(), "  ");
}

void TetraminoQuadrato::moveTetramino(TetraminoQuadrato* tetraminoQ, Collisioni c, int ch, WINDOW* screen) {

    int newX;
    int newY;

    switch (ch) {
        case KEY_DOWN:
            newX = tetraminoQ->posX;
            newY = tetraminoQ->posY + 2;
            if (newY<GRID_HIGH-1 && c.checkDown(newY, newX)) {

                c.setMatrix(tetraminoQ->posX, tetraminoQ->posY, false);
                c.setMatrix(tetraminoQ->posX+1, tetraminoQ->posY, false);

                clearTetramino(screen);

                c.setMatrix(newX, newY, true);
                c.setMatrix(newX+1, newY, true);
                posY++;
            }
            break;

        case KEY_LEFT:

            newX = tetraminoQ->posX -1;
            newY = tetraminoQ->posY ;


            if (newX>0 && c.checkLeft(newY, newX)) {

                c.setMatrix(posX+1, posY, false);
                c.setMatrix(posX+1, posY+1, false);

                clearTetramino(screen);

                c.setMatrix(posX-1, posY, true);
                c.setMatrix(posX-1, posY+1, true);
                posX--;
            }
            break;

        case KEY_RIGHT:

            newX = tetraminoQ->posX +1;
            newY = tetraminoQ->posY ;

            if (newX+1<GRID_WIDE-1 && c.checkRight(newY, newX)) {

                c.setMatrix(posX, posY, false);
                c.setMatrix(posX, posY+1, false);

                clearTetramino(screen);

                c.setMatrix(posX+2, posY, true);
                c.setMatrix(posX+2, posY+1, true);
                posX++;
            }
            break;
        default:
            break;
    }
    tetraminoQ->drawTetramino(screen, c); // Disegna il tetramino nella nuova posizione
}