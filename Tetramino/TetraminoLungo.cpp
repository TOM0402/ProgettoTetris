#include "TetraminoLungo.hpp"

TetraminoLungo::TetraminoLungo(Screen screen): Tetramino(screen){
}

// Disegna i Tetrimini
void TetraminoLungo::drawTetraminoL(WINDOW* screen, CollisioniLungo c){

    mvwprintw(screen,getPosY(),getPosX(),"YYYY");
    for(int i=0; i<4;i++){
        c.setMatrix(posX+i, 1, true);
    }
}
void TetraminoLungo::spawnTetraminoL(Screen screen, CollisioniLungo c){
    mvwprintw(screen.getScreen(),1,(screen.getWide()/2)-2,"YYYY");
    for(int i=0; i<4;i++){
        c.setMatrix(posX+i, 1, true);
    }
}

void TetraminoLungo::clearTetraminoL(WINDOW* screen) {
    mvwprintw(screen, getPosY(), getPosX(), "    ");
}

void TetraminoLungo::moveTetraminoL(TetraminoLungo* tetramino, CollisioniLungo c, int ch, WINDOW* screen) {

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

                clearTetraminoL(screen);

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

                clearTetraminoL(screen);

                //c.setMatrix(posX-1, posY, true);
                posX--;
            }
            break;

        case KEY_RIGHT:
            newX = tetramino->posX +1;
            newY = tetramino->posY ;

            if (newX+3<GRID_WIDE-1 && c.checkRightL(newY, newX)) {

                //c.setMatrix(posX, posY, false);

                clearTetraminoL(screen);

                //c.setMatrix(posX+4, posY, true);

                posX++;
            }
            break;

        default:
            break;
    }
    tetramino->drawTetraminoL(screen, c); // Disegna il tetramino nella nuova posizione
}