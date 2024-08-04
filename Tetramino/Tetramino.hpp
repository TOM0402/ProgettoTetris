
#ifndef ETRAMINO_HPP
#define TETRAMINO_HPP
#include <ncurses.h>
#include "../Screen/ScreenG.hpp"
#include "../Collisioni/Collisioni.hpp"


class Tetramino {
protected:
    int posX, posY;
    int lunghezza, altezza;
public:
    Tetramino(Screen);
    int getPosX();
    void setPosX(int);
    int getPosY();
    void setPosY(int);
    void drawTetramino(WINDOW*);
    void spawnTetramino(WINDOW*);
    void moveTetramino(Tetramino* , int, int, Collisioni);
};


#endif //PROGETTOTETRIS_TETRAMINO_HPP
