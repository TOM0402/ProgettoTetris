#include "TetraminoLungo.hpp"

TetraminoLungo::TetraminoLungo(): Tetramino(){
    posX=22/2-4;
    posY=1;
}

int TetraminoLungo::getOrientamento() {
    return orientamento;
}
void TetraminoLungo::setOrientamento() {
    if(orientamento==0)
        orientamento=1;
    else
        orientamento=0;
}
// Disegna i Tetrimini

void TetraminoLungo::drawTetramino(WINDOW* screen) {
    if(getOrientamento()==0) {
        mvwprintw(screen, getPosY(), getPosX(), "YYYYYYYY");
    }else {
        mvwprintw(screen, getPosY(), getPosX(), "YY");
        mvwprintw(screen, getPosY()+1, getPosX(), "YY");
        mvwprintw(screen, getPosY()+2, getPosX(), "YY");
        mvwprintw(screen, getPosY()+3, getPosX(), "YY");
    }
}
void TetraminoLungo::spawnTetramino(Screen screen){
    mvwprintw(screen.getScreen(),1,(screen.getWide()/2)-2,"YYYYYYYY");
}

void TetraminoLungo::clearTetramino(WINDOW* screen, int ori) {
    if(ori==0){
        mvwprintw(screen, getPosY(), getPosX(), "        ");
    }else{
        mvwprintw(screen, getPosY(), getPosX(), "  ");
        mvwprintw(screen, getPosY()+1, getPosX(), "  ");
        mvwprintw(screen, getPosY()+2, getPosX(), "  ");
        mvwprintw(screen, getPosY()+3, getPosX(), "  ");
    }
}

void TetraminoLungo::moveTetramino(TetraminoLungo* tetramino, CollisioniLungo c, int ch, WINDOW* screen) {

    int newX;
    int newY;
    if(getOrientamento()==0) {
        switch (ch) {

            case KEY_DOWN:
                newX = tetramino->posX;
                newY = tetramino->posY + 1;
                if (newY < GRID_HIGH - 1 && c.checkDownL(newY, newX, 0)) {
                    /*for (int i = 0; i < 4; i++) {
                        c.setMatrix(posX+i, posY, false);
                    }*/

                    clearTetramino(screen, getOrientamento());

                    /*for (int i = 0; i < 4; i++) {
                        c.setMatrix(posX+i, posY+1, true);
                    }*/
                    posY++;
                }
                break;

            case KEY_LEFT:
                newX = tetramino->posX - 1;
                newY = tetramino->posY;

                if (newX > 0 && c.checkLeftL(newY, newX, 0)) {

                    //c.setMatrix(posX+3, posY, false);

                    clearTetramino(screen, getOrientamento());

                    //c.setMatrix(posX-1, posY, true);
                    posX--;
                }
                break;

            case KEY_RIGHT:
                newX = tetramino->posX + 1;
                newY = tetramino->posY;

                if (newX + 7 < GRID_WIDE - 1 && c.checkRightL(newY, newX, 0)) {

                    //c.setMatrix(posX, posY, false);

                    clearTetramino(screen, getOrientamento());

                    //c.setMatrix(posX+4, posY, true);

                    posX++;
                }
                break;
            case KEY_UP:
                if(tetramino->getPosY()>4){
                    clearTetramino(screen, getOrientamento());
                    setOrientamento();
                    drawTetramino(screen);
                }
                break;
            default:
                break;
        }
        tetramino->drawTetramino(screen); // Disegna il tetramino nella nuova posizione
    }else{
        switch (ch) {
            case KEY_DOWN:
                newX = tetramino->posX;
                newY = tetramino->posY + 1;
                if (newY < GRID_HIGH - 1 && c.checkDownL(newY, newX, 1)) {
                    /*for (int i = 0; i < 4; i++) {
                        c.setMatrix(posX+i, posY, false);
                    }*/

                    clearTetramino(screen, getOrientamento());

                    /*for (int i = 0; i < 4; i++) {
                        c.setMatrix(posX+i, posY+1, true);
                    }*/
                    posY++;
                }
                break;

            case KEY_LEFT:
                newX = tetramino->posX - 1;
                newY = tetramino->posY;

                if (newX > 0 && c.checkLeftL(newY, newX, 1)) {

                    clearTetramino(screen, getOrientamento());

                    posX--;
                }
                break;

            case KEY_RIGHT:
                newX = tetramino->posX + 1;
                newY = tetramino->posY;

                if (newX + 7 < GRID_WIDE - 1 && c.checkRightL(newY, newX, 1)) {

                    //c.setMatrix(posX, posY, false);

                    clearTetramino(screen, getOrientamento());

                    //c.setMatrix(posX+4, posY, true);

                    posX++;
                }
                break;
            case KEY_UP:

                break;
            default:
                break;
        }
        tetramino->drawTetramino(screen); // Disegna il tetramino nella nuova posizione
    }
}