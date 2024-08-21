
#ifndef TERAMINO_HPP
#define TETRAMINO_HPP

#include <ncurses.h>
#include "../Screen/Screen.hpp"
#include "../Collisioni/Collisioni.hpp"


class Tetramino{
protected:
    int posX, posY;
public:
    Tetramino();
    int getPosX();
    int getPosY();
    void drawTetramino(WINDOW*, Collisioni c);
    void spawnTetramino(Screen, Collisioni c);
    void clearTetramino(WINDOW*);
    void moveTetramino(Tetramino* , Collisioni, int, WINDOW* screen);
};


#endif //PROGETTOTETRIS_TETRAMINO_HPP
