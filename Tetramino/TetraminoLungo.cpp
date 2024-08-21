#include "TetraminoLungo.hpp"

TetraminoLungo::TetraminoLungo(): Tetramino(){
    posX=22/2-4;
    posY=1;
}

// Disegna i Tetrimini
void TetraminoLungo::drawTetramino(WINDOW* screen, CollisioniLungo c){

    mvwprintw(screen,getPosY(),getPosX(),"YYYYYYYY");
    /*for(int i=0; i<8;i++){
        c.setMatrix(posX+i, 1, true);
    }*/
}
void TetraminoLungo::spawnTetramino(Screen screen, CollisioniLungo c){
    mvwprintw(screen.getScreen(),1,(screen.getWide()/2)-2,"YYYYYYYY");
    /*for(int i=0; i<8;i++){
        c.setMatrix(posX+i, 1, true);
    }*/
}

void TetraminoLungo::clearTetramino(WINDOW* screen) {
    mvwprintw(screen, getPosY(), getPosX(), "        ");
}

void TetraminoLungo::moveTetramino(TetraminoLungo* tetramino, CollisioniLungo c, int ch, WINDOW* screen) {

    int newX;
    int newY;

    switch (ch) {

        case KEY_DOWN:
            newX = tetramino->posX;
            newY = tetramino->posY + 1;
            if (newY<GRID_HIGH-1 && c.checkDownL(newY, newX)) {
                /*for (int i = 0; i < 4; i++) {
                    c.setMatrix(posX+i, posY, false);
                }*/

                clearTetramino(screen);

                /*for (int i = 0; i < 4; i++) {
                    c.setMatrix(posX+i, posY+1, true);
                }*/
                posY++;
            }
            break;

        case KEY_LEFT:
            newX = tetramino->posX -1;
            newY = tetramino->posY ;

            if (newX>0 && c.checkLeftL(newY, newX)) {

                //c.setMatrix(posX+3, posY, false);

                clearTetramino(screen);

                //c.setMatrix(posX-1, posY, true);
                posX--;
            }
            break;

        case KEY_RIGHT:
            newX = tetramino->posX +1;
            newY = tetramino->posY ;

            if (newX+7<GRID_WIDE-1 && c.checkRightL(newY, newX)) {

                //c.setMatrix(posX, posY, false);

                clearTetramino(screen);

                //c.setMatrix(posX+4, posY, true);

                posX++;
            }
            break;

        default:
            break;
    }
    tetramino->drawTetramino(screen, c); // Disegna il tetramino nella nuova posizione
}