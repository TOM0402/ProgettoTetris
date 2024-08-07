
#ifndef TERAMINO_HPP
#define TETRAMINO_HPP

#include <ncurses.h>
#include "../Screen/ScreenG.hpp"
#include "../Collisioni/Collisioni.hpp"


class Tetramino{
protected:
    int posX, posY;
public:
    Tetramino(Screen);
    int getPosX();
    int getPosY();
};


#endif //PROGETTOTETRIS_TETRAMINO_HPP
