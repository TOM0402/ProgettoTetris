
#ifndef ETRAMINO_HPP
#define TETRAMINO_HPP
#include <ncurses.h>


class Tetramino {
protected:
    int posX, posY;
    int lunghezza, altezza;
public:
    Tetramino();
    int getPosX();
    void setPosX(int);
    int getPosY();
    void setPosY(int);
    void drawTetramino(WINDOW*);
    void spawnTetramino(WINDOW*);
    //void moveTetramino(Tetramino* , int , int , char );
};


#endif //PROGETTOTETRIS_TETRAMINO_HPP
