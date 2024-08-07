#include "TetraminoQuadrato.hpp"
#include <ncurses.h>
using namespace std;
TetraminoQuadrato::TetraminoQuadrato(Screen screen): Tetramino(screen){};

void TetraminoQuadrato::drawTetraminoQ(WINDOW* screen, CollisioniQuadrato c){
    mvwprintw(screen,getPosY(),getPosX(),"XX");
    mvwprintw(screen,getPosY()+1,getPosX(),"XX");
    c.setMatrix(posX, posY, true);
    c.setMatrix(posX+1, posY, true);
    c.setMatrix(posX, posY+1, true);
    c.setMatrix(posX+1, posY+1, true);

}

void TetraminoQuadrato::spawnTetraminoQ(Screen screen, CollisioniQuadrato c){
    mvwprintw(screen.getScreen(),1,(screen.getWide()/2)-2,"XX");
    mvwprintw(screen.getScreen(),2,(screen.getWide()/2)-2,"XX");
    c.setMatrix((screen.getWide()/2)-2, 1, true);
    c.setMatrix((screen.getWide()/2)-1, 1, true);
    c.setMatrix((screen.getWide()/2)-2, 2, true);
    c.setMatrix((screen.getWide()/2)-1, 2, true);
}

void TetraminoQuadrato::clearTetraminoQ(WINDOW* screen) {
    mvwprintw(screen, getPosY(), getPosX(), "  ");
    mvwprintw(screen, getPosY()+1, getPosX(), "  ");
}

void TetraminoQuadrato::moveTetraminoQ(TetraminoQuadrato* tetraminoQ, CollisioniQuadrato c, int ch, WINDOW* screen) {

    int newX;
    int newY;

    switch (ch) {
        case KEY_DOWN:
            newX = tetraminoQ->posX;
            newY = tetraminoQ->posY + 2;
            if (newY<GRID_HIGH-1 && c.checkDownQ(newY, newX)) {

                c.setMatrix(tetraminoQ->posY ,tetraminoQ->posX, false);
                c.setMatrix(tetraminoQ->posY, tetraminoQ->posX+1, false);

                clearTetraminoQ(screen);

                c.setMatrix(newY, newX, true);
                c.setMatrix(newY, newX+1, true);
                posY++;
            }
            break;

        case KEY_LEFT:

            newX = tetraminoQ->posX -1;
            newY = tetraminoQ->posY ;


            if (newX>0 && c.checkLeftQ(newY, newX)) {

                c.setMatrix(posX+1, posY, false);
                c.setMatrix(posX+1, posY+1, false);

                clearTetraminoQ(screen);

                c.setMatrix(posX-1, posY, true);
                c.setMatrix(posX-1, posY+1, true);
                posX--;
            }
            break;

        case KEY_RIGHT:

            newX = tetraminoQ->posX +2;
            newY = tetraminoQ->posY ;

            if (newX<GRID_WIDE-1 && c.checkRightQ(newY, newX)) {

                c.setMatrix(posX, posY, false);
                c.setMatrix(posX, posY+1, false);

                clearTetraminoQ(screen);

                c.setMatrix(posX+2, posY, true);
                c.setMatrix(posX+2, posY+1, true);
                posX++;
            }
            break;
        default:
            break;
    }
    tetraminoQ->drawTetraminoQ(screen, c); // Disegna il tetramino nella nuova posizione
}